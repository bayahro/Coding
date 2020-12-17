/*
    https://www.acmicpc.net/problem/1157
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CHAR 26
#define GET_CHAR_VAL(ch) (ch)>='a'?(ch)-'a':(ch)-'A'

int dict[NUM_CHAR];

int main()
{
    int i, size, hit=0;
    int cnt_max=0;
    char answer=0, ch_max=0;
    char *str = malloc(sizeof(char)*1000000);
    scanf("%s", str);
    size = strlen(str);
    for(i=0;i<NUM_CHAR;i++)
    {
        dict[i] = 0;
    }
    for(;size;size--)
    {
        char ch_idx = GET_CHAR_VAL(str[size-1]);
        dict[ch_idx]++;
        if(cnt_max<dict[ch_idx]) {
            cnt_max = dict[ch_idx];
            ch_max = 'A' + ch_idx;
        }
    }
    for(i=0;i<NUM_CHAR;i++)
    {
        if(dict[i]==cnt_max)
        {
            hit++;
        }
    }
    answer = hit>1?'?':ch_max;
    printf("%c",answer);
    return 0;
}
