#ifndef _DICT_H_
# define _DICT_H_

# include <map>

# include <boost/any.hpp>

namespace navi {

class Dict
{
public:
  Dict() {}
  virtual ~Dict() {}

  template <typename T>
  void set(std::string const& key, T const& value) {
    _map[key] = value;
  }

  template <typename T>
  T const get(std::string const& key) const {
    return boost::any_cast<T>(_map.at(key));
  }

  bool exist(std::string const& key) {
    return _map.find(key) != _map.end();
  }

private:
  std::map<std::string const, boost::any> _map;
};

}

#endif /* !_DICT_H_ */
