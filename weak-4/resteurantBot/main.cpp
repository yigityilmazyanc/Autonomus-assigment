#include <iostream>
#include "Menu.hpp"

int main() {
    std::vector<std::vector<std::shared_ptr<Menu::MenuItem>>> menuItems(Menu::NUM_DISH_TYPES);

    Menu::readJsonFile("menu.json", menuItems);

    Menu::printMenu(Menu::STARTER, menuItems);

    return 0;
}