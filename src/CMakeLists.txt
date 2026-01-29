file(GLOB_RECURSE SRC_FILES
    "*.cpp"
    "utils/*.cpp"
)

add_executable(Zcrypt ${SRC_FILES})
