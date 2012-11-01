#ifndef _TYPELIST_H_
# define _TYPELIST_H_

namespace navi {

class NullType {};

template <typename H, typename T>
class TypeList {
  typedef H Head;
  typedef T Tail;
};

// Operations on typeList
namespace TL {

////// SIZE ///////

template<typename TL> struct Size;
template <> struct Size<NullType>
{
  enum { value = 0 };
};
template <typename T, typename U>
struct Size< TypeList<T, U> > {
  enum {
    value = Size<U>::value + 1
  };
};


/////// Get type At /////////
template<typename TL, unsigned int index> struct GetTypeAt;

template <unsigned int index> struct GetTypeAt<NullType, index>
{
  typedef NullType type;
};

template <typename T, typename U>
struct GetTypeAt< TypeList<T, U>, 0 >
{
  typedef T type;
};

template <typename T, typename U, unsigned int index>
struct GetTypeAt< TypeList<T, U>, index >
{
  typedef typename GetTypeAt<U, index - 1>::type type;
};

}

# define TYPELIST_1(T1) navi::TypeList<T1, navi::NullType>
# define TYPELIST_2(T1, T2) navi::TypeList<T1, TYPELIST_1(T2)>
# define TYPELIST_3(T1, T2, T3) navi::TypeList<T1, TYPELIST_2(T2, T3)>
# define TYPELIST_4(T1, T2, T3, T4) navi::TypeList<T1, TYPELIST_3(T2, T3, T4)>
# define TYPELIST_5(T1, T2, T3, T4, T5) navi::TypeList<T1, TYPELIST_4(T2, T3, T4, T5)>
# define TYPELIST_6(T1, T2, T3, T4, T5, T6) navi::TypeList<T1, TYPELIST_5(T2, T3, T4, T5, T6)>

} // !navi

#endif /* !_TYPELIST_H_ */
