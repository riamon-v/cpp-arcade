//
// sfml.cpp for sfml in /home/riamon_v/rendu/CPP/cpp_arcade/src/src_liblapin/src
// 
// Made by Riamon Vincent
// Login   <riamon_v@epitech.net>
// 
// Started on  Mon Apr 10 21:02:03 2017 Riamon Vincent
// Last update Mon Apr 10 22:25:32 2017 Riamon Vincent
//

#include "Sfml.hpp"

Sfml::Sfml()
{
  std::cout << "Sfml" << std::endl;
}

Sfml::~Sfml()
{
}

int Sfml::configure(unsigned int width, unsigned int height)
{
  (void)width;
  (void)height;
  return (0);
}

void Sfml::display(void *data) const
{
  (void)data;
}

void Sfml::displayMenu(void *data) const
{
  (void)data;
}


Input Sfml::getInputs() const
{
}

void Sfml::kill()
{
}

IDisplay *cln::clone()
{
  return new Sfml;
}
