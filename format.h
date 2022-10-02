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
    // Needed if There is SOme Null Values PResent
    void removeNullFromLine()
    {
        string temp = "";
        for (int i = 0; i < line.length(); i++)
        {
            if (int(line[i]) != 0)
            {
                temp += line[i];
            }
        }
        line = temp;
    }
    void nullValue()
    {
        line = ref = name = country = city = endName = endRef = "";
        dollars = cents = no1 = no2 = no3 = no4 = no5 = no6 = lineSize = currPos = 0;
    }
    string convertToString(char *a, int size, int start = 0)
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
        ref = convertToString(temp, count - 1); // 1 for M , 2 for M with space
        // updating line pos
        currPos = count;
    }
}
void Format::readNameCountryCity()
{

    int no_of_decimal = 0;
    int start = currPos - 1;
    int decimalIndex = -1;
    int beforeDecimal = -1;
    int afterDecimal = -1;
    char temp[100] = {'\0'};
    int lineIndex = currPos - 1;
    // Read Till Decimal
    while (true)
    {
        if (line[lineIndex] == '.')
        {
            no_of_decimal++;
            if (no_of_decimal == 2)
            {
                break;
            }
        }
        temp[decimalIndex++] = line[lineIndex++];
    }
    // Find Position Just Before Word
    for (int i = decimalIndex - 1; i > 0; i--)
    {
        if (temp[i] == ' ')
        {
            beforeDecimal = i;
            break;
        }
    }
    // Will Do To Find City
    afterDecimal = decimalIndex;
    while (line[lineIndex] != '0')
    {
        temp[afterDecimal++] = line[lineIndex++];
    }

    name = convertToString(temp, beforeDecimal, 0);
    country = convertToString(temp, decimalIndex, beforeDecimal + 1);
    city = convertToString(temp, afterDecimal, decimalIndex + 1);

    currPos = lineIndex;
}
