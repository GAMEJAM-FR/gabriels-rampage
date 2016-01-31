#ifndef ASSET_HPP_
# define ASSET_HPP_

# include <SFML/Audio.hpp>
# include <SFML/Graphics.hpp>

namespace wrap
{
  class Asset
  {
  protected:
    int _x;
    int _y;
    int _width;
    int _height;
  public:
    int _xOffset;
    int _yOffset;
  protected:
    Asset() {}
    Asset(int x, int y) : _x(x), _y(y) {}
  public:
    int getWidth() const;
    int getHeight() const;
    int getX() const;
    int getY() const;
  };

  class Sprite : public Asset
  {
  private:
    sf::Texture _texture;
  public:
    sf::Sprite _sprite;
    Sprite() {}
    Sprite(const std::string &, int, int, bool);
    Sprite(const wrap::Sprite &);
    wrap::Sprite &operator=(const wrap::Sprite &);
    void setPos(int, int);
  };

  class Text : public Asset
  {
  private:
    sf::Font _font;
  public:
    sf::Text _text;
    Text() {}
    Text(const std::string &, const std::string &, int, int, int);
    Text(const wrap::Text &);
    wrap::Text &operator=(const wrap::Text &);
    void setPos(int, int);
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
