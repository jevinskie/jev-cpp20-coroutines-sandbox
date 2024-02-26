#include "squasher/squasher.h"

#undef NDEBUG
#include <cassert>
#include <cstdlib>
#include <filesystem>
#include <locale>
#include <thread>

#include <argparse/argparse.hpp>
#include <fmt/format.h>

namespace fs = std::filesystem;

using namespace Squashing;

int main(int argc, const char *argv[]) {
    std::locale::global(std::locale("en_US.UTF-8"));
    argparse::ArgumentParser parser(getprogname());
    parser.add_argument("-i", "--in-file").required().help("input file path");
    parser.add_argument("-o", "--out-file").required().help("output file path (use - for stdout)");

    try {
        parser.parse_args(argc, argv);
    } catch (const std::runtime_error &err) {
        fmt::print(stderr, "Error parsing arguments: {:s}\n", err.what());
        return -1;
    }

    const auto in_path  = fs::path{parser.get("--in-file")};
    const auto out_path = fs::path{parser.get("--out-file")};

    auto squasher = Squasher(in_path, out_path);

    return 0;
}
