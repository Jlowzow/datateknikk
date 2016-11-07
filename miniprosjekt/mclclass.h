#ifndef GUARD_mcl_h
#define GUARD_mcl_h

#include <vector>
#include <functional>

double kart(double);
double pdf(double,double,double);

class mcLokaliserer{
	double sensorSD;
	std::vector<double> partikler;
	std::vector<double> vekter;
	std::vector<double> nyePartikler;
public:
	mcLokaliserer(int, double, double);
	std::vector<double> getPartikler();
	std::vector<double> getVekter();
	void resample();
	void oppdaterVekter(double forventning);
	void oppdaterVekter(double, std::function<double(double)>);
	void oppdaterPartikler(double bevegelse);
};

#endif
