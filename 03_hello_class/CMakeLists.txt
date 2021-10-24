# notre executable
add_executable(app_03 main.cpp)

# declaration de la lib hello
add_subdirectory(hello)

# notre application my_app va linker avec la lib hello.
target_link_libraries(app_03 PRIVATE hello) 
