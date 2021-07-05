#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "dictionary.h"

using namespace std;

/* declared vectors globally */
vector<string> definition, keyword, speech;

void keywordSearch(vector<string> &k)
{
    cout << "\t";
    for (vector<string>::iterator it = k.begin(); it != k.end(); it++)
    {
        cout << *it << ", ";
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
        cout << *it << endl;
    }
}

/* search keyword for a matching word */
void wordSearch(vector<string> &w, int cnt)
{
    int location = 0;
    cout << w.at(cnt) << " [" << speech.at(cnt) << "] : " << endl;

    vector<string>::iterator it;

    it = find(keyword.begin(), keyword.end(), w.at(cnt));

    if (it != keyword.end())
    {
        location = (it - keyword.begin());
        cout << "|" << endl;
        cout << definition.at(location + 1) << endl;
        cout << "|" << endl;
    }
    else
    {
        cout << "That word isn't part of the dictionary!\n"
             << endl;
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
    cout << "\tThese following words are currently in the dictionary: \n"
         << endl;

    keywordSearch(keyword);

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

/* This function parses the file and populates the vectors */
void load()
{
    int i = 0;
    string re_open, temp1, temp2, temp3, temp4, temp5, token, txtData[20];

    cout << "! Opening Data File [" << DATA_FILE << "]" << endl;
    cout << "! Loading Data..." << endl;

    /* Open stream to get definitions */
    fstream file(DATA_FILE, ios::in);

    /* Check for errors */
    if (!file)
    {
        cerr << "File could not be opened!" << endl;
        exit(1);
    }

    /* Open another stream to output both the keyword and grammar */
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

    /* Close both connections */
    cout << "! Closing [Temp] Data File for Writing"
         << " [" << DATA_FILE_TEMP << "] " << endl;
    ofile.close();

    cout << "! Closing Data File"
         << " [" << DATA_FILE << "] " << endl;
    file.close();

    /* Open another file for reading */
    cout << "! Opening Temp Data File for Reading [" << DATA_FILE_TEMP << "]" << endl;
    cout << "! Loading Temp Data..." << endl;

    fstream reopen_file(DATA_FILE_TEMP, ios::in);

    /* Check for errors */
    if (!reopen_file)
    {
        cerr << "Temp File could not be opened!" << endl;
        exit(EXIT_FAILURE);
    }

    while (getline(reopen_file, re_open, '|'))
    {
        //cout << "re_open: " << re_open << endl;
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

        wordSearch(vWord, count);

        count += 1;
    } while (count < LOOP);

    return 0;
}