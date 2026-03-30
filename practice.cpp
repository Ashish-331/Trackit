#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<cmath>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <dirent.h>
#include <cctype>
#include <algorithm>

#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
    struct Process {
    int pid;
    std::string name;
    long memory;
    };

    std::vector<Process> getProcesses()
    {
        std::vector<Process> processes;

        DIR* dir = opendir("/proc");
        if (!dir) return processes;

        struct dirent* entry;

        while ((entry = readdir(dir)) != NULL)
        {
            if (entry->d_type == DT_DIR)
            {
                std::string pid_str = entry->d_name;

                // check numeric
                bool isNumber = true;
                for (char c : pid_str)
                {
                    if (!isdigit(c)) { isNumber = false; break; }
                }

                if (!isNumber) continue;

                int pid = std::stoi(pid_str);

                // read name
                std::ifstream f("/proc/" + pid_str + "/comm");
                std::string name;
                if (f.is_open())
                    std::getline(f, name);
                else
                    continue;
                std::ifstream f2("/proc/" + pid_str + "/status");
                std::string line;
                long mem_kb = 0;

                while (std::getline(f2, line))
                {
                    if (line.find("VmRSS:") == 0)
                    {
                        std::stringstream ss(line);
                        std::string key, unit;
                        ss >> key >> mem_kb >> unit;
                        break;
                    }
                }

                processes.push_back({pid, name, mem_kb});
            }
        }

        closedir(dir);
        return processes;
    }

void systemusage(std::vector<std::string>& mem)
{
    std::ifstream file("/proc/meminfo");
    std::string line;
    long long memavl;
    long long tmem;

    bool flag1=false, flag2=false;

    while(getline(file,line))
    {
        if(line.find("MemTotal")!=std::string::npos)
        {
            std::string word, unit;
            std::stringstream ss(line);

            ss>>word>>tmem>>unit;

            flag1=true;

            mem.push_back(
                std::to_string(
                    (double)tmem/(1024.0*1024.0)
                )
            );
        }

        if(line.find("MemAvailable")!=std::string::npos)
        {
            std::string word, unit;
            std::stringstream ss(line);

            ss>>word>>memavl>>unit;

            flag2=true;

            mem.push_back(
                std::to_string(
                    (double)memavl/(1024.0*1024.0)
                )
            );
        }

        if(flag1 && flag2)
        {
            mem.push_back(
                std::to_string(
                    (tmem-memavl)/(1024.0*1024.0)
                )
            );

            break;
        }
    }

    return ;
}


std::vector<std::vector<long long>> cpu()
{
    std::vector<std::vector<long long>> stats;

    std::ifstream file("/proc/stat");
    std::string line;

    while(getline(file,line))
    {
        if(line.rfind("cpu",0)==0)
        {
            std::stringstream ss(line);

            std::string word;
            long long user,nice,system,idle;

            ss>>word>>user>>nice>>system>>idle;

            long long active = user + nice + system;
            long long total  = active + idle;

            stats.push_back({active,total});
        }
        else
        {
            break;
        }
    }

    return stats;
}




int main() {
    glfwInit();

    GLFWwindow* window = glfwCreateWindow(800, 600, "Practice", NULL, NULL);
    glfwMakeContextCurrent(window);

    gladLoadGL();

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // YOU WILL WRITE HERE
        ImVec2 size = ImGui::GetIO().DisplaySize;
        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::SetNextWindowSize(ImVec2(size.x * 0.45f, size.y * 0.5f));
        ImGui::Begin("CPU", NULL,
            ImGuiWindowFlags_NoMove |
            ImGuiWindowFlags_NoResize |
            ImGuiWindowFlags_NoCollapse
        );
        ImGui::Text("My Panel");
        ImGui::Separator();
        ImGui::Text("Name: Ashish!");
        ImGui::SameLine();
        ImGui::Text("Age: 20");
        ImGui::Spacing();

        ImGui::Text("CPU");
        float memo=0.9f;
        static std::vector<std::vector<long long>> prev;
        static float last_time = 0.0f;

        static float cpu_usage = 0.0f;

        float now = ImGui::GetTime();
        static float history[100]={0};

        if (now - last_time >= 0.3f)
        {
            auto curr = cpu();
            for (int i = 0; i < 99; i++)
            {
                history[i] = history[i+1];
            }

            history[99] = cpu_usage;

            if (!prev.empty())
            {
                long long da = curr[0][0] - prev[0][0];
                long long dt = curr[0][1] - prev[0][1];

                cpu_usage = (float)da / dt;
            }

            prev = curr;
            last_time = now;
        }
        std::string dis_cpu=std::to_string(cpu_usage*100)+" %";
        ImGui::ProgressBar(cpu_usage,ImVec2(0,0),dis_cpu.c_str());
        ImGui::Text("Nice to meet youu");
        
        ImGui::Text("Memory");
        std::vector<std::string> mem;
        systemusage(mem);
        float total=std::stof(mem[0]);
        float avl=std::stof(mem[1]);
        float mem_usage=(float)(total-avl)/total;
        std::string dis_mem=mem[2]+"/"+mem[0];
        ImGui::ProgressBar(mem_usage,ImVec2(0,0),dis_mem.c_str());
        

        ImGui::End();

        //process section hai
        ImGui::SetNextWindowPos(ImVec2(0.45f*size.x, 0));
        ImGui::SetNextWindowSize(ImVec2(size.x * 0.55f, size.y * 0.5f));
        ImGui::Begin("PROCESS", NULL,
            ImGuiWindowFlags_NoMove |
            ImGuiWindowFlags_NoResize |
            ImGuiWindowFlags_NoCollapse
        );
        ImGui::Separator();
        ImGui::BeginChild("Processes",ImVec2(0,0),true);
        ImGui::BeginTable("Usage",3,ImGuiTableFlags_BordersInner | ImGuiTableFlags_BordersOuter);
        ImGui::TableNextRow();

        ImGui::TableSetColumnIndex(0);
        ImGui::Text("PID");

        ImGui::TableSetColumnIndex(1);
        ImGui::Text("NAME");

        ImGui::TableSetColumnIndex(2);
        ImGui::Text("RAM");

        static float last_proc_time = 0.0f;
        static std::vector<Process> processes;

        float now2 = ImGui::GetTime();

        if (now2 - last_proc_time > 1.0f)
        {
            processes = getProcesses();

            std::sort(processes.begin(), processes.end(),
                [](const Process &a, const Process &b)
                {
                    return a.memory > b.memory;
                });

            last_proc_time = now2;
        }

        int count = 0;

        for (auto &p : processes)
        {
            if (count++ > 200) break;

            ImGui::TableNextRow();

            ImGui::TableSetColumnIndex(0);
            ImGui::Text("%d", p.pid);

            ImGui::TableSetColumnIndex(1);
            ImGui::Text("%s", p.name.c_str());

            ImGui::TableSetColumnIndex(2);
            ImGui::Text("%ld MB", p.memory / 1024);
        }

        ImGui::EndTable();
        ImGui::EndChild();
        ImGui::End();



        float arr[100];
        for(int i=0;i<100;i++)
        {
            arr[i] = std::sin(i * 0.1f);
        }
        ImGui::SetNextWindowPos(ImVec2(0, size.y*0.5));
        ImGui::SetNextWindowSize(ImVec2(size.x , size.y*0.5f ));
        ImGui::Begin("CPU-Graph", NULL,
            ImGuiWindowFlags_NoMove |
            ImGuiWindowFlags_NoResize |
            ImGuiWindowFlags_NoCollapse
        );

        ImGui::BeginChild("Graph_area", ImVec2(0,0), true);

        ImVec2 pos = ImGui::GetCursorScreenPos();
        ImVec2 size2= ImGui::GetContentRegionAvail();

        ImDrawList* draw = ImGui::GetWindowDrawList();

        for (int i = 0; i <= 5; i++)
        {
            float t = i / 5.0f;
            float y = pos.y + size2.y * (1.0f - t);

            int percent = t * 100;

            draw->AddText(ImVec2(pos.x + 5, y - 8), IM_COL32(200,200,200,255),
                        (std::to_string(percent) + "%").c_str());
        }

        // shift graph
        ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 40);

        ImVec2 avail = ImGui::GetContentRegionAvail();

        ImGui::PushStyleColor(ImGuiCol_PlotLines, IM_COL32(0, 255, 150, 255));
        ImGui::PushStyleColor(ImGuiCol_PlotLinesHovered, IM_COL32(0, 255, 200, 255));
        ImGui::PlotLines("CPU", history, 100, 0, NULL, 0.0f, 1.0f, avail);
        ImGui::PopStyleColor(2);

        ImGui::EndChild();

        ImGui::End();


        ImGui::Render();
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    glfwTerminate();
}