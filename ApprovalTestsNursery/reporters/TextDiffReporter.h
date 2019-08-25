#ifndef APPROVALTESTS_CPP_TEXTDIFFREPORTER_H
#define APPROVALTESTS_CPP_TEXTDIFFREPORTER_H

#include "reporters/Reporter.h"
#include "ConsoleDiffReporter.h"
#include "reporters/FirstWorkingReporter.h"

#include <memory>

// A Reporter class that only uses text-based diff tools, with output written
// to the console. It provides no opportunity for interactive approving
// of files.
// It currently has a short, hard-coded list of diffing tools.
class TextDiffReporter : public Reporter
{
private:
    std::unique_ptr<Reporter> m_reporter;

public:
    TextDiffReporter()
    {
        std::vector<Reporter*> reporters = {new ConsoleDiffReporter("diff"),
            new ConsoleDiffReporter("C:/Windows/System32/fc.exe")};
        m_reporter =
            std::unique_ptr<Reporter>(new FirstWorkingReporter(reporters));
    }
    bool report(std::string received, std::string approved) const override
    {
        std::cout << "Comparing files:" << std::endl;
        std::cout << "received: " << received << std::endl;
        std::cout << "approved: " << approved << std::endl;
        const bool result = m_reporter->report(received, approved);
        if (!result)
        {
            std::cout
                << "TextDiffReporter did not find a working diff program\n\n";
        }

        return result;
    }
};

#endif //APPROVALTESTS_CPP_TEXTDIFFREPORTER_H
