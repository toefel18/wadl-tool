#ifndef RESOURCE_H
#define RESOURCE_H

#include<vector>
#include<string>

#include "method.h"

namespace wadl {

    class Resource
    {
    public:

        typedef std::vector<Method> Methods;

        /**
         * @brief methods container
         */

        Resource(const std::string& uri);

        const Methods& getMethods() const;
        Methods& getMethods();
        std::string getUri();

    private:
        Methods methods;
        std::string uri;
    };
}

#endif // RESOURCE_H
