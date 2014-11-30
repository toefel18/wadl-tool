#include "resource.h"
#include<assert.h>

#include "pathhelper.h"

namespace wadl {

    Resource::Resource(const std::string &uri) : Resource(uri, nullptr) {
    }

    Resource::Resource(const std::string &uri, Resource* parent)
        :uri(uri), parent(parent)
    {
        if (parent != nullptr) {
            parent->children.push_back(this);
        }
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

    std::string Resource::getFullPath() {
        if (parent == nullptr) {
            return uri;
        } else {
            return PathHelper::concat(getParent()->getFullPath(), uri);
        }
    }

    Resource *Resource::getParent() {
        return parent;
    }

    const Resource::Resources &Resource::getChildren() const {
        return children;
    }

    Resource::Resources& Resource::getChildren() {
        return children;
    }

    Resource::Resources Resource::getDescendants() const {
        Resources descendants;
        for (Resource* child: children) {
            descendants.push_back(child);
            Resources childDesc = child->getDescendants();
            descendants.insert(descendants.end(), childDesc.begin(), childDesc.end());
        }
        return descendants;
    }

    Resource::Params& Resource::getParams() {
        return params;
    }

    const Resource::Params &Resource::getParams() const {
        return params;
    }

}
