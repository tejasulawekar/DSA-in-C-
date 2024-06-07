/*
     CIRCULAR LINKED LIST
*/
   #include<stdio.h>
   #include<conio.h>
   #include<stdlib.h>

   struct node
   {
       int num;
       struct node *next;

   }*start=NULL;

       void CREATE();
       void DISP();
       void INSERT_BEGIN();
       void INSERT_END();
       void DELETE_BEGIN();
       void DELETE_END();

      int menu()
      {
	   int choice;

	   clrscr();

	   printf("\n\n 1] Create a Circular LL ");
	   printf("\n 2] Display Circular LL ");
	   printf("\n 3] INSERT_BEGIN ");
	   printf("\n 4] INSERT_END ");
	   printf("\n 5] DELETE_BEGIN ");
	   printf("\n 6] DELETE_END ");
	   printf("\n 7] EXIT ");

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
			CREATE();
			DISP();
			break;
	      case 2:
			DISP();
			break;
	      case 3:
			INSERT_BEGIN();
			DISP();
			break;
	      case 4:
			INSERT_END();
			DISP();
			break;
	      case 5:
			DELETE_BEGIN();
			DISP();
			break;
	      case 6:
			DELETE_END();
			DISP();
			break;
	      case 7:
		       printf("\n\n EXIT ");
			 getch();
			 exit(0);
	      default:
		       printf("\n\n INVALID INPUT ");
	 }
	    getch();
     }while(ch != 7);
   }

      void CREATE()
      {
	   struct node *newnode, *temp;
	   newnode = malloc(sizeof(struct node));

	       printf("\n\n Enter a num : ");
	       scanf("%d" , &newnode->num);

	    if(start == NULL)
	    {
		start = newnode;
		newnode->next = start;
	    }
	    else
	    {
		  temp = start;

		 while(temp->next != start)
		 {
		      temp = temp->next;
		 }

		     temp->next = newnode;
		     newnode->next = start;
	    }
      }

      void DISP()
      {
	    struct node *temp;

	  if(start == NULL)
	  {
	      printf("\n\n NO LINKED LIST ");
	  }
	  else
	  {
		 temp = start;

	      do
	      {
		   printf("\n\n %d ", temp->num);

		      temp = temp->next;

	      }while(temp != start);
	  }
      }

      void INSERT_BEGIN()
      {
	   struct node *newnode, *temp;
	   newnode = malloc(sizeof(struct node));

	     printf("\n\n Enter a num : ");
	       scanf("%d", &newnode->num);

	       newnode->next = start;

	       temp = start;

	    while(temp->next != start)
	    {
		temp = temp->next;
	    }

	      temp->next = newnode;
	      start = newnode;
      }

      void INSERT_END()
      {
	   struct node *newnode, *temp;

	       temp = start;

	    while(temp->next != start)
	    {
		temp = temp->next;
	    }

	      newnode = malloc(sizeof(struct node));

	      printf("\n\n Enter a num : ");
	      scanf("%d" , &newnode->num);

		newnode->next = start;
		temp->next = newnode;
      }

      void DELETE_BEGIN()
      {
	   struct node *temp, *temp2;

	   if(start->next == start)
	   {
		free(start);
		start = NULL;
	   }
	   else
	   {
		      temp = start;

		while(temp->next != start)
		{
		    temp = temp->next;
		}

		  temp2 = start->next;
		    free(start);
		    start = temp2;

		    temp->next = start;

	   }
      }

      void DELETE_END()
      {
	    struct node *temp;

	    if(start->next == start)
	    {
		free(start);
		start = NULL;
	    }
	    else
	    {
		    temp = start;

	       while(temp->next->next != start)
	       {
		     temp = temp->next;
	       }

		   free(temp->next);
		   temp->next = start;
	    }
      }































