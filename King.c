/* https://www.acmicpc.net/problem/1063 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pos_t {
    int x; // 0 ~ 7
    int y; // 0 ~ 7
} pos_t;

#define CHAR_VAL(x) ((x)-'A')
#define check(k, s) \
    ((k)->x>=0 && (k)->x<8) && ((k)->y>=0 && (k)->y<8)\
    && ((s)->x>=0 && (s)->x<8) && ((s)->y>=0 && (s)->y<8)

void show_position_raw(pos_t *king, pos_t *stone)
{
    printf("(%d, %d) - (%d, %d)\n", king->x, king->y, stone->x, stone->y);
}
void show_position(pos_t *king, pos_t *stone)
{
    printf("%c%d\n%c%d", \
        'A'+(char)king->x, 1+king->y, \
        'A'+(char)stone->x, 1+stone->y);
}
void move(pos_t *king, pos_t *stone, char *cmd){
    pos_t sim_king = *king;
    pos_t sim_stone = *stone;
    int tmp_x=0, tmp_y=0;
    /* Simulate position of King */
    if(!strcmp(cmd, "R")) {
        sim_king.x++; 
        tmp_x = 1;
    } else if(!strcmp(cmd, "L")) {
        sim_king.x--;
        tmp_x = -1;
    } else if(!strcmp(cmd, "T")) {
        sim_king.y++;
        tmp_y = 1;
    } else if(!strcmp(cmd, "B")) {
        sim_king.y--;
        tmp_y = -1;
    } else if(!strcmp(cmd, "RT")) {
        sim_king.x++;
        sim_king.y++;
        tmp_x = 1;
        tmp_y = 1;
    } else if(!strcmp(cmd, "LT")) {
        sim_king.x--;
        sim_king.y++;
        tmp_x = -1;
        tmp_y = 1;
    } else if(!strcmp(cmd, "RB")) {
        sim_king.x++;
        sim_king.y--;
        tmp_x = 1;
        tmp_y = -1;
    } else if(!strcmp(cmd, "LB")) {
        sim_king.x--;
        sim_king.y--;
        tmp_x = -1;
        tmp_y = -1;
    }
    /* Simulate position of Stone */
    if(sim_stone.x==sim_king.x && sim_stone.y==sim_king.y)
    {
        sim_stone.x += tmp_x;
        sim_stone.y += tmp_y;
    }
    /* Out of boundary? if false, move. */
    if(check(&sim_king, &sim_stone))
    {
        *king = sim_king;
        *stone = sim_stone;
    }
}

int main()
{
    char x1, x2, cmd[51][3];
    int y1, y2, len;
    scanf("%c%d %c%d %d", &x1, &y1, &x2, &y2, &len);
    pos_t king = { CHAR_VAL(x1), y1-1 };
    pos_t stone = { CHAR_VAL(x2), y2-1 };
    
    for(int i=0;i<len;i++)
    {
        scanf("%s", cmd[i]);
        move(&king, &stone, cmd[i]);
    }
    
    show_position(&king, &stone);
    return 0;
}
