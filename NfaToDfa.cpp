#include<iostream>
#include<bits/stdc++.h>
#define MAX 100
using namespace std;
string nfa_transition_0[MAX], nfa_transition_1[MAX];
string new_state[MAX],dfa_state[MAX],dfa_transition_0[MAX], dfa_transition_1[MAX];
int num_of_new_state=0, num_of_DFA_state=0;
int uni_array[MAX];
string transiiton;

void print_nfa(int state_num)
{
    cout<<endl<<endl<<"________________NFA Transition Table________________"<<endl<<endl;
    cout<<"State\t0\t1"<<endl;
    for(int i=0; i<state_num;i++)
    {
        cout<<(char)(i+65)<<"\t"<<nfa_transition_0[i]<<"\t"<<nfa_transition_1[i]<<endl;
    }
}

void print_dfa(int state_num)
{
    cout<<endl<<endl<<"________________DFA Transition Table________________"<<endl<<endl;
    cout<<"State\t0\t1"<<endl;
    for(int i=0; i<state_num;i++)
    {
        cout<<dfa_state[i].c_str()<<"\t"<<dfa_transition_0[i].c_str()<<"\t"<<dfa_transition_1[i].c_str()<<endl;
    }
}
int calc_string_len(string input)
{
    int i;
    for(i=0;input[i]!='\0';i++);
    return i;
}

int make_union(int t,int input)
{
    transiiton.clear();
    for(int i=0;i<t;i++)
    {
        if(input==0)
        {

            transiiton = transiiton + nfa_transition_0[uni_array[i]];
            //cout<<transiiton<<"?";
        }

        else
        {

            transiiton = transiiton + nfa_transition_1[uni_array[i]];
            //cout<<transiiton<<"?";
        }
    }
    sort(transiiton.begin(), transiiton.end());

    string s = transiiton;
    //cout<<"Value of s "<<transiiton<<"printed"<<endl;
    bool dis=true;
    transiiton.clear();
    int len = calc_string_len(s),p=0;
    for(int i = 0; i<len;i++)
    {
        if((s[i]==',')||(s[i]=='{')||(s[i]=='}'))
        {

        }
        else
        {   dis=true;
            for(int k =0;k<i;k++)
               {
                   if(s[i]==s[k])
                    dis=false;
               }
            if(dis)
            {
                transiiton[p]=s[i];
                p++;
                transiiton[p]=',';
                p++;
            }

        }
    }

    return p;

}

int pick_state(string taken_str,int input)
{
    int len = calc_string_len(taken_str),t=0;
    //cout<<"len is: "<<len<<endl;
    for(int i=0; i<len;i++)
    {
        if((taken_str[i]==',')||(taken_str[i]=='{')||(taken_str[i]=='}'))
        {

        }
        else
        {
            uni_array[t]=((int)(taken_str[i]))-65;
            //cout<<"==>"<<uni_array[t];
            t++;
        }

    }
    make_union(t,input);
}

bool searchState(string takenString)
{
    int d=0;
    for(int i=0;i<num_of_DFA_state;i++)
    {
        if(takenString==dfa_state[i])
        {
            d=1;
            break;
        }
    }
    if(d==0) return true;
    else 
        return false;
}

void convert_nfa_dfa()
{
    int tmp;
    dfa_state[0]=(char)65;
    num_of_DFA_state++;     //cout<<"Now num of dfa state: "<<num_of_DFA_state<<dfa_state[num_of_DFA_state-1]<<endl;
    dfa_transition_0[0]=nfa_transition_0[0];
    dfa_transition_1[0]=nfa_transition_1[0];
    
    new_state[0]=dfa_transition_0[0];   num_of_new_state++;     //cout<<"New state no: "<<(num_of_new_state-1)<<new_state[num_of_new_state-1]<<endl;
    new_state[1]=dfa_transition_1[0];   num_of_new_state++;     //cout<<"New state no: "<<(num_of_new_state-1)<<new_state[num_of_new_state-1]<<endl;
    
    for(int i=0;i<num_of_new_state;i++)
    {
        if(searchState(new_state[i]))
        {
            dfa_state[num_of_DFA_state]=new_state[i];
            num_of_DFA_state++;     //cout<<"Now num of dfa state: "<<num_of_DFA_state<<dfa_state[num_of_DFA_state-1]<<endl;
            
            tmp = pick_state(dfa_state[num_of_DFA_state-1],0); //cout<<"value of tmp : "<<tmp<<endl;
            for(int j=0;j<tmp-1;j++)
                dfa_transition_0[num_of_DFA_state-1][j]=transiiton[j];
            new_state[num_of_new_state].assign(dfa_transition_0[num_of_DFA_state-1]);
            num_of_new_state++;         //cout<<"New state no: "<<(num_of_new_state-1)<<new_state[num_of_new_state-1]<<endl;
                
            tmp = pick_state(dfa_state[num_of_DFA_state-1],1);
            for(int j=0;j<tmp-1;j++)
                dfa_transition_1[num_of_DFA_state-1][j]=transiiton[j];
            new_state[num_of_new_state].assign(dfa_transition_1[num_of_DFA_state-1]);
            num_of_new_state++;     //cout<<"New state no: "<<(num_of_new_state-1)<<new_state[num_of_new_state-1]<<endl;

        }
            
    }
    
}
int main()
{
    int num_of_NFA_state,i;
    string str;

    cout<<"How many states of the NFA: ";
    cin>>num_of_NFA_state;

    for(i=0;i<num_of_NFA_state;i++)
    {
        cout<<"From state "<<(char)(i+65)<<" through 0 transition : ";
        cin>>str;
        if(str=="-1")
            str.clear();
        nfa_transition_0[i]=str;
        //cin>>nfa_transition_0[i];

        cout<<"From state "<<(char)(i+65)<<" through 1 transition : ";
        cin>>str;
        if(str=="-1")
            str.clear();
        nfa_transition_1[i]=str;

        //cout<<"value of i"<<i;
    }
    print_nfa(num_of_NFA_state);
    convert_nfa_dfa();
    print_dfa(num_of_DFA_state);

}
