# CORBATest
Пример клиент-сервеного взаимодействия на архитектуре CORBA.

## Содержание

- [echo.idl](https://github.com/erikrause/CORBATest/blob/main/idl/echo.idl)  - описание интерфейса удаленного объекта.
- [stubs](https://github.com/erikrause/CORBATest/tree/main/stubs) - сгенерированный код для интерфейса.
  - [OmniIdlCppStubs](https://github.com/erikrause/CORBATest/tree/main/stubs/OmniORB4CppStubs) - код, сгенерированный с использованием OmniORB 4.3.0 для C++.
  - [IdljStubs](https://github.com/erikrause/CORBATest/tree/main/stubs/IdljStubs) - код, сгенерированный с использованием Idlj (JDK 1.8.0)для Java.
 
 ---
 
- Сервер:
  - [OmniORB4CppServer](https://github.com/erikrause/CORBATest/tree/main/OmniORB4CppServer) - реализация сервера на C++.
    - [EchoImplementation](https://github.com/erikrause/CORBATest/blob/main/OmniORB4CppServer/src/EchoImplementation.cpp) - непосредвенно реализация интерфейса Echo на C++.
- Клиенты: 
  - [OmniORB4CppClient](https://github.com/erikrause/CORBATest/tree/main/OmniORB4CppClient) - реализация клиента на C++.
  - [IdlJavaClient](https://github.com/erikrause/CORBATest/tree/main/IdljJavaClient) - реализация клиента на Java.

## Использование

Запустить сервер (OmniORB4CppServer.exe), скопировать вывод из консоли сервера ("IOR:...") и вставить как аргумент при запуске клиента, например:

```
OmniORB4CppClient IOR:010000001700000049444c3a434f524241546573742f4563686f3a312e300000010000000000000064000000010102000c0000003139322e3136382e312e3500b8f800000e000000fe302f406300008c68000000000000000200000000000000080000000100000000545441010000001c00000001000000010001000100000001000105090101000100000009010100
Testing echoString: I said,"Hello!". The Server said,"Hello!"
Testing echoReversedString: I said,"Hello!". The Server said,"!elloH"
```
