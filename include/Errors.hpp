//
// Errors.hpp for  in /Users/person-m/Epitech/TEK2/C++/cpp_arcade/include/
//
// Made by Melvin Personnier
// Login   <person_m@epitech.eu>
//
// Started on  Tue Apr 11 21:12:52 2017 Melvin Personnier
// Last update Tue Apr 11 21:30:07 2017 Melvin Personnier
//

#ifndef __ERROR_HPP__
# define __ERROR_HPP__

# include "Protocol.hpp"

class Errors : public std::exception
{
  public:
    Errors(std::string const &message);
    virtual ~Errors() throw();

    const char *what() const throw();

  private:
    std::string _message;
 };

class MapToSmall : public Errors
{
  public:
    MapToSmall(std::string const &message);
    virtual ~MapToSmall() throw();
 };

#endif /* !__ERROR_HPP__ */
