#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
using namespace std;

class Player
{
    public:
        Player()
        {
            //Bal aanmaken om te tekenen
            bal_.setRadius(40);
            bal_.setPosition(400-40, 300-40);
            bal_.setFillColor(sf::Color::Cyan);
        }

        sf::CircleShape bal_;
    private:
};

class Game
{
    public:
        void reageer_op_gebeurtenissen()
        {
            //Kijken of we moeten afsluiten
            sf::Event gebeurtenis;
            while (window_.pollEvent(gebeurtenis))
            {
                if (gebeurtenis.type == sf::Event::Closed)
                    window_.close();
            }
        }
        void teken_scherm()
        {
            //Wis het scherm
            window_.clear();
            //Teken de bal
            window_.draw(player_.bal_);
            //Wissel de schermbuffers: dan pas zie je het resultaat
            window_.display();
        }
        bool venster_is_open()
        {
            return window_.isOpen();
        }

    private:
        sf::RenderWindow window_{sf::VideoMode(800, 600), "Lander zijn game"};
        Player player_;
};

int main()
{
    std::cout << "Hello world." << std::endl;

    Game game;

    while (game.venster_is_open())
    {
        game.reageer_op_gebeurtenissen();

        game.teken_scherm();
    }
    return 0;
}
