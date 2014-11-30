#ifndef PATHHELPER_H
#define PATHHELPER_H

#include <string>

class PathHelper
{
public:

    /**
     * @brief concatenates left and right and avoids double slashes if left ends with a slash and right starts with a slash
     * @param left
     * @param right
     * @return left and right concatenated
     */
    static std::string concat(const std::string& left, const std::string& right);
};

#endif // PATHHELPER_H
