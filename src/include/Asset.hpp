#ifndef ASSET_HPP_
# define ASSET_HPP_

# include <SFML/Audio.hpp>
# include <SFML/Graphics.hpp>
# include <string>

namespace wrap
{
  class Asset
  {
  protected:
    unsigned int _x;
    unsigned int _y;
    unsigned int _width;
    unsigned int _height;
    unsigned int _xOffset;
    unsigned int _yOffset;
    Asset(unsigned int x, unsigned int y) : _x(x), _y(y) {}
    virtual ~Asset() {}
  public:
    unsigned int getWidth() const;
    unsigned int getHeigth() const;
  };

  class Sprite : public Asset
  {
  private:
    sf::Texture *_texture;
    sf::Sprite *_sprite;
    bool _bg;
  public:
    Sprite(const std::string &, unsigned int, unsigned int, bool);
    ~Sprite();
    sf::Sprite &operator*();
    void setPos(unsigned int, unsigned int);
  };

  class Text : public Asset
  {
  private:
    sf::Font *_font;
    sf::Text *_text;
  public:
    Text(const std::string &, const std::string &, unsigned int, unsigned int, unsigned int);
    ~Text();
    sf::Text &operator*();
    void setPos(unsigned int, unsigned int);
  };

  class Music
  {
  private:
    sf::Music *_music;
  public:
    Music(const std::string &, bool);
    ~Music();
    sf::Music &operator*();
  };
}

#endif /* ASSET_HPP_ */
