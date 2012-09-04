#ifndef _DICT_H_
# define _DICT_H_

# include <map>

# include <boost/any.hpp>
# include <boost/thread.hpp>

# include "Exception.hh"
# include "Thread.hh"

namespace navi {

class Dict : public navi::ObjectLevelLockable<Dict>
{
public:
  DEFINE_EXCEPTION(Error);
  typedef std::map<std::string const, boost::any> AnyMap;
  typedef AnyMap::iterator iterator;
  typedef AnyMap::const_iterator const_iterator;

public:
  Dict() {}
  virtual ~Dict() {}

  Dict operator=(Dict const& d)
  {
    return Dict(d);
  }
  Dict(Dict const& d)
  {
    _map = d._map;
  }

  template <typename T>
  void set(std::string const& key, T const& value) {
    Lock guard(this);
    _map[key] = value;
  }

  template <typename T>
  T const get(std::string const& key) const {
    try {
    return boost::any_cast<T>((*this)[key]);
    } catch (std::exception&) {
      throw Error("navi::Dict - key '%s': invalid cast", key.c_str());
    }
  }

  bool exist(std::string const& key) {
    Lock guard(this);
    return _map.find(key) != _map.end();
  }

  boost::any& operator[](std::string const& str)
  {
    Lock guard(this);
    return _map[str];
  }

  boost::any const& operator[](std::string const& str) const
  {
    try {
    Lock guard(this);
    return _map.at(str);
    } catch (std::exception&) {
      throw Error("navi::Dict - key \'%s\' not found", str.c_str());
    }
  }

  iterator begin()
  {
    Lock guard(this);
    return _map.begin();
  }

  iterator end()
  {
    Lock guard(this);
    return _map.end();
  }

  const_iterator begin() const
  {
    Lock guard(this);
    return _map.begin();
  }

  const_iterator end() const
  {
    Lock guard(this);
    return _map.begin();
  }

private:
  AnyMap _map;
};

}

#endif /* !_DICT_H_ */
