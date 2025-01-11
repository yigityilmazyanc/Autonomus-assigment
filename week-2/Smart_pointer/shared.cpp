#include <iostream>
#include <memory>
class Y{
    public:
    void show(){std::cout << "Y::show()" << std::endl;}
};

int main(){
    std::shared_ptr<Y> p1(new Y);
    p1->show();
    std::cout << p1.get() << std::endl;
    std::shared_ptr<Y> p2(p1);
    p2->show();
    std::cout << p1.get() << std::endl;
    std::cout << p2.get() << std::endl;

    return 0;
}