add_library(crtbp "CrtbpSystem.cpp")
target_link_libraries(crtbp PRIVATE Boost::boost)
target_include_directories(crtbp PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")