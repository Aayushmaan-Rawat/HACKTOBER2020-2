#include <stdio.h>
#include <stdlib.h>
struct Node
{
 int data;
 struct Node *next;
}*top=NULL;
void push(int x)
{
 struct Node *t;
 t=(struct Node*)malloc(sizeof(struct Node));
 if(t==NULL)
 printf("stack is full\n");
 else
 {
 t->data=x;
 t->next=top;
 top=t;
 }
}
int pop()
{
 struct Node *t;
 int x=-1;
 if(top==NULL)
 printf("Stack is Empty\n");
 else
 {
 t=top;top=top->next;
 x=t->data;
 free(t);
 }
 return x;
}
void Display()
{
 struct Node *p;
 p=top;
 while(p!=NULL)
 {
 printf("%d ",p->data);
 p=p->next;
 }
 printf("\n");
}
int main()
{
        int opt, ele ;
    while (1)
    {
        printf("\n\n OPTION 1: PUSH");
		printf("\n OPTION 2: POP");
		printf("\n OPTION 3: DISPLAY");
		printf("\n OPTION 4: EXIT");
        printf("\n\n Enter your option: ");
		scanf("%d", &opt);
        switch (opt)
        {	case 1:	printf("\n Enter the element: ");
            		scanf("%d", &ele);
            		push(ele);
            		Display();
            		break;           
        	case 2:	
            		pop();
         	      	Display();
         	        break;
        	case 3:	
        	        Display();
            		break;
			case 4: exit(0);
        			default:
            		break;
       	}
    }
    return 0;
}
