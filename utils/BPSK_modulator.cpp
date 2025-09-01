#include "header.h"

std::vector<std::complex<double>> bpsk_modulate(const std::vector<int> &bits)
{
    std::vector<std::complex<double>> result;
    for (int bit : bits)
    {
        Complex s(bit == 0 ? 1 : -1, 0);
        result.push_back(s);
    }

    return result;
}

std::vector<int> bpsk_demodulate(const std::vector<std::complex<double>> &symbols)
{
    std::vector<int> result;
    for (const auto& symbol : symbols)
        result.push_back(symbol.real() < 0 ? 1 : 0);
    
    return result;
}