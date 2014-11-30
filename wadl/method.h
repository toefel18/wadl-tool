#ifndef METHOD_H
#define METHOD_H

#include "httpmethod.h"
#include "param.h"

#include <string>

namespace wadl {

    class Method {
    public:
        Method(const std::string& id, HttpMethod httpMethod);

        HttpMethod getHttpMethod() const;
        void setHttpMethod(HttpMethod httpMethod);

    private:
        std::string id;
        HttpMethod httpMethod;
    };

}

#endif // METHOD_H
