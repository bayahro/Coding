/* https://www.acmicpc.net/problem/1874 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stack[100000+2]; //stack array
int idx=0; // data index of stack array
int todo[100000+2];
char str[200000+2];
int stridx=0;
int pushdata=0;

int top()
{
    return stack[idx];
}
void push(int data)
{
    stack[++idx] = data;
    str[stridx++]='+'; str[stridx++]='\n';
}
int pop()
{
    str[stridx++]='-'; str[stridx++]='\n';
    return stack[idx--];
}
void show()
{
    for(int i=1;i<=idx;i++)
    {
        printf("[%d] %d, ", i, stack[i]);
    }
    printf(" (idx %d) / (top %d)\n", idx, top());
}

int main()
{
    int i, N, *seq;
    
    scanf("%d", &N);
    seq = malloc(sizeof(int)*(N+1));
    for(i=1;i<=N;i++) 
    {
        scanf("%d", &seq[i]);
    }
    for(i=1;i<=N;i++)
    {
        while(seq[i]>top())
        {
            push(++pushdata);
        }
        if(seq[i]==top())
        {
            pop();
        }
        else
        {
            printf("NO");
            return 0;
        }
    }
    printf("%s", str);
    free(seq);
    return 0;
}
