/* https://www.acmicpc.net/problem/1158 */

#include <stdio.h>

int queue[5010];
int stack[5010];

int main()
{
    int N, K, qidx = 0, sidx = 0;
    scanf("%d %d", &N, &K);
    while(1)
    {
        int hit=0;
        while(1)
        {
            if(queue[qidx]!=-1)
            {
                hit++;
            }
            if(hit==K)
            {
                queue[qidx] = -1;
                break;
            }
            qidx = (qidx+1)%N;
        }
        stack[sidx++] = qidx+1;
        if(sidx==N) break;
    }
    printf("<");
    for(int i=0;i<N-1;i++) printf("%d, ", stack[i]);
    printf("%d", stack[N-1]);
    printf(">");

    return 0;
}
