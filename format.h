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
    double no4;
    double no5;
    double no6;
    string endName;
    string endRef;

    int lineSize;
    int currPos;

    Format();
    void storeDataOnFile(fstream& file){
        file<<ref<<"\t"
            <<name<<"\t"
            <<country<<"\t"
            <<city<<'\t'
            <<dollars<<"."<<cents<<"\t" 
            <<endl;
    }
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
    long long int wordToNumber(string& words) {
	string myword = "";
    


	long long int n = 0;		//the number
	long long int temp = 0;
	long long int finalVlaue = 0;
	for (int i = 0; words[i]!='\0'; i++) {
		if (words[i] == ' ' || words[i] == '\0') {
			if (myword == "one" || myword == "One") {
				temp += 1;
			}
			else if (myword == "two" || myword == "Two") {
				temp += 2;
			}
			else if (myword == "three" || myword == "Three") {
				temp += 3;
			}
			else if (myword == "four" || myword == "Four") {
				temp += 4;
			}
			else if (myword == "five" || myword == "Five") {
				temp += 5;
			}
			else if (myword == "six" || myword == "Six") {
				temp += 6;
			}
			else if (myword == "seven" || myword == "Seven") {
				temp += 7;
			}
			else if (myword == "eight" || myword == "Eight") {
				temp += 8;
			}
			else if (myword == "nine" || myword == "Nine") {
				temp += 9;
			}
			else if (myword == "ten" || myword == "Ten") {
				temp += 10;
			}
			else if (myword == "eleven" || myword == "Eleven") {
				temp += 11;
			}
			else if (myword == "twelve" || myword == "Twelve ") {
				temp += 12;
			}
			else if (myword == "thirteen" || myword == "Thirteen") {
				temp += 13;
			}
			else if (myword == "fourteen" || myword == "Fourteen") {
				temp += 14;
			}
			else if (myword == "fifteen" || myword == "Fifteen") {
				temp += 15;
			}
			else if (myword == "sixteen" || myword == "Sixteen") {
				temp += 16;
			}
			else if (myword == "seventeen" || myword == "Seventeen") {
				temp += 17;
			}
			else if (myword == "eighteen" || myword == "Eighteen") {
				temp += 18;
			}
			else if (myword == "nineteen" || myword == "Nineteen") {
				temp += 18;
			}
			else if (myword == "twenty" || myword == "Twenty") {
				temp += 20;
			}
			else if (myword == "thirty" || myword == "Thirty") {
				temp += 30;
			}
			else if (myword == "fourty" || myword == "Fourty" || myword == "Forty" ||myword == "Forty" ) {
				temp += 40;
			}
			else if (myword == "fifty" || myword == "Fifty") {
				temp += 50;
			}
			else if (myword == "sixty" || myword == "Sixty") {
				temp += 60;
			}
			else if (myword == "seventy" || myword == "Seventy") {
				temp += 70;
			}
			else if (myword == "eighty" || myword == "Eighty") {
				temp += 80;
			}
			else if (myword == "ninety" || myword == "Ninety") {
				temp += 90;
			}
			else if (myword == "hundreds" || myword == "Hundreds" || myword == "Hundred" || myword == "hundred"|| 
                    myword == "wundreds" || myword == "Wundreds" || myword == "Wundred" || myword == "wundred") {
				temp *= 100;
			}
			else if (myword == "thousand" || myword == "Thousand" || myword == "Thousands" || myword == "thousands") {
				n += (temp * 1000);
				temp = 0;
			}
			else if (myword == "million" || myword == "Million" || myword == "Millions" || myword == "millions") {
				n += (temp * 1000000);
				temp = 0;
			}
			else if (myword == "billion" || myword == "Billion" || myword == "Billions" || myword == "billions") {
				n += (temp * 1000000000);
				temp = 0;
			}
			else {
				//If Anyy Error in Words Reading will tell
                if(int(myword[0])!= 0){
				cout << "Error";
                cout<<" In Ref "<<ref<<endl;
                cout<<"Words"<<words<<endl;
                cout<<"("<<myword<<")"<<endl;
                }
			}
			myword = "";
			
		}
		else {
			myword += words[i];
		}
	}
	n += temp;	
    cout<<n<<endl;	
	return n;
}
    
    void readRef();
    void readNameCountryCity();
    void readDollars();
    void readCents();
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
void Format::readDollars(){
    string totalAmount = "";
    string word=" ";
    int index=currPos+1;  // will be at space 
    while((word != "Dollars" && word != "dollars" && word != "Dollar" ) ){
        if(line[index]==' '){
            totalAmount += (' '+word);
            word="";
        }
        else{
            word+=line[index];
        }
        index++;
    }
    totalAmount += " ";
    dollars = wordToNumber(totalAmount);

    // Updating Index
    currPos = index +1;
    
}

void Format::readCents(){
    string totalCents="";
    string word="";
    int index=currPos+1;

    while(word!="Ce" && word!="ce" && word!="CE" && word!="cE" ){
        if(word=="and" || word=="And" || word == "ANd" || word == "AND" || word=="nd" || word=="nd" || word == "Nd" || word == "ND"){
            word="";
        }
        else if(line[index]==' '){
            totalCents += (' '+word);
            word="";
        }
        else{
            word+=line[index];
        }
        index++;
    }
    totalCents+=' ';
    cents=wordToNumber(totalCents);

    // To go to the Next Space ( before AND)
    while(line[index]!=' '){
        index++;
    }
}
