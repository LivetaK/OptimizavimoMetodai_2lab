#include "funkcijos.h"


vector<double> gradientas(vector<double> taskas) {
	double x1 = taskas[0];
	double x2 = taskas[1];
	vector<double> fGrad = { 
		-1.0 / 8 * (x2 - 2 * x1 * x2 - x2 * x2),
		-1.0 / 8 * (x1 - x1 * x1 - 2 * x1 * x2) };
	return fGrad;
}
bool hesse(vector<double> taskas) {
	double x1 = taskas[0], x2 = taskas[1];
	double a = (1.0 / 4 * x2);
	double b = -1.0 / 8 * (1 - 2 * x1 - 2 * x2);
	double c = (1.0 / 4 * x1);
	double D = a * c - b * b;
	return (D > 0 && a > 0);
}
 double gama(const vector<double>& taskas) {
	 double x1 = taskas[0], x2 = taskas[1];
	 double a = (1.0 / 4) * x2;
	 double b = -1.0 / 8 * (1 - 2 * x1 - 2 * x2);
	 double c = (1.0 / 4) * x1;

	 double lambda = (a + c + sqrt((a - c) * (a - c) + 4 * b * b)) / 2;

	 if (fabs(lambda) < 1e-10) {
		 return 0.1;
	 }

	 return 1.0 / lambda;
 }

void gradientinisNusileidimas(vector<double> pradT) {
	vector<vector<double>> visiTaskai;
	visiTaskai.push_back(pradT);
	vector<double> grad = gradientas(pradT);
	const double epsilon = 1e-6;
	double pradGama = 1;
	int i = 0;
	while (fabs(grad[0]) > epsilon || fabs(grad[1]) > epsilon) {
		double gamma = gama(visiTaskai.back());
		vector<double> naujasTaskas = {
					visiTaskai.back()[0] - gamma * grad[0],
					visiTaskai.back()[1] - gamma * grad[1]
		};
		visiTaskai.push_back(naujasTaskas);
		grad = gradientas(naujasTaskas);
		i++;
	}
	if (hesse(visiTaskai.back()) == true) {
		cout << "Gradientinio nusileidimo minimumo taskas: " << visiTaskai.back()[0] << "  " << visiTaskai.back()[1] << endl;
		cout << "Iteraciju skaicius: " << i << endl;
	}
	else {
		cout << "blogai" << endl;
	}
}