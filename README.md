# Monte-Carlo-Optional-Pricer

# Monte Carlo Option Pricer

A C++17 project for pricing European options using
Monte Carlo simulation.

## Current Features

- European Call and Put payoff calculation
- Input validation
- CMake build system
- Basic unit tests

## Requirements

- C++17 compiler
- CMake 3.16+
- Git

## Build

```bash
cmake -S . -B build
cmake --build build
```

## Run

```bash
./build/option_pricer_cli
```

## Test

```bash
ctest --test-dir build --output-on-failure
```

## Roadmap

- [ ] European option payoff
- [ ] Black-Scholes analytical pricing
- [ ] Monte Carlo pricing engine
- [ ] Standard error and confidence interval
- [ ] Convergence experiments
- [ ] Performance benchmarks
