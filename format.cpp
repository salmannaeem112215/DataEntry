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
       s=s+a[i];
    }
    return s;
}

void Format::readNameCountryCity(){
    // Mr.Milton A Kress Orlando.FL
    // 2 decimals . 
    // Last Decimal .... then go back to Before word to decimal ...
    // Store Before Word value in  name;
    // Store Before Dot in Coutry.
    // Store Two Values After . in City 
    // Read After the value unless ' ' nad next to it is ' '
    int no_of_decimal = 0;
    int start = currPos;
    int index = currPos;
    char temp[100]={'\0'};
    int temp_i=0;
    while(true){
        if(line[index]=='.'){
            no_of_decimal++;
            if(no_of_decimal==2){
                break;
            }
        }
        temp[temp_i++]=line[index++];
        // index++;
    }
    //Find Position Just Before Word
    int before_pos=0;
    int after_pos=0;
    for(int i=temp_i-1 ; i>0 ; i--){
        if(temp[i]==' '){
            before_pos=i;
            break;

        }
    }
    after_pos=temp_i;
    for(int i=index+1 ; line[i]!='0' ; i++){
        temp[after_pos++]=line[i];
    }
    currPos = index;
     

    name=convertToString(temp,before_pos);
    country=convertToString(temp,temp_i,before_pos);
    city=convertToString(temp,after_pos,temp_i);
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
            // Needed In case of Any Null Value Present in Char Arr;
            if(int(lineFormator.line[20])==0 || int(lineFormator.line[21])==0 ){
            lineFormator.removeNullFromLine();
            }
            cout<<lineFormator.line<<endl;
            
            lineFormator.readRef();
            lineFormator.readNameCountryCity();

            output<<lineFormator.ref<<"\t"<<lineFormator.name<<"\t"<<lineFormator.country<<"\t"<<lineFormator.city<<endl;

            lineFormator.nullValue();
        }
       
    }

}
