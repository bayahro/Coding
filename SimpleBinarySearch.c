/* https://www.acmicpc.net/problem/1920 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define swap(a,b) do {\
    int tmp=a;\
    a=b;\
    b=tmp;\
}while(0);
#define get_mid(s,e) ((s+e)/2)

int *pool;
int size;
void show()
{
    int i;
    for(i=0;i<size;i++) printf(" [%d]", pool[i]);
    printf("\n");
}
int sort()
{
    int i,j;
    for(i=0;i<size-1;i++)
    {
        for(j=i;j<size;j++)
        {
            if(pool[j]<pool[i])
            {
                swap(pool[i], pool[j]);
            }
        }
    }
}
int binary_search(int num)
{
    int start=0, end=size-1, mid;
    while(start<=end)
    {
        mid = get_mid(start, end);
        if(num==pool[mid])
        {
            return 1;
        }
        else if(num>pool[mid])
        {
            start = mid+1;
        }
        else
        {
            end = mid-1;
        }
    }
    return 0;
}

int compare(const void *a, const void *b) {
    int num1 = *(int*)a;
    int num2 = *(int*)b;
    if (num1 < num2) {
        return -1;
    }
    if (num1 > num2) {
        return 1;
    }
    return 0;
}

int main()
{
    int M, i, j, num;
    scanf("%d", &size);
    pool = malloc(sizeof(int)*size);
    for(i=0;i<size;i++)
    {
        scanf("%d", &pool[i]);
    }
    //sort(); // Time over...
    qsort(pool, size, sizeof(int), compare);
    //show();
    scanf("%d", &M);
    for(;M;M--)
    {
        scanf("%d", &num);
        printf("%d\n", binary_search(num));
    }
    free(pool);
    return 0;
}
