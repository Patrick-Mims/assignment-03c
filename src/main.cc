#include <fstream>
#include <iostream>
#include <map>
#include <string>

#include "dictionary.h"
#define FILE "Data.CS.SFSU.txt"

using namespace std;

map<string, map<string, string>> mm;
map<string, string>::iterator ptr;

void map_search(string s)
{
    cout << "Map Search..." << s << endl;
}

void mapOut(map<string, map<string, string>> m)
{
    map<string, map<string, string>>::iterator it;
    map<string, string>::iterator ptr;

    for (it = m.begin(); it != m.end(); it++)
    {
        for (ptr = it->second.begin(); ptr != it->second.end(); ptr++)
        {
            cout << it->first << " -> " << ptr->first << " \n-> " << ptr->second << endl;
        }
    }
}

void load()
{
    string d, k, s;

    fstream file(FILE, ios::in);

    cout << "! Opening Data File [" << DATA_FILE << "]"
         << "\n"
         << "! Loading Data..." << endl;

    if (file.is_open())
    {
        while (getline(file, d, '.'))
        {
            getline(file, k, '|');

            file >> s;

            mm.insert(make_pair(k, map<string, string>()));
            mm[k].insert(make_pair(s, d));
        }
    }

    cout << "! Loading completed..."
         << "\n"
         << "! Closing Data File..."
         << " [" << DATA_FILE << "] " << endl;

    file.close();
    //    mapOut(mm);
}

void help()
{
    cout << "PARAMETER HOW-TO: " << endl;
    cout << "1. A Search Key" << endl;
    cout << "2. An optional 'grammar' word i.e Noun, Verb..." << endl;
    cout << "3. An optional 'distinct' keyword" << endl;
    cout << "4. An optional 'reverse' keyword" << endl;
    cout << endl;
}

void intro()
{
    cout << endl;
    cout << "====== Dictionary 340 C++ ======" << endl;
    cout << "------ Keywords: " << endl;
    cout << "------ Definitions: " << endl;
    cout << endl;
    help();
}

int main(void)
{
    int i = 0;
    string term;

    load();
    intro();

    do
    {
        cout << "Search [ " << i << " ]: ";

        cin >> term;

        if (term == "!help")
            help();

        map_search(term);

        i += 1;
    } while (i < LOOP);

    return 0;
}