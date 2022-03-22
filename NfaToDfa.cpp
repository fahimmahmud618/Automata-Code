#include<iostream>
#define MAX 100
using namespace std;
string nfa_transition_0[MAX], nfa_transition_1[MAX];

void print_nfa(int state_num)
{
    cout<<"State\t0\t1"<<endl;
    for(int i=0; i<state_num;i++)
    {
        cout<<(char)(i+65)<<"\t"<<nfa_transition_0[i]<<"\t"<<nfa_transition_1[i]<<endl;
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
        nfa_transition_0[i]=str;
        //cin>>nfa_transition_0[i];

        cout<<"From state "<<(char)(i+65)<<" through 1 transition : ";
        cin>>str;
        nfa_transition_1[i]=str;

        //cout<<"value of i"<<i;
    }
    print_nfa(num_of_NFA_state);


}
