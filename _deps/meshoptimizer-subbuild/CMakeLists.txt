# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.22.1)

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(meshoptimizer-populate NONE)



include(ExternalProject)
ExternalProject_Add(meshoptimizer-populate
                     "UPDATE_DISCONNECTED" "False" "URL" "https://github.com/zeux/meshoptimizer/archive/refs/tags/v0.18.zip" "URL_HASH" "MD5=E2BF4D9E82410E9EABA8776C2DE98D7B"
                    SOURCE_DIR          "/mnt/c/Users/talha/Documents/LennyGraphics/_deps/meshoptimizer-src"
                    BINARY_DIR          "/mnt/c/Users/talha/Documents/LennyGraphics/_deps/meshoptimizer-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
)


