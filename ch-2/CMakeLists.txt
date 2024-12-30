# Collect all source files in this chapter
file(GLOB CH2_SOURCES *.cpp)

# Add an executable for each exercise
foreach(SOURCE_FILE ${CH2_SOURCES})
    get_filename_component(EXE_NAME ${SOURCE_FILE} NAME_WE)
    add_executable(${EXE_NAME} ${SOURCE_FILE})

    # Link any necessary libraries here
    # target_link_libraries(${EXE_NAME} ...)
endforeach()