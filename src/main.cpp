//
// main.cpp for main in /home/riamon_v/rendu/CPP/cpp_arcade/src
// 
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
// 
// Started on  Thu Apr  6 18:56:31 2017 Riamon Vincent
// Last update Mon Apr 10 23:56:39 2017 Riamon Vincent
//

#include <dlfcn.h>
#include "IDisplay.hpp"

void		loop_main()
{
  
}

int		main(int argc, char **argv)
{
  IDisplay	*lib;
  int		ret;
  void		*handle;
  func		clone;
  char		*dl_error;

  ret = 0;
  if (argc != 2)
    {
      std::cerr << argv[0] << " [LIBRARY NAME]" << std::endl;
      return (84);
    }
  handle = dlopen(argv[1], RTLD_LAZY);
  if (!handle)
    ret = 84;
  clone = (func)dlsym(handle, "clone");
  if ((dl_error = dlerror()))
    {
      std::cerr << "Cannot load symbol 'clone': " << dl_error << std::endl;
      ret = 84;
    }
  else
    lib = clone();
  if (handle)
    dlclose(handle);
  return (ret);
}
