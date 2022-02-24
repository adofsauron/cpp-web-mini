
#include <log4cpp/Category.hh>
#include <log4cpp/Appender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Layout.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/NDC.hh>

#include "logger.h"

void InitLogInstance()
{
    log4cpp::OstreamAppender* osAppender = new log4cpp::OstreamAppender("osAppender", &std::cout);
        
    log4cpp::Category& root = log4cpp::Category::getRoot();
    log4cpp::Category& logInstance = root.getInstance("");
    logInstance.addAppender(osAppender);
    logInstance.setPriority(log4cpp::Priority::DEBUG);
}

log4cpp::Category& LogInstance()
{
    return log4cpp::Category::getRoot().getInstance("");
}
