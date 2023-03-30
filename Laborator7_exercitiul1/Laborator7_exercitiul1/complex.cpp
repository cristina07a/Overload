#include "complex.h"
#include <iostream>
#include <cmath>
using namespace std;

complex complex::test()
{
	double real, imaginar;
	int nrElem, n;
	complex tablou[256], mem, sumaPar, sumaImpar;
	cout << "n= ";
	cin >> n;
	nrElem = 2 * n;
	cout << "\nNumarul de elemente din tablou: " << nrElem;
	cout << "\nIntroduceti numerele: \n";
	for (int i = 1; i <= nrElem; i++)
	{
		cout << "numarul " << i << ":\n" << "partea reala: ";
		cin >> real;
		cout << "partea imaginara: ";
		cin >> imaginar;
		mem.SetRealImaginar(real, imaginar);
		tablou[i] = mem;
		if (i % 2 == 0) sumaPar = sumaPar + (tablou[i]^4);
		else sumaImpar = sumaImpar + (tablou[i]^3);
	}
	for (int i = 1; i <= nrElem; i++)
		tablou[i].afisare();
	cout << sumaImpar.real << endl;
	cout << sumaPar.real << endl;
	*this = sumaImpar / sumaPar;
	return *this;
}




void complex::afisare()
{
	cout << "Numarul: " << this->real << " +" << this->imaginar << "*i\n";
}

//atribuire =
complex& complex::operator=(const complex &numar)
{
	this->real = numar.real;
	this->imaginar = numar.imaginar;
	return *this;
}

//adunare +
complex complex::operator+(const complex& numar) const
{
	complex suma;
	suma.real = this->real + numar.real;
	suma.imaginar = this->imaginar + numar.imaginar;
	//cout << "Suma\n";
	return suma;
}

//scadere -
complex complex::operator-(const complex& numar) const
{
	complex diferenta;
	diferenta.real = this->real - numar.real;
	diferenta.imaginar = this->imaginar - numar.imaginar;
	//cout << "Diferenta\n";
	return diferenta;
}

//inmultire *
complex complex::operator*(const complex& numar) const
{
	complex produs;
	produs.real = this->imaginar * numar.imaginar * (-1) + this->real*numar.real;
	produs.imaginar = (this->real * numar.imaginar + this->imaginar * numar.real)*(-1);
	//cout << "produsul\n";
	return produs;
}

//impartire /
complex complex::operator/(const complex& numar) const
{
	complex mem(numar.real, -numar.imaginar);
	complex impartire = *this * mem;
	//cout << "real: "  << impartire.real << "\nimaginar: " << impartire.imaginar << endl;
	impartire.real = impartire.real / (numar.real * numar.real - numar.imaginar * numar.imaginar);
	//cout << impartire.real << endl;
	impartire.imaginar = impartire.imaginar / (numar.real * numar.real - numar.imaginar * numar.imaginar);
	//cout << impartire.imaginar << endl;
	//cout << "impartire\n";
	return impartire;
}

//modul ~
complex complex::operator~()const
{
	//un numar complex in modul are decat parte reala, deci partea imaginara este mereu 0
	complex modul;
	modul.real = sqrt(this->real * this->real + this->imaginar * this->imaginar);
	return modul;
}

//putere ^
complex complex::operator^(int putere)
{
	if (putere == 1) return *this;
	if (putere == 0) {
		this->real = 1;
		this->imaginar = 0;
		return *this;
	}
	else
	{
		complex putere2;
		while (putere > 1)
		{
				putere2.real += this->real * this->real + (-1) * this->imaginar * this->imaginar;
				putere2.imaginar += 2 * this->real * this->imaginar;
				putere --;
		}
		if (putere < 0)
		{
			complex mem(1, 0);
			putere=-putere;
			*this = *this^putere;
			putere2 = mem / *this;
		}
		return putere2;
	}
}

void complex::SetRealImaginar(double real, double imaginar)
{
	this->real = real;
	this->imaginar = imaginar;
}