cmake_minimum_required(VERSION 3.9)
project(Kursach)

set(CMAKE_CXX_STANDARD 17)

add_executable(Kursach
        src/exceptions/CustomExceptionBase.hpp
        src/exceptions/ModelFieldNotFoundException.hpp
        src/exceptions/UnableToCastModelFieldException.hpp
        src/menus/login/AuthMenu.cpp
        src/menus/login/LoginOption.cpp
        src/menus/login/RegisterOption.cpp
        src/menus/main/AuthMenuOption.cpp
        src/menus/main/MainMenu.cpp
        src/menus/ExitOption.cpp
        src/menus/Menu.cpp
        src/menus/Option.cpp
        src/menus/SubMenu.cpp
        src/models/User.cpp
        src/orm/Field.hpp
        src/orm/Model.hpp
        src/repositories/files/FilesUsersRepository.cpp
        src/utils/console.cpp
        src/utils/files.cpp
        src/utils/strings.cpp
        src/Instance.cpp
        main.cpp
        )