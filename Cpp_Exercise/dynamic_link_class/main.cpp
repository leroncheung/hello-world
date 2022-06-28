#include "calculator.h"

int main() {
    Calculator<int> cal;
    std::cout << cal.add(12, 34) << std::endl;
    std::cout << cal.minus(12, 10) << std::endl;
    std::cout << cal.multiple(2, 5) << std::endl;
    std::cout << cal.divide(15, 5) << std::endl;

    return 0;
}