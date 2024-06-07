/*
     QUEUE WITH LINKED LIST (FIFO)
*/

   #include<stdio.h>
   #include<conio.h>
   #include<process.h>

   struct node
   {
	 int num;
	 struct node *next;
   };

       struct node *f = NULL;
       struct node *r = NULL;

     void PUSH()
     {
	  struct node *newnode;
	  newnode = malloc(sizeof(struct node));

	    printf("\n\n Enter a num : ");
	    scanf("%d" , &newnode->num);

	    newnode->next = NULL;

	 if(f == NULL)
	 {
	     f = r = newnode;
	 }
	 else
	 {
	      r->next = newnode;
	       r = newnode;
	 }
     }

     void DISP()
     {
	  struct node *temp;

	  if(f == NULL)
	  {
	       printf("\n\n QUEUE IS EMPTY ");
	  }
	  else
	  {
		  temp = f;

		  while(temp != NULL)
		  {
		       printf("\n\n %d ", temp->num);

			 temp = temp->next;
		  }
	  }
     }

     void PEEK()
     {
	  if(f == NULL)
	  {
	       printf("\n\n QUEUE IS EMPTY ");
	  }
	  else
	  {
	       printf("\n\n PEEK = %d ", f->num);
	  }
     }

     void POP()
     {
	 struct node *temp;

	  if(f == NULL)
	  {
	       printf("\n\n QUEUE IS EMPTY ");
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



