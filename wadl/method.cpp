#include "method.h"


namespace wadl {
    Method::Method()
    {
    }

    Method::Method(HttpMethod httpMethod)
     :httpMethod(httpMethod){
    }

    Method::QueryParams& Method::getQueryParams() {
        return queryParams;
    }

    const Method::QueryParams& Method::getQueryParams() const{
        return queryParams;
    }


    HttpMethod Method::getHttpMethod() const {
        return httpMethod;
    }

    void Method::setHttpMethod(HttpMethod newHttpMethod){
        httpMethod = newHttpMethod;
    }
}
