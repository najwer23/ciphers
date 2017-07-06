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

void cypher(string text)
{
    string result;
    int number;

    cout<<" Tekst: "<<text<<endl;
    for(int i=0; i<text.length(); i++)
    {
        text[i]=toupper(text[i]);
        if(text[i]>='A'&&text[i]<='Z')
        {
            number=((int)(text[i]-'A'+1));
            result+=to_string(number)+"-";
        }
        else
        {
            result[result.length()-1]=' ';
        }
    }

    result[result.length()-1]=' ';
    cout<<" Szyfr: "<<result<<endl;
}

void decipher(string text)
{
    cout<<" Szyfr: "<<text<<endl;
    int number;
    char mark;
    string result;
    string test="0";
    int k=0;

    for(int i=0; i<text.length(); i++)
    {
        do
        {
            mark=text[i];
            test+=mark;
            i++;
        }
        while(!(mark=='-'|| mark==' '));
        i--;

        number=stoi(test)+64;
        result+=char(number);
        if(mark!='-')
        {
            result+=" ";
        }
        test="";
    }
    cout<<" Tekst: "<<result;
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
