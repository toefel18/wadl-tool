#ifndef HTTPMETHOD_H
#define HTTPMETHOD_H

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

}
#endif // HTTPMETHOD_H
