#include "header.h"

int generate_random_bit()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis (0, 1);

    return dis(gen);
}

std::vector<int> generate_bits(int num_bits)
{
    std::vector<int> result(num_bits);
    for (int i = 0; i < num_bits; i++)
        result[i] = generate_random_bit();
    
    return result;
}