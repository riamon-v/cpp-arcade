//
// Errors.cpp for  in /Users/person-m/Epitech/TEK2/C++/cpp_arcade/src/src_snake/src/
//
// Made by Melvin Personnier
// Login   <person_m@epitech.eu>
//
// Started on  Tue Apr 11 21:19:18 2017 Melvin Personnier
// Last update Fri Apr 14 00:46:04 2017 Riamon Vincent
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


FailOpen::FailOpen(std::string const &message)
    : Errors(message) {}
FailOpen::~FailOpen() throw(){}
