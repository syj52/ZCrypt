file(GLOB_RECURSE SRC_FILES
    "*.cpp"
    "utils/*.cpp"
    "factories/*.cpp"
    "algorithms/*.cpp"
)

add_executable(Zcrypt ${SRC_FILES})

target_compile_options(Zcrypt PRIVATE /source-charset:utf-8 /execution-charset:utf-8)
