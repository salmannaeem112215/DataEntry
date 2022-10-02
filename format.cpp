#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <conio.h>
#include "format.h"
using namespace std;


int main()
{
    fstream input;
    fstream output;
    char input_fileName[] = "input.txt";
    char output_fileName[] = "output.txt";
    input.open(input_fileName, ios::in);
    output.open(output_fileName, ios::out);

    if (!input.is_open())
    {
        cout << "File Not Found" << endl;
    }
    else
    {
        string line;
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

            lineFormator.display();
            lineFormator.storeDataOnFile(output);

            lineFormator.nullValue();
        }
    }
    cout<<"Press Key To Exist "<<endl;
    getch();
}
