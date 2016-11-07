#include <vector>
#include <iostream>
#include <random> //må kompileres med c++11
#include <cmath>
#include "arrayHjelp.h"
#include <functional> // Muliggjør funksjoner som argument


using namespace std;

double kart(double);
double pdf(double,double,double);

class mcLokaliserer {
	double sensorSD;
	vector<double> partikler;
	vector<double> vekter;
	vector<double> nyePartikler;
public:
	mcLokaliserer(int, double, double);
	vector<double> getPartikler();
	vector<double> getVekter();
	void resample();
	void oppdaterVekter(double forventning);
	void oppdaterVekter(double, function<double(double)>);
	void oppdaterPartikler(double bevegelse);
};
//Konstruktøren lager n hypoteser normalfordelt rundt anslag
mcLokaliserer::mcLokaliserer(int n, double anslag, double sd){
	sensorSD = sd;
	default_random_engine generator;
	normal_distribution<double> dist(anslag, anslag/2); //definert i c++11

	for(int i = 0; i < n; i++){
		double nummer = dist(generator);
		partikler.push_back(nummer);
		vekter.push_back(0);
		nyePartikler.push_back(0);
	}
}
void mcLokaliserer::resample(){
	double sumAvVekter;
	for(double d : vekter){
		sumAvVekter += d;
	}
	default_random_engine gen;
	uniform_real_distribution<double> dist(0,sumAvVekter);

	for(int i = 0; i < partikler.size(); i++){
		double rnd = dist(gen);
		for(int j = 0; j < partikler.size(); j++){
			if(rnd < vekter[j]){
				nyePartikler[i] = partikler[j];
			//	cout << "winner!: " << nyePartikler[i] << "Vektet: " << vekter[j] << endl;
				break;
			}
			rnd = rnd - vekter[j];
		}
	}
	partikler = nyePartikler;
}
	// Når farkosten beveger seg følger partiklene etter, Støy er lagt til for
	// å simulere usikkerhet i hvor stor hastigheten faktisk er.
void mcLokaliserer::oppdaterPartikler(double bevegelse){
	for(int i = 0; i < partikler.size(); i++){
		partikler[i] = partikler[i] + bevegelse + 5*((double)rand()/RAND_MAX - 0.5);
	}
}

vector<double> mcLokaliserer::getPartikler(){
	return partikler;
}
vector<double> mcLokaliserer::getVekter(){
	return vekter;
}
// Funksjonen skal gi vekter til partiklerne utifra hvor sannsynlig
// målingen er oppmot hvor partikkelen befinner seg. Vi tar utgangspunkt i at 
// sensoren er unøyaktig med kjent standardavvik. Vekten blir lik sannsynligheten
// for målingen i en normalfordeling, med kjent standardavvik.
void mcLokaliserer::oppdaterVekter(double forventning){
	for(int i = 0; i < partikler.size(); i++){
		vekter[i] = pdf(kart(partikler[i]), forventning, sensorSD);
	}
}
void mcLokaliserer::oppdaterVekter(double forventning, function<double(double)> k)
{
	for(int i = 0; i < partikler.size(); i++){
		vekter[i] = pdf(k(partikler[i]), forventning, sensorSD);
	}
}

double kart(double x){
		return 100 * (sin(x / 100) + cos(x / 50));
}

double pdf(double x, double my, double var){
	double pi = acos(-1.0);
	double y = (1 / (sqrt(2 * pi) * sqrt(var))) * exp( -1 * (pow((x-my),2)/(2*var)));
	return y;
}

/*
int main(){
	double sensorStandardAvvik = 2.3;
	int x = 50;
	int partikler = 200;
	int v = 5;
	mcLokaliserer mcl(partikler, x, sensorStandardAvvik);
	for(int i = 0; i < 200; i++){
		cout << "Syklus, x= " << x << endl;
		mcl.oppdaterVekter(kart(x));
		vector<double> partikler = mcl.getPartikler();
		vector<double> vekter = mcl.getVekter();
		
		for(int i = 0; i < partikler.size(); i++){
			cout << partikler[i] << " " << vekter[i] << endl;
		}
		mcl.resample();
		mcl.oppdaterPartikler(v);
		x = x + v;
		
	}
}
*/
