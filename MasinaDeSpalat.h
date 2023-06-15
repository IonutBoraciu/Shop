#ifndef MASINADESPALAT_H
#define MASINADESPALAT_H

#include "Produs.h"


class MasinaDeSpalat : public Produs
{
    public:
        MasinaDeSpalat(const int& ,const string&,const double&,const int& rotatiiPeMinut,const string&clasaEnergetica);

        int rotatiiPeMinut;
        string clasaEnergetica;
};

#endif // MASINADESPALAT_H
