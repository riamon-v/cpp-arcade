//
// Map.hpp for  in /Users/person-m/Epitech/TEK2/C++/cpp_arcade/include/
//
// Made by Melvin Personnier
// Login   <person_m@epitech.eu>
//
// Started on  Sun Apr  9 20:32:50 2017 Melvin Personnier
// Last update Mon Apr 10 22:05:20 2017 Melvin Personnier
//

#ifndef __MAP_HPP__
# define __MAP_HPP__

# include "Protocol.hpp"

class Map
{
  public:
    enum Info
    {
      EMPTY = 0,
      BLOCK = 1,
      PLAYER = 2,
      POWERUP = 6,
      ERROR = 7
    };

  private:
	  int _width;
	  int _height;
	  Info **_map;

  public:
    Map(int width, int height);
    Map(Map const &);
    virtual ~Map();
    Map& operator=(Map const &);

    int getHeight() const;
    int getWidth() const;
    Info getCaseInfo(int width, int height);
    void setCaseInfo(int width, int height, Info info);
    void setPowerUp();
    void init();
};

#endif /* !__MAP_HPP__ */
