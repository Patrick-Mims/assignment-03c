#include <fstream>
#include <iostream>
#include <string>
#include "dictionary.h"

using namespace std;

int main(void)
{
    ifstream inFile;
    string data;

    inFile.open("../Data.CS.SFSU.txt");

    inFile >> data;
    cout << "Should be some data here again: " << data << endl;

    inFile.close();

    return 0;
}