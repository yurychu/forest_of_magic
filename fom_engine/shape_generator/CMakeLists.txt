project(shape_generator_lib_project)

add_library(
		shape_generator_lib
        STATIC
		include/shape_generator/shape_generator.hpp
		src/shape_generator.cpp
)

set_property(TARGET shape_generator_lib APPEND PROPERTY CXX_STANDARD 14)

target_include_directories(
        shape_generator_lib

        PUBLIC
        include

		PRIVATE
		include/shape_generator
)
