//filesystem::
// ReSharper disable once CppUnusedIncludeDirective

#define APPROVALS_CATCH
#include "ApprovalTests/Catch2Approvals.h"
#include "ApprovalTests/Approvals.h"

auto directory = Approvals::useApprovalsSubdirectory("approval_tests");

// TODO If it's a CI build, don't allow GUI applications to pop up.
