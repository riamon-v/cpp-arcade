//
// Pacman.hpp for  in /Users/person-m/Epitech/TEK2/C++/cpp_arcade/include/
//
// Made by Melvin Personnier
// Login   <person_m@epitech.eu>
//
// Started on  Wed Apr 12 22:11:13 2017 Melvin Personnier
// Last update Thu Apr 13 13:31:19 2017 Melvin Personnier
//

#ifndef __PACMAN_HPP__
# define __PACMAN_HPP__

# include "Protocol.hpp"

class Pacman
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
    Direction _dir;

  public:
    Pacman(int width, int height);
    Pacman(Pacman const &);
    virtual ~Pacman();
    Pacman& operator=(Pacman const &);

    Map *getMap() const;
    arcade::WhereAmI *getWhereAmI() const;
    Direction getDir() const;
    void getWhereAmI(arcade::CommandType command, Pacman *snake);
    void getMapToGetMap(arcade::CommandType command, Pacman *snake);

    void setDir(Direction _dir);
    void goUp();
    void goDown();
    void goLeft();
    void goRight();
    void goPlay();
};

#endif /* !__PACMAN_HPP__ */
