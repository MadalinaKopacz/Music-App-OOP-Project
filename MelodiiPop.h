#ifndef MELODIIPOP_H_INCLUDED
#define MELODIIPOP_H_INCLUDED
#include "MyMelodyFile.h"
using namespace std;
class MelodyPop : public Melody
{
int pozitieTop;
public:
    MelodyPop():Melody()
    {
        this->pozitieTop = -1;
    }
    MelodyPop(const MelodyPop & p):Melody(p)
    {
        this->pozitieTop = p.pozitieTop;
    }
    MelodyPop& operator=(const MelodyPop & p)
    {
        if(this!=&p)
        {
            Melody::operator=(p);
            this->pozitieTop = p.pozitieTop;
        }
        return *this;
    }
    friend ostream&operator<<(ostream& out, const MelodyPop & p)
    {
        out<<(Melody&)p;
        out<<"\nPozitie in top: "<<p.pozitieTop;
        return out;
    }

    friend ifstream& operator>>(ifstream& fin, MelodyPop& p)
    {
        fin>>(Melody&)p;
        cout<<"Pozitie in top: ";
        fin>>p.pozitieTop;
        return fin;
    }

    ~MelodyPop()
    {
    }

    int getpozitieTop()
    {
        return this->pozitieTop;
    }
     void setpozitieTop(int pozitieTop)
    {
        this->pozitieTop = pozitieTop;
    }
};

#endif // MELODIIPOP_H_INCLUDED
