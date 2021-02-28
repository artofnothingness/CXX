#include <iostream>

#include "imgui-SFML.h"
#include "imgui.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

int main() {
  sf::RenderWindow window(sf::VideoMode(200, 200), "");
  window.setVerticalSyncEnabled(true);
  ImGui::SFML::Init(window);

  sf::Color bgColor;
  float color[3] = {0.f, 0.f, 0.f};

  char windowTitle[255] = "ImGui + SFML = <3";
  window.setTitle(windowTitle);

  sf::Clock deltaClock;

  window.resetGLStates();
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      ImGui::SFML::ProcessEvent(event);

      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    ImGui::SFML::Update(window, deltaClock.restart());

    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImVec2(200, 200));
    ImGui::Begin("ImGui is Cool"); // создаём окно

    if (ImGui::Button("Button1")) {
    }

    static bool b = false;
    ImGui::Checkbox("CheckBox", &b);
    float f;
    ImGui::SliderFloat("float", &f, 0.0f, 1.0f);

    ImGui::End(); // end window

    window.clear(); // заполняем окно заданным цветом
    ImGui::SFML::Render(window);
    window.display();
  }

  ImGui::SFML::Shutdown();
}
