//
// Errors.cpp for  in /Users/person-m/Epitech/TEK2/C++/cpp_arcade/src/src_pacman/src/
//
// Made by Melvin Personnier
// Login   <person_m@epitech.eu>
//
// Started on  Thu Apr 13 09:50:30 2017 Melvin Personnier
// Last update Thu Apr 13 09:50:56 2017 Melvin Personnier
//

#include "Errors.hpp"

const char *Errors::what() const throw()
{
  return _message.c_str();
}

Errors::Errors(std::string const &message)
    : _message(message) {}
Errors::~Errors() throw(){}


MapToSmall::MapToSmall(std::string const &message)
    : Errors(message) {}
MapToSmall::~MapToSmall() throw(){}
