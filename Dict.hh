#ifndef _DICT_H_
# define _DICT_H_

# include <map>

# include <boost/any.hpp>
# include <boost/thread.hpp>

# include "Exception.hh"
# include "Thread.hh"

namespace navi {

class Dict
{
public:
  DEFINE_EXCEPTION(Error);
  typedef std::map<std::string const, boost::any> AnyMap;
  typedef AnyMap::iterator iterator;
  typedef AnyMap::const_iterator const_iterator;

public:
  Dict() {}
  virtual ~Dict() {}

  Dict(Dict const& d) {
    *this = d;
  }

  Dict& operator=(Dict const& d)
  {
    _map = d._map;
    return *this;
  }

  template <typename T>
  void set(std::string const& key, T const& value) {
    AnyMap::iterator it = _map.lower_bound(key);
    if (it != _map.end() && !(_map.key_comp()(key, it->first))) {
      it->second = value;
    } else {
      _map.insert(it, AnyMap::value_type(key, boost::any(value)));
    }
  }

  template <typename T>
  T const& get(std::string const& key) const {
    try {
      return *boost::any_cast<T>(&(*this)[key]);
    } catch (boost::bad_any_cast const&) {
      throw Error("navi::Dict: key '%s': invalid cast", key.c_str());
    }
  }

  bool exist(std::string const& key) const
  {
    return _map.find(key) != _map.end();
  }

  std::size_t size() const
  {
    return _map.size();
  }

  boost::any const& operator[](std::string const& str) const
  {
    try {
      return _map.at(str);
    } catch (std::exception&) {
      throw Error("navi::Dict - key \'%s\' not found", str.c_str());
    }
  }

  iterator begin()
  {
    return _map.begin();
  }

  iterator end()
  {
    return _map.end();
  }

  const_iterator begin() const
  {
    return _map.begin();
  }

  const_iterator end() const
  {
    return _map.end();
  }

private:
  AnyMap _map;
};

}

#endif /* !_DICT_H_ */
