cmake_minimum_required(VERSION 3.25)

project(notepad VERSION 0.1 LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

qt_add_executable(notepad)

target_sources(notepad
    PRIVATE
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        icons.qrc
        
    PUBLIC
        
)

set_target_properties(notepad PROPERTIES AUTORCC on)

target_compile_features(notepad PRIVATE cxx_std_20)

# Define target properties for Android with Qt 6 as:
#    set_property(TARGET notepad APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

find_package(Qt6 REQUIRED COMPONENTS PrintSupport)

target_link_libraries(notepad 
    PRIVATE 
        Qt6::Widgets
        Qt6::PrintSupport
)










































# set_target_properties(notepad PROPERTIES
#     MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
#     MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
#     MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
#     MACOSX_BUNDLE TRUE
#     WIN32_EXECUTABLE TRUE
# )

# install(TARGETS notepad
#     BUNDLE DESTINATION .
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

# if(QT_VERSION_MAJOR EQUAL 6)
#     qt_finalize_executable(notepad)
# endif()





#qt_add_executable(notepad)  //Creates and finalizes an application target of a platform-specific type.
#This command performs the following tasks:

#    1. Create a CMake target of the appropriate type for the target platform.
#    2. Link the target to the Qt::Core library.
#    3. Handle finalization of the CMake target.



# qt_standard_project_setup()     #set(CMAKE_AUTOUIC ON)  set(CMAKE_AUTOMOC ON)  set(CMAKE_AUTORCC ON)

