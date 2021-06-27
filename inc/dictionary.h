#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

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
    cout << "\t\tSearch [2]: book noun reverse" << endl;
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

#endif