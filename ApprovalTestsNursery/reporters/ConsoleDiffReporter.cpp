#include "ConsoleDiffReporter.h"

ConsoleDiffReporter::ConsoleDiffReporter(const std::string &program) : CommandReporter(program, &launcher)
{
}

ConsoleDiffReporter::ConsoleDiffReporter(const DiffInfo &info) : CommandReporter(info.getProgramForOs(), &launcher)
{
}
