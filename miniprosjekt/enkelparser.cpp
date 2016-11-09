#include "exprtk.hpp"
#include <string>
#include <iostream>

using namespace std;

class enkelParser{
	double x;
	double y;
	exprtk::symbol_table<double> symbolTabell;
	exprtk::expression<double>	exp;
	exprtk::parser<double>		pars;

public:
	enkelParser();
	double parsString(string exp_string, double X);
};

enkelParser::enkelParser(){


	symbolTabell.add_variable("x",x);
	symbolTabell.add_constants();

	exp.register_symbol_table(symbolTabell);

}
double enkelParser::parsString(string exp_string, double X){
	pars.compile(exp_string, exp);

	x = X;
	y = exp.value();

	double r = y;


	return y;
}
