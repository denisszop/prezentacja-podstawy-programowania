#include <iostream>
using namespace std;
//nie trzeba poprzedzac cin cout specyfikatorem std::
#include <fstream>
#include <string>
//************************
int main()
{
    string plikA;
    string plikB;
    //--------------------
    cout << " Podaj nazwe pliku wejsciowego: ";
    // odpowiednik printf() dla C
    cin >> plikA;
    // odpowiednik scanf() dla C
    ifstream czyt(plikA.c_str());
    //definicja obiektu klasy ifstream (strumien wejsciowy)
    
    if(!czyt)
    {
        cout << " Nie moge otworzyc tego pliku";
        return 1;
    }
    
    //--------------------
    
    cout << " Podaj nazwe pliku wyjsciowego: ";
    cin >> plikB;
    ofstream pisz(plikB.c_str());
    //definicja obiektu klasy ofstream (strumien wyjsciowy)
    
    if(!pisz)
    {
        cout << " Nie moge otworzyc tego pliku";
        return 1;
    }
    
    // //---przepisywanie---
    // char c;
    // do
    // {
    //     czyt.get(c);
    //     pisz.put(c);
    // }
    // while(!czyt.eof());

    string c;
    do
    {
        getline(czyt, c);
        if (!czyt.eof())
            pisz << c << endl;
        else
            pisz << c;
    }
    while(!czyt.eof());
        //----sprawdzanie---- 
        if(czyt.eof()) { // ???
            cout << "\n Przepisano z " << plikA << " do " << plikB << ".\n";
        }
        else
            cout << " Blad czytania\n";
        
    
    return 0;
}
