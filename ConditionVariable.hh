#ifndef _CONDITIONVARIABLE_H_
#define _CONDITIONVARIABLE_H_

# if defined(NAVI_UNIX_PLATFORM) || defined(NAVI_MAC_PLATFORM)
#  include "unix/ConditionVariableImpl.hh"
# elif defined(NAVI_WIN_PLATFORM)
# include "win/ConditionVariableImpl.hh"
# else
#  error "Navi mutex: plateform not supported"
# endif

#endif /* !_CONDITIONVARIABLE_H_ */
