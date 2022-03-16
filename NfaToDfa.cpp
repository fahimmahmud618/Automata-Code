#include<iostream>
#include<string>
using namespace std;
string nfa_transition_0[100];
string nfa_transition_1[100];
string dfa_state_name[100];
string dfa_transition_0[100];
string dfa_transiton_1[100];
char pick_state_array[100];

string pick_state(string str)
{
    int len = str.length();
    bool dis;

    for(int i=0;i<len;i++)
    {
        if(str[i]!=',')
        {
            for(int j=0; j<i; j++)
            {
                if(str[i]==str[j])
                {
                    dis==false;
                }
            }
        }
    }
}

void print_nfa(int total_state)
{
    for(int i=1;i<=total_state;i++)
    {
        cout<<(char)i+64<<"\t"<<nfa_transition_0[i]<<"\t"<<nfa_transition_1[i]<<endl;
    }
}
int main()
{
    int nfa_total_state,i;
    cout<<"The number of state in NFA : ";
    cin>>nfa_total_state;

    cout<<"Enter the NFA transition table, enter -1 if there is no outgoing transition for that input"<<endl;

    for(i=1;i<=nfa_total_state;i++)
    {
        cout<<"From state "<<(char)(i+64)<<" through 0 transition : ";
        cin>>nfa_transition_0[i];
        cout<<"From state "<<(char)(i+64)<<" through 0 transition : ";
        cin>>nfa_transition_1[i];
    }

    print_nfa(nfa_total_state);


}
