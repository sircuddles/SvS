#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>

class TextWriter
{
public:
	TextWriter(void);
	~TextWriter(void);

	void draw(sf::RenderWindow& w);
	void setPosition(float x, float y);
	void setString(std::string text);

private:
	sf::Font mFont;
	sf::Text mText;
};

