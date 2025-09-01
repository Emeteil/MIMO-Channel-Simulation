#include "header.h"

std::complex<double> generate_channel_gain()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<double> dis (0, 1 / sqrt(2));

    return std::complex<double>(dis(gen), dis(gen));
}

std::array<std::array<std::complex<double>, 2>, 2> generate_channel_matrix()
{
    return {{
        {generate_channel_gain(), generate_channel_gain()},
        {generate_channel_gain(), generate_channel_gain()}
    }}; 
}