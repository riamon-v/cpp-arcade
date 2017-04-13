//
// GLManager.cpp for GLManager in /home/riamon_v/rendu/CPP/cpp_arcade/src
// 
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
// 
// Started on  Tue Apr 11 14:32:41 2017 Riamon Vincent
// Last update Thu Apr 13 18:25:48 2017 Riamon Vincent
//

#include "GLManager.hpp"

GLManager::GLManager(std::string name) : _name(name), _dl_error(NULL)
{
  if (!(_handle = dlopen(_name.c_str(), RTLD_LAZY)))
    _dl_error = dlerror();
}

GLManager::~GLManager()
{
  if (_handle)
    dlclose(_handle);
}

void GLManager::Switch(std::string name)
{
  if (_handle)
    dlclose(_handle);
  if (!(_handle = dlopen(name.c_str(), RTLD_LAZY)))
    _dl_error = dlerror();
  _name = name;
}

std::string GLManager::getName() const
{
  return _name;
}

void *GLManager::getHandle() const
{
  return _handle;
}

char *GLManager::Error() const
{
  return _dl_error;
}

void GLManager::setError(char *err)
{
  _dl_error = err;
}
