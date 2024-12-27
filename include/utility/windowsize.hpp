#pragma once
#include <print>
#include <tuple>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <sys/ioctl.h>
#endif

#include "stdint.hpp"

namespace Utility {
    std::tuple<i32, i32> getTerminalSize();
}