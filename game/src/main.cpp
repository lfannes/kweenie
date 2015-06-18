#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

class Player
{
    public:
        Player()
        {
            //Bal aanmaken om te tekenen
            setRadius_Color_(hoofd_, 50, sf::Color::Cyan);
            hoofd_.setPosition(125, 160);
            //Linker oog aanmaken
            setRadius_Color_(linker_oog_, 10, sf::Color::Red);
            linker_oog_.setPosition(100, 150);
            //Rechter oog aanmaken
            setRadius_Color_(rechter_oog_, 10, sf::Color::Red);
            rechter_oog_.setPosition(150, 150);
            zwarte_balk_.setSize(sf::Vector2f(220, 120));
            zwarte_balk_.setPosition(140, 110);
            zwarte_balk_.setFillColor(sf::Color::Black);
            //Laad font
            if (font_.loadFromFile("GoodDog.otf"))
            {
            	cout << "Font OK" << endl;
            }
            else
            {
            	cout << "Font FAILED" << endl;
            }
            play_.setString("Play");
            play_.setFont(font_);
            play_.setCharacterSize(100);
            play_.setPosition(150, 90);
            play_.setColor(sf::Color::Green);
        	mond_.setSize(sf::Vector2f(40, 20));
        	mond_.setPosition(105, 170);
        	mond_.setFillColor(sf::Color::Black);
        }

        void draw_on(sf::RenderWindow &window)
        {
            window.draw(play_);
            window.draw(zwarte_balk_);
            window.draw(hoofd_);
            window.draw(mond_);
            window.draw(linker_oog_);
            window.draw(rechter_oog_);
        }

        void move(int x, int y)
        {
        	zwarte_balk_.move(x,y);
            hoofd_.move(x,y);
            mond_.move(x,y);
            linker_oog_.move(x,y);
            rechter_oog_.move(x,y);
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
        sf::RectangleShape zwarte_balk_;
        sf::Text play_;
        sf::Font font_;
        sf::RectangleShape mond_;
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
        void update()
        {
            if (aantal_moves_ < 250)
            {
                player_.move(1,0);
                ++aantal_moves_;
            }
        }
        bool venster_is_open()
        {
            return window_.isOpen();
        }

    private:
        sf::RenderWindow window_{sf::VideoMode(800, 600), "Lander zijn game"};
        Player player_;
        int aantal_moves_ = 0;
};

int main()
{
    std::cout << "Hello world." << std::endl;

    Game game;

    while (game.venster_is_open())
    {
        game.reageer_op_gebeurtenissen();

        game.teken_scherm();

        game.update();

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    return 0;
}
