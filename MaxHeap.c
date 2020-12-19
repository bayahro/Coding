/* https://www.acmicpc.net/problem/11279 */

int heap[100000+1];
int size = 0;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define large(a,b) ((a)>(b)?(a):(b))
void swap(int a, int b)
{
    int tmp = heap[a];
    heap[a] = heap[b];
    heap[b] = tmp;
    //printf("swap at idx %d, %d\n", a, b);
}
void show()
{
    for(int i=1;i<=size;i++)
    {
        printf("[%d] %d, ", i, heap[i]);
    }
    printf(" (size %d)\n", size);
}
void insert(int data)
{
    int idx = ++size;
    heap[size] = data;
    while(idx!=1 && data>heap[idx/2])
    {
        swap(idx, idx/2);
        idx /=2;
    }
}
int pop()
{
    // Check empty
    if(size==0) return 0;
    // backup root node
    int idx = 1, ret = heap[1];
    // move last node to root 
    heap[1] = heap[size];
    size--;
    // iterate
    int ch1, ch2;
    while(1)
    {
        ch1 = 2*idx;
        ch2 = ch1 + 1;
        //no child
        if(ch2>size && ch1>size) break;
        //only left child
        else if(ch2>size && ch1<=size)
        {
            if(heap[ch1]>heap[idx])
            {
                swap(idx, ch1);
                idx = ch1;
            }
            else break;
        }
        //both child
        else if(ch2<=size && ch1<=size)
        {
            if(heap[ch1]>=heap[ch2] && heap[ch1]>heap[idx])
            {
                swap(idx, ch1);
                idx = ch1;
            }
            else if(heap[ch2]>heap[ch1] && heap[ch2]>heap[idx])
            {
                swap(idx, ch2);
                idx = ch2;
            }
            else break;
        }
    }
    return ret;
}

int main()
{
    int N;
    scanf("%d", &N);
    for(;N;N--)
    {
        int data;
        scanf("%d", &data);
        if(data>0)
        {
            insert(data);
        }
        else 
        {
            data = pop();
            printf("%d\n", data);
        }
        //show();
    }
    return 0;
}
