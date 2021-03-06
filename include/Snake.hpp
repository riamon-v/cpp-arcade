//
// Snake.hpp for  in /Users/person-m/Epitech/TEK2/C++/cpp_arcade/include/
//
// Made by Melvin Personnier
// Login   <person_m@epitech.eu>
//
// Started on  Tue Apr 11 15:03:32 2017 Melvin Personnier
// Last update Sun Apr 16 19:13:00 2017 Melvin Personnier
//

#ifndef __SNAKE_HPP__
# define __SNAKE_HPP__

# include "ILogic.hpp"
# include "IDisplay.hpp"
# include "Protocol.hpp"

class Snake : public ILogic
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
  Snake(int width, int height);
  Snake(Snake const &);
  virtual ~Snake();
  Snake& operator=(Snake const &);

  Map *getMap() const;
  arcade::WhereAmI *getWhereAmI() const;
  Direction getDir() const;
  void getWhereAmI(arcade::CommandType command, Snake *snake);
  void getMapToGetMap(arcade::CommandType command, Snake *snake);
  void restartGame();

  void setDir(Direction _dir);
  void goUp();
  void goDown();
  void goLeft();
  void goRight();
  void goPlay();
  int is_in_list(int, int) const;
  struct_info runCommand(arcade::CommandType type);
  void updateTiles();
  std::vector<TileInfo> const  &getTiles() const;
  Screen const  &getScreen() const;
  int getSpeed() const;
  int getScore() const;
  bool _gameOver;

private:
  Map *_map;
  arcade::WhereAmI *_whereAmI;
  bool _powerUp;
  Direction _dir;
  std::vector<TileInfo> _tiles;
  Screen _screen;
  int _speed;
  int _speedInit;
  int _nbPowerUp;
  int _nbPowerUpMax;
};

namespace cln
{
  extern "C" ILogic *clone();
};

#endif /* !__SNAKE_HPP__ */
