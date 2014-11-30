#include "httpmethod.h"

namespace wadl {

    HttpMethod toHttpMethod(const std::string& name) {
        if (name == "GET") {
            return HttpMethod::GET;
        } else if (name == "HEAD") {
            return HttpMethod::HEAD;
        } else if (name == "PUT") {
            return HttpMethod::PUT;
        } else if (name == "DELETE") {
            return HttpMethod::DELETE;
        } else if (name == "POST") {
            return HttpMethod::POST;
        } else if (name == "OPTIONS") {
            return HttpMethod::OPTIONS;
        } else if (name == "TRACE") {
            return HttpMethod::TRACE;
        } else if (name == "CONNECT") {
            return HttpMethod::CONNECT;
        } else {
            throw name + " is not a valid HttpMethod";
        }
    }

    std::string toString(HttpMethod method) {
        if (method == HttpMethod::GET) {
            return "GET";
        } else if (method == HttpMethod::HEAD) {
            return "HEAD";
        } else if (method == HttpMethod::PUT) {
            return "PUT";
        } else if (method == HttpMethod::DELETE) {
            return "DELETE";
        } else if (method == HttpMethod::POST) {
            return "POST";
        } else if (method == HttpMethod::OPTIONS) {
            return "OPTIONS";
        } else if (method == HttpMethod::TRACE) {
            return "TRACE";
        } else if (method == HttpMethod::CONNECT) {
            return "CONNECT";
        }
        throw "unknown HTTP method requested";
    }

}
