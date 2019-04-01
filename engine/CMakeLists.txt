project(fom_engine_project)

cmake_policy(SET CMP0074 NEW)  # package_ROOT env variable to find

add_library(
        fom_engine
        STATIC

		shape_generator/ShapeGenerator.cpp

		include/fom/ShapeGenerator.hpp

)

set_property(TARGET fom_engine APPEND PROPERTY CXX_STANDARD 14)

target_include_directories(
        fom_engine
        PUBLIC
        include
)

## If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)
## In most cases better set in the CMake cache
# set(SFML_DIR "E:\\developing\\SFML-2.5.1\\lib\\cmake\\SFML")

find_package(SFML 2.5
	COMPONENTS graphics audio
	REQUIRED
#	HINTS
#	$ENV{SFML_ROOT}
	)

target_link_libraries(
        fom_engine
        
		sfml-graphics
		sfml-audio
)
