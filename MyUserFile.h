#ifndef MYUSERFILE_H_INCLUDED
#define MYUSERFILE_H_INCLUDED
#include <bits/stdc++.h>
using namespace std;


class User
{
    static int numberOfUsers;

    char* last_name;
    string first_name;
    string username;
    int age;
    bool premium;     ///premium = 1 daca userul are abonament premium
    char uploads;     ///upload = Y if the user has his own content
    float totalWatched;
    double uploadsDuration;
    int * watchedPerMonth;
    float * durationPerMonth;
    const int maxDurationPerMonth = 5000;
    int history_number;
    string * history;  ///pastram mereu ultimele 10 melodii/podcasturi

    public:
    User();
    User(const int age, char* last_name, string first_name);
    User(const int age);
    ~User();
    User(const User & user);
    void setLast_name(char * Last_name);
    void setAge(int age);
    void setPremium(bool Premium);
    void setUploads(char Uploads);
    void setTotalWatched(float Total);
    void setUploadsDuration(double Uploads);
    void setWatchedPerMonth( int * WatchedPerMon);
    void setDurationPerMon( float * DurationPerMonth);
    void setFirst_name(string first_name);
    void setHistory( string * History);
    int getAge();
    bool getPremium();
    char getUploads();
    char * getLast_name();
    float getTotalWatched();
    string getFirst_name();
    string getUserName();
    string * getHistory();
    double getUploadsDuration();
    int * getWatchedPerMonth();
    float * getDurationPerMonth();
    User& operator=(const User & user);
    User& operator++();
    User& operator++(int);
    User& operator--();
    User& operator--(int);
    explicit operator int()
    {
        return (int)this->totalWatched;
    }
    friend ofstream& operator<<(ofstream& fout, const User& u);
    friend istream& operator>>(istream& in, User& u);
    void listenToSong(Melody m,int luna_curenta);
};


User :: User()
{
    age = 0;
    premium = 0;
    uploads = 'N';
    last_name = NULL;
    totalWatched = 0;
    uploadsDuration = 0;
    watchedPerMonth = new int[12];
    for(int i = 0; i < 12; i++)
    {
        watchedPerMonth[i] = 0;
    }
    durationPerMonth = new float[12];
    for(int i = 0; i < 12; i++)
    {
        durationPerMonth[i] = 0;
    }
    first_name = "";
    history_number = 0;
    numberOfUsers++;
    last_name = nullptr;
    watchedPerMonth = nullptr;
    durationPerMonth = nullptr;
    history = nullptr;

}
User :: User(const int age, char* last_name, string first_name)
{
    this->age = age;
    this->premium = 0;
    this->uploads = 'N';
    this->last_name = new char[strlen(last_name) + 1];
    strcpy(this->last_name, last_name);
    this->totalWatched = 0;
    this->uploadsDuration = 0;
    watchedPerMonth = new int[13];
    for(int i = 1; i <= 12; i++)
    {
        watchedPerMonth[i] = 0;
    }
    durationPerMonth = new float[13];
    for(int i = 1; i <= 12; i++)
    {
        durationPerMonth[i] = 0;
    }
    this->first_name = first_name;
    history_number = 0;
    numberOfUsers++;
    watchedPerMonth = nullptr;
    durationPerMonth = nullptr;
    history = nullptr;
}
User :: User(const int age)
{
    this->age = age;
    this->premium = 0;
    this->uploads = 'N';
    char guest[] = "Guest";
    this->last_name = new char[strlen(guest) + 1];
    strcpy(this->last_name, guest);
    this->totalWatched = 0;
    this->uploadsDuration = 0;watchedPerMonth = new int[13];
    for(int i = 1; i <= 12; i++)
    {
        watchedPerMonth[i] = 0;
    }
    durationPerMonth = new float[13];
    for(int i = 1; i <= 12; i++)
    {
        durationPerMonth[i] = 0;
    }
    this->first_name = "User";
    this->history = new string[10];
    history_number = 0;
    numberOfUsers++;
}
User :: ~User()
{
    if(last_name != NULL)
        delete[] last_name;
    if(watchedPerMonth != NULL)
        delete[] watchedPerMonth;
    if(durationPerMonth != NULL)
        delete[] durationPerMonth;
    if(history != NULL)
        delete[] history;
    numberOfUsers --;
}
User :: User(const User & user)
{
    this->age = user.age;
    this->premium = user.premium;
    this->uploads = user.uploads;

    this->last_name = new char[strlen(user.last_name)];
    strcpy(this->last_name, user.last_name);

    this->totalWatched = user.totalWatched;
    this->uploadsDuration = user.uploadsDuration;
   if(user.watchedPerMonth!=nullptr)
   {
    this->watchedPerMonth = new int[12];
    for(int i = 0; i < 12; i++)
    {
        this->watchedPerMonth[i] = user.watchedPerMonth[i];
    }
   }
   if(user.durationPerMonth!=nullptr)
   {
    this->durationPerMonth = new float[12];
    for(int i = 0; i < 12; i++)
    {
        this->durationPerMonth[i] = user.durationPerMonth[i];
    }
   }
    this->first_name = user.first_name;
    history_number = user.history_number;
    this->history = new string[history_number];
    if(user.history!=nullptr)
    {
    for(int i = 0; i < history_number; i++)
    {
        this->history[i] = user.history[i];
    }
    }
    numberOfUsers++;

}
void User :: setLast_name(char * Last_name)
{   if(this->last_name!=NULL) delete[] this->last_name;
    this->last_name = new char[strlen(Last_name) + 1];
    int n = strlen(Last_name);
    for(int i = 0; i < n; i++)
        last_name[i] = Last_name[i];
    last_name[n] = NULL;
}
void User :: setAge(int Age)
{
    age = Age;
}
void User :: setPremium(bool Premium)
{
    premium = Premium;
}
void User :: setUploads(char Uploads)
{
    uploads = Uploads;
}
void User :: setTotalWatched(float Total)
{
    totalWatched = Total;
}
void User :: setUploadsDuration(double Uploads)
{
    uploadsDuration = Uploads;
}
void User :: setWatchedPerMonth( int * WatchedPerMon)
{
    for(int i = 1; i <= 12; i++)
        watchedPerMonth[i] = WatchedPerMon[i];
}
void User :: setDurationPerMon( float * DurationPerMonth)
{
    for(int i = 1; i <= 12; i++)
        durationPerMonth[i] = DurationPerMonth[i];
}
void User :: setFirst_name(string First_name)
{
    first_name = First_name;
}
void User :: setHistory( string * History)
{
     for(int i = 0; i < 10; i++)
        history[i] = History[i];
}
int User :: getAge()
{
    return age;
}
bool User :: getPremium()
{
    return premium;
}
char User :: getUploads()
{
    return uploads;
}
char * User :: getLast_name()
{
    return last_name;
}
float User :: getTotalWatched()
{
    return totalWatched;
}
double User:: getUploadsDuration()
{
    return uploadsDuration;
}
int * User :: getWatchedPerMonth()
{
    return watchedPerMonth;
}
float * User :: getDurationPerMonth()
{
    return durationPerMonth;
}
string User :: getFirst_name()
{
    return first_name;
}
string User :: getUserName()
{
    return username;
}
string * User :: getHistory()
{
    return history;
}
User& User::operator=(const User & user)
{
if(this != &user)
{
    this->age = user.age;
    this->premium = user.premium;
    this->uploads = user.uploads;
    if(this->last_name!=nullptr) delete[] this->last_name;
    this->last_name = new char[strlen(user.last_name)];
    strcpy(this->last_name, user.last_name);

    this->totalWatched = user.totalWatched;
    this->uploadsDuration = user.uploadsDuration;
    if(this->watchedPerMonth!=nullptr) delete[] this->watchedPerMonth;
    if(user.watchedPerMonth!=nullptr)
    {
    this->watchedPerMonth = new int[12];
    for(int i = 0; i < 12; i++)
    {
        this->watchedPerMonth[i] = user.watchedPerMonth[i];
    }

    }
    if(this->durationPerMonth!=nullptr) delete[] this->watchedPerMonth;
    if(user.durationPerMonth!=nullptr)
    {
    this->durationPerMonth = new float[12];
    for(int i = 0; i < 12; i++)
    {
        this->durationPerMonth[i] = user.durationPerMonth[i];
    }
    }
    this->first_name = user.first_name;
    this->history_number = user.history_number;
    if(this->history!=nullptr) delete[] this->history;
    if(user.history!=nullptr)
    {
    this->history = new string[history_number];
    for(int i = 0; i < user.history_number; i++)
    {
        this->history[i] = user.history[i];
    }
    }
}
    return *this;
}
User& User::operator++()   //++ prefix
{
    this->age ++;
    return *this;
}
User& User::operator++(int)  //++postfix
{
    User copie = *this;
    this->age++;
    return copie;
}
User& User::operator--()
{
    this->age --;
    return *this;
}
User& User::operator--(int)
{
    User copie = *this;
    this->age --;
    return copie;
}

ofstream& operator<<(ofstream& fout, const User& u)
{
    fout << "\nNume de familie: "<<u.last_name;
    fout << "\nPrenume: "<<u.first_name;
    fout << "\nVarsta: "<<u.age;
    fout << "\nAbonament Premium: "<<u.premium;
    return fout;
}
istream& operator>> (istream& in, User& u)
{   char aux[100];
    cout << "\nNume de familie: ";
    in>>aux;
    if(u.last_name!=nullptr) delete[] u.last_name;
    u.last_name = new char[strlen(aux)+1];
    strcpy(u.last_name, aux);
    in.ignore(256, '\n');
    cout << "\nPrenume: ";
    getline(in,u.first_name);
    cout << "\nNume de utilizator: ";
    getline(in,u.username);
    cout << "\nVarsta: ";
    in>>u.age;
    return in;
}
void User::listenToSong(Melody m, int luna_curenta)
{
    if(watchedPerMonth[luna_curenta] + m.getmelodyDuration() > maxDurationPerMonth)
    {
        cout << "nu poti asculta";
        return;
    }

    watchedPerMonth[luna_curenta] ++;
    durationPerMonth[luna_curenta] += m.getmelodyDuration();
    totalWatched += m.getmelodyDuration();

    if(history_number == 10)
    {
        for(int i = 0; i < 9; i++)
        {
            history[i] = history[i+1];
        }
        history[9] = m.getnameMelody();
    }
    else
    {
        history[history_number] = m.getnameMelody();
    }
}
#endif // MYUSERFILE_H_INCLUDED
