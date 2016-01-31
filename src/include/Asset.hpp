#ifndef ASSET_HPP_
# define ASSET_HPP_

# include <SFML/Audio.hpp>
# include <SFML/Graphics.hpp>

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
    Asset() {}
    Asset(unsigned int x, unsigned int y) : _x(x), _y(y) {}
  public:
    unsigned int getWidth() const;
    unsigned int getHeigth() const;
  };

  class Sprite : public Asset
  {
  private:
    sf::Texture _texture;
    bool _bg;
  public:
    sf::Sprite _sprite;
    Sprite() {}
    Sprite(const std::string &, unsigned int, unsigned int, bool);
    Sprite(const wrap::Sprite &);
    wrap::Sprite &operator=(const wrap::Sprite &);
    void setPos(unsigned int, unsigned int);
  };

  class Text : public Asset
  {
  private:
    sf::Font _font;
  public:
    sf::Text _text;
    Text() {}
    Text(const std::string &, const std::string &, unsigned int, unsigned int, unsigned int);
    Text(const wrap::Text &);
    wrap::Text &operator=(const wrap::Text &);
    void setPos(unsigned int, unsigned int);
  };

  class Music
  {
  private:
    std::string _path;
  public:
    sf::Music _music;
    Music() {}
    Music(const wrap::Music &);
    Music(const std::string &, bool);
    wrap::Music &operator=(const wrap::Music &);
  };

  class Image
  {
  private:
    std::string _path;
  public:
    sf::Image _collision;
    Image() {}
    Image(const wrap::Image &);
    Image(const std::string &);
    wrap::Image &operator=(const wrap::Image &);
  };
}

#endif /* ASSET_HPP_ */
