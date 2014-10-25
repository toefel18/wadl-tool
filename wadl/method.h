#ifndef METHOD_H
#define METHOD_H

#include <vector>

#include "httpmethod.h"
#include "queryparam.h"

namespace wadl {

    class Method {
    public:

        typedef std::vector<QueryParam> QueryParams;
        Method();
        Method(HttpMethod httpMethod);

        const QueryParams& getQueryParams() const;
        QueryParams& getQueryParams();
        HttpMethod getHttpMethod() const;
        void setHttpMethod(HttpMethod httpMethod);

    private:
        QueryParams queryParams;
        HttpMethod httpMethod;
    };

}

#endif // METHOD_H
