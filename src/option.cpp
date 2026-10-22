#include "option.hpp"

#include<algorithm>
#include<cmath>
#include<stdexcept>

double payoff(const Option& option, double underlying_price){
	if(!std::isfinite(underlying_price) ||
	   !std::isfinite(option.strike) ||
	   underlying_price < 0.0 ||
	   option.strike <= 0.0) {
	   throw std::invalid_argument("Invalid option parameters");
	}
	switch (option.type) {
	   case OptionType::Call:
		return std::max(underlying_price - option.strike, 0.0);
	   case OptionType::Put:
		return std::max(option.strike - underlying_price, 0.0);
	}
	throw std::invalid_argument("Unknown option type");
}
