//
// ncurses.cpp for Ncurses in /home/riamon_v/rendu/CPP/cpp_arcade/src/src_liblapin/src
// 
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
// 
// Started on  Mon Apr 10 20:58:59 2017 Riamon Vincent
// Last update Mon Apr 10 22:24:02 2017 Riamon Vincent
//

#include "Ncurses.hpp"

Ncurses::Ncurses()
{
  std::cout << "Ncurses" << std::endl;
}

Ncurses::~Ncurses()
{
}

int Ncurses::configure(unsigned int width, unsigned int height)
{
  (void)width;
  (void)height;
  return (0);
}

void Ncurses::display(void *data) const
{
  (void)data;
}

void Ncurses::displayMenu(void *data) const
{
  (void)data;
}

Input Ncurses::getInputs() const
{
}

void Ncurses::kill()
{
}

IDisplay *cln::clone()
{
  return new Ncurses;
}
