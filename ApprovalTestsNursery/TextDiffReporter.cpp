#include "TextDiffReporter.h"
#include "ConsoleDiffReporter.h"
#include "ApprovalTests/reporters/FirstWorkingReporter.h"

TextDiffReporter::TextDiffReporter()
{
    std::vector<Reporter*> reporters = {
        new ConsoleDiffReporter("diff"),
        new ConsoleDiffReporter("C:WindowsSystem32c.exe")
    };
    m_reporter = std::unique_ptr<Reporter>(new FirstWorkingReporter( reporters ));
}

bool TextDiffReporter::report(std::string received, std::string approved) const
{
    std::cout << "Comparing files:" << std::endl;
    std::cout << "received: " << received << std::endl;
    std::cout << "approved: " << approved << std::endl;
    return m_reporter->report(received, approved);
}
