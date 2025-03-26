#include <iostream>
#include <vector>
#include "funkcijos.h"

using std::vector;

int main()
{
	//double a = 0;
	//double b = 0;
	//double c = 0;
	//double x1 = 2 * a * b;
	//double x2 = 2 * a * c;
	//double x3 = 2 * c * b;
	//double v2 = 1 / 8 * x1 * x2 * x3;
	//double f = 1 / 8 * (x1 * x2 - x1 * x1 * x2 - x1 * x2 * x2);
	//vector<double> fGrad = { -1.0 / 8 * (x2 - 2 * x1 * x2 - x2 * x2), -1.0 / 8 * (x1 - x1 * x1 - 2 * x1 * x2) };
	double pradinisT1 = 0.7, pradinisT2 = 0.3;

	/*if (salygosTikrinimas(pradinisT1, pradinisT2)) {
		return 1;
	}*/
	vector<double> pradinisTaskas = { pradinisT1, pradinisT2 };

	gradientinisNusileidimas(pradinisTaskas);
	greiciausiasNusileidimas(pradinisTaskas);
}
