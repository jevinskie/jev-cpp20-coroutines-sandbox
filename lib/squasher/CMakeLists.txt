set(SQUASHER_SRC
    common-internal.h
    squasher.cpp
    utils.cpp
)

set(SQUASHER_HDR_STANDALONE
    common.h
    common-attrs.h
)

set(SQUASHER_HDR)
foreach(HDR ${SQUASHER_HDR_STANDALONE})
    set(HDR "${CMAKE_CURRENT_SOURCE_DIR}/../../include/squasher/${HDR}")
    list(APPEND SQUASHER_HDR ${HDR})
endforeach()

foreach(SRC ${SQUASHER_SRC})
    get_filename_component(HDR_NAME ${SRC} NAME_WLE)
    set(HDR "${CMAKE_CURRENT_SOURCE_DIR}/../../include/squasher/${HDR_NAME}.h")
    if(EXISTS ${HDR})
        list(APPEND SQUASHER_HDR ${HDR})
    endif()
endforeach()

set(SQUASHER_PUBLIC_LIBS
    icecream
)

set(SQUASHER_PRIVATE_LIBS
    fmt
)

# SQUASHER_HDR added for Xcode project generation
add_library(squasher STATIC ${SQUASHER_SRC} ${SQUASHER_HDR})
add_library(squasher-shared SHARED ${SQUASHER_SRC} ${SQUASHER_HDR})
set_target_properties(squasher squasher-shared PROPERTIES PUBLIC_HEADER "${SQUASHER_HDR}")

target_link_libraries(squasher
PUBLIC
    ${SQUASHER_PUBLIC_LIBS}
PRIVATE
    ${SQUASHER_PRIVATE_LIBS}
)
target_compile_options(squasher PRIVATE -Wall -Wextra -Wpedantic)

target_include_directories(squasher
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../include
    PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(squasher-shared
PUBLIC
    ${SQUASHER_PUBLIC_LIBS}
PRIVATE
    ${SQUASHER_PRIVATE_LIBS}
)
target_compile_options(squasher-shared PRIVATE -Wall -Wextra -Wpedantic)

target_include_directories(squasher-shared
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../include
    PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
)


install(TARGETS squasher squasher-shared
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    PUBLIC_HEADER DESTINATION include/squasher
)

# target_compile_options(squasher PRIVATE -Xclang -fdump-record-layouts)
