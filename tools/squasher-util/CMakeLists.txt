add_executable(squasher-util squasher-util.cpp)

target_link_libraries(squasher-util PRIVATE squasher argparse fmt)
target_compile_options(squasher-util PRIVATE -Wall -Wextra -Wpedantic)

install(TARGETS squasher-util
    RUNTIME DESTINATION bin
)
