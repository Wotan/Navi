#ifndef _PLUGINIMPL_H_
# define _PLUGINIMPL_H_

# include <dlfcn.h>

namespace navi {

class PluginImpl {
public:
  PluginImpl() {}

  bool open(std::string const& name)
  {
    _handle = dlopen(name.c_str(), RTLD_NOW | RTLD_GLOBAL);
    if (_handle)
      dlerror();
    return _handle ? true : false;
  }

  void* getSym(std::string const& name)
  {
    return dlsym(_handle, name.c_str());
  }

  char const* getError()
  {
    return dlerror();
  }

  bool close()
  {
    return (dlclose(_handle) == 0);
  }

private:
  void* _handle;
};

} // !navi

#endif /* !_PLUGINIMPL_H_ */
