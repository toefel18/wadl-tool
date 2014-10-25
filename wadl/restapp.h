#ifndef RESTAPP_H
#define RESTAPP_H

#include <vector>

#include "resource.h"

namespace wadl {

    class RestApp
    {
    public:

        /**
         * @brief resources container
         */
        typedef std::vector<Resource> Resources;

        RestApp();

        Resources& getResources();
        const Resources& getResources() const;

    private:
        Resources resources;
    };

}

#endif // RESTAPP_H
