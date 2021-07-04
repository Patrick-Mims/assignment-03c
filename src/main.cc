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
        cout << "Keyword => " << *it << endl;
    }
}

void speechSearch(vector<string> &s)
{
    for (vector<string>::iterator it = s.begin(); it != s.end(); ++it)
    {
        cout << "Speech => " << *it << endl;
    }
}

void definitionSearch(vector<string> &d)
{
    for (vector<string>::iterator it = d.begin(); it != d.end(); ++it)
    {
        cout << "Definition => " << *it << endl;
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
    string re_open;
    string temp1;
    string temp2;
    string token;
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

    fstream ofile(DATA_FILE_TEMP, ios::out);

    while (getline(file, token, '\n'))
    {
        file >> line1;
        cout << line1 << endl;
        ofile << line1 << endl;
        /*
        speech.push_back(line1);
        definition.push_back(token);
        */
    }

    ofile.close();
    file.close();

    cout << "! Opening Data File..." << DATA_FILE << endl;
    cout << "! Loading Data..." << endl;

    fstream reopen_file(DATA_FILE_TEMP, ios::in);

    while (getline(reopen_file, re_open, '|'))
    {
        reopen_file >> temp1;
        reopen_file >> temp2;

        cout << "**" << endl;
        re_open.erase(remove(re_open.begin(), re_open.end(), '\n'), re_open.end());
        //cout << "re_open |" << re_open << "| " << endl;
        keyword.push_back(re_open);
        /*
        cout << "ro1 => (" << temp1 << ") " << endl;
        cout << "ro2 => [" << temp2 << "] " << endl;
        cout << "**" << endl;
        */
    }

    reopen_file.close();

    cout << "! Loading Completed..." << endl;
    cout << "! Closing Data File..." << endl;

    cout << "Definition Size: " << definition.size() << endl;
    cout << "Speech Size: " << speech.size() << endl;

    definitionSearch(definition);
    keywordSearch(keyword);
    speechSearch(speech);
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