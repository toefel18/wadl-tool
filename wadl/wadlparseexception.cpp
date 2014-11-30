#include "wadlparseexception.h"


namespace wadl {

    WadlParseException::WadlParseException(const std::string &message, const std::string &file, int line)
        :message(message), file(file), line(line)
    {
    }

    std::string WadlParseException::getMessage() const {
        return message;
    }

    std::string WadlParseException::getFile() const {
        return file;
    }

    int WadlParseException::getLine() const {
        return line;
    }
}
