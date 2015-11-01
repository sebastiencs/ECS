#pragma once

#include <exception>
#include <sstream>
#include <string>

#define __throw(except, err) throw except(err, __FILE__, __PRETTY_FUNCTION__, __LINE__)

namespace Ecs {
  namespace Exception {
    class Base : public std::exception {
    protected:
      std::string const _str;
      std::string const _type;
      std::string const _file;
      std::string const _function;
      int const _line;

    public:
      Base(std::string const& str, std::string const& type = "", std::string const& file = __FILE__, std::string const& function = __PRETTY_FUNCTION__, int line = __LINE__);
      ~Base() throw();
      const char *what() const throw();
    };

    class Component : public Ecs::Exception::Base {
    public:
      Component(std::string const &str, std::string const& file, std::string const& function, int line);
    };
  }
}
