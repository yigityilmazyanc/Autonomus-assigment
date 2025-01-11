#include <iostream>
#include <memory>

class Y{
    public:
    void show(){std::cout << "Y::show()" << std::endl;}
};

int main(){
    std::unique_ptr<Y> p1(new Y);
    p1->show();
    std::cout << p1.get() << std::endl;
    std::unique_ptr<Y> p2(std::move(p1));
    p2->show();
    std::cout << p1.get() << std::endl;
    std::cout << p2.get() << std::endl;
    
}

