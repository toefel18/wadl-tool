#include "param.h"

namespace wadl {

    Param::Param(const std::string &name, const std::string &style, const std::string &type)
        :name(name), style(style), type(type)
    {
    }

    std::string Param::getName() const {
        return name;
    }

    std::string Param::getStyle() const {
        return style;
    }

    std::string Param::getType() const {
        return type;
    }
}
