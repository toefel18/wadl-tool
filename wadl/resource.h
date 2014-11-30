#ifndef RESOURCE_H
#define RESOURCE_H

#include<vector>
#include<string>

#include "method.h"
#include "param.h"

namespace wadl {

    class Resource
    {
    public:

        typedef std::vector<Method*> Methods;
        typedef std::vector<Resource*> Resources;
        typedef std::vector<Param> Params;

        Resource(const std::string &uri);
        Resource(const std::string &uri, Resource* parent);

        const Methods& getMethods() const;
        Methods& getMethods();
        std::string getUri();
        std::string getFullPath();

        Resource* getParent();
        const Resources& getChildren() const;
        Resources& getChildren();
        Resources getDescendants() const;


        const Params& getParams() const;
        Params& getParams();
    private:

        Methods methods;
        std::string uri;
        Resource *parent;
        Resources children;
        Params params;
    };
}

#endif // RESOURCE_H
