#include <iostream>

using namespace std;

template <typename T>
class myVector {
private:
    T* data_;
    size_t capacity_;
    size_t size_;

public:
    myVector(T* data = nullptr, size_t capacity = 0, size_t size = 0) :
        data_(data), capacity_(capacity), size_(size) {
        cout << "constr" << endl;
    }

};

int main() {

    myVector<int> v1;  //default const
    myVector<int> v2 = { 1,3,5 };  //copy constr with initializer list
    myVector<int> v3(5); //create a 5 element vector and init to 0
    myVector<int> v4 = v3;  // copy constructor
    myVector<int> v5 = move(v3); // move const

    v2 = v5;  // assignment operator overload
    v2 = move(v4); // move assignment

    cout << "size is " << v4.size() << endl;

    myVector v6(itr1, itr2);//copy from beg and end iter

    v1.push_back(4);

    cout << v1.pop_back() << endl;







}