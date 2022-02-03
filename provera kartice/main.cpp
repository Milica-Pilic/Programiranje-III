#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <regex>
#include <fstream>

using namespace std;

int main()
{
    ifstream fajl("text.txt");
    string brojkartice;
    regex provera1("[0-9][0-9][0-9][0-9][ ][0-9][0-9][0-9][0-9][ ][0-9][0-9][0-9][0-9][ ][0-9][0-9][0-9][0-9]");
    smatch m;
    if(fajl.is_open())
    {
    for(int i = 1; getline(fajl,brojkartice); i++)
    {
        if(regex_match(brojkartice,provera1))
        {
            cout << "Unos validan" << endl;
            cout << endl;
        }
        else
        {
            cout << "Nije dobro unet broj kartice na liniji - " << i << "." << endl;
        }
    }
        fajl.close();
    }
    else
    {
        cout << "Greska pri otvaranju fajla." << endl;
    }


    return 0;
}
