#include "funkcijos.h"


vector<double> gradientas(vector<double> taskas) {
	double x1 = taskas[0];
	double x2 = taskas[1];
	vector<double> fGrad = { -1.0 / 8 * (x2 - 2 * x1 * x2 - x2 * x2), -1.0 / 8 * (x1 - x1 * x1 - 2 * x1 * x2) };
	return fGrad;
}
 bool hesse(vector<double> taskas) {
	 double x1 = taskas[0];
	 double x2 = taskas[1];
	 double a = (1.0 / 4 * x2);
	 double D = a * (1.0 / 4 * x1) - (-1.0 / 8 * (1 - 2 * x1 - 2 * x2) * (-1.0 / 8 * (1 - 2 * x1 - 2 * x2)));
	 if (D > 0 && a > 0) return true;
	 else return false;
}

void gradientinisNusileidimas(vector<double> pradT) {
	vector<vector<double>> visiTaskai;
	visiTaskai.push_back(pradT);
	vector<double> grad = gradientas(pradT);
	const double epsilon = 1e-6;
	int i = 0;
	while (fabs(grad[0]) > epsilon || fabs(grad[1]) > epsilon) {
		vector<double> naujasTaskas = {
					visiTaskai.back()[0] - 0.125 * grad[0],
					visiTaskai.back()[1] - 0.125 * grad[1]
		};
		visiTaskai.push_back(naujasTaskas);
		grad = gradientas(naujasTaskas);
		i++;
	}
	if (hesse(visiTaskai.back()) == true) {
		cout << "Gradientinio nusileidimo minimumo taskas: " << visiTaskai.back()[0] << "  " << visiTaskai.back()[1] << endl;

	}
	else {
		cout << "blogai" << endl;
	}
}