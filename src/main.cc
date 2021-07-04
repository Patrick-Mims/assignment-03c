#include <algorithm>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <regex>

#include "dictionary.h"

using namespace std;

void keywordSearch(vector<string> &w)
{
    for (vector<string>::iterator it = w.begin(); it != w.end(); ++it)
    {
        cout << "Keyword search: " << *it << endl;
    }
}

void speechSearch(vector<string> &s)
{
    for (vector<string>::iterator it = s.begin(); it != s.end(); ++it)
    {
        cout << "Speech search: " << *it << endl;
    }
}

void definitionSearch(vector<string> &d)
{
    for (vector<string>::iterator it = d.begin(); it != d.end(); ++it)
    {
        cout << *it << endl;
    }
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
    cout << endl;
}

void intro()
{
    cout << endl;
    cout << "Dictionary 340 C++" << endl;
    cout << "Keywords: [KEYWORD_SIZE]" << endl;
    cout << "Definitions: [DEFINITION_SIZE]" << endl;
    cout << endl;
    help();
}

void load()
{
    int i = 0;
    string token;
    string t;
    string txtData[20];

    vector<string> keyword;
    vector<string> speech;
    vector<string> definition;

    cout << "! Opening Data File..." << DATA_FILE << endl;
    cout << "! Loading Data..." << endl;

    fstream file(DATA_FILE, ios::in);

    if (!file)
    {
        cerr << "File could not be opened!" << endl;
        exit(1);
    }

    cout << "! Loading Completed..." << endl;
    cout << "! Closing Data File..." << endl;

    string line1;

    while (getline(file, token, '|'))
    {
        file >> line1;
        speech.push_back(line1);
        definition.push_back(token);
    }

    file.close();

    speechSearch(speech);
    definitionSearch(definition);
}

/*
    you have to read in book|noun into another file , then read it back in 
    and use | as a delimeter. The store the token in the vector

*/

int main(void)
{
    load();
    intro();

    int count = 0;

    string word;
    vector<string> w;

    do
    {
        cout << "Search [ " << count << " ]: ";

        cin >> word;

        if (word == "!help")
        {
            help();
        }

        w.push_back(word);

        keywordSearch(w);

        count += 1;
    } while (count < 2);

    return 0;
}