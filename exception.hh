#ifndef _EXCEPTION_H_
# define _EXCEPTION_H_

# include <exception>
# include <stdexcept>
# include <cstdio>
# include <cstdarg>

namespace navi {

  class exception : public std::exception {
    static int const buffer_size = 512;
  public:
    exception(std::string const& str) : _str(str) {}
    exception(char const* str) : _str(str) {}
    exception(char const* str, ...) : _str() {
      va_list ap; char buffer[buffer_size];
      va_start(ap, str);
      vsnprintf(buffer, buffer_size, str, ap);
      va_end(ap);
      _str.append(buffer);
    }
    exception& operator=(exception const& o);
    virtual ~exception() throw() {}
    virtual const char* what() const throw() { return _str.c_str(); }
  private:
    std::string _str;
  };

# define DEFINE_EXCEPTION(NAME)					\
  class NAME : public navi::exception {				\
  public:							\
  NAME(std::string const& str) : navi::exception(str) {}	\
  }

}



#endif /* !_EXCEPTION_H_ */
