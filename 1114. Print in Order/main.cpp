#include <iostream>
#include <vector>
#include <thread>
#include <future>

using namespace std;

class Foo {
private:
    promise<void> p1, p2;
public:
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        printFirst();
        p1.set_value();
    }

    void second(function<void()> printSecond) {
        p1.get_future().wait();
        printSecond();
        p2.set_value();
    }

    void third(function<void()> printThird) {
        p2.get_future().wait();
        printThird();
    }
};

int main()
{
    vector<int> a = {1,2,3};
    Foo obj;
    
    thread t1(&Foo::first, &obj, [](){cout << "first";});
    thread t2(&Foo::first, &obj, [](){cout << "second";});
    thread t3(&Foo::first, &obj, [](){cout << "third" << endl;});

    for(int x : a) {
        if(x == 1) t1.join();
        if(x == 2) t2.join();
        if(x == 3) t3.join();
    }
    
    return 0;
}