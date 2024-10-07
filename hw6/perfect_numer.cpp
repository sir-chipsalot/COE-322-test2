#include <ranges>
#include <iostream>

namespace rng = std::ranges;

int main() {
    int count = 0;

    auto perfect_numbers = rng::views::iota(2, 10000) 
        | rng::views::filter(
            [&count](int num) { 
                int sum = 1;
                for (int i = 2; i * i <= num; ++i) {
                    if (num % i == 0) {
                        sum += i;
                        if (i * i != num) {
                            sum += num / i;
                        }
                    }
                }
                if (sum == num) {
                    count++;
                    return true;
                }
                return false;
            }
        );

    // Output perfect numbers until we find all known ones
    for (int num : perfect_numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl; 
    return 0;
}

