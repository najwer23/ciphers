#include <iostream>
#include <bitset>
#include <map>
using namespace std;

void menu()
{
    cout<<" Menu"<<endl;
    cout<<" p --- Pokaz Menu"<<endl;
    cout<<" d --- Odszyfruj"<<endl;
    cout<<" c --- Zaszyfruj"<<endl;
    cout<<" k --- Koniec"<<endl;
}

void createDictionary(map<char, string>& dictionary)
{
    char A=65; // A
    string code;

    for(int i=0, k=0; i<26; i++)
    {
        if(i==9)
            k--;
        else if(i==21)
            k--;

        bitset<5> binary(k); //z int na format binarny
        code=binary.to_string(); //z binarnego na stringa

        for(int j=0; j<code.length(); j++)
        {
            if(code[j]=='0')
                code[j]='a';
            else
                code[j]='b';
        }

        dictionary.insert(pair<char,string>(A+i,code));
        k++;
    }
}

void cypher(string text, map<char, string>& dictionary)
{
    cout<<" Tekst: "<<text<<endl;
    cout<<" Szyfr (litery): "<<endl;
    for (int i=0; i<text.length(); i++)
    {
        text[i]=toupper(text[i]);

        if(text[i]>='A' && text[i]<='Z')
            cout<<dictionary[text[i]]<<" ";
    }
    cout<<endl<<" Szyfr (wyrazy): "<<endl;
    for (int i=0; i<text.length(); i++)
    {
        text[i]=toupper(text[i]);

        if(text[i]>='A' && text[i]<='Z')
            cout<<dictionary[text[i]];
        else
            cout<<" ";
    }
    cout<<endl;
}

void decipher(string text, map<char, string>& dictionary)
{
    int j;
    string test;
    string result;
    map<char,string>::iterator it;

    cout<<" Szyfr: "<<text;
    for (int i=0; i<text.length(); i++)
    {
        text[i]=tolower(text[i]);
        test="";

        if(text[i]>='a' && text[i]<='z')
        {
            for(j=i; j<i+5; j++)
                test+=text[j];
            i=j-1;

            for (it=dictionary.begin(); it!=dictionary.end(); it++)
            {
                if(it->second==test)
                {
                    result+=it->first;
                    break;
                }
            }
        }
        else
        {
            result+=" ";
        }
    }
    cout<<endl<<" Teskt: "<<result<<endl;
}

int main()
{
    map<char,string> dictionary;
    createDictionary(dictionary);
    string text;
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

            cout<<" Podaj tekst do odszyfrowania"<<endl<<" --> ";
            getline(cin,text);
            decipher(text,dictionary);

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

            cout<<" Podaj tekst do szyfrowania"<<endl<<" --> ";
            getline(cin,text);
            cypher(text,dictionary);

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
