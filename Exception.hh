#ifndef _EXCEPTION_H_
# define _EXCEPTION_H_

# include <exception>
# include <stdexcept>
# include <cstdio>
# include <cstdarg>

namespace navi {

  class Exception : public std::exception {
    static int const buffer_size = 512;
  public:
    Exception(std::string const& str) : _str(str) {}
    Exception(char const* str) : _str(str) {}
    Exception(char const* str, ...) : _str() {
      va_list ap; char buffer[buffer_size];
      va_start(ap, str);
      vsnprintf(buffer, buffer_size, str, ap);
      va_end(ap);
      _str.append(buffer);
    }
    Exception& operator=(exception const& o);
    virtual ~Exception() throw() {}
    virtual const char* what() const throw() { return _str.c_str(); }
  private:
    std::string _str;
  };

# define DEFINE_EXCEPTION(NAME)					\
  class NAME : public navi::Exception {				\
  public:							\
  NAME(std::string const& str) : navi::Exception(str) {}	\
  }

} // !navi



#endif /* !_EXCEPTION_H_ */
