#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <menu.hpp>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Memory");

    Menu menu(window.getSize().x, window.getSize().y);

    sf::SoundBuffer buffer;
    if(!buffer.loadFromFile("Resources/BackgroundSound.wav"))
    {
        std::cout << "Sound not found" << std::endl;
    }

    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.play();

    sf::Texture bTexture;
    sf::Sprite backgroundImage;

    if(!bTexture.loadFromFile("Resources/memory.png"))
    {
        cout << "background not succesfull loaded" << endl;
    }

    backgroundImage.setTexture(bTexture);
    backgroundImage.setPosition(640, 360);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::KeyReleased:
                switch(event.key.code)
                {
                    case sf::Keyboard::Up:

                    cout << "The up key is pressed" << endl;
                    menu.MoveUp();
                    break;

                    case sf::Keyboard::Down:

                    cout << "The down key is pressed" << endl;
                    menu.MoveDown();
                    break;

                    case sf::Keyboard::Return:
                    switch (menu.GetPressedItem())
                    {
                        case 0:
                            cout << "Play button has beeb pressed" << endl;
                        case 1:
                            cout << "Options button has been pressed" << endl;
                        case 2:
                            cout << "Exit button has been pressed" << endl;
                            window.close();
                    }
                    break;
                }

                break;
            case sf::Event::Closed:
            window.close();
            break;
            }   
        }
    window.clear();

    menu.draw(window);

    window.draw(backgroundImage);
    window.display();
    }
    
}
