#include "Asset.hpp"

wrap::Sprite::Sprite(const std::string &path, unsigned int x, unsigned int y, bool bg)
  : wrap::Asset(x, y), _texture(new sf::Texture()), _bg(bg)
{
  this->_texture->loadFromFile(path);
  this->_sprite = new sf::Sprite(*this->_texture);
  this->_width = this->_sprite->getLocalBounds().width;
  this->_height = this->_sprite->getLocalBounds().height;
  this->_xOffset = this->_bg ? 0 : this->_width / 2;
  this->_yOffset = this->_bg ? 0 : this->_height / 2;
  this->_sprite->setPosition(sf::Vector2f(this->_x - this->_xOffset, this->_y - this->_yOffset));
}

wrap::Sprite::~Sprite()
{
}

sf::Sprite &wrap::Sprite::operator*()
{
  return (*this->_sprite);
}

void wrap::Sprite::setPos(unsigned int x, unsigned int y)
{
  this->_x = x;
  this->_y = y;
  this->_sprite->setPosition(sf::Vector2f(this->_x - this->_xOffset, this->_y - this->_yOffset));
}

wrap::Text::Text(const std::string &content, const std::string &path,
		 unsigned int size, unsigned int x, unsigned int y)
  : wrap::Asset(x, y)
{
  this->_font = new sf::Font();
  this->_font->loadFromFile(path);
  this->_text = new sf::Text(content, *this->_font, size);
  this->_width = this->_text->getLocalBounds().width;
  this->_height = this->_text->getLocalBounds().height;
  this->_xOffset = this->_width / 2;
  this->_yOffset = this->_height / 2;
  this->_text->setPosition(sf::Vector2f(this->_x - this->_xOffset, this->_y - this->_yOffset));
}

wrap::Text::~Text()
{
  delete this->_text;
  delete this->_font;
}

sf::Text &wrap::Text::operator*()
{
  return (*this->_text);
}

void wrap::Text::setPos(unsigned int x, unsigned int y)
{
  this->_x = x;
  this->_y = y;
  this->_text->setPosition(sf::Vector2f(this->_x - this->_xOffset, this->_y - this->_yOffset));
}

wrap::Music::Music(const std::string &path, bool loop)
{
  this->_music = new sf::Music();
  this->_music->openFromFile(path);
  if (loop)
    this->_music->setLoop(true);
}

wrap::Music::~Music()
{
  delete this->_music;
}

sf::Music &wrap::Music::operator*()
{
  return (*this->_music);
}

unsigned int wrap::Asset::getWidth() const
{
  return (this->_width);
}

unsigned int wrap::Asset::getHeigth() const
{
  return (this->_height);
}
