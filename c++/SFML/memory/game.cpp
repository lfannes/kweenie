#include "game.hpp"
#include "menu.hpp"
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

Game::Game(): window_(sf::VideoMode(1750, 870), "Memory"), menu_(window_.getSize().x, window_.getSize().y)
{
    if(!font_.loadFromFile("Resources/font.ttf"))
    {
        std::cout << "Font not found" << std::endl;
        return;
    }

    text_.setFont(font_);
    text_.setCharacterSize(24);
    text_.setFillColor(sf::Color::Green);
    text_.setPosition(15, 20);
}

Game::~Game()
{

}

bool Game::ok() const
{
    return window_.isOpen();
}

void Game::process()
{
    sf::Event event;
    while (window_.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::KeyPressed:
            switch(event.key.code)
            {
                case sf::Keyboard::Up:
                cout << "Up has been pressed" << endl;
                cout << "Now go you to the next scene" << endl;
                if (scene_ < 2)
                scene_++;
                menu_.MoveUp();
                break;

                case sf::Keyboard::Down:
                cout << "Down has been pressed" << endl;
                cout << "Now go you to the next scene" << endl;
                if (scene_ > 0)
                scene_--;
                menu_.MoveDown();
                break;

                case sf::Keyboard::Return:
					switch (menu_.GetPressedItem())
					{
						case 0:
						cout << "Play button has been pressed" << endl;		
						playingScene_ = 2;	
						cout << playingScene_ << endl;		
						break;

						case 1:
						cout << "Options button has been pressed" << endl;
						break;

						case 2:
						cout << "Exit button has been pressed" << endl;
						window_.close();
						break;
					}
					break;
			}
 
        
            break;

            
            case sf::Event::Closed:
            window_.close();
            break;            
        }




    }   
}

void Game::update()
{

}


void Game::draw()
{
    window_.clear();

    switch (scene_)
    {
        case 0:
            window_.clear(sf::Color::Black);
            break;
        case 1:
            window_.clear(sf::Color::Black);
            break;
        case 2:
        	window_.clear(sf::Color::Black);

    }

    ostringstream oss;
    oss << "scene: " << scene_ << endl;
    text_.setString(oss.str());
    window_.draw(text_);
    menu_.draw(window_);

    window_.display();
}

void Game::old()
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
						cout << "Play button has been pressed" << endl;
						menu.Play(window);
						break;

						case 1:
						cout << "Options button has been pressed" << endl;
						break;

						case 2:
						cout << "Exit button has been pressed" << endl;
						window.close();
						break;
					}
					break;
				}

				break;
				case sf::Event::Closed:
				window.close();
				break;
			}   
		}
		window.clear(sf::Color::White);

		menu.draw(window);

		window.display();
	}		
}
