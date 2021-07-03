#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define DATA_FILE "Data.CS.SFSU.txt"

using namespace std;

void vector_search_definitions(vector<string> &d)
{
    for (vector<string>::iterator it = d.begin(); it != d.end(); ++it)
    {
        cout << *it << endl;
    }
}

void vector_search_grammar(vector<string> &g)
{
    for (vector<string>::iterator it = g.begin(); it != g.end(); ++it)
    {
        cout << "Searching Grammar Vector => " << *it << endl;
    }
}

void helpMenu()
{
    cout << "\t**********" << endl;
    cout << "\tPARAMETER HOW-TO: " << endl;
    cout << "\t1. A Search Key" << endl;
    cout << "\t2. An optional 'grammar' word i.e Noun, Verb..." << endl;
    cout << "\t3. An optional 'distinct' keyword" << endl;
    cout << "\t4. An optional 'reverse' keyword" << endl;
    cout << "\t**********" << endl;
    cout << "\tExample: " << endl;
    cout << "\t\tSearch [0]: book " << endl;
    cout << "\t\tSearch [1]: book noun" << endl;
    cout << "\t\tSearch [2]: book noun reverse" << endl;
    cout << "\t\tSearch [3]: book noun distinct" << endl;
    cout << endl;
}

void introduction()
{
    cout << endl;
    cout << "Dictionary 340 C++" << endl;
    cout << "Keywords: [KEYWORD_SIZE]" << endl;
    cout << "Definitions: [DEFINITION_SIZE]" << endl;
    cout << endl;
    helpMenu();
}

string parseFile(ifstream &file)
{
    const int INDEX = 1024;
    char buf[INDEX];

    file.getline(&(buf[0]), INDEX, '|');

    return string(buf);
}

void loadData()
{
    vector<string> vGrammar;
    vector<string> vDefinition;

    string definition;
    string grammar;
    string inDataFile = "Data.CS.SFSU.txt";

    cout << "! Opening Data File..." << DATA_FILE << endl;
    cout << "! Loading Data..." << endl;

    ifstream inGrammar(inDataFile.c_str());

    if (inGrammar.fail())
    {
        cout << "Couldn't open the file!" << endl;
    }

    cout << "! Loading Completed..." << endl;

    while (getline(inGrammar, grammar, '|'))
    {
        inGrammar >> grammar;
        vGrammar.push_back(grammar);
    }

    inGrammar.close();

    /************************************************/

    ifstream inDefinition(inDataFile.c_str());

    while (getline(inDefinition, definition, '|'))
    {
        vDefinition.push_back(definition);
    }

    inDefinition.close();

    cout << "! Closing Data File..." << endl;

    cout << "vector Definition size: " << vDefinition.size() << endl;
    cout << "vector Grammar size: " << vGrammar.size() << endl;
}

#endif