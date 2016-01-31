#include <SFML/Graphics.hpp>
#include "Asset.hpp"

wrap::Sprite::Sprite(const std::string &path, unsigned int x, unsigned int y, bool bg)
  : wrap::Asset(x, y), _bg(bg)
{
  this->_texture.loadFromFile(path);
  this->_sprite.setTexture(this->_texture);
  this->_width = this->_sprite.getLocalBounds().width;
  this->_height = this->_sprite.getLocalBounds().height;
  this->_xOffset = this->_bg ? 0 : this->_width / 2;
  this->_yOffset = this->_bg ? 0 : this->_height / 2;
  this->_sprite.setPosition(sf::Vector2f(this->_x - this->_xOffset, this->_y - this->_yOffset));
}

wrap::Sprite::Sprite(const wrap::Sprite &obj)
  : wrap::Asset(obj._x, obj._y), _texture(obj._texture), _bg(obj._bg)
{
  this->_sprite.setTexture(this->_texture);
  this->_width = this->_sprite.getLocalBounds().width;
  this->_height = this->_sprite.getLocalBounds().height;
  this->_xOffset = this->_bg ? 0 : this->_width / 2;
  this->_yOffset = this->_bg ? 0 : this->_height / 2;
  this->_sprite.setPosition(sf::Vector2f(this->_x - this->_xOffset, this->_y - this->_yOffset));
}

wrap::Sprite &wrap::Sprite::operator=(const wrap::Sprite &obj)
{
  this->_x = obj._x;
  this->_y = obj._y;
  this->_texture = obj._texture;
  this->_bg = obj._bg;
  this->_sprite.setTexture(this->_texture);
  this->_width = this->_sprite.getLocalBounds().width;
  this->_height = this->_sprite.getLocalBounds().height;
  this->_xOffset = this->_bg ? 0 : this->_width / 2;
  this->_yOffset = this->_bg ? 0 : this->_height / 2;
  this->_sprite.setPosition(sf::Vector2f(this->_x - this->_xOffset, this->_y - this->_yOffset));
  return (*this);
}

void wrap::Sprite::setPos(unsigned int x, unsigned int y)
{
  this->_x = x;
  this->_y = y;
  this->_sprite.setPosition(sf::Vector2f(this->_x - this->_xOffset, this->_y - this->_yOffset));
}

wrap::Text::Text(const std::string &content, const std::string &path,
		 unsigned int size, unsigned int x, unsigned int y)
  : wrap::Asset(x, y)
{
  this->_font.loadFromFile(path);
  this->_text.setString(content);
  this->_text.setFont(this->_font);
  this->_text.setCharacterSize(size);
  this->_width = this->_text.getLocalBounds().width;
  this->_height = this->_text.getLocalBounds().height;
  this->_xOffset = this->_width / 2;
  this->_yOffset = this->_height / 2;
  this->_text.setPosition(sf::Vector2f(this->_x - this->_xOffset, this->_y - this->_yOffset));
}

wrap::Text::Text(const Text &obj)
  : wrap::Asset(obj._x, obj._y), _font(obj._font)
{
  this->_text.setString(obj._text.getString());
  this->_text.setFont(this->_font);
  this->_text.setCharacterSize(obj._text.getCharacterSize());
  this->_width = this->_text.getLocalBounds().width;
  this->_height = this->_text.getLocalBounds().height;
  this->_xOffset = this->_width / 2;
  this->_yOffset = this->_height / 2;
  this->_text.setPosition(sf::Vector2f(this->_x - this->_xOffset, this->_y - this->_yOffset));
}

wrap::Text &wrap::Text::operator=(const wrap::Text &obj)
{
  this->_x = obj._x;
  this->_y = obj._y;
  this->_font = obj._font;
  this->_text.setString(obj._text.getString());
  this->_text.setFont(this->_font);
  this->_text.setCharacterSize(obj._text.getCharacterSize());
  this->_width = this->_text.getLocalBounds().width;
  this->_height = this->_text.getLocalBounds().height;
  this->_xOffset = this->_width / 2;
  this->_yOffset = this->_height / 2;
  this->_text.setPosition(sf::Vector2f(this->_x - this->_xOffset, this->_y - this->_yOffset));
  return (*this);
}

void wrap::Text::setPos(unsigned int x, unsigned int y)
{
  this->_x = x;
  this->_y = y;
  this->_text.setPosition(sf::Vector2f(this->_x - this->_xOffset, this->_y - this->_yOffset));
}

wrap::Music::Music(const std::string &path, bool loop)
  : _path(path)
{
  this->_music.openFromFile(this->_path);
  if (loop)
    this->_music.setLoop(true);
}

wrap::Music::Music(const wrap::Music &obj)
  : _path(obj._path)
{
  this->_music.openFromFile(obj._path);
  if (obj._music.getLoop())
    this->_music.setLoop(true);
}

wrap::Music &wrap::Music::operator=(const wrap::Music &obj)
{
  this->_path = obj._path;
  this->_music.openFromFile(this->_path);
  if (obj._music.getLoop())
    this->_music.setLoop(true);
  return (*this);
}

unsigned int wrap::Asset::getWidth() const
{
  return (this->_width);
}

unsigned int wrap::Asset::getHeight() const
{
  return (this->_height);
}

unsigned int wrap::Asset::getX() const
{
  return (this->_x);
}

unsigned int wrap::Asset::getY() const
{
  return (this->_y);
}

wrap::Image::Image(const std::string &path)
  : _path(path)
{
  this->_collision.loadFromFile(this->_path);
}

wrap::Image::Image(const Image &obj)
  : _path(obj._path)
{
  this->_collision.loadFromFile(this->_path);
}

wrap::Image &wrap::Image::operator=(const wrap::Image &obj)
{
  this->_path = obj._path;
  this->_collision.loadFromFile(this->_path);
  return (*this);
}
