//
// LibManager.hpp for LibManager in /home/riamon_v/rendu/CPP/cpp_arcade/include
// 
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
// 
// Started on  Tue Apr 11 14:28:12 2017 Riamon Vincent
// Last update Tue Apr 11 16:49:37 2017 Riamon Vincent
//

#ifndef LIBMANAGER_HPP_
# define LIBMANAGER_HPP_

#include <iostream>
#include <dlfcn.h>

class LibManager
{
public:
  LibManager(std::string);
  ~LibManager();
  void Switch(std::string);
  std::string getLib() const;
  void *getHandle() const;
  char *Error() const;
  void setError(char *err);

private:
  std::string _lib;
  void *_handle;
  char *_dl_error;
};

#endif //LIBMANAGER_HPP_
