#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>

int main()
{
    std::cout << "Hello world." << std::endl;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Lander zijn game");

    //Bal aanmaken om te tekenen
    sf::CircleShape bal;
    bal.setRadius(40);
    bal.setPosition(400-40, 300-40);
    bal.setFillColor(sf::Color::Cyan);

    while (window.isOpen())
    {
        //Kijken of we moeten afsluiten
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //Teken het scherm
        {
            //Wis het scherm
            window.clear();
            //Teken de bal
            window.draw(bal);
            //Wissel de schermbuffers: dan pas zie je het resultaat
            window.display();
        }
    }
    return 0;
}
