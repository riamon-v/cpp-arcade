//
// Snake.hpp for  in /Users/person-m/Epitech/TEK2/C++/cpp_arcade/include/
//
// Made by Melvin Personnier
// Login   <person_m@epitech.eu>
//
// Started on  Mon Apr 10 22:28:27 2017 Melvin Personnier
// Last update Mon Apr 10 23:09:04 2017 Melvin Personnier
//

#ifndef __SNAKE_HPP__
# define __SNAKE_HPP__

# include "Map.hpp"
# include "Protocol.hpp"

class Snake
{
  private:
	   Map *_map;

  public:
    Snake(int width, int height);
    Snake(Map const &);
    virtual ~Snake();
    Snake& operator=(Snake const &);

    Map *getMap() const;
};

#endif /* !__SNAKE_HPP__ */
