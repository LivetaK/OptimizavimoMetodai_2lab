#pragma once

#include <vector>
#include <iostream>
#include <cmath> 
#include <stdexcept>


using std::vector;
using std::cout;
using std::endl;
using std::fabs;
using std::cerr;

vector<double> antigradientas(vector<double> taskas);
bool hesse(vector<double> taskas);
double gama(const vector<double>& taskas);
void gradientinisNusileidimas(vector<double> pradT);
int salygosTikrinimas(double t1, double t2);
double tiksloF(vector<double> taskas);
void intervaloDalijimasPusiau(vector<double>& xm, vector<double>& x1, vector<double>& x2, vector<double>& r,
	vector<double>& l, vector<double>& L, double& ym);
void greiciausiasNusileidimas(vector<double> pradT);
