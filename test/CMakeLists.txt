add_library(printer
        ../src/printer.cpp
        ../include/printer.h
)

target_link_libraries(printer PUBLIC library1)