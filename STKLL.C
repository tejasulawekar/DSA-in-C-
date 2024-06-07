/*
      STACK WITH LINKED LIST (LIFO)
*/

   #include<stdio.h>
   #include<conio.h>
   #include<process.h>

   struct node
   {
	 int num;
	 struct node *prev;

   }*top=NULL;


      void PUSH()
      {
	    struct node *newnode;
	    newnode = malloc(sizeof(struct node));

	    printf("\n\n Enter a num : ");
	    scanf("%d" , &newnode->num);

	      newnode->prev = top;
		top = newnode;
      }

      void DISP()
      {
	    struct node *temp;

	    if(top == NULL)
	    {
		printf("\n\n STACK IS EMPTY ");
	    }
	    else
	    {
		 temp = top;

		while(temp != NULL)
		{
		     printf("\n\n %d ", temp->num);

			 temp = temp->prev;
		}
	    }
      }

      void PEEK()
      {
	    if(top == NULL)
	    {
		printf("\n\n STACK IS EMPTY ");
	    }
	    else
	    {
		printf("\n\n PEEK = %d ", top->num);
	    }
      }

      void POP()
      {
	   struct node *temp;

	    if(top == NULL)
	    {
		printf("\n\n STACK IS EMPTY ");
	    }
	    else
	    {
		   temp = top->prev;
		     free(top);
		     top = temp;
	    }
      }

   int menu()
   {
	int choice;

	clrscr();

      printf("\n\n 1] PUSH  ");
      printf("\n\n 2] DISP  ");
      printf("\n\n 3] PEEK  ");
      printf("\n\n 4] POP  ");
      printf("\n\n 5] EXIT  ");

      printf("\n\n Enter your choice :  ");
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
		     PUSH();
		     DISP();
		     break;
	      case 2:
		     DISP();
		     break;
	      case 3:
		     PEEK();
		     break;
	      case 4:
		     POP();
		     DISP();
		     break;
	      case 5:
		     printf("\n\n EXIT ");
			getch();
			exit(0);
	      default:
		      printf("\n\n INVALID INPUT ");
	  }
	    getch();
      }while(ch != 5);
   }



