#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <fstream>
#include <string>

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
    cout << "Opening data file: Data.CS.SFSU.txt";

    string data = "Data.CS.SFSU.txt";
    string lineOne, lineTwo, lineThree;

    /*
    cout << endl;

    in >> lineOne;
    while (in >> lineOne)
    {
        cout << lineOne << endl;
    }
    cout << endl;
    */

    ifstream in(data.c_str());

    while (in >> lineOne)
    {
      string words = parseFile(in);

      if (in.eof())
        break;

      cout << words << endl;
    }

    /*
    cout << endl;
    in >> lineOne;
    while (in >> lineOne >> lineTwo >> lineThree)
    {
        if (!in.eof())delimfiledelimfile
        {delimfile
            cout << "      " << lineOne << endl;
        }
    }
    cout << endl;
    */

    /*
    while (getline(in, line))
    {
        cout << line << endl;
        cout << endl;
    }
    */

    in.close();
}

#endif
