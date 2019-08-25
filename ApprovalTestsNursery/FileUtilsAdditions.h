#ifndef APPROVALTESTS_CPP_FILEUTILSADDITIONS_H
#define APPROVALTESTS_CPP_FILEUTILSADDITIONS_H

#include "FileUtils.h"

#include <stdexcept>
#include <fstream>
#include <sstream>
#include <string>

namespace ApprovalTests
{
    class FileUtilsAdditions
    {
    public:
        static std::string readFileThrowIfMissing(std::string fileName)
        {
            std::ifstream in(fileName.c_str(), std::ios_base::in);
            if (!in)
            {
                throw std::runtime_error("File does not exist: " + fileName);
            }
            std::stringstream written;
            written << in.rdbuf();
            in.close();

            std::string text = written.str();
            return text;
        }

        static std::string readFileReturnEmptyIfMissing(std::string fileName)
        {
            if (FileUtils::fileExists(fileName))
            {
                return readFileThrowIfMissing(fileName);
            }
            else
            {
                return std::string();
            }
        }
    };
} // namespace ApprovalTests

#endif //APPROVALTESTS_CPP_FILEUTILSADDITIONS_H
