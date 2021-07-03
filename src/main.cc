#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "dictionary.h"

using namespace std;

void load()
{
    cout << "! Opening Data File..." << DATA_FILE << endl;
    cout << "! Loading Data..." << endl;

    fstream inFile(DATA_FILE);
    cout << "! Loading Completed..." << endl;
    cout << "! Closing Data File..." << endl;
    inFile.close();

    /*
    ioFile >> col1;
    ioFile >> col2;
    ioFile >> col3;

    cout << col1 << "  " << col2 << " " << col3 << " " << endl;
    */

    /*
    while (ioFile >> col1 >> col2 >> col3)
    {
        cout << col1 << " " << col2 << " " << col3 << " " << endl;
    }
    */

    /*
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

    ifstream inDefinition(inDataFile.c_str());

    while (getline(inDefinition, definition, '|'))
    {
        vDefinition.push_back(definition);
    }

    inDefinition.close();

    cout << "! Closing Data File..." << endl;

    cout << "vector Definition size: " << vDefinition.size() << endl;
    cout << "vector Grammar size: " << vGrammar.size() << endl;

    vector_search_definitions(vDefinition);
    */
}

int main(void)
{
    load();
    /*
    load();
    intro();

    int count = 0;

    string word;
    vector<string> w;

    do
    {
        cout << "Search [ " << count << " ]: ";

        cin >> word;
        //getline(cin, word);

        if (word == "!help")
        {
            helpMenu();
        }

        w.push_back(word);

        word_search(w);

        count += 1;
    } while (count < 2);
    */
    return 0;
}