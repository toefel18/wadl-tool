#ifndef WADLPARSEEXCEPTION_H
#define WADLPARSEEXCEPTION_H

#include <string>

namespace wadl {

    class WadlParseException
    {
    public:
        WadlParseException(const std::string& message, const std::string& file, int line);

        std::string getMessage() const;
        std::string getFile() const;
        int getLine() const;


    private:
        std::string message;
        std::string file;
        int line;
    };

}
#endif // WADLPARSEEXCEPTION_H
