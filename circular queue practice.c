
#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
    struct node_t *prev;
    struct node_t *next;
    int data;
} node_t;

typedef struct circ_queue_t {
    struct node_t *head;
    struct node_t *tail;
    int size;
    int load;
}circ_queue_t;

node_t *create_node(int data)
{
    node_t *node = malloc(sizeof(node_t));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}
circ_queue_t *create_circ_queue(int size)
{
    circ_queue_t *q = malloc(sizeof(circ_queue_t));
    q->head = NULL;
    q->tail = NULL;
    q->size = size;
    q->load = 0;
    return q;
}
void show_node(node_t *node)
{
    printf("  %p(%d) <- %p(%d) -> %p(%d)\n",\
        node->prev, node->prev?node->prev->data:-1, \
        node, node?node->data:-255, \
        node->next, node->next?node->next->data:-2 \
        );
}
void show_circ_queue(circ_queue_t *q)
{
    node_t *node = q->head;
    printf("queue load : %d\n", q->load);
    printf("     head : ");
    show_node(q->head);
    while(node)
    {
        show_node(node);
        node = node->next;
        if(node==q->head) break;
    }
    printf("     tail : ");
    show_node(q->tail);
}

void insert(circ_queue_t *q, int data)
{
    node_t *node;
    node = create_node(data);
    //Empty
    if(q->head==NULL)
    {
        q->head = node;
        q->tail = node;
        q->tail->next = q->head;
        q->head->prev = q->tail;
        q->load++;
    }
    //Not Full (load<size)
    else if(q->load<q->size)
    {
        node->prev = q->tail;
        node->next = q->tail->next;
        q->tail->next = node;
        q->tail = node;
        q->load++;
        //if(q->load==q->size) //full
        {
            //q->tail->next = q->head;
            q->head->prev = q->tail;
        }
    }
    //Full (load>=size) -> replace first input
    else
    {
        node_t *org_head = q->head;
        q->head->next->prev = node;
        node->next = q->head->next;
        node->prev = q->head->prev;
        q->head->prev->next = node;
        q->tail = node;
        q->head = q->head->next;
        free(org_head);
    }
}
node_t *pop(circ_queue_t *q)
{
    node_t *ret = q->head;
    //Empty
    if(q->head==NULL)    {;}
    //Not Full
    else if(q->load<q->size)
    {
        node_t *new_tail = q->tail->prev;
        ret = q->tail;
        new_tail->next = q->head;
        q->tail = new_tail;
        q->head->prev = q->tail;
        q->load--;
    }
    //Full
    else
    {
        q->head->prev->next = q->head->next;
        q->head->next->prev = q->head->prev;
        ret = q->head;
        q->load--;
        q->head = q->head->next;
    }
    printf("popped %d\n", ret?ret->data:-255);
    return ret;
}

static circ_queue_t *queue;
static int queue_size = 5;
int main()
{
    queue = create_circ_queue(queue_size);
    insert(queue, 1);
    insert(queue, 2);
    insert(queue, 3);
    insert(queue, 4);
    pop(queue);
#if 0
    insert(queue, 5);
    insert(queue, 6);
    insert(queue, 7);
    pop(queue);
    insert(queue, 8);
    pop(queue);
    insert(queue, 9);
    pop(queue);
    pop(queue);
#endif
    show_circ_queue(queue);
    return 0;
}
