#ifndef HTTPMETHOD_H
#define HTTPMETHOD_H

#include <string>

namespace wadl {

    enum class HttpMethod {
        GET,
        HEAD,
        PUT,
        DELETE,
        POST,
        OPTIONS,
        TRACE,
        CONNECT
    };

    HttpMethod toHttpMethod(const std::string& name);
    std::string toString(HttpMethod method);

}
#endif // HTTPMETHOD_H
