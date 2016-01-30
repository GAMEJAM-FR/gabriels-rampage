#include "GameWindow.hpp"
#include "Constants.hpp"

GameWindow::GameWindow() :
  _window(new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), TITLE))
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
}

void GameWindow::update()
{
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

void GameWindow::add_sprite(const std::string &path)
{
  this->_sprites.push_back(new wrap::Sprite(path));
}

void GameWindow::add_text(const std::string &content, const std::string &path, unsigned int size)
{
  this->_texts.push_back(new wrap::Text(content, path, size));
}

void GameWindow::add_music(const std::string &path)
{
  this->_musics.push_back(new wrap::Music(path));
}
