

set(INC_ENGINE
        GameObject.hpp
        Developing.hpp
)

set(SRC_ENGINE
        GameObject.cpp
)


add_library(
        fom_engine
        ${INC_ENGINE}
        ${SRC_ENGINE}
)

target_include_directories(
        fom_engine
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}

        /home/yurych4/developing/installs/include

)

