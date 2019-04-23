#ifndef APPROVALTESTS_CPP_AUTOAPPROVEIFMISSINGREPORTER_H
#define APPROVALTESTS_CPP_AUTOAPPROVEIFMISSINGREPORTER_H

#include "ApprovalTests/reporters/Reporter.h"

class AutoApproveIfMissingReporter : public Reporter
{
public:
    bool report(std::string received, std::string approved) const override;
};

#endif //APPROVALTESTS_CPP_AUTOAPPROVEIFMISSINGREPORTER_H
