#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>
struct node
{  char name[10];
    int info;
    struct node *next;
} * start;
void display()
{      if (start == NULL)
        printf("\n Empty List\n");
    else
    {   struct node *ptr = start;
        while (ptr != NULL)
       {     printf("%d ", ptr->info);
            printf(" %s \t", ptr->name);
            ptr = ptr->next;    }
    }}
void createlist(int data, char nm[10])
{    struct node *new_node, *ptr;
    new_node = malloc(sizeof(struct node));
    new_node->info = data;
    strcpy(new_node->name, nm);
    new_node->next = NULL;
    if (start == NULL)
    {       start = new_node;  }
    else
    {  ptr = start;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = new_node;  }
}
void insertbeg(int element, char nm[10])
{    struct node *ptr = malloc(sizeof(struct node));
    ptr->info = element;
 	strcpy(ptr->name,nm);   
    if (start == NULL)
    {       start = ptr; }
    else
    {   ptr->next = start;
        start = ptr;
        printf("Element inserted successfully \n New List :\n");
        display(); }
}
void insertloc(int element, char nm[10])
{    if (start == NULL)
    {       printf("\n Empty List \n");  }
    else
    {  struct node *new_node = malloc(sizeof(struct node)),*ptr = start;
        int loc, c=1;
        new_node->info = element;
        strcpy(new_node->name,nm);
        printf("Enter the address where element to be inserted :");
        scanf("%d",&loc);
        while (c<loc-1)
        {      ptr = ptr->next;
               ++c;  }
        new_node->next = ptr->next;
        ptr->next = new_node;
        printf("\n New list :\n");
        display();  }
}
void insertend(int element, char nm[10])
{   if (start == NULL)
    {     printf("\n Empty List \n");  }
    else 
        { struct node *ptr,*new_node = malloc(sizeof(struct node));
        new_node->info = element;
        strcpy(new_node->name,nm);
        ptr = start;
        new_node->next = NULL;
        while (ptr->next!= NULL)
            ptr = ptr->next;
        ptr->next = new_node;
        printf("\n New list :\n");
        display();  }
}
void delfirst()
{   if (start == NULL)
    {       printf("\n Underflow Error.");  }
    else
    {  struct node *ptr;
        ptr = start;
        start = start->next;
        free(ptr);
        printf("\n element deleted successfully \n New list is :\n");
        display();   }
}
void delend()
{   if (start == NULL)
    {       printf("\n Underflow Error. ");  }
    else
    {    struct node *ptr;
        ptr = start;
        while (ptr->next->next != NULL)
            ptr = ptr->next;
        ptr->next = NULL;
        printf("\n element deleted successfully \n New list is :\n");
        display();  }
}
void delspecific()
{   if (start == NULL)
    {       printf("\n Underflow Error. ");  }
    else
    {  int loc,c=1;
        struct node *ptr;
        ptr = start;
        printf("\n Enter the location of element to be deleted from the list: ");
        scanf("%d", &loc);
        while (c<loc-1)
        {     printf("  %d", ptr->info);
            ptr = ptr->next;
            ++c; }
        ptr->next = ptr->next->next;
        printf("\n element deleted successfully \n New list is :\n");
       	display();   }
}
void countele()
{   if (start == NULL)
    {       printf("\n Empty list \n");  }
    else
    {  int count = 0;
        struct node *ptr = start;
        while (ptr != NULL)
        {     ptr = ptr->next;
            count++;  }
        printf("\n Total elements in list: %d", count);  }
}
void reverse()
{   if (start == NULL)
    { printf("\n Empty list\n"); }
    else
    { struct node *p1,*p2,*p3;
        p1 = start;
        p2 = p1->next;
        p3 = p2->next;
        p1->next = NULL;
        p2->next = p1;
        while(p3!=NULL)
      {      p1 = p2;
            p2 = p3;
            p3 = p3->next;
            p2->next = p1; }
        start = p2;
        display();  }
}
int main()
{   int opt, ele, ch=0, ch1=0, element, i;
    char nam[10];
    start = NULL;
    while (1)
    {    printf("\n\n OPTION 1: Creation of New list.");
		printf("\n OPTION 2: Insersion in the list.");
		printf("\n OPTION 3: Deletion from the list.");
		printf("\n OPTION 4: Counting of elements in the list.");
		printf("\n OPTION 5: Display the list.");
		printf("\n OPTION 6: Reversal of the list.");
		printf("\n OPTION 7: Exit ");
        printf("\n\n Enter your option: ");
		scanf("%d", &opt);
        switch (opt)
        {	case 1:	printf("\n Enter the no. of elements: ");
            		scanf("%d", &ele);
            		int n;
            		char nm[10];
            		printf("\n Enter Roll no. and name :\n");
            		for (i = 0; i < ele; i++)
            		{   scanf("\n %d", &n);
            		    scanf(" %s", &nm);
            		    createlist(n, nm);  }
            		printf("\n List created succesfully \n");
            		break;
        	case 2:	printf("\n OPTION 1: Insertion at the beginning of the list.");
        			printf("\n OPTION 2: Insertion at the specified location in the list.");
        			printf("\n OPTION 3: Insertion at the end of the list.");
        			printf("\n Enter your option: ");
            	    scanf("%d", &ch1);
        		    printf("\n Enter the roll no. to be inserted: ");
            		scanf("%d", &element);
            		printf("\n Enter the roll no. to be inserted: ");
            		scanf(" %s",&nam);
            		switch (ch1)
            		{	case 1:	insertbeg(element,nam);
            	    			break;
              	            			case 2: insertloc(element,nam);
                				break;				
            			case 3: insertend(element,nam);
                				break;
            			default: printf("\n wrong input \n ");
                				 break;        }
         	                             break;
        	case 3: printf("\n OPTION 1: Deletion at the beginning of the list.");
        			printf("\n OPTION 2: Deletion at the user specified location in the list.");
        			printf("\n OPTION 3: Deletion at the end of the list.");
        			printf("\n Enter your Option: ");
        		    scanf("%d", &ch);
        		    switch (ch)
            		{	case 1:	delfirst();
                				break;
            			case 2: delspecific();
                				break;
            			case 3: delend();
            				    break;
				default:printf("\n wrong input \n ");
                    			break;       }
                               		break;
        	                             case 4: countele();
            		                            break;
			case 5: printf("\n Your list is : \n");
            		                           display();
            	                             	break;
			case 6:	reverse();
            		                            break;
			case 7: exit(0);
        			default:
            		                           break;  	}
         }
    getch();
    return 0;
}
