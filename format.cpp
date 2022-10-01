#include<iostream>
#include<fstream>
#include<string.h>
#include<string>
#include<conio.h>
#include"format.h"
using namespace std;

string convertToString(char* a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}

void Format::readNameCountryCity(){
    cout<<"Hell"<<endl;
}


int main(){
    fstream input;
    fstream output;
    char input_fileName[] = "input.txt";
    char output_fileName[] = "output.txt";
    input.open(input_fileName,ios::in);
    output.open(output_fileName,ios::out);

    if(!input.is_open()){
        cout<<"File Not Found"<<endl;
    }
    else{
        string line;
        string page_no;
        int line_no=0;
        getline(input,page_no);
        Format lineFormator;
        while (getline(input,lineFormator.line))
        {
            cout<<lineFormator.line;
            cout<<endl;

            lineFormator.readRef();
            lineFormator.readNameCountryCity();


            lineFormator.nullValue();
        }
       
    }

}
