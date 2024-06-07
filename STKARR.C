/*
       STACK WITH ARRAY  (LIFO)
*/

   #include<stdio.h>
   #include<conio.h>
   #include<process.h>

   int stk[30], top=-1;

     void PUSH();
     void DISP();
     void PEEK();
     void POP();

   int menu()
   {
	int choice;

	clrscr();

       printf("\n\n 1] PUSH ");
       printf("\n\n 2] DISP ");
       printf("\n\n 3] PEEK ");
       printf("\n\n 4] POP ");
       printf("\n\n 5] EXIT ");

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
		      printf("\n\n THANK YOU!");
			getch();
			exit(0);
	       default:
		      printf("\n\n INVALID INPUT ");
	   }
	       getch();
       }while(ch != 5);
   }

     void PUSH()
     {
	 if(top == 29)
	 {
	     printf("\n\n OVERFLOW!");
	 }
	 else
	 {
		 top++;

	     printf("\n\n Enter a num : ");
	       scanf("%d" , &stk[top]);
	 }
     }

     void DISP()
     {
	    int i;

	 if(top == -1)
	 {
	     printf("\n\n STACK IS EMPTY! ");
	 }
	 else
	 {
	     for(i=top ; i>=0 ; i--)
	     {
		 printf("\n\n %d ", stk[i]);
	     }
	 }
     }

     void PEEK()
     {
	 if(top == -1)
	 {
	     printf("\n\n STACK IS EMPTY! ");
	 }
	 else
	 {
	    printf("\n\n PEEK => %d ", stk[top]);
	 }
     }

     void POP()
     {
	 if(top == -1)
	 {
	     printf("\n\n STACK IS EMPTY! ");
	 }
	 else
	 {
	       stk[top] = 0;
		top--;
	 }
     }
