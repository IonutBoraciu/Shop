#include "Frigider.h"

Frigider::Frigider(const int& id ,const string& nume,const double& pret,const int&volum,const int& areCongelator):Produs(id,nume,pret,volum,areCongelator)
{

    this->id=id;
    this->nume=nume;
    this->pret=pret;
    this->volum=volum;
    this->areCongelator=areCongelator;
}

int Frigider::nimic()
{
    return 0;
}
