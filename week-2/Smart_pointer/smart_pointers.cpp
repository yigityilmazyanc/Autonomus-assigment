#include <iostream>
#include <memory>

template <class T> class SmartPointer {
    T* ptr; 
public:
    SmartPointer(T* p = nullptr) { ptr = p; }

    ~SmartPointer() { delete (ptr); }
   
    T& operator*() { return *ptr; }

    T* operator->() { return ptr; }

    T* get() const { return ptr; }

    void reset(T* p) { delete ptr; ptr = p; }
};

int main()
{
    SmartPointer<int> sp(new int(10));
    std::cout << "Value of sp: " << *sp << std::endl;
    std::cout << "Address of sp: " << sp.get() << std::endl;

    sp.reset(new int(20));
    std::cout << "Value of sp: " << *sp << std::endl;
    std::cout << "Address of sp: " << sp.get() << std::endl;

    std::auto_ptr<int> autoPtr = std::auto_ptr<int>(new int(10));
    std::cout << "Address of autoPtr: " << autoPtr.get() << std::endl;

    std::auto_ptr<int> autoPtr2 = std::move(autoPtr);
    std::cout << "After using move(), address of autoPtr: " << autoPtr.get() << std::endl;
    std::cout << "Address of autoPtr2: " << autoPtr2.get() << std::endl;

    std::unique_ptr<int> uniquePtr(new int(40));
    std::cout << "Address of uniquePtr: " << uniquePtr.get() << std::endl;

    std::unique_ptr<int> uniquePtr2 = std::move(uniquePtr);
    std::cout << "After using move(), address of uniquePtr: " << uniquePtr.get() << std::endl;
    std::cout << "Address of uniquePtr2: " << uniquePtr2.get() << std::endl;

    std::shared_ptr<int> sharedPtr1 = std::make_shared<int>(50);
    std::cout << "Address of sharedPtr1: " << sharedPtr1.get() << std::endl;
    std::cout << "use_count of sharedPtr1: " << sharedPtr1.use_count() << std::endl;

    std::shared_ptr<int> sharedPtr2 = sharedPtr1;
    std::cout << "After sharing, address of sharedPtr2: " << sharedPtr2.get() << std::endl;
    std::cout << "use_count of sharedPtr1: " << sharedPtr1.use_count() << std::endl;
    std::cout << "use_count of sharedPtr2: " << sharedPtr2.use_count() << std::endl;

    sharedPtr1.reset(new int(60));
    std::cout << "After reset, address of sharedPtr1: " << sharedPtr1.get() << std::endl;
    std::cout << "use_count of sharedPtr1: " << sharedPtr1.use_count() << std::endl;
    std::cout << "use_count of sharedPtr2: " << sharedPtr2.use_count() << std::endl;

    return 0;
}