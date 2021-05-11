#ifndef Admin_H_INCLUDED
#define Admin_H_INCLUDED

class Admin
{
    string adminName, parola;

public:
 Admin()
{
    adminName = "";
    parola = "adminNou";
}
 Admin(string adminName, string parola)
{
    this->adminName = adminName;
    this->parola = parola;
}

 ~Admin()
{
}
 Admin(const Admin & Admin)
{
    this->adminName = Admin.adminName;
    this->parola = Admin.parola;
}

void setAdminName(string adminName)
{
    this->adminName = adminName;
}

void  setParola(string parola)
{
    this->parola= parola;
}

string getAdminName()
{
    return adminName;
}

string  getParola()
{
    return parola;
}
Admin& operator=(const Admin & a)
{
     if(this != &a)
         {this->adminName = a.adminName;
          this->parola = a.parola;
         }
    return *this;
}


friend istream& operator>>(istream& in, Admin& u);
};
istream& operator>> (istream& in, Admin& u)
{
    in.ignore(256, '\n');
    cout << "\nNume: ";
    getline(in,u.adminName);
    cout << "\nIntroduceti parola dorita: ";
    in>>u.parola;
    cout << "\nRepetati parola: ";
    string aux;
    in>>aux;
    bool parolaOk = 0;
    while(!parolaOk)
      if(aux == u.parola)  { cout<<"Admin creat cu succes!\n"; parolaOk = 1;}
      else {cout<<"Reintroduceti parola!\n";
            in>>aux;
           }
    return in;
}
#endif // Admin_H_INCLUDED
