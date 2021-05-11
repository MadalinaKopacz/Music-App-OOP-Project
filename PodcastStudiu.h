#ifndef PODCASTSTUDIU_H_INCLUDED
#define PODCASTSTUDIU_H_INCLUDED
#include "MyPodcastFile.h"
#include <bits/stdc++.h>

class PodcastStudiu : public Podcast
{
    string materie;
public:
    PodcastStudiu():Podcast()
    {
        this->materie = "";
    }
    PodcastStudiu(const PodcastStudiu & p):Podcast(p)
    {
        this->materie = p.materie;
    }
    PodcastStudiu& operator=(const PodcastStudiu & p)
    {
        if(this!=&p)
        {
            Podcast::operator=(p);
            this->materie = p.materie;
        }
        return *this;
    }
    friend ostream&operator<<(ostream& out, const PodcastStudiu & p)
    {
        out<<(Podcast&)p;
        out<<"\nMaterie"<<p.materie;
        return out;
    }

    friend istream& operator>>(istream& in, PodcastStudiu& p)
    {
        in>>(Podcast&)p;
        cout<<"Materie: ";
        in>>p.materie;
        return in;
    }

    ~PodcastStudiu()
    {
    }

    string getmaterie()
    {
        return this->materie;
    }
    void setmaterie(string materie)
    {
        this->materie = materie;
    }
};


#endif // PODCASTSTUDIU_H_INCLUDED
