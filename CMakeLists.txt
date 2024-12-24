# cmake_minimum_required(VERSION 3.10)
# project(Trading-ROPES CXX)

# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# # set(SOURCE_FILES src/main.cpp src/ropes_client.cpp src/credentials_manager.cpp)
# set(SOURCE_FILES src/main.cpp src/deribit_api.cpp)
# set(SOURCE_DIR /home/sterben/Project/Trading-ROPES/src)


# # add your include directories here
# include_directories(include)

# # add_executable(Trading-ROPES /home/sterben/Project/Trading-ROPES/main.cpp)
# add_executable(Trading-ROPES /home/sterben/Project/Trading-ROPES/src/main.cpp)


# ///--------------------------------///
cmake_minimum_required(VERSION 3.10)
project(Trading-ROPES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define source files
set(SOURCE_FILES 
    ${CMAKE_SOURCE_DIR}/src/main.cpp
    ${CMAKE_SOURCE_DIR}/src/deribit_api.cpp
)

# Add include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Create executable using all source files
add_executable(Trading-ROPES ${SOURCE_FILES})

# Add curl dependency
find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIRS})
target_link_libraries(Trading-ROPES ${CURL_LIBRARIES})

# Add nlohmann_json dependency
find_package(nlohmann_json REQUIRED)
target_link_libraries(Trading-ROPES nlohmann_json::nlohmann_json)