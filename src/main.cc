#include <fstream>
#include <iostream>
#include <map>
#include <string>

#define FILE "Data.CS.SFSU.txt"

using namespace std;

int counter = 0;

map<string, map<string, string>> mm;
map<string, string>::iterator ptr;

void help(void)
{
    cout << "PARAMETER HOW-TO: " << endl;
    cout << "1. A Search Key" << endl;
    cout << "2. An optional 'grammar' word i.e Noun, Verb..." << endl;
    cout << "3. An optional 'distinct' keyword" << endl;
    cout << "4. An optional 'reverse' keyword" << endl;
    cout << endl;
}

void introduction(void)
{
    cout << endl;
    cout << "====== Dictionary 340 C++ ======" << endl;
    cout << "------ Keywords: " << mm.size() << endl;
    cout << "------ Definitions: " << counter << endl;
    cout << endl;
    help();
}

void search_dictionary(string s)
{
    cout << "Map Search..." << s << endl;
}

void display_dictionary(map<string, map<string, string>> m)
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

void parse(void)
{
    string d, k, s;

    fstream file(FILE, ios::in);

    cout << "! Opening Data File [" << FILE << "]"
         << "\n"
         << "! Loading Data..." << endl;

    if (file.is_open())
    {
        while (getline(file, d, '.'))
        {
            counter += 1;
            getline(file, k, '|');

            file >> s;

            mm.insert(make_pair(k, map<string, string>()));
            mm[k].insert(make_pair(s, d));
        }
    }

    cout << "! Loading Completed..."
         << "\n"
         << "! Closing Data File..." << endl;

    file.close();
    //    mapOut(mm);
    introduction();
}

int main(void)
{
    int i = 0;
    string term;

    parse();

    do
    {
        cout << "Search [ " << i << " ]: ";

        cin >> term;

        if (term.compare("!help") == 0)
            help();

        search_dictionary(term);

        i += 1;
    } while (i < mm.size());

    return 0;
}