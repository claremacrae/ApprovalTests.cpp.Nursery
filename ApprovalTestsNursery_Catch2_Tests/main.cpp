//filesystem::
// ReSharper disable once CppUnusedIncludeDirective

#define APPROVALS_CATCH
#include "Catch2Approvals.h"
#include "Approvals.h"
#include "reporters/DiffReporter.h"
#include "reporters/CIBuildOnlyReporter.h"
#include "reporters/TextDiffReporter.h"

auto directory = Approvals::useApprovalsSubdirectory("approval_tests");

// If it's a CI machine, show differences as text in the console/log
auto reporterForCIDisposer =
    Approvals::useAsFrontLoadedReporter(std::make_shared<CIBuildOnlyReporter>(
        std::make_shared<TextDiffReporter>()));

// Demonstrate how to set a default reporter for tests on non-CI machines.
// (in fact, DiffReporter is the default anyway, so this doesn't actually
// change the behaviour)
auto interactiveReporterDisposer =
    Approvals::useAsDefaultReporter(std::make_shared<DiffReporter>());
