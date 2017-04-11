//
// LibManager.cpp for LibManager in /home/riamon_v/rendu/CPP/cpp_arcade/src
// 
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
// 
// Started on  Tue Apr 11 14:32:41 2017 Riamon Vincent
// Last update Tue Apr 11 16:48:38 2017 Riamon Vincent
//

#include "LibManager.hpp"

LibManager::LibManager(std::string lib) : _lib(lib), _dl_error(NULL)
{
  if (!(_handle = dlopen(_lib.c_str(), RTLD_LAZY)))
    _dl_error = dlerror();
}

LibManager::~LibManager()
{
  if (_handle)
    dlclose(_handle);
}

std::string LibManager::getLib() const
{
  return _lib;
}

void *LibManager::getHandle() const
{
  return _handle;
}

char *LibManager::Error() const
{
  return _dl_error;
}

void LibManager::setError(char *err)
{
  _dl_error = err;
}
