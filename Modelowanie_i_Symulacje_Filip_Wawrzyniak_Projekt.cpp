/*
	Imie i nazwisko: Filip Wawrzyniak
	Opis: Projekt Modelowanie i Symulacje komputerowe
			- Czas potrzebny na zamowienie i otrzymanie jedzenia on-line
	Data utworzenia: 20.01.2021

	Funckja dopasowania: Gauss
	Parametry dopasowania:
		 EXT PARAMETER                                   STEP         FIRST
	  NO.   NAME      VALUE            ERROR          SIZE      DERIVATIVE
	   1  Constant     3.08657e+02   3.83514e+00   2.78582e-02   1.78476e-04
	   2  Mean         6.15952e+01   1.37559e-01   1.13993e-03   1.05072e-02
	   3  Sigma        1.25192e+01   9.07916e-02   1.65486e-05  -1.91232e-01
*/


#include <fstream>
#include <random>

using namespace std;

double Strona();
double Kuchnia();
double Restauracja();
double Wybor_dania();
double Strefa();
double Godzina();
double ndUtil(double time, double dev);

int main()
{
	fstream out;
	out.open("output.txt");
	unsigned int N = 10000;

	for (unsigned int i = 0; i < N; ++i)
		out << Strona() + Kuchnia() + Restauracja()
		+ Wybor_dania() + Strefa() + Godzina() << endl;

	out.close();

	return 0;
}

double Strona()
{
	std::random_device rd{};
	std::mt19937 gen(rd());
	std::discrete_distribution<> d{ 50, 30, 20 };

	int x = d(gen);

	if		(x == 0)	return ndUtil(10, 2);
	else if (x == 1)	return ndUtil(6, 2);
	else				return ndUtil(4, 2);
}

double Kuchnia()
{
	std::random_device rd{};
	std::mt19937 gen(rd());
	std::discrete_distribution<> d{ 40, 30, 20, 10 };

	int x = d(gen);

	if		(x == 0)	return ndUtil(6, 1);
	else if (x == 1)	return ndUtil(5, 1);
	else if (x == 2)	return ndUtil(5, 1);
	else				return ndUtil(3, 1);
}

double Restauracja()
{
	std::random_device rd{};
	std::mt19937 gen(rd());
	std::discrete_distribution<> d{ 60, 15, 25 };

	int x = d(gen);

	if		(x == 0)	return ndUtil(10, 2);
	else if (x == 1)	return ndUtil(4, 2);
	else				return ndUtil(6, 2);
}

double Wybor_dania()
{
	std::random_device rd{};
	std::mt19937 gen(rd());
	std::discrete_distribution<> d{ 15, 65, 20 };

	int x = d(gen);

	if		(x == 0)	return ndUtil(3, 1.5);
	else if (x == 1)	return ndUtil(5, 1.5);
	else				return ndUtil(9, 1.5);
}

double Strefa()
{
	std::random_device rd{};
	std::mt19937 gen(rd());
	std::discrete_distribution<> d{ 20, 40, 40 };

	int x = d(gen);

	if		(x == 0)	return ndUtil(40, 5);
	else if (x == 1)	return ndUtil(25, 5);
	else				return ndUtil(15, 5);
}

double Godzina()
{
	std::random_device rd{};
	std::mt19937 gen(rd());
	std::discrete_distribution<> d{ 10, 30, 15, 30, 15 };

	int x = d(gen);

	if		(x == 0)	return ndUtil(2, 2);
	else if (x == 1)	return ndUtil(15, 4);
	else if (x == 2)	return ndUtil(10, 2);
	else if (x == 3)	return ndUtil(12, 3);
	else				return ndUtil(10, 3);
}

double ndUtil(double time, double dev)
{
	std::random_device rd{};
	std::mt19937 gen(rd());
	std::normal_distribution<> nd{ time, dev };
	return nd(gen);
}
