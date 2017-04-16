//
// Pacman.hpp for  in /Users/person-m/Epitech/TEK2/C++/cpp_arcade/include/
//
// Made by Melvin Personnier
// Login   <person_m@epitech.eu>
//
// Started on  Wed Apr 12 22:11:13 2017 Melvin Personnier
// Last update Sun Apr 16 15:35:09 2017 Melvin Personnier
//

#ifndef __PACMAN_HPP__
# define __PACMAN_HPP__

# include "ILogic.hpp"
# include "IDisplay.hpp"
# include "Protocol.hpp"
# include "Ghost.hpp"

class Pacman : public ILogic
{
  public:
    enum Direction
    {
      UP = 2,
      DOWN = 3,
      LEFT = 4,
      RIGHT = 5,
    };

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
    void updateTiles();
    void isInBlock();
    bool isInList(int x, int y) const;
    void updateGhostEatable(int x, int y);
  struct_info runCommand(arcade::CommandType type);
  std::vector<TileInfo> const &getTiles() const;
  Screen const &getScreen() const;
  int const &getSpeed() const;

private:
  Map *_map;
  Ghost *_ghost1;
  Ghost *_ghost2;
  Ghost *_ghost3;
  Ghost *_ghost4;
  arcade::WhereAmI *_whereAmI;
  bool _gameOver;
  Direction _dir;
  Direction _lastDir;
  int _nbPlay;
  std::vector<TileInfo> _tiles;
  Screen _screen;
  int _speed;
};

namespace cln
{
  extern "C" ILogic *clone();
};

#endif /* !__PACMAN_HPP__ */
