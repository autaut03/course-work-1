cmake_minimum_required(VERSION 3.9)
project(Kursach)

set(CMAKE_CXX_STANDARD 11)

add_executable(Kursach
        main.cpp
        src/menus/login/AuthMenu.cpp
        src/menus/login/LoginOption.cpp
        src/menus/login/RegisterOption.cpp
        src/menus/main/AuthMenuOption.cpp
        src/menus/main/MainMenu.cpp
        src/menus/ExitOption.cpp
        src/menus/Menu.cpp
        src/menus/Option.cpp
        src/menus/SubMenu.cpp
        src/orm/Model.tpp
        src/models/User.cpp
        src/repositories/files/FilesUsersRepository.cpp
        src/utils/console.cpp
        src/utils/files.cpp
        src/utils/strings.cpp
        src/Instance.cpp
        )