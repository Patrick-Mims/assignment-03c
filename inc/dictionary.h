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
    vector<string> vec;
    vector<string> vGrammar;
    vector<string> vDefinition;

    char copy[256];

    string definition;
    string defSet;
    string grammar;
    string separator;
    string inDataFile = "Data.CS.SFSU.txt";
    string outDataFile = "grammar.txt";
    string lineOne;
    string lineTwo;

    cout << "! Opening Data File..." << DATA_FILE << endl;
    cout << "! Loading Data..." << endl;

    ifstream in_gram(inDataFile.c_str());
    if (in_gram.fail())
    {
        cout << "Couldn't open the file!" << endl;
    }

    cout << "! Loading Completed..." << endl;

    string item;

    cout << "! Closing Data File..." << endl;

    in_gram.close();

    ifstream in(inDataFile.c_str());

    char str[255];

    string tp;
    while (getline(in, tp, '|'))
    {
        vDefinition.push_back(tp);
    }

    /*
    while (in >> lineOne >> lineTwo)
    {
        cout << "this is lineTwo: " << lineTwo << endl;
        string parsedData = parseFile(in);
        vec.push_back(parsedData);
        //cout << parsedData << endl;
    }
    */

    in.close();

    cout << "vec: size: " << vec.size() << endl;
    cout << "gram: size: " << vGrammar.size() << endl;

    //vector_search_definitions(vDefinition);

    //vector_search_grammar(vGrammar);
}

/*
void loadDefinitions()
{
}

void loadData()
{
    vector<string> vec;
    cout << "Opening data file: Data.CS.SFSU.txt" << endl;

    string filename = "temp.txt";
    string inDataFile = "Data.CS.SFSU.txt";

    string lineOne;

    ifstream in(inDataFile.c_str());

    while (in >> lineOne)
    {
        string parsedData = parseFile(in);
        vec.push_back(parsedData);
        cout << parsedData << endl;
    }

    in.close();

    if (vec.empty() == false)
    {
        cout << vec.size() << endl;
    }
    else
    {
        cout << "Vector is empty." << endl;
    }

    vector<string>::iterator v = vec.begin();

    while (v != vec.end())
    {
        cout << "value of v = " << *v << endl;
        v++;
    }
}
*/

#endif