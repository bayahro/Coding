/* https://www.acmicpc.net/problem/10845 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 10000
#define is_cmd_push(cmd) cmd[0]=='p'&&cmd[1]=='u'&&cmd[2]=='s'&&cmd[3]=='h'

int q[10002];
int head=LIMIT, tail=LIMIT, size = 0;

int empty()
{
    return size==0;
}
void push(int data)
{
    q[tail--] = data;
    size++;
}
int pop()
{
    if(empty())
    {
        return -1;
    }
    else
    {
        size--;
        return q[head--];
    }
}
int front()
{
    return empty()?-1:q[head];
}
int back()
{
    return empty()?-1:q[tail+1];
}
void show()
{
    printf("tail %d ]]]]]] head %d\n", tail, head);
    for(int i=tail;i<=head;i++)
    {
        printf("[%d] %d ", i, q[i]);
    }
    printf("\n");
}

int main()
{
    int N, val;
    char *cmd = malloc(sizeof(char)*20);
    scanf("%d", &N);
    for(;N;N--)
    {
        scanf("%s", cmd);
        if(is_cmd_push(cmd))
        {
            scanf("%d", &val);
            push(val);
        }
        else
        {
            if(!strcmp(cmd, "pop"))
            {
                val = pop();
            }
            else if(!strcmp(cmd, "size"))
            {
                val = size;
            }
            else if(!strcmp(cmd, "empty"))
            {
                val = empty();
            }
            else if(!strcmp(cmd, "front"))
            {
                val = front();
            }
            else if(!strcmp(cmd, "back"))
            {
                val = back();
            }
            printf("%d\n", val);
        }
    }
    free(cmd);
    return 0;
}
