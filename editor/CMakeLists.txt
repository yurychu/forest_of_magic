
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


target_link_libraries(
        editor
        LINK_PUBLIC
        fom_engine
)
