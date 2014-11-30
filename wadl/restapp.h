#ifndef RESTAPP_H
#define RESTAPP_H

#include <vector>
#include <string>

#include "resource.h"

namespace wadl {

    class RestApp
    {
    public:

        /**
         * @brief resources container
         */
        typedef std::vector<Resource*> Resources;

        /**
         * @brief RestApp
         * @param wadlFilename the filename that this restapp is based on
         */
        RestApp(const std::string& wadlFilename);

        /**
         * @brief Retrieves the resources defined in the wadl. Each resource may contain children.
         * @return reference to the internal vector
         */
        Resources& getResources();

        /**
         * @brief Retrieves the resources defined in the wadl. Each resource may contain children.
         * @return reference to the internal vector
         */
        const Resources& getResources() const;

        /**
         * @brief Collects all resources and subresouces and returns the result. meaning it will get all the child resources and all their descendants
         * @return a new vector with all the resouces
         */
        Resources getAllResources() const;

    private:
        Resources resources;
        std::string wadlFilename;
    };

}

#endif // RESTAPP_H
