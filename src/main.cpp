//
// main.cpp for main in /home/riamon_v/rendu/CPP/cpp_arcade/src
// 
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
// 
// Started on  Thu Apr  6 18:56:31 2017 Riamon Vincent
// Last update Fri Apr  7 14:25:27 2017 Riamon Vincent
//

#include <iostream>
#include <dlfcn.h>

typedef void	(*type)();

int		main(int argc, char **argv)
{
  void		*handle;
  type		zbeub;
  char		*dl_error;

  if (argc != 2)
    return (1);
  handle = dlopen(argv[1], RTLD_LAZY);
  zbeub = (type)dlsym(handle, "test");
  if ((dl_error = dlerror()))
    std::cerr << "Cannot load symbol 'test': " << dl_error << std::endl;
  else
    zbeub();
  dlclose(handle);
  return (0);
}
