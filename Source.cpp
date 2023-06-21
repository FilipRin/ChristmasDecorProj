#include"Boja.h"
#include"Ukras.h"
#include"Lista.h"
#include"Kugla.h"
#include<iostream>
int main() {

	Lista<Kugla> lista;
	Boja b1(100, 100, 100);
	Boja b2(150, 100, 150);
	Boja b3(50, 150, 50);
	Boja b4 = b1 + b2;
	cout << (b1 == b2) << endl;
	cout << b1 << endl;
	cout << b4 << endl;

	Kugla k1(b1, 100, Kugla::MALA);
	Kugla k2(b2, 500, Kugla::SREDNJA);
	Kugla k3(b3, 750, Kugla::VELIKA);
	Kugla k4(b4, 1000, Kugla::NAJVECA);

	lista <<= k1;
	lista <<= k2;
	lista >>= k3;
	lista <<= k4;

	cout << lista<<endl;

	return 0;
}