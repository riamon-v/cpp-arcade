//
// Ghost.hpp for  in /Users/person-m/Epitech/TEK2/C++/cpp_arcade/include/
//
// Made by Melvin Personnier
// Login   <person_m@epitech.eu>
//
// Started on  Fri Apr 14 12:29:06 2017 Melvin Personnier
// Last update Sat Apr 15 16:36:30 2017 Melvin Personnier
//

#ifndef __GHOST_HPP__
# define __GHOST_HPP__

# include "ILogic.hpp"
# include "IDisplay.hpp"
# include "Protocol.hpp"

class Ghost
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
    arcade::WhereAmI *_whereAmI;
    Direction _dir;
    bool _eatable;
    Map *_map;
    bool _outOfBlock;

  public:
    Ghost(int x, int y, Map *map);
    Ghost(Ghost const &);
    virtual ~Ghost();
    Ghost& operator=(Ghost const &);

    Direction getDir() const;
    bool getOutOfBlock();
    void setDir(Direction _dir);
    void setOutOfBlock();
    arcade::WhereAmI *getWhereAmI() const;
    Map *getMap() const;
    bool goUp();
    bool goDown();
    bool goLeft();
    bool goRight();
    void goPlay();
    void chooseDir();
};

#endif /* !__GHOST_HPP__ */
