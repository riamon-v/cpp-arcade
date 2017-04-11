//
// main.cpp for main in /home/riamon_v/rendu/CPP/cpp_arcade/src
//
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
//
// Started on  Thu Apr  6 18:56:31 2017 Riamon Vincent
// Last update Tue Apr 11 10:07:08 2017 Riamon Vincent
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
// <<<<<<< HEAD
  if (!handle)
    ret = 84;
  clone = (func)dlsym(handle, "clone");
// =======
//   zbeub = (type)dlsym(handle, "Play");
// >>>>>>> 9ccffa76495002d012b72d8054196d5355e6a29f
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
