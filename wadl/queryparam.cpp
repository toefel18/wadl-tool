#include "queryparam.h"

namespace wadl {

    QueryParam::QueryParam(const std::string &name, const std::string &type)
        :name(name), type(type)
    {
    }

    std::string QueryParam::getName() const {
        return name;
    }

    std::string QueryParam::getType() const {
        return type;
    }
}
