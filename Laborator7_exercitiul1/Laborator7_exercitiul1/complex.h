#pragma once
class complex
{
public:
	complex() : real(0), imaginar(0) {}
	complex(float real, float imaginar) : real(real), imaginar(imaginar) {}
	void SetRealImaginar(double real, double imaginar);
	void afisare();
	complex& operator=(const complex& numar);
	complex operator^(int putere);
	complex operator+(const complex& numar) const;
	complex operator-(const complex& numar) const;
	complex operator~()const;
	complex operator*(const complex& numar) const;
	complex operator/(const complex& numar) const;

	complex test();
private:
	double real;
	double imaginar;
};

