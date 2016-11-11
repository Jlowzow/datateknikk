#ifndef GUARD_enkelParser_h
#define GUARD_enkelParser_h

#include "exprtk.hpp"
#include <string>
class enkelParser{
	double x;
	double y;
	exprtk::symbol_table<double> symbolTabell;
	exprtk::expression<double>  exp;
	exprtk::parser<double>      pars;
 
public:
	enkelParser();
	double parsString(std::string exp_string, double X);
};

#endif
