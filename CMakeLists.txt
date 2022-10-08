# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.8)

project ("CORBATest")

# Vars.
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_definitions (__WIN32__ __x86__ _WIN32_WINNT=0x0400 __NT__ __OSVERSION__=4)


# Includes.
include_directories ("C:/omniORB-4.3.0/include")
include_directories ("stubs/OmniORB4CppStubs/include")

# Links.
link_directories ("C:/omniORB-4.3.0/bin/x86_win32")
link_directories ("C:/omniORB-4.3.0/lib/x86_win32")
link_libraries ("omniORB4_rtd.lib" "omniDynamic4_rtd.lib" "omnithread_rtd.lib")

# Projects.
add_subdirectory ("stubs/OmniORB4CppStubs")
#add_subdirectory ("stubs/IdljStubs")
add_subdirectory ("OmniORB4CppServer")
add_subdirectory ("OmniORB4CppClient")
#add_subdirectory ("IdljJavaClient")
