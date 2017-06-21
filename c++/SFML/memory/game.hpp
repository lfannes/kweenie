#pragma once

#include "menu.hpp"
#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	~Game();

	bool ok() const;

	void process();
	void update();
	void draw();

	void old();

private:		
	int scene_ = 1;
	int playingScene_ = 0;
 	sf::RenderWindow window_;
 	sf::Text text_;
 	sf::Font font_;
 	Menu menu_;
};
