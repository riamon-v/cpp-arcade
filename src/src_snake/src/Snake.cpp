//
// Snake.cpp for  in /Users/person-m/Epitech/TEK2/C++/cpp_arcade/src/src_snake/src/
//
// Made by Melvin Personnier
// Login   <person_m@epitech.eu>
//
// Started on  Mon Apr 10 23:07:42 2017 Melvin Personnier
// Last update Tue Apr 11 00:06:57 2017 Melvin Personnier
//

#include "Snake.hpp"

Snake::Snake(int width, int height)
{
	_map = new Map(width, height);
}

Snake::~Snake()
{
	delete _map;
}

Map *Snake::getMap() const
{
	return _map;
}
