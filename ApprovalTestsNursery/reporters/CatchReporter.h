#ifndef APPROVALTESTS_CPP_NURSERY_CATCHREPORTER_H
#define APPROVALTESTS_CPP_NURSERY_CATCHREPORTER_H

#include "reporters/Reporter.h"

// A reporter which uses Catch CHECK statement to check the output
class CatchReporter : public Reporter
{
public:
    bool report(std::string received, std::string approved) const override;
};


#endif //APPROVALTESTS_CPP_NURSERY_CATCHREPORTER_H
