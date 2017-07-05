#include <iostream>
using namespace std;

void menu()
{
    cout<<" Menu"<<endl;
    cout<<" p --- Pokaz Menu"<<endl;
    cout<<" d --- Odszyfruj"<<endl;
    cout<<" c --- Zaszyfruj"<<endl;
    cout<<" k --- Koniec"<<endl;
}

// A - 65   --- 13
// M - 77
// Z - 90   --- 13
void cypher(string text, string key)
{
    cout<<endl<<" Odczytany: "<<text<<endl;

    for(int i=0, j=0; i<text.length(); i++)
    {
        key[i]=toupper(key[i]);
        text[i]=toupper(text[i]);
        if(text[i]>='A' && text[i]<='Z')
        {
            j=j%key.length();
            text[i]=((text[i]+key[j])%26)+'A';
            j++;
        }
    }

    cout<<" Odpowiedz: "<<text<<endl;
}

void decipher(string text, string key)
{
    cout<<endl<<" Odczytany: "<<text<<endl;


    for(int i=0, j=0; i<text.length(); i++)
    {
        key[i]=toupper(key[i]);
        text[i]=toupper(text[i]);
        if(text[i]>='A' && text[i]<='Z')
        {
            j=j%key.length();
            text[i]=((text[i]-key[j]+26)%26)+'A';
            j++;
        }

    }
    cout<<" Odpowiedz: "<<text<<endl;
}

int main()
{
    string text;
    string key;
    char ask='p';

    while(ask!='k')
    {
        switch(ask)
        {
        case 'p' :
        {
            cout<<endl;
            menu();
            cout<<endl<<" Co chcesz zrobic?"<<endl;
            cout<<" --> ";
            cin.sync();
            cin>>ask;
            break;
        }
        case 'd' :
        {
            cin.clear();
            cin.sync();

            cout<<" Podaj klucz (tekst) "<<endl<<" --> ";
            //brak zabezpieczenia dla liczb, wydaje sie zbedne
            getline(cin,key);

            cout<<" Podaj tekst do odszyfrowania"<<endl<<" --> ";
            getline(cin,text);
            decipher(text,key);

            cout<<endl<<" Co chcesz zrobic?"<<endl;
            cout<<" --> ";
            cin.sync();
            cin>>ask;
            break;
        }

        case 'c' :
        {
            cin.clear();
            cin.sync();
            cout<<" Podaj klucz (tekst) "<<endl<<" --> ";
            getline(cin,key);

            cout<<" Podaj tekst do szyfrowania"<<endl<<" --> ";
            getline(cin,text);
            cypher(text,key);

            cout<<endl<<" Co chcesz zrobic?"<<endl;
            cout<<" --> ";
            cin.sync();
            cin>>ask;
            break;
        }

        default  :
        {
            cin.ignore(100,'\n');
            cout<<endl;
            cout<<" Bledny znak!!"<<endl;
            cout<<" --> ";
            cin>>ask;
            break;
        }
        }
    }
    cout<<" Koniec pracy programu"<<endl<<endl;
    system("pause");
    return 0;
}
