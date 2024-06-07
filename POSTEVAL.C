/*
     POSTFIX EVALUATION USING STACK
*/

   #include<stdio.h>
   #include<conio.h>
   #include<string.h>
   #include<ctype.h>

   float stk[30];
   int top=-1;

   void PUSH(float n)
   {
	top++;
	stk[top] = n;
   }

   float POP()
   {
       if(top != -1)
       {
	   return stk[top--];
       }
   }

   void main()
   {
       char post[30];
       int i;
       float n1, n2, ans=0;

       clrscr();

     printf("\n\n Enter postfix : ");
	gets(post);

     for(i=0 ; i<strlen(post); i++)
     {
	 if( isdigit(post[i]) )
	 {
	     PUSH( post[i]-'0' );
	 }
	 else
	 {
	     n2 = POP();
	     n1 = POP();

	     switch(post[i])
	     {
		case '+':
			  ans = n1 + n2;
			  break;
		case '-':
			  ans = n1 - n2;
			  break;
		case '*':
			  ans = n1 * n2;
			  break;
		case '/':
			  ans = n1 / n2;
			  break;
	     }

		 PUSH(ans);
	 }
     }

	       ans = POP();

	   printf("\n\n Answer = %f ", ans);
       getch();
   }










