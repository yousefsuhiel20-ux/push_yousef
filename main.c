#include "push_swap.h"

t_list  *t(int  a)
{
    t_list *head;

    head = malloc(sizeof(t_list));
    head->content = a;
    head->next = NULL;
    head->index = 0;
    return (head);
}

void append_node(t_list *head, int a)
{
    t_list node;

    node = t(a);
    while (head->next != NULL)
    {
        head = head->next;
        node.index++;
    }
    head->next = node;
}
void remove_node(t_list *head, int in)
{
    t_list *pre;
    t_list *nxt;
    t_list *tmp;

    pre = head;
    head = head->next;
    while(head->index != in)
    {
        head = head->next;
        pre = pre->next;
    }
    nxt = head->next;
    tmp = nxt;
    free(head);
    pre->next = nxt;   
    while(tmp != NULL)
    {
        tmp->index--;
        tmp = tmp->next;
    }
}

void insert_node(t_list *head, int content, int in)
{
    t_list *pre;
    t_list *node_add;

    pre = head;
    head = head->next;
    node_add = t(content);

    while(head->index != in)
    {
        head = head->next;
        pre = pre->next;
    }
    pre->next = node_add;
    node_add->next = head;
    node_add->index = in;
    while(head != NULL)
    {
        head->index++;
        head = head->next;
    }
}
t_list *mid_node(t_list *head)
{
    t_list  *slow;
    slow = head;
    while(head != NULL && head->next != NULL)
    {
        head = head->next.next;
        slow = slow->next;
    }
    return(slow);
}