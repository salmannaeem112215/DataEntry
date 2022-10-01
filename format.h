#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <conio.h>
using namespace std;

class Format
{
public:
    string line;
    string ref;
    string name;
    string country;
    string city;
    int dollars;
    int cents;
    int no1;
    int no2;
    double no3;
    double no4;
    double no5;
    double no6;
    string endName;
    string endRef;

    int lineSize;
    int currPos;

    Format();
    void nullValue()
    {
        line = ref = name = country = city = "";
        dollars = cents = no1 = no2 = no3 = no4 = no5 = no6 = 0;
        endName = endRef = "";
        lineSize = currPos = 0;
    }
    string convertToString(char *a, int size , int start=0)
    {
        int i;
        string s = "";
        for (i = start; i < size; i++)
        {
            s = s + a[i];
        }
        return s;
    }
    void readRef();
    void readNameCountryCity();
};

Format::Format()
{
    nullValue();
}

void Format::readRef()
{
    {
        int count = 0;
        char temp[45] = {'\0'};
        // Read Untill MR or MS find
        while ((line[count] != 'M' && !(line[count + 1] == 's' || line[count + 1] == 's')))
        {
            temp[count] = line[count];
            count++;
        }
        // Storing char arra into string
        ref = convertToString(temp, count - 2); // 1 for M , 2 for M with space
        // updating line pos
        currPos = count;
    }
}