
#include "option.hpp"

#include <iostream>

int main() {
    const Option call{OptionType::Call, 100.0};
    const Option put{OptionType::Put, 100.0};

    const double spot = 110.0;

    std::cout << "Call payoff: "
              << payoff(call, spot) << '\n';

    std::cout << "Put payoff: "
              << payoff(put, spot) << '\n';

    return 0;
}

