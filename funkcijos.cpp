#include "funkcijos.h"


vector<double> antigradientas(vector<double> taskas) {
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
	vector<double> grad = antigradientas(pradT);
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
		grad = antigradientas(naujasTaskas);
		i++;
	}// nereikia tikrinti su hesse matrica
	if (hesse(visiTaskai.back()) == true) {
		cout << "Gradientinio nusileidimo minimumo taskas: " << visiTaskai.back()[0] << "  " << visiTaskai.back()[1] << endl;
		cout << "Iteraciju skaicius: " << i << endl;
	}
	else {
		cout << "Minimumas nebuvo rastas" << endl;
	}
}

int salygosTikrinimas(double t1, double t2) {
	const double minimalusPlotas = 1e-6;
	const double maksimalusPlotas = 1.0 - 1e-6;

	if (t1 < minimalusPlotas || t2 < minimalusPlotas) {
		cerr << "Per mazas pavirsiaus plotas";
		return 1;
	}
	if (t1 >= maksimalusPlotas || t2 >= maksimalusPlotas) {
		cerr << "Pavirsiaus plotas per didelis";
		return 1;
	}
}

double tiksloF(vector<double> taskas) {
	double x1 = taskas[0];
	double x2 = taskas[1];
	double f = 1 / 8 * (x1 * x2 - x1 * x1 * x2 - x1 * x2 * x2);
	return f;
}


//void intervaloDalijimasPusiau(vector<double>& xm, vector<double>& x1, vector<double>& x2, vector<double>& r,
//	vector<double>& l, vector<double>& L, double& ym) {
//
//	double y1 = tiksloF(l);
//	double y2 = tiksloF(r);
//
//	if (y1 < ym) {
//		r = xm;
//		xm = x1;
//		ym = y1;
//	}
//	else if (y2 < ym) {
//		l = xm;
//		xm = x2;
//		ym = y2;
//	}
//	else {
//		l = x1;
//		r = x2;
//	}
//	x1 = {
//		(xm[0] + l[0]) / 2,
//		(xm[1] + l[1]) / 2
//	};
//	x2 = {
//		(r[0] + xm[0]) / 2,
//		(r[1] + xm[1]) / 2
//	};
//	L = {
//		r[0] - l[0],
//		r[1] - l[1]
//	};
//}
//
//void greiciausiasNusileidimas(vector<double> pradT) {
//	vector<vector<double>> visiTaskai;
//	visiTaskai.push_back(pradT);
//	vector<double> grad = antigradientas(pradT);
//	const double epsilon = 1e-6;
//	int i = 0;
//
//	vector<double> l = { 0.0, 0.0 }, r = { 1.0, 1.0 };
//	vector<double> L = {
//		r[0] - l[0],
//		r[1] - l[1]
//	};
//	vector<double> middle = {
//		(r[0] - l[0]) / 2,
//		(r[1] - l[1]) / 2
//	};
//	vector<double> alpha1{
//		(middle[0] - l[0]) / 2,
//		(middle[1] - l[1]) / 2
//	};
//	vector<double> alpha2{
//		(r[0] - middle[0]) / 2,
//		(r[1] - middle[1]) / 2
//	};
//	double middley = tiksloF(middle);
//	vector<double> gamma = { 10, 10 };
//
//
//	while (gamma[0] > epsilon || gamma[1] > epsilon) {
//		intervaloDalijimasPusiau(middle, alpha1, alpha2, r, l, L, middley);
//		gamma = alpha1;
//	}
//	while (fabs(grad[0]) > epsilon || fabs(grad[1]) > epsilon) {
//
//		vector<double> naujasTaskas = {
//					visiTaskai.back()[0] - gamma[0] * grad[0],
//					visiTaskai.back()[1] - gamma[0] * grad[1]
//		};
//		visiTaskai.push_back(naujasTaskas);
//		grad = antigradientas(naujasTaskas);
//		i++;
//	}
//	if (hesse(visiTaskai.back()) == true) {
//		cout << "Greièiausio nusileidimo minimumo taskas: " << visiTaskai.back()[0] << "  " << visiTaskai.back()[1] << endl;
//		cout << "Iteraciju skaicius: " << i << endl;
//	}
//	else {
//		cout << "Minimumas nebuvo rastas" << endl;
//	}
//}


double intervaloDalijimasPusiau(const vector<double>& x, const vector<double>& grad, double a, double b, double tol = 1e-6) {
	// Funkcija, kurià minimizuojame (f(x - gamma * grad))
	auto f_gamma = [&](double gamma) {
		vector<double> x_new = { x[0] - gamma * grad[0], x[1] - gamma * grad[1] };
		return tiksloF(x_new);
		};

	double gamma_min = a;
	double f_min = f_gamma(a);

	while (fabs(b - a) > tol) {
		double c = (a + b) / 2.0;
		double fc = f_gamma(c);

		// Tikriname, ar funkcija maþëja
		if (fc < f_min) {
			gamma_min = c;
			f_min = fc;
		}

		// Atnaujiname intervalà
		double d = (a + c) / 2.0;
		double fd = f_gamma(d);

		if (fd < fc) {
			b = c;
		}
		else {
			a = d;
		}
	}

	return gamma_min;
}

void greiciausiasNusileidimas(vector<double> pradT) {
	vector<vector<double>> visiTaskai = { pradT };
	vector<double> grad = antigradientas(pradT);
	const double epsilon = 1e-6;
	const int max_iter = 1000;
	int i = 0;

	while ((fabs(grad[0]) > epsilon || fabs(grad[1]) > epsilon) && i < max_iter) {
		// Pradinis intervalas [0, 2] (galima keisti)
		double gamma = intervaloDalijimasPusiau(visiTaskai.back(), grad, 0.0, 2.0);

		vector<double> naujasTaskas = {
			visiTaskai.back()[0] - gamma * grad[0],
			visiTaskai.back()[1] - gamma * grad[1]
		};

		// Tikriname, ar naujas taðkas yra geriau
		if (tiksloF(naujasTaskas) >= tiksloF(visiTaskai.back())) {
			break;  // Jei ne, stabdome
		}

		visiTaskai.push_back(naujasTaskas);
		grad = antigradientas(naujasTaskas);
		i++;
	}

	// Rezultatø iðvedimas
	if (i >= max_iter) {
		cout << "Pasiektas maksimalus iteracijø skaièius!" << endl;
	}

	if (hesse(visiTaskai.back())) {
		cout << "Greièiausio nusileidimo minimumas: ("
			<< visiTaskai.back()[0] << ", " << visiTaskai.back()[1] << ")\n";
		cout << "Iteracijos: " << i << endl;
	}
	else {
		cout << "Minimumas nerastas (Hesë nëra teigiamai apibrëþta)" << endl;
	}
}