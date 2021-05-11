#ifndef MEDIA_H_INCLUDED
#define MEDIA_H_INCLUDED
#include <bits/stdc++.h>

using namespace std;

///clasa abstracta
class media
{
string cod, permisiune;
public:
    virtual void afisareProductie()=0;
     string getcod()
    {
        return this->cod;
    }
    void setcod(string cod)
    {
        this->cod = cod;
    }
     string getpermisiune()
    {
        return this->permisiune;
    }
    void setpermisiune(string permisiune)
    {
        this->permisiune = permisiune;
    }
};


#endif // MEDIA_H_INCLUDED
