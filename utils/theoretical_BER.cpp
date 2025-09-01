#include "header.h"

double theoreticalBER_SISO(double SNRdB)
{
    double snr_times = pow(10, SNRdB / 10);
    return 0.5 * (1 - sqrt(snr_times / (1 + snr_times)));
}

double theoreticalBER_Alamouti(double SNRdB)
{
    double p = 0.5 - 0.5 * pow(1 + 2/SNRdB, -0.5);
    return p * p * round(1 + 2 * (1 - p));
}
