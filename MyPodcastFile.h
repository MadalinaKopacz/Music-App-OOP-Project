#ifndef MYPODCASTFILE_H_INCLUDED
#define MYPODCASTFILE_H_INCLUDED
#include <bits/stdc++.h>
using namespace std;

class Podcast : public media
{
    string namePodcast, subject;
    float podcastDuration;
    string * authors;
    int noOfAuthors;

public:
    Podcast();
    Podcast(string namePodcast, string Subject, const float Duration);
    Podcast(string namePodcast, string Subject, const float Duration, string * Authors, int noOfAuthors );
    ~Podcast();
    Podcast(const Podcast & Podcast);
    void setnamePodcast(string namePodcast);
    void setsubjectPodcast(string subjectPodcast);
    void setPodcast( string * Authors, int noOfAuthors);
    void setPodcastDuration(float PodcastDuration);
    string getnamePodcast();
    string getsubjectPodcast();
    float getpodcastDuration();
    int getnoOfAuthors();
    string * getAuthors();
    bool operator<(Podcast other);
    bool operator==(Podcast other);
    friend ostream& operator<<(ostream& out, const Podcast& p);
    friend istream& operator>>(istream& in, Podcast& p);
    Podcast& operator=(const Podcast & Podcast);
    void AfisareInformatii();
    virtual void afisareProductie()
    {   cout<<"Autorii podcastului "<<namePodcast<<" sunt: ";
        for(int i = 0; i < noOfAuthors; i++)
            cout << authors[i] <<" ";
        cout<<"\n";
    }
};
Podcast :: Podcast()
{
    namePodcast = "";
    subject = "";
    podcastDuration = 0;
    noOfAuthors = 0;
    authors = nullptr;
}
Podcast :: Podcast(string namePodcast, string Subject, const float Duration)
{
    this->namePodcast = namePodcast;
    subject = Subject;
    podcastDuration = Duration;
    noOfAuthors = 0;
    authors = nullptr;
}
Podcast :: Podcast(string namePodcast, string Subject, const float Duration, string * Authors, int noOfAuthors )
{
    this->namePodcast = namePodcast;
    subject = Subject;
    this->podcastDuration = Duration;
    this->noOfAuthors = noOfAuthors;
    authors = new string[noOfAuthors];
    for(int i = 0; i < noOfAuthors; i++) authors[i] = Authors[i];
}
Podcast :: ~Podcast()
{
    if(authors != NULL)
        delete[] authors;
}
Podcast :: Podcast(const Podcast & podcast)
{
    this->noOfAuthors = podcast.noOfAuthors;
    this->podcastDuration = podcast.podcastDuration;
    this->subject = podcast.subject;
    this->namePodcast = podcast.namePodcast;
    this->authors = new string[noOfAuthors];
    for(int i = 0; i < noOfAuthors; i++)
        this->authors[i] = podcast.authors[i];
}
void Podcast :: setnamePodcast(string namePodcast)
{
    this->namePodcast = namePodcast;
}
void Podcast :: setsubjectPodcast(string subjectPodcast)
{
    this->subject = subjectPodcast;
}
void Podcast :: setPodcast(string * Authors, int noOfAuthors)
{    if(this->authors!=NULL) delete[] this->authors;
     this->noOfAuthors = noOfAuthors;
     for(int i = 0; i < noOfAuthors; i++)
            authors[i] = Authors[i];
}
void Podcast:: setPodcastDuration(float PodcastDuration)
{
    this->podcastDuration = PodcastDuration;
}
int Podcast ::getnoOfAuthors()
{
    return noOfAuthors;
}
float Podcast::getpodcastDuration()
{
    return podcastDuration;
}
string Podcast ::getnamePodcast()
{
    return namePodcast;
}
string Podcast ::getsubjectPodcast()
{
    return subject;
}
string * Podcast ::getAuthors()
{
    return  authors;
}
bool Podcast::operator<(Podcast other)
{
    if(this->podcastDuration < other.podcastDuration)
    {
        return true;
    }
    else return false;
}
bool Podcast::operator==(Podcast other)
{
    if(this->podcastDuration == other.podcastDuration)
    {
        return true;
    }
    else return false;
}
ostream& operator<<(ostream& out, const Podcast& p)
{
    out << "\nDenumire podcast: "<<p.namePodcast;
    out << "\nDurata podcast: "<<p.podcastDuration;
    out << "\nSubiect podcast: "<<p.subject;
    out << "\nAutori: ";
    for(int i=0;i < p.noOfAuthors; i++) out<<p.authors[i]<<" ";
    return out;
}
istream& operator>> (istream& in, Podcast& p)
{ in.ignore(256, '\n');
    cout << "\nDenumire podcast: ";
    getline(in,p.namePodcast);
    cout << "Durata podcast: ";
    in>>p.podcastDuration;
    in.ignore(256, '\n');
    cout << "Subiect podcast: ";
    getline(in,p.subject);
    cout << "Numar autori: ";
    in>>p.noOfAuthors;
    in.ignore(256, '\n');
    if(p.authors!=nullptr) delete[] p.authors;
    p.authors = new string[p.noOfAuthors];
    cout << "Autori: ";
    for(int i=0;i < p.noOfAuthors; i++) getline(in,p.authors[i]);
    return in;
}
Podcast& Podcast::operator=(const Podcast & p)
{if(this != &p)
    {
    this->noOfAuthors = p.noOfAuthors;
    this->podcastDuration = p.podcastDuration;
    this->namePodcast = p.namePodcast;
    this->subject = p.subject;
    if(this->authors!=nullptr) delete[] this->authors;
    this->authors = new string[p.noOfAuthors];
    for(int i = 0; i < noOfAuthors; i++)
    {
        this->authors[i] = p.authors[i];
    }
    }
    return *this;
}
void Podcast:: AfisareInformatii()
{
    cout << "Denumire podcast: "<<namePodcast;
    cout << "\nSubiect: "<<subject;
    cout << "\nAutori: ";
    for(int i=0;i < noOfAuthors; i++) cout<<authors[i]<<" ";
}
#endif // MYPODCASTFILE_H_INCLUDED
