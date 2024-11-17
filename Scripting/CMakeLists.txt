cmake_minimum_required(VERSION 3.0.0)

message("Hello World")

set(NAME "BOB SMITH")
set(HEIGHT 190)


message("Hello, my name is ${NAME}, my height is ${HEIGHT}cm and my age is ${AGE} years old")

set( VAR a b c;d "e;f" 2.7 "Hello There")
list(APPEND VAR 1.6 XX)
message( ${VAR})
list(REMOVE_AT VAR 2 -3)
message( ${VAR})
list(REMOVE_ITEM VAR a 2.7)
message( ${VAR})
list(INSERT VAR 2 XX 2.7)
message( ${VAR})
list(REVERSE VAR)
message( ${VAR})
list(REMOVE_DUPLICATES VAR)
message( ${VAR})
list(SORT VAR)
message( ${VAR})

set(VAR YES)

if(VAR)
        message("If block executed")
else()
        message("Else block executed")
endif ()

set(Name Alice)
if(DEFINED Name)
    message("Name: if block executed")
else ()
    message("Name: else block executed")
    endif()

    if(DEFINED Age)
        message("Age: if block executed")
    else ()
        message("Age: else block executed")
    endif()

if(COMMAND target_link_library)
    message("target_link_library is a command")
else ()
    message("target_link_library is NOT a command")
endif()

if(COMMAND target_link_libraries)
    message("target_link_libraries is a command")
else ()
    message("target_link_libraries is NOT a command")
endif()

if(EXISTS /home/dusti/projects/cmake_tutorials/Scripting/CMakeLists.txt)
    message("Given file exists")
else ()
    message("File not found")
endif()

set(Name1 Alice)
set(Name2 Bob)

if(Name1 STRLESS Name2)
    message("${Name1} is less than ${Name2}")
elseif(Name1 STRGREATER Name2)
    message("${Name1} is greater than ${Name2}")
    elseif(Name1 STREQUAL Name2)
    message("${Name1} is equal to ${Name2}")
endif()

set(VAR A)
while(NOT VAR STREQUAL "AAAAAAAAAA")
    set(VAR ${VAR}A)
    message(${VAR})
endwhile()

foreach(Name Alice Bob Charlie)
    message(${Name})
endforeach()

foreach(x RANGE 100 105)
    message("Person_${x}")
endforeach()

set(VAR1 0;1)
set(VAR2 2 3)
set(VAR3 "4 5")

foreach(x IN LISTS VAR1 VAR2 VAR3)
    message("x = ${x}")
endforeach ()

function(print_detail)
    message("My name is Bob")
endfunction()

print_detail()

function(print_detail name_var)
    message(${${name_var}})
endfunction()

set (Name Charlie)
print_detail(Name)



set(Name Charlie)

function(print_detail)
    message("Inside function: Before modification: ${Name}")
    set(Name Bob PARENT_SCOPE)
    message("Inside function: After modification: ${Name}")
endfunction(
)

message("Outside function: before function call: ${Name}")
print_detail()
message("Outside function:  after function call: ${Name}")


macro(print_detail name_var)
    message("My name is ${name_var}")
    set(name_var abc)
    message("My name is ${name_var}")
endmacro()

print_detail(Charlie)

macro(print_detail name_var)
    set(name_var Bob)
    message("My name is ${name_var}")
    if(DEFINED name_var)
        message ("If block executed")
        endif()
endmacro()

print_detail(Charlie)