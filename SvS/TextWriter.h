#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include "Board.h"

class TextWriter
{
public:
	TextWriter();
	~TextWriter(void);

	void draw();
	void initialize(Board *board);
	void setPosition(float x, float y);
	void setString(std::string text);

private:
	sf::Font mFont;
	sf::Text mText;
	Board* mBoard;
};

