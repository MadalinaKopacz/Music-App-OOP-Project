#ifndef MYMELODYFILE_H_INCLUDED
#define MYMELODYFILE_H_INCLUDED
#include <bits/stdc++.h>
#include "Media.h"
using namespace std;

class Melody : public media
{
    string nameMelody;
    float melodyDuration;
    string * musicians;
    int noOfMusicians;
public:
    Melody();
    Melody(string nameMelody, const float Duration);
    Melody(string nameMelody, const float Duration, string * Musicians, int noOfMusicians );
    ~Melody();
    Melody(const Melody & melody);
    void setnameMelody(string nameMelody);
    void setMusicians( string * Musicians, int noOfMusicians);
    void setMelodyDuration(float MelodyDuration);
    string getnameMelody();
    float getmelodyDuration();
    int getnoOfMusicians();
    string * getMusicians();
    bool operator<(Melody other);
    bool operator==(Melody other);
    friend ostream& operator<<(ostream& out, const Melody& m);
    friend ifstream& operator>>(ifstream& fin, Melody& m);
    Melody& operator=(const Melody & Melody);
    Melody& operator-(int nr);
    void AfisareDate();
    virtual void afisareProductie()
    {    cout<<"Artistii melodiei "<<nameMelody<<" sunt: ";
        for(int i = 0; i < noOfMusicians; i++)
            cout << musicians[i] <<" ";
        cout<<"\n";
    }
};
Melody :: Melody()
{
    nameMelody = "";
    melodyDuration = 0;
    noOfMusicians = 0;
    musicians = nullptr;
}
Melody :: Melody(string nameMelody, const float Duration)
{
    this->nameMelody = nameMelody;
    melodyDuration = Duration;
    noOfMusicians = 0;
    musicians = nullptr;
}
Melody :: Melody(string nameMelody, const float Duration, string * Musicians, int noOfMusicians )
{
    this->nameMelody = nameMelody;
    this->melodyDuration = Duration;
    this->noOfMusicians = noOfMusicians;
    musicians = new string[noOfMusicians];
    for(int i = 0; i < noOfMusicians; i++) musicians[i] = Musicians[i];
}
Melody :: ~Melody()
{
    if(musicians != NULL)
        delete[] musicians;
}
Melody :: Melody(const Melody & melody)
{
    this->noOfMusicians = melody.noOfMusicians;
    this->melodyDuration = melody.melodyDuration;
    this->nameMelody = melody.nameMelody;
    this->musicians = new string[noOfMusicians];
    for(int i = 0; i < noOfMusicians; i++)
    {
        this->musicians[i] = melody.musicians[i];
    }

}
void Melody :: setnameMelody(string nameMelody)
{
    this->nameMelody = nameMelody;
}
void Melody :: setMusicians( string * Musicians, int noOfMusicians)
{   if(musicians!=NULL) delete[] musicians;
    this->noOfMusicians = noOfMusicians;
    for(int i = 0; i < noOfMusicians; i++)
            musicians[i] = Musicians[i];
}
void Melody :: setMelodyDuration(float MelodyDuration)
{
    this->melodyDuration = MelodyDuration;
}
int Melody ::getnoOfMusicians()
{
    return noOfMusicians;
}
float Melody::getmelodyDuration()
{
    return melodyDuration;
}
string Melody ::getnameMelody()
{
    return nameMelody;
}
string * Melody ::getMusicians()
{
    return musicians;
}
bool Melody::operator<(Melody other)
{
    if(this->melodyDuration < other.melodyDuration)
    {
        return true;
    }
    else return false;
}
bool Melody::operator==(Melody other)
{
    if(this->melodyDuration == other.melodyDuration)
    {
        return true;
    }
    else return false;
}
ostream& operator<<(ostream& out, const Melody& m)
{
    out << "\nDenumire melodie: "<<m.nameMelody;
    out << "\nDurata melodie: "<<m.melodyDuration;
    out << "\nCantareti: ";
    for(int i=0;i < m.noOfMusicians; i++)
           {out<<m.musicians[i];
            if(i<m.noOfMusicians-1) out<<", ";
           }
    return out;
}
ifstream& operator>> (ifstream& fin, Melody& m)
{
//cout << "\nDenumire melodie: ";
    getline(fin, m.nameMelody);
//    cout << "Durata melodie: ";
   fin>>m.melodyDuration;
//    cout << "Numar cantareti: ";
    fin>>m.noOfMusicians;
    fin.ignore(256, '\n');
//    cout << "Cantareti: \n";
    if(m.musicians!=nullptr)  delete[] m.musicians;
    m.musicians = new string[m.noOfMusicians];
    for(int i=0;i < m.noOfMusicians; i++) getline(fin,m.musicians[i]);
    return fin;
}
Melody& Melody::operator=(const Melody & m)
{   if(this!=&m)
{
    this->noOfMusicians = m.noOfMusicians;
    this->melodyDuration = m.melodyDuration;
    this->nameMelody = m.nameMelody;
    if(this->musicians!=nullptr) delete[] this->musicians;
    this->musicians = new string[noOfMusicians];
    for(int i = 0; i < noOfMusicians; i++)
    {
        this->musicians[i] = m.musicians[i];
    }
}
    return *this;
}
Melody& Melody :: operator-(int nr)
{
   noOfMusicians -= nr;
}
void Melody:: AfisareDate()
{
    cout << "Denumire melodie: "<<nameMelody;
    cout << "\nCantareti: ";
    for(int i=0;i < noOfMusicians; i++) cout<<musicians[i]<<" ";
}

#endif // MYMELODYFILE_H_INCLUDED
