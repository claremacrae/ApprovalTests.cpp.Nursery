# Only regenerate Sphinx when:
# - Doxygen has rerun
# - Our doc files have been updated
# - The Sphinx config has been updated
add_custom_command(OUTPUT ${SPHINX_INDEX_FILE}
        COMMAND
        ${SPHINX_EXECUTABLE} -b html
        # Tell Breathe where to find the Doxygen output
        -Dbreathe_projects.ApprovalTests.cpp.Nursery=${DOXYGEN_OUTPUT_DIR}/xml
        ${SPHINX_SOURCE} ${SPHINX_BUILD}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        DEPENDS
        # Other docs files you want to track should go here (or in some variable)
        ${CMAKE_CURRENT_SOURCE_DIR}/index.rst
        ${DOXYGEN_INDEX_FILE}
        MAIN_DEPENDENCY ${SPHINX_SOURCE}/conf.py
        COMMENT "Generating documentation with Sphinx - for output, open ${SPHINX_INDEX_FILE}")

# Nice named target so we can run the job easily
add_custom_target(Sphinx DEPENDS ${SPHINX_INDEX_FILE} Doxygen)

# Add an install target to install the docs
include(GNUInstallDirs)
install(DIRECTORY ${SPHINX_BUILD}
        DESTINATION ${CMAKE_INSTALL_DOCDIR})
