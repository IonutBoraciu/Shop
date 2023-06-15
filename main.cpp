#include <iostream>
#include "Produs.h"
#include "Magazin.h"
#include "Frigider.h"
#include "MasinaDeSpalat.h"
#include<string>
#include <exception>
#include <stdexcept>
#include<fstream>
ifstream fin("DATE.in", ofstream::in | ofstream::out);
using namespace std;
class MagazinPlinException_2:public exception
{
public:
    virtual const char*what() const throw()
    {
        return "Nu mai adaugati produse, magazinul este deja plin";
    }
} MagazinPlinException_2;

int main()
{ cout<<"Bine ati venit!"<<endl;
 cout<<"Programul are cateva optiuni printre care:"<<endl;
 cout<<"-A : adauga in baza de date un nou produs"<<endl;
 cout<<"-E : elimina un produs din baza de date in functie de id-ul pe care il furnizati"<<endl;
 cout<<"-C : cauta un produs in functie de id-ul pe care il furnizati"<<endl;
 cout<<"-N : afiseaza numarul masinilor de spalat din baza de date"<<endl;
 cout<<"-P : afiseaza numarul frigiderelor din baza de date"<<endl;
 cout<<"-L : listeaza toate produsele din baza de date"<<endl;
 cout<<"-Q : iese din program"<<endl;
 cout<<"Pentru functionarea optima a programului este fundamental ca tasta 'Q' sa fie apasata la sfarsitul programului"<<endl;
 cout<<"...............................................................................................................";
 cout<<endl;
   int y=2000000;
    char op;
   int b=0;
   Magazin magazin(y);
    char tipObiect;
      while(fin>>tipObiect)
      { int id;
        string nume;
        double pret;
        fin>>id;
        fin.get();
        getline(fin,nume);


        fin>>pret;
        if(tipObiect=='F')
        {
           int volum;
           bool areCongelator;
           fin>>volum;
           fin>>areCongelator;
           magazin.adaugaProdus(new Frigider(id,nume,pret,volum,areCongelator));


        }
        else if(tipObiect=='M')
        {
             int rotatiiPeMinut;

             string clasaEnergetica;
             fin>>rotatiiPeMinut;
             fin.ignore();
             getline(fin,clasaEnergetica);




              magazin.adaugaProdus(new MasinaDeSpalat(id,nume,pret,rotatiiPeMinut,clasaEnergetica));
        }
        b++;
      }
   bool x=1;

   while(x)
   {
    cout<<"Introduceti A/E/C/N/P/L/Q in functie de ce doriti! ";
     cin>>op;
    switch(op)
    {
    case 'A':

{      char a;
        try
    {

        if(b!=y)
    {

        cout<<"Introduceti tipul de produs pe care vreti sa il introduceti(F/M): ";
        cin>>a;
        int id;
        if(a!='F'&& a!='M')
            {
                cout<<"Va rugam introduceti F sau M!!"<<endl;
                continue;
            }


        string nume;
        double pret;
        cout<<"Introduceti id-ul produsului pe care doriti sa il introduceti: ";
        cin>>id;
        cout<<"Introduceti numele produsului pe care doriti sa il introduceti: ";
         cin.ignore();
         getline(cin,nume);
        cout<<"Introduceti pretul produsului pe care doriti sa il introduceti: ";
        cin>>pret;

        if(a=='F')
        {
            int volum;
            bool areCongelator;
            cout<<"Introduceti volumul produsului: ";
            cin>>volum;
            cout<<"Precizati daca produsul are congelator sau nu(1 sau 0): ";
            cin>>areCongelator;
             magazin.adaugaProdus(new Frigider(id,nume,pret,volum,areCongelator));
         b++;

        }
        else
            if(a=='M')
        {
            int rotatiiPeMinut;
            string clasaEnergetica;
            cout<<"Introduceti rotatiile pe minut ale produsului: ";
            cin>>rotatiiPeMinut;
            cout<<"Introduceti clasa energetica a produslui: ";
            cin.ignore();
            getline(cin,clasaEnergetica);
           magazin.adaugaProdus(new MasinaDeSpalat(id,nume,pret,rotatiiPeMinut,clasaEnergetica));

          b++;

        }

        }
    else
    {

      throw MagazinPlinException_2;
    }
    }
catch(exception& p)
    {

       cout<<p.what()<<endl;

    }








}

        break;

    case 'E':
        {  int id;
            cout<<"Introduceti id-ul produsului pe care doriti sa il eliminati: ";
            cin>>id;
            magazin.eliminaProdus(id);
            b--;
        }
        break;
    case 'C':
        {
            int id;
            cout<<"Introduceti id-ul prodsului pe care il cautati: ";
            cin>>id;
            magazin.cautaProdus(id);
        }
        break;
    case 'N':
        {   cout<<"Numarul masinilor de spalat este: ";
            cout<<magazin.numarMasiniDeSpalat()<<endl;
        }
        break;
    case 'P':
        {
            cout<<"Numarul frigiderelor este: ";
            cout<<magazin.numarFrigidere()<<endl;
        }
        break;
    case 'L':
        magazin.scrieProduse();

        break;
    case 'Q':
      {

        cout<<"La revedere!";
        x=0;
        std::ofstream ofs;
        ofs.open("DATE.in", std::ofstream::in | std::ofstream::trunc);
        magazin.scrieProduse2();
      }
        break;
    default:
        cout<<"Va rugam sa apasati pe A/E/C/N/L/Q"<<endl;
        break;


    }
   }

    return 0;
}
