#ifndef ASSET_HPP_
# define ASSET_HPP_

# include <SFML/Audio.hpp>
# include <SFML/Graphics.hpp>
# include <string>

namespace wrap
{
  class Sprite
  {
  private:
    sf::Texture *_texture;
    sf::Sprite *_sprite;
  public:
    Sprite(const std::string &);
    ~Sprite();
    sf::Sprite &operator*();
  };

  class Text
  {
  private:
    sf::Font *_font;
    sf::Text *_text;
  public:
    Text(const std::string &, const std::string &, unsigned int);
    ~Text();
    sf::Text &operator*();
  };

  class Music
  {
  private:
    sf::Music *_music;
  public:
    Music(const std::string &);
    ~Music();
    sf::Music &operator*();
  };
}

#endif /* ASSET_HPP_ */
