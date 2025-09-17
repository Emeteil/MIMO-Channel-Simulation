# MIMO BER Simulator

A C++ implementation of a Monte Carlo simulation to analyze the Bit Error Rate (BER) performance of a 2x2 MIMO system with Zero-Forcing equalization over a Rayleigh fading channel.

## 📖 Overview

This project simulates a complete digital communication chain for a 2x2 MIMO system. It generates random bits, modulates them using BPSK, transmits them through a simulated Rayleigh fading channel with AWGN, performs Zero-Forcing equalization to combat interference, and demodulates the signal. The core output is the calculated Bit Error Rate across a range of SNR values, which is compared to the theoretical BER for a SISO system for baseline performance understanding.

## 🧩 Key Features (Implemented)

*   **Bit Generation:** Creates random sequences of bits for transmission.
*   **Modulation:** Binary Phase-Shift Keying (BPSK).
*   **Channel Model:** Models a 2x2 MIMO channel with:
    *   **Rayleigh Fading:** Complex channel coefficients generated as `CN(0, 1)`.
    *   **Additive White Gaussian Noise (AWGN):** Added with power calculated from the SNR.
*   **Equalization:** Zero-Forcing (ZF) receiver to invert the channel effect.
*   **Demodulation:** Converts equalized symbols back to bits.
*   **Analysis:** Monte Carlo simulation for accurate BER calculation across a specified range of SNR values.
*   **Theoretical Comparison:** Outputs the theoretical BER for a SISO AWGN channel for reference.

## 🚀 Getting Started

### Prerequisites
- g++ (GNU C++ Compiler)
- cmake (build system)

**Ubuntu/Debian:**
```bash
sudo apt update
sudo apt install -y g++ cmake
```

### Compilation and Running
```bash
# Clone the repository
git clone https://github.com/your-username/MIMO-BER-Simulator.git
cd MIMO-BER-Simulator

# Compile and run using the provided script
chmod +x start.sh
./start.sh

# Or compile and run manually
mkdir -p build
cd build
cmake ..
make
./a.out
```

## 📊 Output

The program outputs BER values for each SNR point for the 2x2 MIMO ZF system, alongside the theoretical SISO BER for comparison. The results are printed to the console in a format that can be easily plotted (e.g., using Python's matplotlib, GNUplot) to visualize the performance of the MIMO system.
Example output:
```
SNR_DB: 0
BER: 0.120663
theoreticalBER_SISO: 0.146447

SNR_DB: 1
BER: 0.132028
theoreticalBER_SISO: 0.126733

SNR_DB: 5
BER: 0.09078
theoreticalBER_SISO: 0.0641827

SNR_DB: 10
BER: 0.0176967
theoreticalBER_SISO: 0.0232687

SNR_DB: 15
BER: 0.000495
theoreticalBER_SISO: 0.007723

SNR_DB: 20
BER: 1.16667e-05
theoreticalBER_SISO: 0.0024814
```

## 🏗️ Implementation Details

### Project structure
```
.
├── CMakeLists.txt          # CMake build configuration
├── main.cpp                # Main simulation loop and logic
├── header.h                # Common header with declarations
├── start.sh                # Helper build & run script
└── utils/                  # Directory with source files
    ├── bit_generator.cpp   # Generates random bits (generate_bits)
    ├── BPSK_modulator.cpp  # BPSK modulation/demodulation
    ├── channel_generator.cpp # Generates Rayleigh channel matrix
    ├── mimo_channel.cpp    # Applies channel model (H*X + N)
    ├── demodulation.cpp    # Zero-Forcing equalization (inverseMatrix, zf_demodulate)
    ├── calculation_BER.cpp # Calculates Bit Error Rate
    └── theoretical_BER.cpp # Theoretical BER formulas
```

### Implementation Details

1.  **Channel Model (2x2 MIMO):** Implemented strictly according to the formula `Y = H * X + N` in the `mimo_channel` function.
    *   `H` is a 2x2 channel matrix where each element `h_ij` is an independent complex random variable `CN(0, 1)`.
    *   `X` is the vector of transmitted symbols (BPSK: +1, -1). Symbols are transmitted in pairs: `[s1, s2]` for the first and second antennas.
    *   `N` is the vector of additive white Gaussian noise `CN(0, σ²)`, where the noise power `σ²` is calculated from the given SNR.

2.  **Zero-Forcing Demodulation:** Implemented via explicit computation of the inverse matrix for the 2x2 system in the `inverse_matrix` function.
    *   For a pair of received symbols `[y1, y2]`, the estimated transmitted symbols are calculated as `X_hat = H^{-1} * Y`.
    *   This is the exact solution to the system of equations `Y = H * X` in the absence of noise.

3.  **Monte Carlo Method:** The main loop in `main.cpp` runs `NUM_LOOPS` trials for each SNR value. In each trial, new bits and a new channel realization `H` are generated, allowing for an averaged estimate of the BER.

## 📚 Theoretical Background

The simulation models key wireless concepts:
*   **Rayleigh Fading:** Represents multipath signal propagation in an environment without a dominant line-of-sight path. Implemented as complex Gaussian channel coefficients.
*   **Zero-Forcing Equalizer:** A linear detection method that inverts the channel response to recover transmitted symbols. It effectively eliminates inter-antenna interference at the cost of potentially amplifying noise.
*   **Theoretical BER for SISO:** The formula `0.5 * (1 - sqrt(SNR/(1+SNR)))` provides a benchmark for the best possible performance in a single-antenna system without fading.
