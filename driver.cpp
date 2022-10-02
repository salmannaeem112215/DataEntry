#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <conio.h>
#include "format.h"

using namespace std;
void appendDataFromFile(string fileName)
{   fstream input;
    fstream output;
    input.open(fileName.c_str(), ios::in);
    output.open("excelData.txt", ios::app);

    if (!input.is_open())
    {
        cout << "File Not Found" << endl;
    }
    else
    {
        string page_no;
        int line_no = 0;
        getline(input, page_no);
        Format lineFormator;
        while (getline(input, lineFormator.line))
        {
            // Needed In case of Any Null Value Present in Char Arr;
            if (int(lineFormator.line[20]) == 0 || int(lineFormator.line[21]) == 0)
            {
                lineFormator.removeNullFromLine();
            }
            lineFormator.line;
            lineFormator.readRef();
            lineFormator.readNameCountryCity();
            lineFormator.readDollars();
            lineFormator.readCents();
            lineFormator.readNo1();
            lineFormator.readNo2();
            lineFormator.readNo3();
            lineFormator.readNo4();
            lineFormator.readNo5();
            lineFormator.readNo6();
            lineFormator.readEndName();
            lineFormator.readEndRef();
            lineFormator.addFormat();

            // lineFormator.display();
            lineFormator.storeDataOnFile(output);
            lineFormator.nullValue();
        }
        input.close();
        output.close();
    }

}


int main()
{
    string page_no  ;
    string fileName = " ";
    fstream input;
    do
    {
        cout << "Enter -1 to Exist "<<endl;
        cout << "Enter Page No -> ";
        cin >> page_no;
        
        if(page_no=="-1"){
            break;
        }
        page_no+=".txt";
        appendDataFromFile(page_no);

        page_no=="";

    } while (true);
}