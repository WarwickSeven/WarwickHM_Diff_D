#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

int32_t getRandomNum(const int32_t min, const int32_t max) {
    const static auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    static std::mt19937_64 generator(seed);
    std::uniform_int_distribution<int32_t> dis(min, max);
    return dis(generator);
}

template <typename T> void printContainer(const T &cnt) {
    for (auto i : cnt) {
          std::cout << i << " ";
      }
    std::cout << std::endl;
  }

void ADC(const std::vector<double> &v1, std::vector<int> &v2) {
    transform(v1.begin(), v1.end(), v2.begin(), [](double i){ return floor(i);});
}

double ADCdeviatioin(const std::vector<double> &v1, const std::vector<int> &v2) {
    double result = 0;
    for (int i = 0; i < v1.size(); ++i) {
        result += pow((v1[i]-v2[i]),2);
    }
    return result;
}

int main() {
    std::vector<double> aSignal(100);
    std::vector<int> dSignal(aSignal.size());
    generate(aSignal.begin(), aSignal.end(), [](){return (getRandomNum(100, 10000)/100.00);});
    ADC(aSignal, dSignal);
    printContainer(aSignal);
    printContainer(dSignal);
    std::cout << "ADC deviation is: " << ADCdeviatioin(aSignal, dSignal) << std::endl;
}
