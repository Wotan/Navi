#ifndef _SINGLETON_H_
# define _SINGLETON_H_

# include <cstdlib>
# include "CreationPolicies.hh"

namespace navi {

  template <class T>
  struct DestroyAtExit {
    typedef void (*DestroyFun)();
    static void ScheduleDestruction(DestroyFun fun) {
      atexit(fun);
    }
  };

  template <
    class T,
    template <class> class creationPolicy = CreateWithNew,
    template <class> class lifetimePolicy = DestroyAtExit
    >
  class SingletonHolder {
  public:
    static T& instance() {
      if (!_instance) {
	_instance = creationPolicy<T>::create();
	lifetimePolicy<T>::ScheduleDestruction(&destroy);
      }
      return *_instance;
    }

  private:
    static void destroy() {
      creationPolicy<T>::destroy(_instance);
    }

    SingletonHolder() {}
    ~SingletonHolder() {}

  private:
    static T* _instance;
  };

template <
  class T,
  template <class> class creationPolicy,
  template <class> class lifetimePolicy
  >
T* SingletonHolder<T, creationPolicy, lifetimePolicy>::_instance = 0;

} // !navi

#endif /* !_SINGLETON_H_ */
