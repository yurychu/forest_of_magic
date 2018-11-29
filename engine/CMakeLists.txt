

set(INC_ENGINE
        GameObject.hpp
        Developing.hpp
)

set(SRC_ENGINE
        GameObject.cpp
)




add_library(
        fom_engine
        STATIC
        ${INC_ENGINE}
        ${SRC_ENGINE}
)

set_property(TARGET fom_engine APPEND PROPERTY CXX_STANDARD 14)

target_include_directories(
        fom_engine
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}

        /home/yurych4/developing/installs/include

)


find_library(SDL_LIBRARY SDL2 HINTS /home/yurych4/developing/installs/lib)

target_link_libraries(
        fom_engine
        ${SDL_LIBRARY}
)
