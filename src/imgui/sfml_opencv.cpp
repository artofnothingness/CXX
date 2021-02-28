#include <iostream>

#include "imgui-SFML.h"
#include "imgui.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

void fromMatToSprite(const Mat &m, Mat &m_rgba, sf::Texture & t, sf::Image &i, sf::Sprite &s) {
  cv::cvtColor(m, m_rgba, cv::COLOR_BGR2RGBA);
  i.create(m_rgba.cols, m_rgba.rows, m_rgba.ptr());
  if (!t.loadFromImage(i)) 
    return;

  s.setTexture(t);
}

int main() {

  cv::VideoCapture cap(0); // open the video file for reading
  if (!cap.isOpened()) {
    return 0;
  }

  sf::RenderWindow window(sf::VideoMode(1200, 900), "RenderWindow");
  cv::Mat frameRGB, frameRGBA;
  sf::Image image;
  sf::Texture texture;
  sf::Event event;
  sf::Sprite sprite;

  while (window.isOpen()) {
    cap >> frameRGB;

    if (frameRGB.empty()) {
      break;
    }

    fromMatToSprite(frameRGB, frameRGBA, texture, image, sprite);

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.draw(sprite);
    window.display();
  }
}
