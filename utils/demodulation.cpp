#include "header.h"

std::array<std::array<std::complex<double>, 2>, 2> inverse_matrix(const std::array<std::array<std::complex<double>, 2>, 2> &matrix)
{
    std::complex<double> det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

    std::array<std::array<std::complex<double>, 2>, 2> result;
    result[0][0] = matrix[1][1] / det;
    result[0][1] = -matrix[0][1] / det;
    result[1][0] = -matrix[1][0] / det;
    result[1][1] = matrix[0][0] / det;

    return result;
}

std::vector<std::complex<double>> zf_demodulate(
    const std::vector<std::complex<double>> &mimoY,
    const std::array<std::array<std::complex<double>, 2>, 2> &h_mimo)
{
    auto h_mimo_r = inverse_matrix(h_mimo);

    std::vector<std::complex<double>> result;
    for (int i = 0; i < mimoY.size() - 1; i+=2)
    {
        // H^(-1) * Y (X = H^(-1) * Y)
        result.push_back(h_mimo_r[0][0] * mimoY[i] + h_mimo_r[0][1] * mimoY[i + 1]);
        result.push_back(h_mimo_r[1][0] * mimoY[i] + h_mimo_r[1][1] * mimoY[i + 1]);
    }
    if (mimoY.size() % 2 != 0)
        result.push_back(mimoY.back());

    return result;
}