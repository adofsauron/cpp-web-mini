#ifndef _LOGGER_H__
#define _LOGGER_H__

#include <log4cpp/Category.hh>


void InitLogInstance();

log4cpp::Category& LogInstance();


#endif // _LOGGER_H__