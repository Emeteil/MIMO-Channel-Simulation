#include <iostream>
#include <random>
#include <complex>
#include <vector>
#include <array>

using Complex = std::complex<double>;

template <typename T>
void print_vector(std::string display, std::vector<T> &_vector)
{
    std::cout << display << ": ";
    for (const T& element : _vector)
        std::cout << element << " ";
    std::cout << std::endl;
}

int generate_random_bit();
std::vector<int> generate_bits(int num_bits);

std::vector<std::complex<double>> bpsk_modulate(const std::vector<int> &bits);
std::vector<int> bpsk_demodulate(const std::vector<std::complex<double>> &symbols);

std::complex <double> generate_channel_gain();
std::array<std::array<std::complex<double>, 2>, 2> generate_channel_matrix();

std::vector<std::complex<double>> mimo_channel(
    const std::vector<std::complex<double>> &mimo_symbols,
    const std::array<std::array<std::complex<double>, 2>, 2> &h_mimo,
    const double &SNR);

std::array<std::array<std::complex<double>, 2>, 2> inverseMatrix(const std::array<std::array<std::complex<double>, 2>, 2>& matrix);
std::vector<std::complex<double>> zf_demodulate(
    const std::vector<std::complex<double>> &mimoY,
    const std::array<std::array<std::complex<double>, 2>, 2> &h_mimo);

double calculate_ber(const std::vector<int> &original, const std::vector<int> &received);
double theoreticalBER_SISO(double SNRdB);
double theoreticalBER_Alamouti(double SNRdB);