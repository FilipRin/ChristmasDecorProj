#pragma once
#ifndef _kugla_h_
#define _kugla_h_
#include"Ukras.h"

class Kugla :public Ukras {

public:
	static enum tip
	{
		MALA, 
		SREDNJA,
		VELIKA,
		NAJVECA
	};
	tip velicina;
	Kugla(Boja& b, int g, tip v) :Ukras( b,g), velicina(v) {}
	friend ostream& operator<<(ostream& it, Kugla& k);
	void pisi(ostream& it) override;
};

#endif // !_kugla_h_
