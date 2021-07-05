#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "dictionary.h"

using namespace std;

/* declared vectors globally */
vector<string> definition, keyword, speech;

void keywordSearch(vector<string> &w)
{
    for (vector<string>::iterator it = w.begin(); it != w.end(); it++)
    {
        cout << "Keyword => " << *it << endl;
    }
}

void speechSearch(vector<string> &s)
{
    for (vector<string>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << "Speech => " << *it << endl;
    }
}

void definitionSearch(vector<string> &d)
{
    for (vector<string>::iterator it = d.begin(); it != d.end(); it++)
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
    cout << "Keywords: " << keyword.size() << endl;
    cout << "Speech: " << speech.size() << endl;
    cout << "Definitions: " << definition.size() << endl;
    cout << endl;
    help();
}

void load()
{
    int i = 0;
    string re_open, temp1, temp2, token, txtData[20];

    cout << "! Opening Data File [" << DATA_FILE << "]" << endl;
    cout << "! Loading Data..." << endl;

    /* Open stream to get definitions */
    fstream file(DATA_FILE, ios::in);

    if (!file)
    {
        cerr << "File could not be opened!" << endl;
        exit(1);
    }

    /* Here I open another stream to output both the keyword and grammar */
    cout << "! Opening [TEMP] Data File for Writing"
         << " [" << DATA_FILE_TEMP << "] " << endl;
    fstream ofile(DATA_FILE_TEMP, ios::out);

    /* Set the definition vector */
    while (getline(file, token, '\n'))
    {
        file >> temp1;
        ofile << temp1 << endl;
        definition.push_back(token);
    }

    /* close both connections */
    cout << "! Closing [Temp] Data File for Writing"
         << " [" << DATA_FILE_TEMP << "] " << endl;
    ofile.close();

    cout << "! Closing Data File"
         << " [" << DATA_FILE << "] " << endl;
    file.close();

    /* Opening another file for reading */
    cout << "! Opening Temp Data File for Reading [" << DATA_FILE_TEMP << "]" << endl;
    cout << "! Loading Temp Data..." << endl;

    fstream reopen_file(DATA_FILE_TEMP, ios::in);

    /* check if the file was opened successfully */
    if (!reopen_file)
    {
        cerr << "Temp File could not be opened!" << endl;
        exit(EXIT_FAILURE);
    }

    while (getline(reopen_file, re_open, '|'))
    {
        re_open.erase(remove(re_open.begin(), re_open.end(), '\n'), re_open.end());
        reopen_file >> temp2;
        keyword.push_back(re_open);
        speech.push_back(temp2);
    }

    reopen_file.close();

    cout << "! Closing Temp Data File for Reading..."
         << " [" << DATA_FILE_TEMP << "] " << endl;

    /* This is here to show the contents of the vectors 
        definitionSearch(definition);
        keywordSearch(keyword);
        speechSearch(speech);

        cout << "Definition Size: " << definition.size() << endl;
        cout << "Keyword Size: " << keyword.size() << endl;
        cout << "Speech Size: " << speech.size() << endl; */
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

        vWord.push_back(word);

        keywordSearch(vWord);

        count += 1;
    } while (count < 2);

    return 0;
}