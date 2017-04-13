//
// Snake.hpp for  in /Users/person-m/Epitech/TEK2/C++/cpp_arcade/include/
//
// Made by Melvin Personnier
// Login   <person_m@epitech.eu>
//
// Started on  Tue Apr 11 15:03:32 2017 Melvin Personnier
// Last update Wed Apr 12 20:47:34 2017 Melvin Personnier
//

#ifndef __SNAKE_HPP__
# define __SNAKE_HPP__

# include "Protocol.hpp"

class Snake
{
  public:
    enum Direction
    {
      UP = 2,
      DOWN = 3,
      LEFT = 4,
      RIGHT = 5,
    };
  private:
	   Map *_map;
     arcade::WhereAmI *_whereAmI;
     bool _gameOver;
     bool _powerUp;
     Direction _dir;

  public:
    Snake(int width, int height);
    Snake(Snake const &);
    virtual ~Snake();
    Snake& operator=(Snake const &);

    Map *getMap() const;
    arcade::WhereAmI *getWhereAmI() const;
    Direction getDir() const;
    void getWhereAmI(arcade::CommandType command, Snake *snake);
    void getMapToGetMap(arcade::CommandType command, Snake *snake);

    void setDir(Direction _dir);
    void goUp();
    void goDown();
    void goLeft();
    void goRight();
    void goPlay();
};

#endif /* !__SNAKE_HPP__ */
