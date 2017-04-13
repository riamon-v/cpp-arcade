//
// GLManager.hpp for GLManager in /home/riamon_v/rendu/CPP/cpp_arcade/include
// 
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
// 
// Started on  Thu Apr 13 18:05:29 2017 Riamon Vincent
// Last update Thu Apr 13 18:26:58 2017 Riamon Vincent
//

#ifndef GLMANAGER_HPP_
# define GLMANAGER_HPP_

#include <iostream>
#include <dlfcn.h>

class GLManager
{
public:
  GLManager(std::string name);
  ~GLManager();
  void Switch(std::string);
  std::string getName() const;
  void *getHandle() const;
  char *Error() const;
  void setError(char *err);

private:
  std::string _name;
  void *_handle;
  char *_dl_error;
};

#endif //GLMANAGER_HPP_
