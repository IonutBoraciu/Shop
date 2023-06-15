#include "Magazin.h"
#include<iostream>
#include <exception>
#include<stdexcept>
#include<fstream>
ofstream fout("DATE.in",ofstream::in | ofstream::out);
using namespace std;

Magazin::Magazin(const int&nrProduse)
{
    this->numarProduse=nrProduse;
    a=new Produs*[numarProduse];

    for(int i=0; i<numarProduse; i++)
    {
        a[i]=NULL;
    }



}
Magazin::~Magazin()
{
    for(int i=0; i<numarProduse; i++)
        if(a[i]!=NULL)
            delete a[i];
    delete []a;


}
class MagazinPlinException:public exception
{
public:
    virtual const char*what() const throw()
    {
        return "Magazinul este plin, numerele adaugate dupa acesta vor fi ignorate";
    }
} MagazinPlinException;

class ProdusInexistentException:public exception
{
public:
    virtual const char*what() const throw()
    {
        return "Produsul pe care doriti sa il eliminati nu exista introduceti unul existent!!";
    }
} ProdusInexistentException;



class ProdusInexistentException_2:public exception
{
public:
    virtual const char*what() const throw ()
    {
        return "Produsul cautat nu exista";
    }
} ProdusInexistentException_2;


void Magazin::adaugaProdus(Produs* produs)
{



            for(int i=0; i<numarProduse; i++)

                if(a[i]==NULL)
                {
                    a[i]=produs;


                    return;

                }

}









void Magazin::eliminaProdus(int idProdus)
{
    int y=0;
    for(int i=0; i<numarProduse; i++)
    {

        if(dynamic_cast<Frigider*>(a[i]))


            if(a[i]->id==idProdus)
            {
                y=1;


            }
        if(dynamic_cast<MasinaDeSpalat*>(a[i]))
            if(a[i]->id==idProdus)
            {
                y=1;

            }
    }





    try
    {
        if(y==0)
        {
            throw ProdusInexistentException;
        }
        else
        {

            int z=0;

            for(int i=0; i<numarProduse; i++)
            {

                if(dynamic_cast<Frigider*>(a[i]))


                    if(a[i]->id==idProdus)
                    {
                        for(int j=i; j<numarProduse; j++)
                            a[j]=a[j+1];

                        z=1;

                    }

                if(dynamic_cast<MasinaDeSpalat*>(a[i]))
                    if(a[i]->id==idProdus)
                    {

                        for(int j=i; j<numarProduse; j++)
                            a[j]=a[j+1];

                        z=1;
                    }

                if(z==1)
                    break;
            }



        }

    }
    catch(exception& d)
    {
        cout<<d.what()<<endl;
    }


}

void Magazin::scrieProduse()
{

    for(int i=0; i<numarProduse; i++)
    {

        if(a[i]!=NULL)
        {
            if(dynamic_cast<Frigider*>(a[i]))
                cout<<"Frigider";
            else
                cout<<"MasinaDeSpalat";
            cout<<" id: ";
            cout<<a[i]->id<<" ";
            cout<<" nume: ";
            cout<<a[i]->nume<<" ";
            cout<<" pret: ";
            cout<<a[i]->pret<<" ";
            if(dynamic_cast<Frigider*>(a[i]))
            {
                cout<<" volum: ";
                cout<<a[i]->volum<<" ";
                cout<<" areCongelator: ";
                cout<<a[i]->areCongelator<<endl;
            }
            if(dynamic_cast<MasinaDeSpalat*>(a[i]))
            {
                cout<<" rotatiiPeMinut: "<<" ";
                cout<<a[i]->rotatiiPeMinut<<" ";
                cout<<" clasaEnergetica:"<<" ";
                cout<<a[i]->clasaEnergetica<<endl;
            }

        }




    }

}
Produs* Magazin::cautaProdus(int idProdus)
{
    int u=0;




    for(int i=0; i<numarProduse; i++)
    {

        if(dynamic_cast<Frigider*>(a[i]))
            if(a[i]->id==idProdus)
            {
                cout<<"Produsul cautat este: ";
                cout<<"id: ";
                cout<<a[i]->id<<" ";
                cout<<"nume: ";
                cout<<a[i]->nume<<" ";
                cout<<"pret: ";
                cout<<a[i]->pret<<" ";
                cout<<"volum: ";
                cout<<a[i]->volum<<" ";
                cout<<"areCongelator: ";
                cout<<a[i]->areCongelator<<endl;
                u=1;
                return 0;

            }
        if(dynamic_cast<MasinaDeSpalat*>(a[i]))
            if(a[i]->id==idProdus)
            {
                cout<<"Produsul cautat este: ";
                cout<<"id: ";
                cout<<a[i]->id<<" ";
                cout<<"nume: ";
                cout<<a[i]->nume<<" ";
                cout<<"pret: ";
                cout<<a[i]->pret<<" ";
                cout<<"rotatiiPeMinut: ";
                cout<<a[i]->rotatiiPeMinut<<" ";
                cout<<"clasaEnergetica: ";
                cout<<a[i]->clasaEnergetica<<endl;
                u=1;
                return 0;


            }

    }





    try
    {
        if(u==0)
            throw ProdusInexistentException_2;
    }
    catch(exception& e)
    {
        cout<<e.what()<<endl;
    }


}
int Magazin::numarMasiniDeSpalat()
{
    nrMasiniDeSpalat=0;
    for(int i=0; i<numarProduse; i++)
        if(dynamic_cast<MasinaDeSpalat*>(a[i]))
            nrMasiniDeSpalat=nrMasiniDeSpalat+1;
    return nrMasiniDeSpalat;
}
int Magazin::numarFrigidere()
{
    int  nrFrigidere=0;
    for(int i=0; i<numarProduse; i++)
        if(dynamic_cast<Frigider*>(a[i]))
            nrFrigidere++;
    return nrFrigidere;
}
void Magazin::scrieProduse2()
{

    for(int i=0; i<numarProduse; i++)
    {

        if(a[i]!=NULL)
        {
            if(dynamic_cast<MasinaDeSpalat*>(a[i]))
                fout<<'M'<<endl;
            else
                fout<<'F'<<endl;

            fout<<a[i]->id<<endl;
            fout<<a[i]->nume<<endl;
            fout<<a[i]->pret<<endl;
            if(dynamic_cast<Frigider*>(a[i]))
            {

                fout<<a[i]->volum<<endl;
                fout<<a[i]->areCongelator<<endl;
            }
            if(dynamic_cast<MasinaDeSpalat*>(a[i]))
            {
                fout<<a[i]->rotatiiPeMinut<<endl;
                fout<<a[i]->clasaEnergetica<<endl;

            }

        }




    }

}



