#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
struct employee
{   int emp_id;
    char emp_name[20];
    struct employee *prev;
    struct employee *next;
} *start;
void create_employee(int id, char name[10])
{	struct employee *ptr,*new_node = malloc(sizeof(struct employee));
	new_node->emp_id = id;
    strcpy(new_node->emp_name, name);
    if (start == NULL)
    {   start = new_node;
        new_node->next = NULL;
    	new_node->prev = NULL;  }
	else
    {	ptr = start;
     	while (ptr->next != NULL)
       	ptr = ptr->next;
     	ptr->next = new_node;
       	new_node->next = NULL;
       	new_node->prev = ptr;   }
}
void display()
{      if (start == NULL)
        printf("\n Empty List \n");
    else
    {  struct employee *ptr = start;
        while (ptr != NULL)
        {  printf("%d ", ptr->emp_id );
            printf(" %s \t", ptr->emp_name);
            ptr = ptr->next;  }
    }
}
void main()
{	int id,opt,r,i,loc; 
	char name[10];
	struct employee *ptr,*new_node = malloc(sizeof(struct employee));
    start = NULL;
    while (1)
    {
    printf("\n\n OPTION 1: Create New Record.");
		printf("\n OPTION 2: Insertion at end in the Record.");
		printf("\n OPTION 3: Exit.");
    printf("\n\n Enter your option: ");
		scanf("%d", &opt);
        switch (opt)
        {	case 1: printf("\n Enter the no. of Records: ");
            		scanf("%d", &r);
               	printf("\n Enter Employee Id and Name :\n");
            		for (i = 0; i < r; i++)
            		{	//printf("\n Enter Employee Id %d",i+1);
            		    scanf(" %d", &id);
            		    //printf("\n Enter Employee Id %d",i+1);
            		    scanf(" %s",&name);
    		create_employee(id,name);					
            		}
            		printf("\n List created succesfully \n");
            		display();
            		break;	
            case 2: printf("\n Enter the employee id be inserted: ");
            		scanf("%d", &id);
            		printf("\n Enter the employee name to be inserted: ");
            		scanf(" %s",&name);
            		if (start == NULL)
		printf("\n Empty List \n");
    		else 
    		{	new_node->emp_id = id;
        			strcpy(new_node->emp_name,name);
        			ptr = start;
       			new_node->next = NULL;
      			while (ptr->next!= NULL)
            			ptr = ptr->next;
        			ptr->next = new_node;
       			new_node->prev = ptr;
        			new_node->next = NULL;
        			printf("\n New list :\n");
        			display();   }
    				break;  				
    		case 3: exit(0);
        			default:
            		break;
		}
		     }
               getch();     }
   }
