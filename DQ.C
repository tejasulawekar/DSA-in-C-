/*
       DOUBLY ENDED QUEUE (DEQUE)
*/

   #include<stdio.h>
   #include<process.h>
   #include<conio.h>

     int x[5], f=-1, r=-1, size=5;

      void INSERT_LEFT();
      void INSERT_RIGHT();
      void DELETE_LEFT();
      void DELETE_RIGHT();
      void DISPLAY();

   int menu()
   {
	 int choice;

	 clrscr();

       printf("\n\n 1] INSERT LEFT ");
       printf("\n\n 2] INSERT RIGHT ");
       printf("\n\n 3] DELETE LEFT ");
       printf("\n\n 4] DELETE RIGHT ");
       printf("\n\n 5] DISPLAY ");
       printf("\n\n 6] EXIT ");

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
		      INSERT_LEFT();
		      DISPLAY();
		      break;
	      case 2:
		      INSERT_RIGHT();
		      DISPLAY();
		      break;
	      case 3:
		      DELETE_LEFT();
		      DISPLAY();
		      break;
	      case 4:
		      DELETE_RIGHT();
		      DISPLAY();
		      break;
	      case 5:
		      DISPLAY();
		      break;
	      case 6:
		      printf("\n\n EXIT ");
			getch();
			exit(0);
	      default:
		      printf("\n\n INVALID INPUT ");
	 }
	     getch();
     }while(ch != 6);
   }


     void INSERT_LEFT()
     {
	 if((f==0 && r==size-1) || (f == r+1))
	 {
	     printf("\n\n DEQUEUE OVERFLOW ");
		return;
	 }

	 if(f == -1)
	 {
	      f = r = 0;
	 }
	 else if(f == 0)
	 {
	     f = size-1;
	 }
	 else
	 {
	     f--;
	 }

	      printf("\n\n Enter a num : ");
		scanf("%d", &x[f]);
     }

     void INSERT_RIGHT()
     {
	 if((f==0 && r==size-1) || (f == r+1))
	 {
	     printf("\n\n DEQUEUE OVERFLOW ");
		return;
	 }
	 if(r == -1)
	 {
	     f = 0;
	 }
	 if(r == size-1)
	 {
	     r = -1;
	 }
		   r++;

	   printf("\n\n Enter a num : ");
	     scanf("%d", &x[r]);
     }

     void DELETE_LEFT()
     {
	  if(f == -1)
	  {
	       printf("\n\n DQ IS EMPTY ");
	  }
	  else if(f == r)
	  {
	      x[f] = 0;
	      f = r = -1;
	  }
	  else
	  {
	      x[f] = 0;
	      f++;
	  }
	  if(f == size)
	  {
	      f = 0;
	  }
     }

     void DELETE_RIGHT()
     {
	 if(r == -1)
	 {
	     printf("\n\n DQ IS EMPTY ");
	 }
	 else if(f == r)
	 {
	     x[r] = 0;
	     f = r = -1;
	 }
	 else
	 {
	     x[r] = 0;
	       r--;

		if(r == -1)
		{
		   r = size-1;
		}
	 }
     }

      void DISPLAY()
      {
	    int i;

	  if(f == -1)
	  {
	      printf("\n\n DQ IS EMPTY ");
	  }
	  else
	  {
	       printf("\n\n DEQUE : ");

	       if(f <= r)
	       {
		   for(i=f ; i<=r ; i++)
		   {
		       printf(" %d ", x[i]);
		   }
	       }
	       else
	       {
		   for(i=f ; i<size ; i++)
		   {
		       printf(" %d ", x[i]);
		   }

		   for(i=0 ; i<=r ; i++)
		   {
		       printf(" %d ", x[i]);
		   }
	       }
	  }
      }

