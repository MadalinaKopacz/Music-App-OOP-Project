#include <bits/stdc++.h>
#include "MyMelodyFile.h"
#include "MyUserFile.h"
#include "MyAlbumFile.h"
#include "MyPodcastFile.h"
#include "PodcastRelaxare.h"
#include "PodcastStudiu.h"
#include "Admin.h"
#include "playable.h"
#include "MelodiiPop.h"
using namespace std;
ifstream fin("bazaDateAlbume.txt");
ofstream fout("bazaDateUseri.txt");
int User::numberOfUsers = 0;

class MeniuInteractiv{
private:
    static MeniuInteractiv *obiect;
public:
    static MeniuInteractiv* getInstance(){
        if(!obiect) obiect=new MeniuInteractiv();
        return obiect;
    }
    void meniu(){
    vector <User> Useri;
    set <string> numeUseri;
    list <Admin> Admini;
    map <int, vector<string> > albumAni;
    vector <Melody> tot;
    vector <Podcast> totpod;
    int k=1;
    while(k==1)
        {
        cout<<"Pentru a te loga ca admin apasa <<A>>.\n";
        cout<<"Pentru a te loga ca utilizator apasa <<U>>\n";
        cout<<"Pentru a iesi din aplicatie apasa <<I>>\n";
        char actiune;
        cin>>actiune;
        if(actiune == 'A')
        {
            int l = 1;
        int ct = 0;
            while(l){
        if(ct == 0)
        {
        cout<<"Nu ai cont? Pentru a crea cont nou de admin apasa tasta 1.\n";
        cout<<"Nu iti mai amintesti parola? Pentru a o schimba apasa tasta 2.\n";
        cout<<"Ai deja cont? Pentru a te conecta apasa tasta 3.\n";
        }
        else{
        cout<<"Pentru a adauga un album apasa tasta 4.\n";
        cout<<"Pentru a adauga un podcast apasa tasta 5.\n";
        cout<<"Pentru a sterge un podcast apasa tasta 6.\n";
        cout<<"Pentru a te deconecta apasa tasta 0.\n";
        }

        int comanda;
        cin>>comanda;
        if(comanda == 1 || comanda == 2 || comanda == 3) ct++;
        switch(comanda)
        {
        case 1:{
            Admin nou;
            cin>>nou;
            Admini.push_back(nou);
            cout<<"Cont creat cu succes!\n";
            cout<<"Esti conectat!\n";
            break;
        }
        case 2:{
            cout<<"Introduceti noua parola: ";
            string p1, p2;
            cin>>p1;
            bool parolaOk = 0;
            cout<<"Reintroduceti parola: ";
            cin>>p2;
            while(!parolaOk)
            if(p1 == p2)   parolaOk = 1;
            else {cout<<"Reintroduceti parola!\n";
            cin>>p2;
            cout<<"Esti conectat!\n";
            break;
           }
        }
        case 3:{
            string numeAux;
            cout<<"Introduceti numele dumneavoastra: ";
            cin>>numeAux;
            bool numeOk = 0;
            for(list<Admin>::iterator it=Admini.begin(); it != Admini.end(); ++it)
            {
                Admin aux;
                aux = *it;
                if(aux.getAdminName() == numeAux) {numeOk = 1; break;}
            }
            while(numeOk == 0)
                        {cout << "Nume gresit. Reintroduceti numele:";
                         for(list<Admin>::iterator it=Admini.begin(); it != Admini.end(); ++it)
                            {   Admin aux;
                                aux = *it;
                                if(aux.getAdminName() == numeAux) {numeOk = 1; break;}
                            }
                        }
            string parolaAux;
            cout<<"Introduceti parola dumneavoastra: ";
            cin>>parolaAux;
            bool parolaOk = 0;
            for(list<Admin>::iterator it=Admini.begin(); it != Admini.end(); ++it)
            {
                Admin aux;
                aux = *it;
                if(aux.getParola() == parolaAux) {parolaOk = 1; break;}
            }
            while(parolaOk == 0)
                {cout << "Parola gresita. Reintroduceti parola.";
                 for(list<Admin>::iterator it=Admini.begin(); it != Admini.end(); ++it)
                            {   Admin aux;
                                aux = *it;
                                if(aux.getParola() == parolaAux) {parolaOk = 1; break;}
                            }
                        }
                cout<<"Esti conectat!\n";
                break;
           }
        case 4:{
            Album a;
            fin>>a;
            cout<<"Album adaugat cu succes din baza de date.\n";
            bool anGasit=0;
            for(auto it : albumAni)
                if(it.first == a.getAnAparitie()) anGasit = 1;
            if(anGasit) albumAni[a.getAnAparitie()].push_back(a.getdenumireAlbum());

            else
            {vector <string> nouaDen;
             nouaDen.push_back(a.getdenumireAlbum());
             albumAni.insert({a.getAnAparitie(), nouaDen});
            }
            Melody * auxm = a.getMelodii();
            for(int i = 0; i < a.getNrMelodii(); i++)
                tot.push_back(auxm[i]);
            break;
        }
        case 5:{
            Podcast p;
            cin>>p;
            totpod.push_back(p);
            break;
        }
        case 6:{
            cout<<"Introduceti numele podcastului care doriti sa fie sters: ";
            string numepodsterg; cin>>numepodsterg;
            vector <Podcast> auxip;
            for(int ind = 0; ind < totpod.size();ind++)
                if(totpod[ind].getnamePodcast()!=numepodsterg)
                    auxip.push_back(totpod[ind]);
            totpod = auxip;
            break;
        }
         case 0:
         {
             l=0; break;
         }
        }
    }
        }
        if (actiune == 'U')
        {
        int l = 1;
        int ct = 0;
        User userCurent;
        while(l){
        if(ct == 0)
        {
        cout<<"Nu ai cont? Pentru a-ti crea un cont nou de utilizator apasa tasta 1!\n";
        cout<<"Ai deja cont? Pentru a te conecta apasa tasta 2!\n";
        }
        else{
        cout<<"Esti conectat!\n";
        cout<<"Pentru a-ti schimba tipul abonamentulului apasa tasta 3!\n";
        cout<<"Pentru a da play la o melodie apasa tasta 4!\n";
        cout<<"Pentru a rula un podcast apasa tasta 5!\n";
        cout<<"Pentru a vedea cate minute ai petrecut ascultand articole media apasa tasta 6.\n";
        cout<<"Pentru a te deconecta apasa tasta 0.\n";
        }
        int comanda;
        cin>>comanda;
        if(comanda == 1 || comanda == 2) ct++;
        switch(comanda)
        {
        case 1:{
            User nou;
            cin>>nou;
            numeUseri.insert(nou.getUserName());
            Useri.push_back(nou);
            userCurent = nou;
            cout<<"Cont creat cu succes!\n";
            fout<<nou<<"\n";
            break;
        }
        case 2:{
            string numeAux;
            cout<<"Introduceti numele de utilizator al dumneavoastra: ";
            cin>>numeAux;
            bool numeOk = 0;
            for(string it : numeUseri)
                if(it==numeAux) {numeOk = 1; break;}

            while(numeOk == 0)
                        {cout << "Nu exista niciun cont aferent acestui username.\n";
                         cout<<"Aveti cont? Apasati 1 si Reintroduceti Username-ul!\n";
                         cout<<"Daca nu aveti cont, apasati 2 si continuati procesul de inregistrare!\n";
                         int comandacont; cin>>comandacont;
                         if(comandacont == 1)
                         {  string userNameAux;
                            cin>>userNameAux;
                            for(User it : Useri)
                                if(it.getUserName()==userNameAux) { userCurent = it; numeOk = 1; break;}
                         }
                         else
                         {
                             User nou;
                             cin>>nou;
                             Useri.push_back(nou);
                              userCurent = nou;
                              cout<<"Cont creat cu succes!\n";
                         }
                        }
                break;
        }
        case 3:{
            if(userCurent.getPremium())
            {   cout<<"Ai deja abonament premium! Doresti sa schimbi tipul abonamentului? Daca da, apasa tasta 1.\n";
                int tasta;
                cin>>tasta;
                if(tasta==1) userCurent.setPremium(0);
            }
            else
            {
                cout<<"Doresti sa iti upgradezi abonamentul la abonament premium? Daca da, apasa tasta 1.Daca nu, apasa 2.\n";
                bool tasta;
                cin>>tasta;
                if(tasta==1) userCurent.setPremium(tasta);

            }
            for(int i = 0; i <Useri.size();i++)
                if(Useri[i].getUserName()==userCurent.getUserName())
                     Useri[i].setPremium(1);
            break;
        }
        case 4:{
           cout<<"Ce melodie doresti sa asculti?\n";
           string melAux; bool gasitMel = 0;
           getline(cin>>std::ws,melAux);
           for(int i = 0; i < tot.size();i++)
              if(melAux == tot[i].getnameMelody()) gasitMel = 1;
            if(gasitMel==1)
            {
                cout<<"Asculti "<<melAux<<"\n";
                cout<<"Daca iti place, poti apasa pe 1 sa ii dai like!\n";
                cout<<"Daca nu iti place, poti apasa pe 2 sa ii dai dislike!\n";
                cout<<"Daca nu doresti sa reactionezi, apasa 3 pentru a iesi din meniul de like-uri!\n";
                int comLike; cin>>comLike;
                LikeMelody like;
                {if(comLike==1) like.Liked();}
                {if(comLike==2) like.Disliked();}
            }
            if(gasitMel==0)
                cout<<"Nu am gasit melodia pe care o doresti:(\n";
            break;
        }
        case 5:{
            if(userCurent.getPremium()==0)
                cout<<"Podcasturile pot fi accesate doar in pachetul premium. Daca doresti sa accesezi un podcast te invitam sa iti upgradezi pachetul!\n";
            else{
             cout<<"Daca stii ce podcast doresti sa asculti apasa 1.\nDaca nu, apasa 2 pentru a-ti recomanda noi cateva pe subiectele tale de interes!\n";
             int stiutPod;cin>>stiutPod;
             if(stiutPod==1)
             {
             cout<<"Ce podcast doresti sa asculti?\n";
             string podAux; bool gasitPod = 0;
             getline(cin>>std::ws,podAux);
            for(Podcast it : totpod)
               if(podAux == it.getnamePodcast()) {gasitPod=1; break;}
            if(gasitPod)
            {
                cout<<"Asculti "<<podAux<<"\n";
                cout<<"Daca iti place, poti apasa pe 1 sa ii dai like!\n";
                cout<<"Daca nu iti place, poti apasa pe 2 sa ii dai dislike!\n";
                cout<<"Daca nu doresti sa reactionezi, apasa 3 pentru a iesi din meniul de like-uri!\n";
                int comLike; cin>>comLike;
                LikePodcast like;
                if(comLike==1) like.Liked();
                if(comLike==2) like.Disliked();
            }
            }
            else{
                cout<<"Introdu un subiect de interes pentru tine!\n";
                 string podSub; bool gasitSub = 0;
               cin>>podSub;
                for(Podcast it : totpod)
                   if(podSub == it.getsubjectPodcast())
                      cout<<it.getnamePodcast()<<"\n";

            }

        }
        break;}
         case 0:
         {
             l=0; break;
         }
        }
        }}
        if(actiune == 'I')
        {
            k = 0;break;
        }
}
}
}
    ;
MeniuInteractiv* MeniuInteractiv::obiect=0;
int main()
{
    MeniuInteractiv *meniulMeu=meniulMeu->getInstance();
    meniulMeu->meniu();
    return 0;
}
