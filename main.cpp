#include "header.h"

#define DEBUG false

int main()
{
    const std::vector<double> snt_db_list{0, 1, 5, 10, 15, 20};
    const int NUM_BITS = 30000;
    const int NUM_LOOPS = 10;

    for (auto snr_db : snt_db_list)
    {
        double ber = 0;
        std::cout << "SNR_DB: " << snr_db << std::endl;
        for (int i = 0; i < NUM_LOOPS; i++)
        {
            std::vector<int> original_bits = generate_bits(2 * NUM_BITS);
            if (DEBUG) print_vector("Original bits", original_bits);

            std::vector<std::complex<double>> symbols = bpsk_modulate(original_bits);

            auto h_mimo = generate_channel_matrix();

            std::vector<std::complex<double>> Y = mimo_channel(symbols, h_mimo, snr_db);
            if (DEBUG) print_vector("MIMO channel", Y);

            auto X_restored = zf_demodulate(Y, h_mimo);
            if (DEBUG) print_vector("X_restored", X_restored);

            std::vector<int> received_bits = bpsk_demodulate(X_restored);
            if (DEBUG) print_vector("Received bits", received_bits);

            ber += calculate_ber(original_bits, received_bits);
        }
        std::cout << "BER: " << ber / NUM_LOOPS << std::endl;
        std::cout << "theoreticalBER_SISO: " << theoreticalBER_SISO(snr_db) << std::endl;
        std::cout << std::endl;
    }
}