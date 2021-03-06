#ifndef _MUTEX_H_
#define _MUTEX_H_

# include "Navi.hh"

# if defined(NAVI_UNIX_PLATFORM) || defined(NAVI_MAC_PLATFORM)
#  include "unix/MutexImpl.hh"
# elif defined(NAVI_WIN_PLATFORM)
# include "win/MutexImpl.hh"
# else
#  error "Navi mutex: plateform not supported"
# endif

#endif /* !_MUTEX_H_ */
