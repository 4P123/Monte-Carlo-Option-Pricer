
#include "option.hpp"

#include <cassert>
#include <cmath>
#include <iostream>
#include <stdexcept>

bool approximately_equal(double a, double b) {
    return std::abs(a - b) < 1e-10;
}

int main() {
    const Option call{OptionType::Call, 100.0};
    const Option put{OptionType::Put, 100.0};

    // Call: in-the-money
    assert(approximately_equal(payoff(call, 110.0), 10.0));

    // Call: out-of-the-money
    assert(approximately_equal(payoff(call, 90.0), 0.0));

    // Call: at-the-money
    assert(approximately_equal(payoff(call, 100.0), 0.0));

    // Put: in-the-money
    assert(approximately_equal(payoff(put, 90.0), 10.0));

    // Put: out-of-the-money
    assert(approximately_equal(payoff(put, 110.0), 0.0));

    // Put: at-the-money
    assert(approximately_equal(payoff(put, 100.0), 0.0));

    // Invalid underlying price
    bool threw = false;

    try {
        payoff(call, -1.0);
    } catch (const std::invalid_argument&) {
        threw = true;
    }

    assert(threw);

    std::cout << "All option tests passed.\n";
    return 0;
}
