#include <iostream>
#include <vector>
#include <algorithm>

template <typename T> void printContainer(const T &cnt) {
    for (auto i : cnt) {
         std::cout << i << " ";
     }
    std::cout << '\n' << "Capacity: " << cnt.capacity() << std::endl;;
 }

template <typename T>
void insert_sorted(std::vector<T> &v, const T &i) {
    v.insert(lower_bound(v.begin(), v.end(), i), i);
    v.shrink_to_fit();
}

int main() {
    using MyType = double;
    std::vector<MyType> MyVec = {10, 20, 30, 40, 50, 60, 70};
    MyType MyNum = 35.5;
    printContainer(MyVec);
    insert_sorted(MyVec, MyNum);
    printContainer(MyVec);
    return 0;
}
