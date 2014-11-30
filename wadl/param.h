#ifndef QUERYPARAM_H
#define QUERYPARAM_H

#include <string>

namespace wadl {

    class Param
    {
    public:
        Param(const std::string& name, const std::string& style, const std::string& type);

        std::string getName() const;
        std::string getStyle() const;
        std::string getType() const;

    private:
        std::string name;
        std::string style;
        std::string type;
    };

}
#endif // QUERYPARAM_H
