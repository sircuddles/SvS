#include "TextWriter.h"


TextWriter::TextWriter() {}

TextWriter::~TextWriter(void) {}

void TextWriter::initialize(Board *board)
{
	mBoard = board;

	mFont.loadFromFile("assets/font.ttf");
	mText.setFont(mFont);

	mText.setPosition(0, 0);
	mText.setCharacterSize(30);
	mText.setColor(sf::Color::Black);
	mText.setString("");
}

void TextWriter::draw() {
	mBoard->getGameWindow()->draw(mText);
}

void TextWriter::setPosition(float x, float y) {
	mText.setPosition(x, y);
}

void TextWriter::setString(std::string text) {
	mText.setString(text);
}