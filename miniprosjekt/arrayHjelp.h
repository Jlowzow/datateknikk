#ifndef GUARD_arrayHjelp_h
#define GUARD_arrayHjelp_h

#include <vector>

void bytt(double &a, double &b);
void bytt(std::vector<double> & vec,int i,int j);
void sorter(double *x, int n);
void boblesorter(std::vector<double>& vec);
void boblesorter(std::vector<double>& vec, std::vector<double>& kol);
void reverser(double *x, int n);
void differens(const double *a, const double *b, double *diff, int n);
double min(const double*, int&, int n);
double max(const double*, int&, int n);
double max(std::vector<double>&vec);

#endif
