#include <iostream>
#include <memory>

class Y{
    public:
    void show(){std::cout << "Y::show()" << std::endl;}
};

int main(){
    std::shared_ptr<Y> shared = std::make_shared<Y>();
    std::weak_ptr<Y> weak = shared;

    shared->show();
    std::cout << shared.use_count() << std::endl;
    std::cout << weak.use_count() << std::endl;

    if(!weak.expired()){
        std::shared_ptr<Y> shared2 = weak.lock();
        shared2->show();
    }
    else{
        std::cout << "Weak pointer expired!" << std::endl;
    }

    weak.reset();
}