#include <iostream>
#include <vector>
#include <algorithm>

template <typename T> void printContainer(const T &cnt) {
    std::cout << "Capacity: " << cnt.capacity() << std::endl;
    for (auto i : cnt) {
         std::cout << i << " ";
     }
     std::cout << std::endl;
 }

template <typename T>
void insert_sorted(std::vector<T> &v, const T &i) {
    sort(v.begin(), v.end());
    std::vector<int>::iterator low;
    low = lower_bound(v.begin(), v.end(), i);
    std::cout << "insert new data to position: " << (low - v.begin()) << std::endl;
    v.insert(low, i);
    v.shrink_to_fit();
}

int main() {
    using MyType = int;
    std::vector<MyType> MyVec = {10, 20, 30, 40, 50, 60, 70};
    MyType MyInt = 35;
    printContainer(MyVec);
    insert_sorted(MyVec, MyInt);
    printContainer(MyVec);
    return 0;
}
