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
    long long int dollars;
    int cents;
    int no1;
    int no2;
    double no3;
    string no4;
    string no5;
    string no6;
    string endName;
    string endRef;

    int lineSize;
    int currPos;

    Format();
    
    // Utility Functions
    void display();
    void removeNullFromLine();
    void storeDataOnFile(fstream &file);
    void nullValue();
    long long int wordToNumber(string &words);
    string convertToString(char *a, int size, int);
    string addSpace(string , int );
    
    // Necessary Function
    void readRef();
    void readNameCountryCity();
    void readDollars();
    void readCents();
    void readNo1();
    void readNo2();
    void readNo3();
    void readNo4();
    void readNo5();
    void readNo6();
    void readEndName();
    void readEndRef();
    void addFormat();
};

Format::Format()
{
    nullValue();
}

void Format::display(){
        cout << ref << "\t"
         << name << "\t"
         << country << "\t"
         << city << '\t'
         << dollars << "." << cents << "\t"
         << no1 << "\t"
         << no2 << "\t"
         << no3 << "\t"
         << no4 << "\t"
         << no5 << "\t"
         << no6 << "\t"
         << endName << "\t"
         << endRef << "\t"
         << endl;
}

void Format::storeDataOnFile(fstream &file)
{
    file << ref << "\t"
         << name << "\t"
         << country << "\t"
         << city << '\t'
         << dollars << "." << cents << "\t"
         << no1 << "\t"
         << no2 << "\t"
         << no3 << "\t"
         << no4 << "\t"
         << no5 << "\t"
         << no6 << "\t"
         << endName << "\t"
         << endRef << "\t"
         << endl;
}
// Needed if There is SOme Null Values PResent
// Also Add Sapce between 2 words if not present
void Format::removeNullFromLine()
{
    string temp = "";
    for (int i = 0; i < line.length(); i++)
    {
        if (int(line[i]) != 0)
        {
            if (temp.length() > 2)
            {
                if (int(temp[temp.length() - 2]) <= 122 && int(temp[temp.length() - 2]) >= 97)
                {
                    if (int(temp[temp.length() - 1]) <= 90 && int(temp[temp.length() - 1]) >= 65)
                    {
                        char a = temp[temp.length() - 1];
                        temp[temp.length() - 1] = ' ';
                        temp += a;
                    }
                }
            }
            temp += line[i];
        }
    }
    line = temp;
}
void Format::nullValue()
{
    line = ref = name = country = city = endName = endRef = no4 = no5 = no6 = "";
    dollars = cents = no1 = no2 = no3  = lineSize = currPos = 0;

}
string Format::convertToString(char *a, int size, int start = 0)
{
    int i;
    string s = "";
    for (i = start; i < size; i++)
    {
        s = s + a[i];
    }
    return s;
}
long long int Format::wordToNumber(string &words)
{
    string myword = "";

    long long int n = 0; // the number
    long long int temp = 0;
    long long int finalVlaue = 0;
    for (int i = 0; words[i] != '\0'; i++)
    {
        if (words[i] == ' ' || words[i] == '\0')
        {
            if (myword == "one" || myword == "One")
            {
                temp += 1;
            }
            else if (myword == "two" || myword == "Two")
            {
                temp += 2;
            }
            else if (myword == "three" || myword == "Three")
            {
                temp += 3;
            }
            else if (myword == "four" || myword == "Four")
            {
                temp += 4;
            }
            else if (myword == "five" || myword == "Five")
            {
                temp += 5;
            }
            else if (myword == "six" || myword == "Six")
            {
                temp += 6;
            }
            else if (myword == "seven" || myword == "Seven")
            {
                temp += 7;
            }
            else if (myword == "eight" || myword == "Eight")
            {
                temp += 8;
            }
            else if (myword == "nine" || myword == "Nine")
            {
                temp += 9;
            }
            else if (myword == "ten" || myword == "Ten")
            {
                temp += 10;
            }
            else if (myword == "eleven" || myword == "Eleven")
            {
                temp += 11;
            }
            else if (myword == "twelve" || myword == "Twelve ")
            {
                temp += 12;
            }
            else if (myword == "thirteen" || myword == "Thirteen")
            {
                temp += 13;
            }
            else if (myword == "fourteen" || myword == "Fourteen")
            {
                temp += 14;
            }
            else if (myword == "fifteen" || myword == "Fifteen")
            {
                temp += 15;
            }
            else if (myword == "sixteen" || myword == "Sixteen")
            {
                temp += 16;
            }
            else if (myword == "seventeen" || myword == "Seventeen")
            {
                temp += 17;
            }
            else if (myword == "eighteen" || myword == "Eighteen")
            {
                temp += 18;
            }
            else if (myword == "nineteen" || myword == "Nineteen")
            {
                temp += 18;
            }
            else if (myword == "twenty" || myword == "Twenty")
            {
                temp += 20;
            }
            else if (myword == "thirty" || myword == "Thirty")
            {
                temp += 30;
            }
            else if (myword == "fourty" || myword == "Fourty" || myword == "Forty" || myword == "Forty")
            {
                temp += 40;
            }
            else if (myword == "fifty" || myword == "Fifty")
            {
                temp += 50;
            }
            else if (myword == "sixty" || myword == "Sixty")
            {
                temp += 60;
            }
            else if (myword == "seventy" || myword == "Seventy")
            {
                temp += 70;
            }
            else if (myword == "eighty" || myword == "Eighty")
            {
                temp += 80;
            }
            else if (myword == "ninety" || myword == "Ninety")
            {
                temp += 90;
            }
            else if (myword == "hundreds" || myword == "Hundreds" || myword == "Hundred" || myword == "hundred" ||
                     myword == "wundreds" || myword == "Wundreds" || myword == "Wundred" || myword == "wundred")
            {
                temp *= 100;
            }
            else if (myword == "thousand" || myword == "Thousand" || myword == "Thousands" || myword == "thousands")
            {
                n += (temp * 1000);
                temp = 0;
            }
            else if (myword == "million" || myword == "Million" || myword == "Millions" || myword == "millions")
            {
                n += (temp * 1000000);
                temp = 0;
            }
            else if (myword == "billion" || myword == "Billion" || myword == "Billions" || myword == "billions")
            {
                n += (temp * 1000000000);
                temp = 0;
            }
            else
            {
                // If Anyy Error in Words Reading will tell
                if (int(myword[0]) != 0)
                {
                    cout << "Error";
                    cout << " In Ref " << ref << endl;
                    cout << "Words" << words << endl;
                    cout << "(" << myword << ")" << endl;
                }
            }
            myword = "";
        }
        else
        {
            myword += words[i];
        }
    }
    n += temp;
    return n;
}
string Format::addSpace(string a, int space=3){
        string temp="";
        string final="";
        for(int i=0 ;i<a.length();i++){
            temp+=a[i];
            if(a[i]==' '){
                for(int i=1 ; i<space; i++){
                    temp+=" ";
                }
            }
        }
        return temp;
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
void Format::readDollars()
{
    string totalAmount = "";
    string word = " ";
    int index = currPos + 1; // will be at space
    while ((word != "Dollars" && word != "dollars" && word != "Dollar"))
    {
        if (line[index] == ' ')
        {
            totalAmount += (' ' + word);
            word = "";
        }
        else
        {
            word += line[index];
        }
        index++;
    }
    totalAmount += " ";
    dollars = wordToNumber(totalAmount);

    // Updating Index
    currPos = index + 1;
}
void Format::readCents()
{
    string totalCents = "";
    string word = "";
    int index = currPos + 1;

    while (word != "Ce" && word != "ce" && word != "CE" && word != "cE")
    {
        if (word == "and" || word == "And" || word == "ANd" || word == "AND" || word == "nd" || word == "nd" || word == "Nd" || word == "ND")
        {
            word = "";
        }
        else if (line[index] == ' ')
        {
            totalCents += (' ' + word);
            word = "";
        }
        else
        {
            word += line[index];
        }
        index++;
    }
    totalCents += ' ';
    cents = wordToNumber(totalCents);

    // To go to the Next Space ( before AND)
    while (line[index] != ' ')
    {
        index++;
    }
    currPos = index;
}

// AND Sixteen %
void Format::readNo1()
{
    string number = "";
    string word = "";
    int index = currPos;

    while (word != "%")
    {
        if (word == "AND" || word == "ND" || word == "and" || word == "nd")
        {
            word = "";
        }
        else if (line[index] == ' ')
        {
            number += (' ' + word);
            word = "";
        }
        else
        {
            word += line[index];
        }
        index++;
    }
    number += ' ';

    no1 = wordToNumber(number);
    currPos = index;
}
//  Twenty Two Years AND
void Format::readNo2()
{
    string number = "";
    string word = "";
    int index = currPos;

    while (word != "Years")
    {

        if (word == "years" || word == "year")
        {
            if (line[index + 1] = 's')
            {
                index++;
            }
            word = "";
            break;
        }
        else if (line[index] == ' ')
        {
            number += (' ' + word);
            word = "";
        }
        else
        {
            word += line[index];
        }
        index++;
    }
    number += ' ';

    no2 = wordToNumber(number);
    currPos = index;
}
// AND Nine.Eighteen %
void Format::readNo3()
{
    string number = "";
    string word = "";
    bool decimal = false;
    int index = currPos;
    int count = 0;

    while (word != "%")
    {
        if (word == "AND" || word == "ND" || word == "and" || word == "nd")
        {
            word = "";
            index--;
        }
        else if (line[index] == ' ')
        {
            number += (' ' + word);
            word = "";
        }
        else if (line[index] == '.')
        {
            decimal = true;
            number += (' ' + word);
            number += ' ';

            no3 = wordToNumber(number);
            number = " ";
            word = "";
        }
        else
        {
            word += line[index];
        }
        index++;
        count++;
    }
    number += ' ';
    no3 = no3 + 0.01 * wordToNumber(number);


    if (!decimal)
    {
        cout << "Error Found Decimal Not FOund " << endl;
        cout << " In Ref " << ref << endl;
        cout << " no3 Value " << no3 << endl;
    }
    currPos = index;
}
//  (Purchase Value Reduction 13.14%) (Monthly Principal Reduction 4.69%) (Total Interest Reduction 14.41%)
void Format::readNo4()
{
    string number = "";
    bool found = true;
    while (line[currPos] != '%')
    {
        currPos++;
    }
    int index = currPos;
    while (found)
    {
        // Space Found Before
        if (line[index] == ' ' || line[index]=='n')
        {
            if(line[index]=='n'){
                index++;
                break;
            }
            // Is Not Number
            if (int(line[index - 1]) >= 57 && int(line[index - 1]) >= 48)
            {
                    if (int(line[index + 1]) <= 57 && int(line[index + 1]) >= 48)
                    {
                        break;
                    }
            }            
        }
        index--;
    }
bool decimal = false;
   for(int i=index; i<currPos; i++){
    if(line[i]=='.'){
        decimal=true;
    }
    number+=line[i];
    
   }
    number+=" ";
    no4=number;

    currPos++;

    if (!decimal)
    {
        cout << "Error Found Decimal Not FOund " << endl;
        cout << " In Ref " << ref << endl;
        cout << " no4 Value " << no4 << endl;
    }
}
// %) (Monthly Principal Reduction 828%)
void Format::readNo5()
{
    string number = "";
    bool found = true;
    while (line[currPos] != '%')
    {
        currPos++;
    }
    int index = currPos;
    while (found)
    {
        // Space Found Before
        if (line[index] == ' ' || line[index]=='n')
        {
            if(line[index]=='n'){
                index++;
                break;
            }
            // Is Not Number
            if (int(line[index - 1]) >= 57 && int(line[index - 1]) >= 48)
            {
                    if (int(line[index + 1]) <= 57 && int(line[index + 1]) >= 48)
                    {
                        break;
                    }
            }            
        }
        index--;
    }
    bool decimal=false;;
   for(int i=index; i<currPos; i++){
    if(line[i]=='.'){
        decimal= true;
    }
    number+=line[i];
   }
    number+=" ";
    no5=number;
    currPos++;

    if (!decimal)
    {
        cout << "Error Found Decimal Not FOund " << endl;
        cout << " In Ref " << ref << endl;
        cout << " no5 Value " << no5 << endl;
    }
}
// %) (Total Interest Reduction 14.41%)
void Format::readNo6()
{
    string number = "";
    bool found = true;
    while (line[currPos] != '%')
    {
        currPos++;
    }
    int index = currPos; // Position just before %
    while (found)
    {
        // Space Found Before
        if (line[index] == ' ' || line[index]=='n')
        {
            if(line[index]=='n'){
                index++;
                break;
            }
            // Is Not Number
            if (int(line[index - 1]) >= 57 && int(line[index - 1]) >= 48)
            {
                    if (int(line[index + 1]) <= 57 && int(line[index + 1]) >= 48)
                    {
                        break;
                    }
            }            
        }
        index--;
    }
    bool decimal=false;;
   for(int i=index; i<currPos; i++){
    if(line[i]=='.'){
        decimal= true;
    }
    number+=line[i];
   }
    number+=" ";
    no6=number;
    currPos++;

    if (!decimal)
    {
        cout << "Error Found Decimal Not FOund " << endl;
        cout << " In Ref " << ref << endl;
        cout << " no6 Value " << no6 << endl;
    }
}
void Format::readEndName(){
    // Skip Until Space is Find
    while(line[currPos]!=' '){
        currPos++;
    }
    string temp=" ";
    while(line[currPos]!='0'){
        temp+=line[currPos];
        currPos++;
    }
    endName=temp;
    currPos++;
}

void Format::readEndRef(){
    string temp = "";
    while(currPos != line.length()-1){
        temp+=line[currPos++];
        
    }
    endRef = temp;

}

void Format::addFormat(){
    ref = addSpace(ref);
    name = addSpace(name);

    endRef=addSpace(endRef);
    endName = addSpace(endName);
}