#include "header.h"

double calculate_ber(const std::vector<int> &original , const std::vector<int> &received)
{
    int error_count = 0;
    for (int i = 0; i < original.size(); i++)
    {
        if (original[i] != received[i])
            error_count++;
    }
    
    return (double)error_count / original.size();
}