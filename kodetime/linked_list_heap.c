/*
 * Linked list
 */

#include <stdio.h>   /* printf */
#include <stdlib.h>  /* malloc, free */
#include <assert.h>  /* assert */

typedef struct node
{
   int value;
   struct node * next;
} node;

/* terminal node at the end of the list */
node SENTINEL = {0, 0};

/* functions to create lists */
node * make_node(int v)
{
  node* p = malloc(sizeof(node));
  p->value = v;
  p->next = &SENTINEL;
  return p;
}

/* free all nodes in the list p */
void free_list(node* p)
{
  node* q = p;
  while(q != &SENTINEL)
  {
    node * t = q->next;
    free(q);
    q = t;
  }
}

/* insert node q after p */
void insert_after(node * p, node * q)
{
  /* pre-condition */
  assert (p != &SENTINEL);

  /* post-condition */
  q->next = p->next;
  p->next = q;
}

/* remove and return node after p */
node * remove_after(node * p)
{
  /* pre-condition */
  assert (p->next != &SENTINEL);

  /* post-condition */
  node * q = p->next;
  p->next = q->next;
  q->next = &SENTINEL;
  return q;
}

/* print list to console */
void print_list(node * p)
{
  node * q = p;
  while(q != &SENTINEL)
  {
    printf("%d ", q->value);
    q = q->next;
  }
  printf("\n");
}


int main(void)
{

  node * e1;

  e1 = make_node(1);

  free_list(e1);

  return 0;
}