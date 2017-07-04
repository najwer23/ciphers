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
void cypher(string text)
{
    cout<<endl<<" Odczytany tekst: "<<text<<endl;
    int first='A';
    int mid='M';
    int last='Z';
    int distance;

    for(int i=0; i<text.length(); i++)
    {
        text[i]=toupper(text[i]);
        if(text[i]>=first&&text[i]<=last)
        {
            if(text[i]<=mid)
            {
                distance=text[i]-first;
                text[i]=last-distance;
            }
            else
            {
                distance=last-text[i];
                text[i]=first+distance;
            }
        }

    }
    cout<<" Odpowiedz: "<<text<<endl;

}

int main()
{
    string text;
    char ask='p';    //pytanie do menu
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
            cout<<endl<<" Podaj tekst do odszyfrowania"<<endl<<" --> ";
            getline(cin,text);
            cypher(text);

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
            cout<<endl<<" Podaj tekst do szyfrowania"<<endl<<" --> ";
            getline(cin,text);
            cypher(text);

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
