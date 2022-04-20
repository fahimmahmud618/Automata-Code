#include<stdio.h>

int main(){
    int state_num,start_state,end_state,i,state_0[20],state_1[20],initial_state,final_state,l=0,state;
    char string[20];
    char end[5]="11";

    printf("_  _  _  _  _  _  _  _  _  _  _  _  _DFA to check if a string ends with %s_  _  _  _  _  _  _  _  _  _  _  _  _\n\nHow many states in that DFA: ",end);
    scanf("%d",&state_num);
    //printf("Enter -1 to stop");

    for(i=1;i<=state_num;i++)
    {
        printf("\n_  _  _  _  _  _  _  _  _  _  _  _  _\n\n");

        printf("From state %d through '0' transition: ",i);
        scanf("%d",&state_0[i]);

        printf("From state %d, through '1' transition: ",i);
        scanf("%d",&state_1[i]);

    }
    printf("\n_  _  _  _  _  _  _  _  _  _  _  _  _\n\nEnter the number of initial state: ");
    scanf("%d",&initial_state);

    printf("Enter the number of final state: ");
    scanf("%d",&final_state);

        printf("Enter the string to check: ");
        scanf("%s",string);

        for(i=0;string[i]!='\0';i++)
            l++;
        //printf("%d",l);

        state=initial_state;
        printf("\n_  _  _  _  _  _  _  _  _  _  _  _  _\n\nstate %d --",state);
        for(i=0;i<l;i++)
        {
            if(string[i]=='0')
            {
                state=state_0[state];
                if(i==(l-1))
                    printf("(%c)--> state %d",string[i],state);
                 else
                    printf("(%c)--> state %d --",string[i],state);
            }
            else if(string[i]=='1')
            {
                state=state_1[state];
                 if(i==(l-1))
                    printf("(%c)--> state %d",string[i],state);
                 else
                    printf("(%c)--> state %d --",string[i],state);
            }
        }
        printf("\n_  _  _  _  _  _  _  _  _  _  _  _  _\n\n");
        if(state==final_state)
            printf("                                    This string ends with %s\n\n",end);
        else
            printf("                                    This string doesn't end with %s\n\n",end);



}
