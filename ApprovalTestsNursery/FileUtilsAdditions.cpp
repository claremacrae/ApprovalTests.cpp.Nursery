#include "FileUtilsAdditions.h"
#include "FileUtils.h"

#include <stdexcept>
#include <fstream>
#include <sstream>

std::string FileUtilsAdditions::readFileThrowIfMissing(std::string fileName)
{
    std::ifstream in(fileName.c_str(), std::ios_base::in);
    if ( ! in )
    {
        throw std::runtime_error("File does not exist: " + fileName);
    }
    std::stringstream written;
    written << in.rdbuf();
    in.close();

    std::string text = written.str();
    return text;
}

std::string FileUtilsAdditions::readFileReturnEmptyIfMissing(std::string fileName)
{
    if ( FileUtils::fileExists(fileName ))
    {
        return readFileThrowIfMissing(fileName); 
    }
    else
    {
        return std::string();
    }
}
