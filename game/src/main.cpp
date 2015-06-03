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
            setRadius_Color_(hoofd_, 100, sf::Color::Cyan);
            hoofd_.setPosition(250, 320);
            //Linker oog aanmaken
            setRadius_Color_(linker_oog_, 20, sf::Color::Red);
            linker_oog_.setPosition(200, 300);
            //Rechter oog aanmaken
            setRadius_Color_(rechter_oog_, 20, sf::Color::Red);
            rechter_oog_.setPosition(300, 300);
        }

        void draw_on(sf::RenderWindow &window)
        {
            window.draw(hoofd_);
            window.draw(linker_oog_);
            window.draw(rechter_oog_);
        }

    private:
        void setRadius_Color_(sf::CircleShape &bal, float radius, sf::Color color)
        {
            bal.setRadius(radius);
            bal.setOrigin(radius, radius);
            bal.setFillColor(color);
        }
        sf::CircleShape hoofd_;
        sf::CircleShape linker_oog_;
        sf::CircleShape rechter_oog_;
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
            player_.draw_on(window_);
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
