#pragma once

#include "common.h"

#include <cstdio>

namespace Squashing {

class SQUASHER_EXPORT Squasher {
public:
    Squasher(const fs::path &in_path, const fs::path &out_path);
    ~Squasher();

private:
    fs::path m_out_path;
    int m_out_fd   = -1;
    FILE *m_out_fh = nullptr;
};

} // namespace Squashing
