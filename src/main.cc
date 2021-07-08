#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "dictionary.h"
#define FILE "Data.CS.SFSU.txt"

using namespace std;

map<string, map<string, string>> mm;
map<string, string>::iterator ptr;

void mapSearch(map<string, map<string, string>> m)
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

    cout << "! Opening Data File [" << DATA_FILE << "]" << endl;
    cout << "! Loading Data..." << endl;

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

    cout << "! Loading completed..." << endl;
    cout << "! Closing Data File..."
         << " [" << DATA_FILE_TEMP << "] " << endl;

    file.close();

    mapSearch(mm);
}

void help()
{
    cout << "**********" << endl;
    cout << "PARAMETER HOW-TO: " << endl;
    cout << "1. A Search Key" << endl;
    cout << "2. An optional 'grammar' word i.e Noun, Verb..." << endl;
    cout << "3. An optional 'distinct' keyword" << endl;
    cout << "4. An optional 'reverse' keyword" << endl;
    cout << "**********" << endl;
    cout << "Example: " << endl;
    cout << "\tSearch [0]: book " << endl;
    cout << "\tSearch [1]: book noun" << endl;
    cout << "\tSearch [2]: book noun reverse" << endl;
    cout << "\tSearch [3]: book noun distinct" << endl;
    cout << "\tThese following words are currently in the dictionary: \n"
         << endl;

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
    load();
    intro();

    int count = 0;

    string word;
    vector<string> vWord;

    do
    {
        cout << "Search [ " << count << " ]: ";

        cin >> word;

        if (word == "!help")
        {
            help();
        }

        /* push the word onto the word vector */
        vWord.push_back(word);

        //        wordSearch(vWord, count);

        count += 1;
    } while (count < LOOP);

    return 0;
}
