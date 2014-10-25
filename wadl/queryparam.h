#ifndef QUERYPARAM_H
#define QUERYPARAM_H

#include <string>

namespace wadl {

    class QueryParam
    {
    public:
        QueryParam(const std::string& name, const std::string& type);

        std::string getName() const;
        std::string getType() const;

    private:
        std::string name;
        std::string type;
    };

}
#endif // QUERYPARAM_H
