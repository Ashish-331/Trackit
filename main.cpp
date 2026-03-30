#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

int main() {
    // 1. Init GLFW (window system)
    glfwInit();

    GLFWwindow* window = glfwCreateWindow(800, 600, "System Monitor", NULL, NULL);
    glfwMakeContextCurrent(window);

    // 2. Load OpenGL functions
    gladLoadGL();

    // 3. Init ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        // Start ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // -------- UI START --------
        ImGui::Begin("CPU");
        ImGui::Text("Usage: 45%%");
        ImGui::ProgressBar(0.45f);
        ImGui::End();

        ImGui::Begin("Processes");

        // Scrollable region
        ImGui::BeginChild("scroll", ImVec2(0, 300), true);

        for (int i = 0; i < 100; i++) {
            ImGui::Text("Process %d - CPU %d%%", i, i % 100);
        }

        ImGui::EndChild();
        ImGui::End();
        // -------- UI END --------

        // Render
        ImGui::Render();
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    glfwTerminate();
}