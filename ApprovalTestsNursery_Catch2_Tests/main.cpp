//filesystem::
// ReSharper disable once CppUnusedIncludeDirective

#define APPROVALS_CATCH
#include "Catch2Approvals.h"
#include "ApprovalTests/Approvals.h"
#include "ApprovalTests/reporters/DiffReporter.h"
#include "reporters/CIBuildOnlyReporter.h"
#include "reporters/TextDiffReporter.h"

auto directory = Approvals::useApprovalsSubdirectory("approval_tests");

using namespace ApprovalTests;
// If it's a CI machine, show differences as text in the console/log
auto ciReporterDisposer = CIBuildOnlyReporter::useAsFrontLoadedReporter( std::make_shared<TextDiffReporter>() );

// Demonstrate how to set a default reporter for tests on non-CI machines.
// (in fact, DiffReporter is the default anyway, so this doesn't actually
// change the behaviour)
auto interactiveReporterDisposer =
    Approvals::useAsDefaultReporter(std::make_shared<DiffReporter>());
