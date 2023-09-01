# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.22.1)

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(glfw-populate NONE)



include(ExternalProject)
ExternalProject_Add(glfw-populate
                     "UPDATE_DISCONNECTED" "False" "URL" "https://github.com/glfw/glfw/archive/3.3.8.zip" "URL_HASH" "MD5=b06789a44e82a8a3ebd2e0301fb0484a" "UPDATE_COMMAND" ""
                    SOURCE_DIR          "/mnt/c/Users/talha/Documents/LennyGraphics/_deps/glfw-src"
                    BINARY_DIR          "/mnt/c/Users/talha/Documents/LennyGraphics/_deps/glfw-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
)


