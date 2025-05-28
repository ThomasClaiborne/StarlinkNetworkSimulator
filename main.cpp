#include <Eigen/Dense>

#include "imgui.h"
#include "imgui-SFML.h"

#include "SFML/Graphics.hpp"

using Eigen::MatrixXd;

int main()
{
    MatrixXd m(2, 2);


    sf::RenderWindow window(sf::VideoMode({ 800, 900 }), "Starlink Network Simulator!");
	ImGui::SFML::Init(window);
    
    bool drawCircle = true;
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Blue);

	sf::Clock deltaClock;
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
			ImGui::SFML::ProcessEvent(window, *event);
            if (event->is<sf::Event::Closed>())
                window.close();
        }
		ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::Begin("Stats");
		ImGui::Text("Hello, world!");
        ImGui::Checkbox("Circle", &drawCircle);
        ImGui::End();



        window.clear();
        if(drawCircle)
            window.draw(shape);
		ImGui::SFML::Render(window);
        window.display();
    }
	ImGui::SFML::Shutdown(window);
	return 0;
}