#ifndef MYALBUMFILE_H_INCLUDED
#define MYALBUMFILE_H_INCLUDED
#include <bits/stdc++.h>
using namespace std;

class Album
{
    Melody * melodii; //vector de melodii
    int nrMelodii;
    int anAparitie;
    string casaDeProductie, denumireAlbum;
public:
    Album();
    Album(const int AnAparatie, int nrMelodii, Melody *melodii,string denumireAlbum);
    Album(const int AnAparatie, int nrMelodii, Melody *melodii, string casaDeProductie, string denumireAlbum);
    Album(const Album & album);
    ~Album();
    void setMelodii(int nrMelodii, Melody melodii[]);
    void setAnApartie(int anAparitie);
    void setCasaDeProductie(string casaDeProductie);
    void setDenumireAlbum(string denumireAlbum);
    int getAnAparitie();
    int getNrMelodii();
    string getcasaDeProductie();
    string getdenumireAlbum();
    Melody * getMelodii();
    Melody& operator[] (int index);
    Album& operator=(const Album & album);
    Album& operator+(const Album & album);
    friend ostream& operator<<(ostream& out, const Album& a);
    friend ifstream& operator>>(ifstream& fin, Album& a);
    void AfisareMelodii();
};
    Album :: Album()
    {
        nrMelodii = 0;
        anAparitie = 0;
        casaDeProductie = "";
        denumireAlbum = "";
        melodii = nullptr;
    }
    Album :: Album(const int anAparatie, int nrMelodii, Melody *melodii, string denumireAlbum)
    {
        this->nrMelodii = nrMelodii;
        this->anAparitie = anAparitie;
        melodii = new Melody[nrMelodii];
        this->denumireAlbum=denumireAlbum;
        for(int i = 0; i < nrMelodii; i++)
            this->melodii[i] = melodii[i];
        this->casaDeProductie = "";
    }
    Album :: Album(const int anAparatie, int nrMelodii, Melody *melodii, string casaDeProductie, string denumireAlbum)
    {
        this->nrMelodii = nrMelodii;
        this->denumireAlbum = denumireAlbum;
        this->anAparitie = anAparitie;
        this->casaDeProductie = casaDeProductie;
        melodii = new Melody[nrMelodii];
        for(int i = 0; i < nrMelodii; i++)
            this->melodii[i] = melodii[i];
    }
    Album :: Album(const Album & album)
    {
        this->nrMelodii = album.nrMelodii;
        this->denumireAlbum = denumireAlbum;
        this->anAparitie = album.anAparitie;
         melodii = new Melody[nrMelodii];
        this->casaDeProductie = album.casaDeProductie;
        for( int i = 0; i < nrMelodii; i++)
            this->melodii[i] = album.melodii[i];

    }
    Album :: ~Album()
    {
        if(melodii != NULL)
        delete[] melodii;
    }
    void Album :: setMelodii(int nrMelodii, Melody * melodii)
    {
        this->nrMelodii = nrMelodii;
        for(int i= 0; i <= nrMelodii; i++)
            this->melodii[i] = melodii[i];
    }
    void Album :: setAnApartie(int anAparitie)
    {
        this->anAparitie = anAparitie;
    }
    void Album :: setCasaDeProductie(string casaDeProductie)
    {
        this->casaDeProductie = casaDeProductie;
    }
    void Album :: setDenumireAlbum(string denumireAlbum)
    {
        this->denumireAlbum = denumireAlbum;
    }
    int Album :: getAnAparitie()
    {
        return anAparitie;
    }
    int Album :: getNrMelodii()
    {
        return nrMelodii;
    }
    string Album :: getcasaDeProductie()
    {
        return casaDeProductie;
    }
    string Album :: getdenumireAlbum()
    {
        return denumireAlbum;
    }
    Melody * Album :: getMelodii()
    {
        return melodii;
    }
    Melody & Album :: operator[](int index)
    {
        return melodii[index];
    }
    Album& Album :: operator=(const Album & album)
    {if(this != &album)
    {
        this->denumireAlbum = album.denumireAlbum;
        this->casaDeProductie = album.casaDeProductie;
        this->anAparitie = album.anAparitie;
        this->nrMelodii = album.nrMelodii;
        if(this->melodii!=NULL) delete[] this->melodii;
        this->melodii = new Melody[nrMelodii];
        for(int i = 0; i < nrMelodii; i++)
            this->melodii[i] = album.melodii[i];
    }
    return *this;
    }
    Album& Album::operator+(const Album & album)
    {
        if(this->nrMelodii+album.nrMelodii <= 100)
           { for(int i = this->nrMelodii; i<album.nrMelodii+this->nrMelodii; i++)
                     this->melodii[i] = album.melodii[i-this->nrMelodii];
             this->nrMelodii += album.nrMelodii;
           }
        else cout<<"Prea multe melodii intr-un singur album";

    }
    ostream& operator<<(ostream& out, const Album& a)
    {
    out << "\nDenumire Album: "<<a.denumireAlbum;
    out << "\nCasa de productie: "<<a.casaDeProductie;
    out << "\nAn aparitie: "<<a.anAparitie;
    out << "\nNumar de melodii: "<<a.nrMelodii;
    out << "\nMelodii: ";
    for(int i=0;i < a.nrMelodii; i++) out<<a.melodii[i]<<"\n";
    return out;
    }
    ifstream& operator>>(ifstream& fin, Album& a)
    {
//    cout << "Denumire Album: ";
    getline(fin,a.denumireAlbum);
//    cout << "Casa de productie: ";
    getline(fin,a.casaDeProductie);
//    cout << "An aparitie: ";
    fin>>a.anAparitie;;
//    cout << "Numar de melodii: ";
    fin>>a.nrMelodii;
    if(a.melodii!=nullptr) delete[] a.melodii;
    a.melodii = new Melody[a.nrMelodii];
//    cout << "\nMelodii: ";
    fin.ignore(256, '\n');
    for(int i=0;i < a.nrMelodii; i++) fin>>a.melodii[i];
    return fin;
    }
    void Album :: AfisareMelodii()
    {
        for(int i = 0; i < nrMelodii; i++) cout<<melodii[i].getnameMelody()<<" ";

    }
#endif // MYALBUMFILE_H_INCLUDED
