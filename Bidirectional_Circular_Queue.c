/* 
	BaekJoon Online Judge Site
	https://www.acmicpc.net/problem/1021 
	My Implementations were uploaded to https://www.acmicpc.net/source/24328986
	- Youngrok Song
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
    struct node_t *prev;
    struct node_t *next;
    int data;
} node_t;

typedef struct queue_t {
    node_t *head;
    node_t *tail;
} queue_t;

node_t* create_node(node_t *prev, node_t *next, int data)
{
    node_t *node;
    node = malloc(sizeof(node_t));
    node->prev = prev;
    node->next = next;
    node->data = data;
    return node;
}

void init_queue(queue_t *q, int size)
{
    for(int i=0;i<size+1;i++)
    {
        node_t *node;
        node = create_node(NULL, NULL, i);
        if(q->head==NULL)
        {
            q->head = node;
        }
        else
        {
            node->prev = q->tail;
            q->tail->next = node;
        }
        q->tail = node;
    }
}
void show_queue_data(queue_t *q)
{
    node_t *node = q->head;
    printf("============================\n");
    while(node!=NULL)
    {
        printf("  %p -> %p (%d) -> %p\n", node->prev, node, node->data, node->next);
        node = node->next;
    }
}

void push_head(queue_t *q, node_t *node)
{
    node_t *head = q->head;
    head->next->prev = node;
    node->next = head->next;
    head->next = node;
    node->prev = head;
}
void pop_head(queue_t *q, int kill)
{
    node_t *target = q->head->next;
    if(target->next!=NULL)
    {
        q->head->next = target->next;
        target->next->prev = q->head;
        if(kill)
            free(target);
    }
}
void push_tail(queue_t *q, node_t *node)
{
    node->prev = q->tail;
    node->next = NULL;
    q->tail->next = node;
    q->tail = node;
}
void pop_tail(queue_t *q, int kill)
{
    node_t *new_tail = q->tail->prev;
    new_tail->next = NULL;
    if(kill)
        free(q->tail);
    q->tail = new_tail;
}
int left_dist(queue_t *q, int val)
{
    int sum = 0;
    node_t *node = q->head->next;
    while(node)
    {
        if(node->data == val)
        {
            break;
        }
        sum++;
        node = node->next;
    }
    return sum;
}
int right_dist(queue_t *q, int val)
{
    int sum = 0;
    node_t *node = q->tail;
    while(node)
    {
        if(node->data == val)
        {
            break;
        }
        sum++;
        node = node->prev;
    }
    return sum+1;
}
void move_and_pop_left(queue_t *q, int val)
{
    node_t *node = q->head->next;
    while(node->data!=val)
    {
        node_t *new_tail = q->head->next;
        pop_head(q, 0);
        push_tail(q, new_tail);
        node = q->head->next;
    }
    pop_head(q, 1);
}
void move_and_pop_right(queue_t *q, int val)
{
    node_t *node = q->head->next;
    while(node->data!=val)
    {
        node_t *new_head = q->tail;
        pop_tail(q, 0);
        push_head(q, new_head);
        node = q->head->next;
    }
    pop_head(q, 1);
}

static queue_t queue = {
    .head = NULL,
    .tail = NULL,
};

int main()
{
    int N, M, sum = 0;
    scanf("%d %d", &N, &M);
    if(N>50) return -1;
    if(M>N) return -2;    
    init_queue(&queue, N);    
    for(int i=0;i<M;i++)
    {
        int position, left, right;
        scanf("%d", &position);
        left = left_dist(&queue, position);
        right = right_dist(&queue, position);
        if(left<=right)
        {
            move_and_pop_left(&queue, position);
            sum += left;
            //printf("     <<<  left  <<< pick %d, sum %d\n", position, sum);
        }
        else
        {
            move_and_pop_right(&queue, position);
            sum += right;
            //printf("     >>>  right  >>> pick %d, sum %d \n", position, sum);
        }
        //show_queue_data(&queue);
    }
    printf("%d", sum);
   
    return 0;
}
