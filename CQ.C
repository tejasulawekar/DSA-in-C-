/*
     CIRCULAR  QUEUE WITH ARRAYS (FIFO)
*/

   #include<stdio.h>
   #include<conio.h>
   #include<stdlib.h>

   void INSERT();
   void DISP();
   void DELETE();

   int x[5], f=-1, r=-1, size=5;

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
	if( (f==0 && r==size-1) || (f == r+1) )
	{
	     printf("\n\n CQ OVERFLOW!");
		 return;
	}

	if(f == -1)
	{
	    f=0;
	}
	if(r == size-1)
	{
	    r = -1;
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
	   printf("\n\n CQ IS EMPTY ");
       }
       else
       {
	     printf("\n\n CQ : ");

	   if(f <= r)
	   {
	       for(i=f; i<=r ; i++)
	       {
		   printf(" %d ", x[i]);
	       }
	   }
	   else
	   {
	       for(i=f; i<size ; i++)
	       {
		  printf(" %d ", x[i]);
	       }

	       for(i=0 ; i<=r; i++)
	       {
		  printf(" %d ", x[i]);
	       }
	   }
       }
   }

   void DELETE()
   {
	if(f == -1)
	{
	     printf("\n\n CQ IS EMPTY ");
	}
	else
	{
	     x[f] = 0;
	     f++;
	}
	if(f == r+1)
	{
	     f = r = -1
	}
	if(f == size)
	{
	      f = 0;
	}
   }

