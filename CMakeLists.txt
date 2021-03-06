cmake_minimum_required(VERSION 3.9)
project(Kursach)

set(CMAKE_CXX_STANDARD 17)

add_executable(Kursach
        src/exceptions/CustomExceptionBase.hpp
        src/exceptions/ModelFieldNotFoundException.hpp
        src/exceptions/UnableToCastModelFieldException.hpp
        src/menus/item/BuyItemOption.cpp
        src/menus/item/DeleteItemOption.cpp
        src/menus/item/ItemMenu.cpp
        src/menus/items/ItemOption.cpp
        src/menus/items/ItemsListMenu.cpp
        src/menus/main/auth-options/LoginOption.cpp
        src/menus/main/auth-options/RegisterOption.cpp
        src/menus/main/auth-options/LogOutOption.cpp
        src/menus/main/items-options/AddItemOption.cpp
        src/menus/main/items-options/ItemsListOption.cpp
        src/menus/main/MainMenu.cpp
        src/menus/ExitOption.cpp
        src/menus/Menu.cpp
        src/menus/MenuItem.cpp
        src/menus/Option.cpp
        src/menus/CategorizerItem.cpp
        src/menus/DummyItem.cpp
        src/menus/SubMenu.cpp
        src/models/Item.cpp
        src/models/User.cpp
        src/orm/Field.hpp
        src/orm/Model.hpp
        src/utils/console.cpp
        src/utils/files.cpp
        src/utils/strings.cpp
        src/Instance.cpp
        main.cpp
        )