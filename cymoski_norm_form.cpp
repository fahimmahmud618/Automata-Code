#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define MAX 100
vector<string> expression;
char start_of_expression[MAX];

bool isChamosky(char *start_of_expression,vector<string> expression,int expression_number)
{

    int i,j,expression_len;
    string expre;
    bool dis=false;

    for(i=0;i<expression_number;i++)
    {
        if(dis)
            break;
        else if((start_of_expression[i]>='A')&&(start_of_expression[i]<='Z'))
        {
            expre = expression[i];
            expression_len = expre.size();
            //cout<<expre<<expression_len;
            if(expression_len==1)
            {
                    //cout<<"exprelen1: "<<expre;
                    if((expre[0]='a')&&(expre[0]<='z'))
                        dis =false;
                    else
                        dis = true;
            }
            else
            {
                for(j=0;j<expression_len;j++)
                {
                    if(expre[i]=='|')
                        continue;
                    else if((expre[j]>='A')&&(expre[j]<='Z'))
                    {
                        //cout<<"<"<<expre[j]<<">";
                    }
                    else{
                        dis=true;
                        break;
                    }
                }
            }
        }
        else
            dis =true;
    }
    if(dis)
        return false;
    else
        return true;
}
int main()
{
    int expression_num;
    string expre;
    cout<<"How many Expressions? ";
    cin>>expression_num;

    for(int i=0;i<expression_num;i++)
    {
        cin>>start_of_expression[i]>>expre;
        expression.push_back(expre);
    }


    if(isChamosky(start_of_expression,expression,expression_num))
        cout<<"It is in Chamosky's Normal form";
    else
        cout<<"It is not in Chamosky's Normal form";
}

/*
A BC
B c
C a
*/
