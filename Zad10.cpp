#include <iostream>

class Segment {
	double A, B;
	double* C, * D;
public:
	Segment(double A, double B) : A(A), B(B) { }
	// ...
	//metody


	int numb;

	Segment(int numb) : numb(numb) { };

	//metoda true / false

	Segment(double x) {

	}

	//odejmowanie
	friend Segment operator-(Segment se, Segment s2) {
		se.A = se.A - s2.numb;
		se.B = se.B - s2.numb;
		return se;
	}

	//dodawanie
	friend Segment operator+(Segment s2, Segment se) {

		//gdy mamy podana liczbe a nie sag
		if ((s2.A == 0 && s2.B == 0) || (se.A == 0 && se.B == 0)) {
			se.A = s2.numb + se.A;
			se.B = s2.numb + se.B;
			return se;

		}
		else { // jezeli sa dodawane punkty do dodajê je do siebie

			s2.A = se.A + s2.A;
			s2.B = se.B + s2.B;
			return s2;
		}

	}

	//dzielenie
	friend Segment operator/(Segment se, Segment s2) {
		se.A = se.A / s2.numb;
		se.B = se.B / s2.numb;
		return se;
	}

	//mnozenie int*Seg
	friend Segment operator*(Segment s2, Segment se) {
		se.A = se.A * s2.numb;
		se.B = se.B * s2.numb;
		return se;
	}

	//wyswietlanie
	friend std::ostream& operator<<(std::ostream& str, const Segment& se) {
		return str << "[" << (int)se.A << " " << (int)se.B << "]";
	}

	//funkcja prawda falsz
	//bool& operator()(double);

	//funkcja prawda falsz rozwinieta poza

	bool operator()(double x) {
		if (x >= A && x <= B) { return true; }
		else return false;
	}

};
int main() {
	using std::cout; using std::endl;
	Segment seg{ 2,3 }, s = 1 + 2 * ((seg - 2) / 2 + seg) / 3;
	cout << s << endl << std::boolalpha; //czy wartoœci logiczne wypisywaæ jako 0 i 1 (domyœlnie), czy s³owami jako true i false.
	for (double x = 0.5; x < 4; x += 1)
		cout << "x=" << x << ": " << s(x) << endl;

}
