#ifndef APPROVALTESTS_CPP_AUTOAPPROVEREPORTER_H
#define APPROVALTESTS_CPP_AUTOAPPROVEREPORTER_H

#include "ApprovalTests/reporters/Reporter.h"

class AutoApproveReporter : public Reporter
{
public:
    bool report(std::string received, std::string approved) const override;
};

#endif //APPROVALTESTS_CPP_AUTOAPPROVEREPORTER_H
