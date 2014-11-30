#include "method.h"

namespace wadl {

    Method::Method(const std::string& id, HttpMethod httpMethod)
     :id(id), httpMethod(httpMethod){
    }

    HttpMethod Method::getHttpMethod() const {
        return httpMethod;
    }

    void Method::setHttpMethod(HttpMethod newHttpMethod){
        httpMethod = newHttpMethod;
    }
}
