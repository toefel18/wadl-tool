#include "resource.h"
#include<assert.h>

namespace wadl {

    Resource::Resource(const std::string &uri)
        :uri(uri)
    {
    }

    const Resource::Methods& Resource::getMethods() const {
        return methods;
    }

    Resource::Methods& Resource::getMethods() {
        return methods;
    }

    std::string Resource::getUri() {
        return uri;
    }
}
