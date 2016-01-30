#include "GameWindow.hpp"
#include "Constants.hpp"

GameWindow::GameWindow() :
  _window(new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), TITLE)),
  _sprites(std::vector<sf::Sprite *>()),
  _musics(std::vector<sf::Music *>()),
  _texts(std::vector<sf::Text *>()),
  _event(sf::Event())
{
}

GameWindow::~GameWindow()
{
  delete this->_window;
}

void GameWindow::init(std::vector<sf::Sprite *> &sprites,
		     std::vector<sf::Text *> &texts,
		     std::vector<sf::Music *> &musics)
{
  this->_sprites = sprites;
  this->_texts = texts;
  this->_musics = musics;
}

void GameWindow::input()
{
  this->_event_tab.clear();
  while (this->_window->pollEvent(this->_event))
    this->_event_tab.push_back(this->_event.type);
}

void GameWindow::update()
{
  if (this->_event_tab << sf::Event::Closed)
    this->_window->close();
}

void GameWindow::draw()
{
  unsigned int ct = 0;

  this->_window->clear();
  while (ct < this->_sprites.size() || (ct = 0))
    {
      this->_window->draw(*this->_sprites[ct]);
      ct++;
    }
  while (ct < this->_musics.size() || (ct = 0))
    {
      this->_musics[ct]->play();
      ct++;
    }
  while (ct < this->_texts.size())
    {
      this->_window->draw(*this->_texts[ct]);
      ct++;
    }
  this->_window->display();
}

void GameWindow::loop(unsigned int fps)
{
  (void)fps;
  while (this->_window->isOpen())
    {
      this->input();
      this->update();
      this->draw();
    }
}

bool operator<<(std::vector<int> tab, int elem)
{
  unsigned int ct = 0;

  while (ct < tab.size())
    {
      if (tab[ct] == elem)
	return (true);
      ct++;
    }
  return (false);
}
