#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "Lander Application", sf::Style::Close | sf::Style::Resize);
    sf::CircleShape shape(50);
    shape.setFillColor(sf::Color(100, 250, 50));
    while (window.isOpen())
    {
    sf::Event event;
    while (window.pollEvent(event))
    {

        switch(event.type)
        {
            case sf::Event::Closed:
            window.close();
            break;
            case sf::Event::Resized:
            printf("New window width:%i New window height:%i\n", event.size.width ,event.size.height);
            break;

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {

        }

        if(event.type == event.Closed)
        {
            window.close();
        }       
    }

    }
    window.clear();
    window.draw(shape);
    window.display();
    return 0;
}
