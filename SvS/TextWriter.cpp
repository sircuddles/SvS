#include "TextWriter.h"


TextWriter::TextWriter(void) {
	mFont.loadFromFile("assets/font.ttf");
	mText.setFont(mFont);

	mText.setPosition(0, 0);
	mText.setCharacterSize(30);
	mText.setColor(sf::Color::Black);
	mText.setString("");
}
TextWriter::~TextWriter(void) {}

void TextWriter::draw(sf::RenderWindow& w) {
	w.draw(mText);
}

void TextWriter::setPosition(int x, int y) {
	mText.setPosition(x, y);
}

void TextWriter::setString(std::string text) {
	mText.setString(text);
}