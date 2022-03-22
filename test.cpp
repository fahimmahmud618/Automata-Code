#include<iostream>
#include<cstring>
using namespace std;
int uni_array[100];
int calc_string_len(string input)
{
    int i;
    for(i=0;input[i]!='\0';i++);
    return i;
}
int pick_state(string taken_str)
{
    int len = calc_string_len(taken_str),t=0;
    cout<<"len is: "<<len<<endl;
    for(int i=0; i<len;i++)
    {
        if((taken_str[i]==',')||(taken_str[i]=='{')||(taken_str[i]=='}'))
        {

        }
        else
        {
            uni_array[t]=((int)(taken_str[i]))-65;
            cout<<"==>"<<uni_array[t];
            t++;
        }

    }
    return t;
}
int main()
{
    string a="{A,B,C,D}";
    int size = pick_state(a);

    for(int i=0;i<size;i++)
    {
        cout<<uni_array[i]<<endl;
    }
}
