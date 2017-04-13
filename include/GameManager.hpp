//
// GameManager.hpp for GameManager in /home/riamon_v/rendu/CPP/cpp_arcade/include
// 
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
// 
// Started on  Tue Apr 11 14:28:12 2017 Riamon Vincent
// Last update Tue Apr 11 16:49:37 2017 Riamon Vincent
//

#ifndef GAMEMANAGER_HPP_
# define GAMEMANAGER_HPP_

#include <iostream>
#include <dlfcn.h>

class GameManager
{
public:
  GameManager(std::string);
  ~GameManager();
  void Switch(std::string);
  std::string getGame() const;
  void *getHandle() const;
  char *Error() const;
  void setError(char *err);

private:
  std::string _game;
  void *_handle;
  char *_dl_error;
};

#endif //GAMEMANAGER_HPP_
