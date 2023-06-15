#ifndef FRIGIDER_H
#define FRIGIDER_H

#include "Produs.h"


class Frigider : public Produs
{
    public:
        Frigider(const int& ,const string&,const double&,const int&,const int&);

        int volum;
        bool areCongelator;
        int nimic();
};

#endif // FRIGIDER_H
