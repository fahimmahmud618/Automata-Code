#include <iostream>
#include <stack>
using namespace std;
string transition[12];
stack<char> stk;
stack<char> stk2;
string taken_string;
int i,len,j,curr_pos=0;
char curr_state = 'A';

bool guess_half(int position)
{
    while(!stk2.empty())
    stk2.pop();

    for(i=0;i<position;i++)
        stk2.push(taken_string[i]);
        i--;
    for(j=position;j<position*2;j++)
    {
        if(stk2.top()==taken_string[j])
        {
            //cout<<i<<" "<<stk2.top()<<" "<<taken_string[i]<<endl;
            stk2.pop();
            i--;
        }
    }


    if(stk2.empty())
        return true;
    else
        return false;
}
int main()
{
    /*transition[0]="A0NAP";
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
    transition[11]="BNNCN";*/


    cout<<"Enter a string : ";
    cin>>taken_string;
    len = taken_string.size();
    int half_pos,k;

    for(i=0;i<len;i++)
    {
        if(guess_half(i))
        {
            half_pos=3;

            for(k=0;k<half_pos;k++)
                cout<<"A--"<<"("<<taken_string[k]<<")"<<"-->";
            cout<<"A--(e)-->B";
            for(k=half_pos;k<len;k++)
                cout<<"B--"<<"("<<taken_string[k]<<")"<<"-->";
            cout<<"B--(e)-->C";

            cout<<endl<<endl<<"String Accepted";
            return 0;
        }
    }
    cout<<endl<<"String doesn't accepted";

}
