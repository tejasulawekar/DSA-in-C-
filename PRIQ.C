/*
      PRIORITY QUEUE WITH LINKED LIST
*/

   #include<stdio.h>
   #include<conio.h>
   #include<stdlib.h>

   void INSERT();
   void DISP();
   void DELETE();

   struct node
   {
       int num;
       int pri;
       struct node *next;
   };

       struct node *f = NULL;
       struct node *r = NULL;

   int menu()
   {
	int choice;

	clrscr();

      printf("\n\n 1] INSERT ");
      printf("\n\n 2] DISP ");
      printf("\n\n 3] DELETE ");
      printf("\n\n 4] EXIT ");

      printf("\n\n Enter your choice : ");
	scanf("%d" , &choice);

	return choice;
   }

   void main()
   {
       int ch;

       clrscr();

    do
    {
	ch = menu();

	switch(ch)
	{
	    case 1:
		     INSERT();
		     DISP();
		     break;
	    case 2:
		     DISP();
		     break;
	    case 3:
		     DELETE();
		     DISP();
		     break;
	    case 4:
		     printf("\n\n THANK YOU!");
			getch();
			exit(0);
	    default:
		     printf("\n\n INVALID INPUT ");
	}
	    getch();
    }while(ch != 4);
   }

       void INSERT()
       {
	    struct node *newnode, *temp;
	    newnode = malloc(sizeof(struct node));

	    printf("\n\n Enter a num : ");
	    scanf("%d" , &newnode->num);

	    printf("\n\n Enter a priority : ");
	    scanf("%d" , &newnode->pri);

	      newnode->next = NULL;

	    if(f == NULL)
	    {
		f = r = newnode;
	    }
	    else if(newnode->pri < f->pri)
	    {
		 newnode->next = f;
		 f = newnode;
	    }
	    else
	    {
		  temp = f;

		while(temp->next != NULL && temp->next->pri <= newnode->pri)
		{
		   temp = temp->next;
		}

		if(temp->next != NULL)
		{
		    newnode->next = temp->next;
		    temp->next = newnode;
		}
		else
		{
		     r->next = newnode;
		     r = newnode;
		}
	    }
       }

      void DISP()
      {
	   struct node *temp;

	    if(f == NULL)
	    {
		printf("\n\n EMPTY ");
	    }
	    else
	    {
		  temp = f;

		while(temp != NULL)
		{
		     printf("\n\n %d ", temp->num);
		     printf("[%d]", temp->pri);
		     temp = temp->next;
		}
	    }
      }

      void DELETE()
      {
	   struct node *temp;

	    if(f == NULL)
	    {
		printf("\n\n EMPTY ");
	    }
	    else
	    {
	       temp = f->next;
		 free(f);
		 f = temp;
	    }
	    if(f == NULL)
	    {
	       r = NULL;
	    }
       }
