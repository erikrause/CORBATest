#cmake_minimum_required (VERSION 3.8)
#find_package(Java)
#include(UseJava)

# add_jar("_EchoStub.java")

#add_custom_command(OUTPUT "_EchoStub.class"
                   #COMMAND javac CORBATest/_EchoStub.java
                   #WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}#)



#JAVA команды консоли:

#1.
#javac Client.java CORBATest/_EchoStub.java CORBATest/Echo.java CORBATest/EchoHelper.java CORBATest/EchoHolder.java CORBATest/EchoOperations.java CORBATest/EchoPOA.java

#2.
#jar cfm client.jar ClientManifest.txt Client.class CORBATest/_EchoStub.class CORBATest/Echo.class CORBATest/EchoHelper.class CORBATest/EchoHolder.class CORBATest/EchoOperations.class CORBATest/EchoPOA.class

#3.
#java -jar client.jar <IOR>