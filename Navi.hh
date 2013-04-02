#ifndef _NAVI_H_
# define _NAVI_H_

# if defined(unix) || defined(__unix__) || defined(__unix)
#  define NAVI_UNIX_PLATFORM
#  define UNIX_PLATFORM
# elif defined(_WINDOWS) || defined(__WIN32) || defined(WIN32) || defined(__WIN32__)
#  define NAVI_WIN_PLATFORM
#  define WIN_PLATFORM
# elif defined(__APPLE__)
#  define NAVI_MAC_PLATFORM
#  define MAC_PLATFORM
# else
#  error "Unknown plateform"
# endif

#endif /* !_NAVI_H_ */
