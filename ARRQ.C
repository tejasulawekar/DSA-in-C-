/*
      QUEUE WITH ARRAY (FIFO)
*/

   #include<stdio.h>
   #include<conio.h>
   #include<process.h>

   int x[30], f=-1, r=-1;

   void PUSH()
   {
	if(f == -1)
	{
	     f = 0;
	}

	     r++;

	printf("\n\n Enter a num : ");
	  scanf("%d" , &x[r]);
   }

   void DISP()
   {
       int i;

       if(f == -1)
       {
	  printf("\n\n QUEUE IS EMPTY ");
       }
       else
       {
	     for(i=f; i<=r; i++)
	     {
		printf("\n\n %d ", x[i]);
	     }
       }
   }

   void PEEK()
   {
       if(f == -1)
       {
	  printf("\n\n QUEUE IS EMPTY ");
       }
       else
       {
	  printf("\n\n PEEK => %d ", x[f]);
       }
   }

   void POP()
   {
       if(f == -1)
       {
	  printf("\n\n QUEUE IS EMPTY ");
       }
       else
       {
	    x[f] = 0;
	    f++;
       }

       if(f == r+1)
       {
	   f = r = -1;
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
