#include"Ukras.h"
ostream& operator<<(ostream& it, Ukras& u)
{
	u.pisi(it);
	return it;
}

void Ukras::pisi(ostream& it)
{
	it << masa << " " << boja;
}
