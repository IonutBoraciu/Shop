#include "Produs.h"

Produs::Produs(const int& id,const string& nume,const double& pret,const int& volum, const bool& areCongelator):id(id),nume(nume),pret(pret),volum(volum),areCongelator(areCongelator)
{
    //ctor
}
Produs::Produs(const int& id,const string& nume,const double& pret,const int&rotatiiPeMinut,const string& clasaEnergetica):id(id),nume(nume),pret(pret),rotatiiPeMinut(rotatiiPeMinut),clasaEnergetica(clasaEnergetica)
{

}
int Produs::nimic()
{
    return 1;
}
