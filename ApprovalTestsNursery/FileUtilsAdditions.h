#ifndef APPROVALTESTS_CPP_NURSERY_FILEUTILSADDITIONS_H
#define APPROVALTESTS_CPP_NURSERY_FILEUTILSADDITIONS_H

#include <string>

class FileUtilsAdditions
{
public:
    static std::string readFileThrowIfMissing(std::string fileName);
    static std::string readFileReturnEmptyIfMissing(std::string fileName);
};

#endif //APPROVALTESTS_CPP_NURSERY_FILEUTILSADDITIONS_H
