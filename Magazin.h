#ifndef MAGAZIN_H
#define MAGAZIN_H
#include "Produs.h"
#include "Frigider.h"
#include "MasinaDeSpalat.h"
class Magazin
  {

  public:;
        Magazin(const  int& nrProduse);
        Produs *citesteProdus();
        void adaugaProdus(Produs* produs);
        void eliminaProdus(int idProdus);
        Produs* cautaProdus(int idProdus);
        int numarMasiniDeSpalat();
        int numarFrigidere();
        void scrieProduse();
        void scrieProduse2();

        ~Magazin();



       int nrMasiniDeSpalat;
        int numarProduse;
         Produs**a;


};

#endif // MAGAZIN_H
