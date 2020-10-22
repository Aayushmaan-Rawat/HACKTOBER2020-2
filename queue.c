#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *next;
};
struct queue
{
  struct node *front;
  struct node *rear;
};
struct queue *q;
void create_queue (struct queue *);
struct queue *insert (struct queue *, int);
struct queue *display (struct queue *);
int main ()
{
  int val, option;
  create_queue (q);
  do
    {
      printf ("\n MAIN MENU");
      printf ("\n 1. INSERT");
      printf ("\n 2. DISPLAY");
      printf ("\n 3. EXIT");
      printf ("\n Enter your option : ");
      scanf ("%d", &option);
      switch (option)
	{
	case 1:
	  printf ("\n Enter the number to insert in the queue:");
	  scanf ("%d", &val);
	  q = insert (q, val);
	  display(q);
	  break;
	case 2:
	  q = display (q);
	  break;
	}
printf("\n PARMEET KAUR CSE 2 09213202719");
    }
  while (option != 3);
  return 0;
}

void create_queue (struct queue *q)
{
  q->rear = NULL;
  q->front = NULL;
}

struct queue *insert (struct queue *q, int val)
{
  struct node *ptr;
  ptr = (struct node *) malloc (sizeof (struct node));
  ptr->data = val;
  if (q->front == NULL)
    {
      q->front = ptr;
      q->rear = ptr;
      q->front->next = q->rear->next = NULL;
    }
  else
    {
      q->rear->next = ptr;
      q->rear = ptr;
      q->rear->next = NULL;
    }
  return q;
}

struct queue *display (struct queue *q)
{
  struct node *ptr;
  ptr = q->front;
  if (ptr == NULL)
    printf ("\n QUEUE IS EMPTY");
  else
    {
      printf ("\n");
       while (ptr != q->rear)
	{
	  printf ("%d\t", ptr->data);
	  ptr = ptr->next;
	}
      printf ("%d\t", ptr->data);
    }
  return q;
}


