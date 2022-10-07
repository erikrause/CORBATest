cmake_minimum_required (VERSION 3.8)

include_directories ("include")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (OmniORB4CppServer "src/OmniORB4CppServer.cpp" "src/EchoImplementation.cpp")


target_link_libraries (OmniORB4CppServer OmniORB4Stubs)