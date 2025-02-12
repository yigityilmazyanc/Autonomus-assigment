#include <iostream>
#include <vector>
#include "json.hpp"

using json = nlohmann::json;

namespace Menu {
    enum Ishot {
        True,
        False
    };
    enum Gender {
        MR,
        MRS
    };
    enum Taste {
        SWEET,
        SOUR,
        BITTER,
        SALTY,
        SAVORY,
        NUM_TASTES
    };
    enum DishType {
        STARTER,
        SALAD,
        MAIN_COURSE,
        DRINK,
        APPETIZER,
        DESSERT,
        NUM_DISH_TYPES
    };
    struct TasteBalance {
        int sweet;
        int sour;
        int salty;
        int bitter;
        int savory;
    };
    class MenuItem {
    public:
        MenuItem(std::string foodName, double foodPrice, TasteBalance foodTasteBalance)
            : foodName(foodName), foodPrice(foodPrice), foodTasteBalance(foodTasteBalance) {}
        virtual ~MenuItem() {}

        virtual void display() const = 0;

        std::string getFoodName() const { return foodName; }
        double getFoodPrice() const { return foodPrice; }
        TasteBalance getFoodTasteBalance() const { return foodTasteBalance; }

    private:
        std::string foodName;
        double foodPrice;
        TasteBalance foodTasteBalance;
    };
    class Menu {
    private:
        std::vector<std::vector<std::shared_ptr<MenuItem>>> menu;
        double totalCostMenu = 0;
        TasteBalance chosenMenuTasteBalance;

    public:
        void addMenuItem(int type, std::shared_ptr<MenuItem> item) {
            if (type >= 0 && type < NUM_DISH_TYPES) {
                menu[type].push_back(item);
            }
        }

        const std::vector<std::vector<std::shared_ptr<MenuItem>>>& getMenu() const {
            return menu;
        }
    };
    class User : public Menu {
    public:
        std::string name;
        std::string surname;
        Gender gender;
        std::string chosenMenu;
    };
    class Starter : public MenuItem {
    private:
        Ishot isHot;

    public:
        Starter(std::string foodName, double foodPrice, TasteBalance foodTasteBalance)
            : MenuItem(foodName, foodPrice, foodTasteBalance) {}
        void display() const override {
            std::cout << "Starter: " << getFoodName() << ", Price: " << getFoodPrice() << std::endl;
        }
    };
    class Salad : public MenuItem {
    public:
        Salad(std::string foodName, double foodPrice, TasteBalance foodTasteBalance)
            : MenuItem(foodName, foodPrice, foodTasteBalance) {}
        void display() const override {
            std::cout << "Salad: " << getFoodName() << ", Price: " << getFoodPrice() << std::endl;
        }
    };
    class MainCourse : public MenuItem {
    public:
        MainCourse(std::string foodName, double foodPrice, TasteBalance foodTasteBalance)
            : MenuItem(foodName, foodPrice, foodTasteBalance) {}
        void display() const override {
            std::cout << "Main Course: " << getFoodName() << ", Price: " << getFoodPrice() << std::endl;
        }
    };
    class Drink : public MenuItem {
    public:
        Drink(std::string foodName, double foodPrice, TasteBalance foodTasteBalance)
            : MenuItem(foodName, foodPrice, foodTasteBalance) {}
        void display() const override {
            std::cout << "Drink: " << getFoodName() << ", Price: " << getFoodPrice() << std::endl;
        }
    };
    class Appetizer : public MenuItem {
    public:
        Appetizer(std::string foodName, double foodPrice, TasteBalance foodTasteBalance)
            : MenuItem(foodName, foodPrice, foodTasteBalance) {}
        void display() const override {
            std::cout << "Appetizer: " << getFoodName() << ", Price: " << getFoodPrice() << std::endl;
        }
    };
    class Dessert : public MenuItem {
    public:
        bool isHot;
        Dessert(std::string foodName, double foodPrice, TasteBalance foodTasteBalance)
            : MenuItem(foodName, foodPrice, foodTasteBalance) {}
        void display() const override {
            std::cout << "Dessert: " << getFoodName() << ", Price: " << getFoodPrice() << std::endl;
        }
    };
}