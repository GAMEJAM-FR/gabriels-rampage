#include "Asset.hpp"

wrap::Sprite::Sprite(const std::string &path)
{
  this->_texture = new sf::Texture();
  this->_texture->loadFromFile(path);
  this->_sprite = new sf::Sprite(*this->_texture);
}

wrap::Sprite::~Sprite()
{
  delete this->_sprite;
  delete this->_texture;
}

sf::Sprite &wrap::Sprite::operator*()
{
  return (*this->_sprite);
}

wrap::Text::Text(const std::string &content, const std::string &path, unsigned int size)
{
  this->_font = new sf::Font();
  this->_font->loadFromFile(path);
  this->_text = new sf::Text(content, *this->_font, size);
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

wrap::Music::Music(const std::string &path)
{
  this->_music = new sf::Music();
  this->_music->openFromFile(path);
}

wrap::Music::~Music()
{
  delete this->_music;
}

sf::Music &wrap::Music::operator*()
{
  return (*this->_music);
}
