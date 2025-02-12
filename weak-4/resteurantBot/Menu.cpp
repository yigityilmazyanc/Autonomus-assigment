#include <iostream>
#include <vector>
#include "Menu.hpp"
#include <fstream>
#include "json.hpp"


using json = nlohmann::json;

namespace Menu {
    void readJsonFile(std::string fileName, std::vector<std::vector<std::shared_ptr<MenuItem>>>& menu) {
        std::ifstream file(fileName);
        if (!file.is_open()) {
            std::cout << "File not found" << std::endl;
            return;
        }

        json menuData;
        file >> menuData;
        file.close();

        for (const auto& item : menuData["starters"]) {
            std::string foodName = item["name"];
            double foodPrice = item["price"];
            TasteBalance foodTasteBalance = item["taste_balance"];
            menu[STARTER].push_back(std::make_shared<Starter>(foodName, foodPrice, foodTasteBalance));
        }
    }

    void printMenu(int typeFood, const std::vector<std::vector<std::shared_ptr<MenuItem>>>& menu) {
        for (const auto& item : menu[typeFood]) {
            item->display();
        }
    }
}