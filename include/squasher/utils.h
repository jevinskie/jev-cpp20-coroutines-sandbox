#pragma once

#include "common.h"

#include <stdexcept>

namespace Squashing {

void posix_check(int retval, const std::string &msg);

}
