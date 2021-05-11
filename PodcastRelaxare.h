#ifndef PODCASTRELAXARE_H_INCLUDED
#define PODCASTRELAXARE_H_INCLUDED
#include <bits/stdc++.h>
#include "MyMelodyFile.h"
#include "MyUserFile.h"
#include "MyAlbumFile.h"
#include "MyPodcastFile.h"
#include "PodcastStudiu.h"

using namespace std;

class PodcastRelaxare : public Podcast
{
    string recomandarePerioadaZi;
public:
    PodcastRelaxare():Podcast()
    {
        this->recomandarePerioadaZi = "";
    }
    PodcastRelaxare(const PodcastRelaxare & p):Podcast(p)
    {
        this->recomandarePerioadaZi = p.recomandarePerioadaZi;
    }
    PodcastRelaxare& operator=(const PodcastRelaxare & p)
    {
        if(this!=&p)
        {
            Podcast::operator=(p);
            this->recomandarePerioadaZi = p.recomandarePerioadaZi;
        }
        return *this;
    }
    friend ostream&operator<<(ostream& out, const PodcastRelaxare & p)
    {
        out<<(Podcast&)p;
        out<<"\nRecomandare Perioada din Zi: "<<p.recomandarePerioadaZi;
        return out;
    }

    friend istream& operator>>(istream& in, PodcastRelaxare& p)
    {
        in>>(Podcast&)p;
        cout<<"Recomandare Perioada din Zi: ";
        in>>p.recomandarePerioadaZi;
        return in;
    }

    ~PodcastRelaxare()
    {
    }

    string getRecomandarePerioadaZi()
    {
        return this->recomandarePerioadaZi;
    }
     void setRecomandarePerioadaZi(string recomandarePerioadaZi)
    {
        this->recomandarePerioadaZi = recomandarePerioadaZi;
    }
};
#endif // PODCASTRELAXARE_H_INCLUDED
