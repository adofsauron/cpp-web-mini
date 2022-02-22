#include <string>
#include <vector>
#include <boost/regex.hpp>

#include "tools.h"


std::vector<std::string> splitString(std::string str, std::string s)
{
    boost::regex reg(s.c_str());
    std::vector<std::string> vec;
    boost::sregex_token_iterator it(str.begin(),str.end(),reg,-1);
    boost::sregex_token_iterator end;
    while(it != end) {
        vec.push_back(*it++);
    }

    return vec;
}
