#ifndef PRODUS_H
#define PRODUS_H
#include<string>

using namespace std;
class Produs
{
    public:
        Produs(const int& ,const string&,const double&,const int&,const bool&);
        Produs(const int&, const string&,const double&,const int&,const string&);

        int id;
        string nume;
        double pret;
        virtual int nimic();
        int volum;
        bool areCongelator;
        int rotatiiPeMinut;
        string clasaEnergetica;

};

#endif // PRODUS_H
