
include_directories(
        ${PROJECT_SOURCE_DIR}
)


set (INC_EDITOR

        )

set (SRC_EDITOR
        editor.cpp
        )


add_executable(
        editor
        ${INC_EDITOR}
        ${SRC_EDITOR}
)

set_property(TARGET editor APPEND PROPERTY CXX_STANDARD 14)

target_link_libraries(
        editor
        LINK_PUBLIC
        fom_engine
)
