#include <iostream>
#include <stack>
using namespace std;
string transition[12];
stack<char> stk;
string taken_string;
int i,len,j,curr_pos=0;
char curr_state = 'A';

bool guess_half()
{
    curr_state = 'B';
}
int main()
{
    transition[0]="A0NAP";
    transition[1]="A1NAP";
    transition[2]="A00AP";
    transition[3]="A01AP";
    transition[4]="A10AP";
    transition[5]="A11AP";
    transition[6]="ANNBN";
    transition[7]="AN0B0";
    transition[8]="AN1B1";
    transition[9]="B00BO";
    transition[10]="B11BO";
    transition[11]="BNNCN";
    
    
    cout<<"Enter a string :";
    cin>>taken_string;
    len = taken_string.size();
    
    for(i=0;i<len;i++)
    {
        for(j=0;j<12;j++)
        {
            
        }
    }
    
    cout<<"Hello World";

    return 0;
}
