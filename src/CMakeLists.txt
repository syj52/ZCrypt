file(GLOB_RECURSE SRC_FILES
    "*.cpp"
    "utils/*.cpp"
    "factories/*.cpp"
    "algorithm/*.cpp"
    "compression/*.cpp"
    "encrytion/*.cpp"
)

add_executable(Zcrypt ${SRC_FILES})
target_compile_options(Zcrypt PRIVATE /source-charset:utf-8 /execution-charset:utf-8)