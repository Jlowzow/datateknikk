#include "signal.h"
#include <math.h>
#include <time.h>
#include <cstdlib>

using namespace std;


double dToRad(double d){
    double rad;
    rad = d *  PI / 180;
    return rad;
}

double noise(double in){
    double out;
    out = in + 0.1 * ((double) rand() / RAND_MAX - 0.5);
    return out;
}
