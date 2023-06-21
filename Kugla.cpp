#include"Kugla.h"
ostream& operator<<(ostream& it, Kugla& k)
{
	k.pisi(it);
	return it;
}

void Kugla::pisi(ostream& it)
{
	if (velicina == 0)it << ". ";
	else if (velicina == 1)it << "o ";
	else if (velicina == 2)it << "O ";
	else it << "( ) ";
	Ukras::pisi(it);
}
