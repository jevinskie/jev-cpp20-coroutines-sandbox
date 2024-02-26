#include "squasher/squasher.h"
#include "common-internal.h"
#include "squasher/utils.h"

#undef NDEBUG
#include <cstdio>

#include <icecream/icecream.hpp>

namespace Squashing {

Squasher::Squasher(const fs::path &in_path, const fs::path &out_path) : m_out_path{out_path} {
    if (m_out_path.string() != "-") {
        m_out_fh = fopen(m_out_path.c_str(), "wb");
        if (!m_out_fh) {
            throw std::runtime_error(fmt::format("Failed to open output file: {}", out_path));
        }
        m_out_fd = fileno(m_out_fh);
        posix_check(m_out_fd, fmt::format("trying to fileno() FILE* {} for {}", fmt::ptr(m_out_fh),
                                          m_out_path));
    } else {
        m_out_fd = fileno(stdout);
        posix_check(m_out_fd, fmt::format("trying to fileno() FILE* {} for {}", fmt::ptr(stdout),
                                          m_out_path));
    }
}

Squasher::~Squasher() {
    if (m_out_fh) {
        const auto close_res = fclose(m_out_fh);
        posix_check(close_res, fmt::format("trying to fclose() {}", m_out_path));
        m_out_fh = nullptr;
    }
    m_out_fd = -1;
}

} // namespace Squashing
