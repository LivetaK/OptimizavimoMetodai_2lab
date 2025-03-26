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