project(fom_lib_project)

add_library(
        fom_lib
        STATIC
		include/fom/fom.hpp
		src/fom.cpp
)

set_property(TARGET fom_lib APPEND PROPERTY CXX_STANDARD 14)

target_include_directories(
        fom_lib
        PUBLIC
        include
)

target_link_libraries(
        fom_lib

        PRIVATE
		shape_generator_lib

)
