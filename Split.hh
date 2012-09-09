#ifndef _SPLIT_H_
# define _SPLIT_H_

# include <vector>

# include "boost/lexical_cast.hpp"

namespace navi {

template <typename T>
void split(std::string const& str, std::vector<T>& vect, char sep = ' ')
{
  for (std::size_t i = 0; str[i]; ++i) {
    for (;str[i] == sep; ++i);
    if (str[i]) {
      std::string pending;
      for (;str[i] != sep && str[i]; ++i)
	pending.push_back(str[i]);
      vect.push_back(boost::lexical_cast<T, std::string>(pending));
    }
  }
}

} // !navi

#endif /* !_SPLIT_H_ */
