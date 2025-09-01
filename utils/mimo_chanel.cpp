#include "header.h"

std::vector<std::complex<double>> mimo_channel(
    const std::vector<std::complex<double>> &mimo_symbols,
    const std::array<std::array<std::complex<double>, 2>, 2> &h_mimo,
    const double &SNR)
{
    double snr_times = pow(10, SNR / 10);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<double> dis (0, 1 / sqrt(2));

    std::vector<std::complex<double>> result;
    for (int i = 0; i < mimo_symbols.size() - 1; i+=2)
    {
        // h_mimo * mimo_symbols (Y = HX + N)

        auto noise1 = sqrt(1 / snr_times) * std::complex<double>(dis(gen), dis(gen));
        auto noise2 = sqrt(1 / snr_times) * std::complex<double>(dis(gen), dis(gen));

        result.push_back(h_mimo[0][0] * mimo_symbols[i] + h_mimo[0][1] * mimo_symbols[i + 1] + noise1);
        result.push_back(h_mimo[1][0] * mimo_symbols[i] + h_mimo[1][1] * mimo_symbols[i + 1] + noise2);
    }
    if (mimo_symbols.size() % 2 != 0)
        result.push_back(mimo_symbols.back());

    return result;
}