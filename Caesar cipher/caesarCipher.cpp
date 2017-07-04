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

cypher(string text)
{
    int shift=-1;
    // zabezpieczenie przed zlym formatem
    // przyjmuje liczbe z zakresu [0,26)
    // blokuje litery, i cyfry z poza zakresu
    while(!(shift>=0&&shift<26))
    {
        cout<<" Ile wynosi przesuniecie?"<<endl<<" --> ";
        cin>>shift;
        if(!cin)
        {
            cin.ignore(100,'\n');
            cin.clear();
            cin.sync();
            shift=-1;
        }
        else
        {
            cin.ignore(100,'\n');
        }
    }
    cout<<" Odczytane przesuniecie: "<<shift<<endl;
    cout<<" Tekst: "<<text<<endl;

    for(int i=0; i<text.length(); i++)
    {
        text[i]=toupper(text[i]);
        if((text[i]>='A')&&(text[i]<='Z'))
            text[i]=char(65+(text[i]-(65-shift))%26);
    }
    cout<<" Szyfr: "<<text<<endl;
}

void decipher(string text)
{
    int shift;
    char ask;
    int flag=1;
    //male zabezpieczenie, "efekciarskie"
    while(flag)
    {
        if(flag==1)
        {
            cout<<endl<<" Wybierz opcje:"<<endl;
            cout<<" a --- Szyfr Cezara (przesuniecie = 3)"<<endl;
            cout<<" b --- Dowolne inne (przesuniecie od 0 do 26)"<<endl<<" -> ";
        }
        cin>>ask;
        cin.ignore(100,'\n');
        flag=(ask>='a'&&ask<='b')?0:1;
    }

    cout<<endl<<" Szyfr: "<<text<<endl;
    if(ask=='a')
    {

        for(int i=0; i<text.length(); i++)
        {
            text[i]=toupper(text[i]);
            if((text[i]>='A')&&(text[i]<='Z'))
                text[i]=char(65+(text[i]-42)%26);
        }
        cout<<" Odszyfrowany tekst: "<<text<<endl;
    }
    else if(ask=='b')
    {
        string test=text;
        for(int j=0; j<26; j++)
            for(int i=0; i<text.length(); i++)
            {
                text[i]=toupper(text[i]);
                if((text[i]>='A')&&(text[i]<='Z'))
                    test[i]=char(65+(text[i]-39-j)%26);

                if(text.length()-1==i)
                {
                    cout<<" ";
                    cout.width(2);
                    cout.fill(' ');
                    cout<<j<<"."<<" Odszyfrowany tekst: "<<test<<endl;
                    test=text;
                }

            }

    }
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
            decipher(text);

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
