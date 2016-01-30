#include "GameWindow.hpp"
#include "Constants.hpp"

#include <iostream>

GameWindow::GameWindow() :
  _window(new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), TITLE)),
  _width(WIDTH),
  _height(HEIGHT),
  _sprites(std::vector<wrap::Sprite *>()),
  _texts(std::vector<wrap::Text *>()),
  _musics(std::vector<wrap::Music *>())
{
}

GameWindow::~GameWindow()
{
  unsigned int ct = 0;

  delete this->_window;
  while (ct < this->_sprites.size())
    {
      delete this->_sprites[ct];
      ct++;
    }
  ct = 0;
  while (ct < this->_texts.size())
    {
      delete this->_texts[ct];
      ct++;
    }
  ct = 0;
  while (ct < this->_musics.size())
    {
      delete this->_musics[ct];
      ct++;
    }
}

void GameWindow::input()
{
  while (this->_window->pollEvent(this->_event))
    {
      if (this->_event.type == sf::Event::Closed)
	{
	  this->_window->close();
	  return ;
	}
      if (this->_event.type == sf::Event::Resized)
	{
	  this->_width = this->_event.size.width;
	  this->_height = this->_event.size.height;
	}
    }
}

void GameWindow::update()
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
      std::cout << "BITE\n";
    }
}

void GameWindow::draw()
{
  unsigned int ct = 0;

  this->_window->clear();
  while (ct < this->_sprites.size())
    {
      this->_window->draw(**this->_sprites[ct]);
      ct++;
    }
  ct = 0;
  while (ct < this->_texts.size())
    {
      this->_window->draw(**this->_texts[ct]);
      ct++;
    }
  this->_window->display();
}

void GameWindow::loop(unsigned int fps)
{
  (void)fps;
  if (this->_musics.size() > 0)
    (**this->_musics[0]).play();
  while (this->_window->isOpen())
    {
      this->input();
      this->update();
      this->draw();
    }
}

void GameWindow::add_sprite(const std::string &path, unsigned int x, unsigned int y, bool bg)
{
  this->_sprites.push_back(new wrap::Sprite(path, x, y, bg));
}

void GameWindow::add_text(const std::string &content, const std::string &path,
			  unsigned int size, unsigned int x, unsigned int y)
{
  this->_texts.push_back(new wrap::Text(content, path, size, x, y));
}

void GameWindow::add_music(const std::string &path, bool loop)
{
  this->_musics.push_back(new wrap::Music(path, loop));
}
