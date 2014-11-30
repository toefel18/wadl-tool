#include "pathhelper.h"

#include <string>
#include <boost/algorithm/string/predicate.hpp>

using boost::algorithm::ends_with;
using boost::algorithm::starts_with;

std::string PathHelper::concat(const std::string &left, const std::string &right) {
    std::string result = left;
    while (ends_with(result, "/")) {
        result.pop_back();
    }
    if (starts_with(right, "/")) {
        result += right;
    } else {
        result += "/" + right;
    }
    return result;
}
