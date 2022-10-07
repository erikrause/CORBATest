# CORBATest
Пример клиент-сервеного взаимодействия на архитектуре CORBA.

# Содержание

- [echo.idl](https://github.com/erikrause/CORBATest/blob/main/idl/echo.idl)  - описание интерфейса удаленного объекта.
- [stubs](https://github.com/erikrause/CORBATest/tree/main/stubs) - сгенерированный код для интерфейса.
  - [OmniIdlCppStubs](https://github.com/erikrause/CORBATest/tree/main/stubs/OmniORB4CppStubs) - код, сгенерированный с использованием OmniORB 4.3.0 для C++.
  - [IdljStubs](https://github.com/erikrause/CORBATest/tree/main/stubs/IdljStubs) - код, сгенерированный с использованием Idlj (JDK 1.8.0) для Java.
 
 ---
 
- Сервер:
  - [OmniORB4CppServer](https://github.com/erikrause/CORBATest/tree/main/OmniORB4CppServer) - реализация сервера на C++.
    - [EchoImplementation](https://github.com/erikrause/CORBATest/blob/main/OmniORB4CppServer/src/EchoImplementation.cpp) - непосредвенно реализация интерфейса Echo на C++.
- Клиенты: 
  - [OmniORB4CppClient](https://github.com/erikrause/CORBATest/tree/main/OmniORB4CppClient) - реализация клиента на C++.
  - [IdlJavaClient](https://github.com/erikrause/CORBATest/tree/main/IdljJavaClient) - реализация клиента на Java.
