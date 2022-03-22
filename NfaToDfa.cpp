#include<iostream>
#define MAX 100
using namespace std;
string nfa_transition_0[MAX], nfa_transition_1[MAX];
string dfa_new_or_done_state[MAX],dfa_state[MAx],dfa_transition_0[MAX], dfa_transition_1[MAX];
int num_dfa_new_or_done_state=0, num_of_DFA_state=0;
int uni_array[MAX];

void print_nfa(int state_num)
{
    cout<<"State\t0\t1"<<endl;
    for(int i=0; i<state_num;i++)
    {
        cout<<(char)(i+65)<<"\t"<<nfa_transition_0[i]<<"\t"<<nfa_transition_1[i]<<endl;
    }
}
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
void convert_nfa_dfa()
{
    dfa_state[0]=(char)(65);
    dfa_transition_0[0]= nfa_transition_0[0];
    dfa_transition_1[0]= nfa_transition_1[0];
    num_of_DFA_state++;



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
        nfa_transition_0[i]=str;
        //cin>>nfa_transition_0[i];

        cout<<"From state "<<(char)(i+65)<<" through 1 transition : ";
        cin>>str;
        nfa_transition_1[i]=str;

        //cout<<"value of i"<<i;
    }
    print_nfa(num_of_NFA_state);



}
