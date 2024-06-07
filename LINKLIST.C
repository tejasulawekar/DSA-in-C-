/*
     Singly Linked List
*/

   #include<stdio.h>
   #include<stdlib.h>
   #include<conio.h>

   struct node
   {
       int num;
       struct node *next;
   };

       struct node *start = NULL;

       void CREATE();
       void DISP();
       void INSERT_BEGIN();
       void INSERT_BEFORE();
       void INSERT_AFTER();
       void INSERT_END();
       void DELETE_BEGIN();
       void DELETE_GIVEN();
       void DELETE_LAST();

    int menu()
    {
	int choice;

	clrscr();

	printf("\n\n 1] Create a Linked List ");
	printf("\n 2] Display Linked List ");
	printf("\n 3] INSERT_BEGIN ");
	printf("\n 4] INSERT_BEFORE ");
	printf("\n 5] INSERT_AFTER ");
	printf("\n 6] INSERT_END ");
	printf("\n 7] DELETE_BEGIN ");
	printf("\n 8] DELETE_GIVEN ");
	printf("\n 9] DELETE_LAST ");
	printf("\n 10] EXIT ");

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
		    INSERT_BEFORE();
		    DISP();
		    break;
	     case 5:
		    INSERT_AFTER();
		    DISP();
		    break;
	     case 6:
		    INSERT_END();
		    DISP();
		    break;
	     case 7:
		    DELETE_BEGIN();
		    DISP();
		    break;
	     case 8:
		    DELETE_GIVEN();
		    DISP();
		    break;
	     case 9:
		    DELETE_LAST();
		    DISP();
		    break;
	     case 10:
		     printf("\n\n THANK YOU! ");
		     getch();
		     exit(0);
	     default:
		     printf("\n\n INVALID INPUT ");
	 }
	 getch();
     }while(ch != 10);
   }

      void CREATE()
      {
	   struct node *newnode, *temp;
	   newnode = malloc(sizeof(struct node));

	    printf("\n\n Enter a num : ");
	    scanf("%d" , &newnode->num);

	       newnode->next = NULL;

	   if(start == NULL)
	   {
		start = newnode;
	   }
	   else
	   {
		    temp = start;

		while(temp->next != NULL)
		{
		   temp = temp->next;
		}

		  temp->next = newnode;
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

	       while(temp != NULL)
	       {
		   printf("\n\n %d ", temp->num);

		     temp = temp->next;
	       }
	   }
      }

      void INSERT_BEGIN()
      {
	   struct node *newnode;
	   newnode = malloc(sizeof(struct node));

	     printf("\n\n Enter a num : ");
	       scanf("%d", &newnode->num);

	       newnode->next = start;
	       start = newnode;
      }



      void INSERT_BEFORE()
      {
	   struct node *newnode, *temp;
	   int tnum;

	   printf("\n\n Enter a target num : ");
	     scanf("%d" , &tnum);

	    if(tnum == start->num)
	    {
		newnode = malloc(sizeof(struct node));

		     printf("\n\n Enter a num : ");
		       scanf("%d", &newnode->num);

		       newnode->next = start;
		       start = newnode;
	    }
	    else
	    {
		  temp = start;

		while(temp->next != NULL && temp->next->num != tnum)
		{
		    temp = temp->next;
		}

		 if(temp->next == NULL)
		 {
		    printf("\n\n Target number not found...");
		 }
		 else
		 {
		     newnode = malloc(sizeof(struct node));

		       printf("\n\n Enter a num : ");
		       scanf("%d" , &newnode->num);

		       newnode->next = temp->next;
		       temp->next = newnode;
		 }
	    }
      }


      void INSERT_AFTER()
      {
	   struct node *newnode, *temp;
	   int tnum;

	   printf("\n\n Enter a target num : ");
	     scanf("%d" , &tnum);

		temp = start;

	    while(temp != NULL && temp->num != tnum)
	    {
		temp=  temp->next;
	    }

	    if(temp == NULL)
	    {
		printf("\n\n Target num not found ");
	    }
	    else
	    {
		     newnode = malloc(sizeof(struct node));

		       printf("\n\n Enter a num : ");
		       scanf("%d" , &newnode->num);

		       newnode->next = temp->next;
		       temp->next = newnode;
	    }
      }

      void INSERT_END()
      {
	   struct node *newnode, *temp;

	      temp = start;

	    while(temp->next != NULL)
	    {
	       temp = temp->next;
	    }

		newnode = malloc(sizeof(struct node));

		  printf("\n\n Enter a num : ");
		  scanf("%d" , &newnode->num);

		   newnode->next = NULL;
		   temp->next = newnode;
      }


      void DELETE_BEGIN()
      {
	    struct node *temp;

	    temp = start->next;

	      free(start);

	     start = temp;
      }


      void DELETE_GIVEN()
      {
	  int dnum;
	  struct node *temp, *temp2;

	     printf("\n\n Enter a num to be deleted : ");
	       scanf("%d", &dnum);

	    if(dnum == start->num)
	    {
		temp = start->next;
		  free(start);
		  start = temp;
	    }
	    else
	    {
		 temp = start;

		 while(temp->next != NULL && temp->next->num != dnum)
		 {
		     temp = temp->next;
		 }

	     if(temp->next == NULL)
	     {
		printf("\n\n NUM NOT FOUND ");
	     }
	     else
	     {
		  temp2 = temp->next->next;
		    free(temp->next);
		    temp->next = temp2;
	     }
	    }
      }

      void DELETE_LAST()
      {
	   struct node *temp;

	   if(start->next == NULL)
	   {
	       free(start);
	       start = NULL;
	   }
	   else
	   {
		temp = start;

	      while(temp->next->next != NULL)
	      {
		   temp = temp->next;
	      }

		  free(temp->next);
		  temp->next = NULL;
	   }
      }



	f























