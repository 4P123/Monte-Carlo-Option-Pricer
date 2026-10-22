#pragma once

enum class OptionType {
	Call,
	Put
};

struct Option {
	OptionType type;
	double strike;
};

double payoff(const Option& option, double underlying_price);
