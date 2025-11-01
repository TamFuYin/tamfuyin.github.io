#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>
#include <deque>
#include <cstdlib>
#include <ctime>

struct SnakeGame {
    int grid_size = 20;
    int cell_size = 20;
    ImVec2 food;
    std::deque<ImVec2> snake;
    ImVec2 dir = ImVec2(1, 0);
    bool alive = true;
    float tick = 0.15f;
    float timer = 0.0f;

    SnakeGame() { reset(); }

    void reset() {
        snake.clear();
        snake.push_back(ImVec2(5, 5));
        snake.push_back(ImVec2(4, 5));
        snake.push_back(ImVec2(3, 5));
        dir = ImVec2(1, 0);
        spawn_food();
        alive = true;
        timer = 0;
    }

    void spawn_food() {
        food.x = rand() % grid_size;
        food.y = rand() % grid_size;
    }

    void update(float dt) {
        if (!alive) return;
        timer += dt;
        if (timer < tick) return;
        timer = 0;

        ImVec2 head = snake.front();
        head.x += dir.x;
        head.y += dir.y;

        // 撞墙或撞自己
        if (head.x < 0 || head.y < 0 || head.x >= grid_size || head.y >= grid_size)
            alive = false;
        for (auto& p : snake)
            if (p.x == head.x && p.y == head.y)
                alive = false;

        if (!alive) return;

        snake.push_front(head);
        if (head.x == food.x && head.y == food.y) {
            spawn_food();
        } else {
            snake.pop_back();
        }
    }

    void render(ImDrawList* draw, ImVec2 origin) {
        // 绘制格子
        ImU32 col_grid = IM_COL32(80, 80, 80, 255);
        for (int i = 0; i <= grid_size; i++) {
            draw->AddLine(ImVec2(origin.x, origin.y + i * cell_size),
                          ImVec2(origin.x + grid_size * cell_size, origin.y + i * cell_size),
                          col_grid);
            draw->AddLine(ImVec2(origin.x + i * cell_size, origin.y),
                          ImVec2(origin.x + i * cell_size, origin.y + grid_size * cell_size),
                          col_grid);
        }

        // 绘制食物
        ImU32 col_food = IM_COL32(255, 100, 100, 255);
        draw->AddRectFilled(ImVec2(origin.x + food.x * cell_size, origin.y + food.y * cell_size),
                            ImVec2(origin.x + (food.x + 1) * cell_size, origin.y + (food.y + 1) * cell_size),
                            col_food);

        // 绘制蛇
        ImU32 col_snake = IM_COL32(100, 255, 100, 255);
        for (auto& p : snake) {
            draw->AddRectFilled(ImVec2(origin.x + p.x * cell_size, origin.y + p.y * cell_size),
                                ImVec2(origin.x + (p.x + 1) * cell_size, origin.y + (p.y + 1) * cell_size),
                                col_snake);
        }
    }
};

int main() {
    srand((unsigned)time(0));
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(800, 600, "ImGui Snake", NULL, NULL);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    SnakeGame game;

    float last_time = (float)glfwGetTime();
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        float now = (float)glfwGetTime();
        float dt = now - last_time;
        last_time = now;

        // 键盘输入
        if (ImGui::IsKeyPressed(ImGuiKey_UpArrow) && game.dir.y == 0) game.dir = ImVec2(0, -1);
        if (ImGui::IsKeyPressed(ImGuiKey_DownArrow) && game.dir.y == 0) game.dir = ImVec2(0, 1);
        if (ImGui::IsKeyPressed(ImGuiKey_LeftArrow) && game.dir.x == 0) game.dir = ImVec2(-1, 0);
        if (ImGui::IsKeyPressed(ImGuiKey_RightArrow) && game.dir.x == 0) game.dir = ImVec2(1, 0);

        game.update(dt);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::Begin("Snake Game");
        if (!game.alive) {
            ImGui::Text("Game Over!");
            if (ImGui::Button("Restart")) game.reset();
        } else {
            ImGui::Text("Use arrow keys to move");
        }

        ImVec2 origin = ImGui::GetCursorScreenPos();
        ImDrawList* draw = ImGui::GetWindowDrawList();
        game.render(draw, origin);
        ImGui::Dummy(ImVec2(game.grid_size * game.cell_size, game.grid_size * game.cell_size));

        ImGui::End();

        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
