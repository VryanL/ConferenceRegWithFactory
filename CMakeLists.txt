cmake_minimum_required(VERSION 3.5)

project(Ass2_Question_4 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Xml)

set(PROJECT_SOURCES
        main.cpp
        registrationwindow.cpp
        registrationwindow.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Ass2_Question_4
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        registration.h registration.cpp
        person.h person.cpp
        registrationlist.h registrationlist.cpp
        studentregistration.h studentregistration.cpp
        guestregistration.h guestregistration.cpp
        userinfodialog.h userinfodialog.cpp
        registrationlistwriter.h registrationlistwriter.cpp
        registrationlistreader.h registrationlistreader.cpp
        registrationfactory.h registrationfactory.cpp
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Ass2_Question_4 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Ass2_Question_4 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Ass2_Question_4
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Ass2_Question_4 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(Ass2_Question_4 PRIVATE Qt6::Xml)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Ass2_Question_4)
endif()
set_target_properties(Ass2_Question_4 PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Ass2_Question_4
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Ass2_Question_4)
endif()
