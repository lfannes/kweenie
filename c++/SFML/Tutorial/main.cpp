#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 640), "Lander Application");

    sf::SoundBuffer buffer;
    if(!buffer.loadFromFile("Resources/cat.wav"))
    {
        std::cout << "Font not found" << std::endl;
    }

    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.play();

    sf::Font font;
    if(!font.loadFromFile("Resources/arial.ttf"))
    {
        std::cout << "Font not found" << std::endl;
        return -1;
    }


    sf::Text text;
    text.setFont(font);
    text.setString("Kaka pipi");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Red);
    text.setPosition(315.f, 20.f);


    sf::RectangleShape line(sf::Vector2f(150, 5));
    line.setPosition(320.f, 320.f);

    sf::CircleShape shape(80, 8);
    shape.setFillColor(sf::Color::Cyan);
    shape.setRadius(40.f);
    shape.setPosition(100.f, 100.f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                shape.move(-3, 0);
                line.rotate(-3);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                shape.move(3, 0);
                line.rotate(3);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                shape.move(0, -3);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                shape.move(0, 3);
            }

            if(event.type == event.Closed)
            {
                window.close();
            }       
        }
    window.clear();
    window.draw(shape);
    window.draw(line);
    window.draw(text);
    window.display();
    }
    
}
