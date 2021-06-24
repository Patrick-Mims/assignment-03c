#include <fstream>
#include <iostream>
#include <string>
#include "dictionary.h"

using namespace std;

int main(void)
{
    introduction();
    //    loadData();
    int i = 0;

    string word;

    do
    {
        cout << "Search [ " << i << " ]: ";
        cin >> word;

        if (word == "!help")
        {
            helpMenu();
        }

        cout << "=> " << word << endl;

        i += 1;
    } while (i < 2);

    return 0;
}