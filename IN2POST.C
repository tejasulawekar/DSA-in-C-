/*
       INFIX TO POSTFIX USING STACK
*/

   #include<stdio.h>
   #include<conio.h>
   #include<string.h>
   #include<ctype.h>

   char stk[30];
   int top=-1;

   void PUSH(char ch)
   {
	 top++;
       stk[top] = ch;
   }

   char POP()
   {
       if(top != -1)
       {
	  return stk[top--];
       }
   }

   int getpri(char op)
   {
	if(op=='*' || op=='/' || op=='%')
	{
	    return 1;
	}
	else if(op=='+' || op=='-')
	{
	     return 0;
	}
	else
	{
	     return -1;
	}
   }

   void main()
   {
      char infix[30], postfix[30];
      int i,j=0;

       clrscr();

     printf("\n\n Enter infix : ");
	gets(infix);

     for(i=0 ; i<strlen(infix) ; i++)
     {
	 if(infix[i] == '(')
	 {
	     PUSH(infix[i]);
	 }
	 else if(isalpha(infix[i]))
	 {
	    postfix[j] = infix[i];
	      j++;
	 }
	 else if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*'
		      || infix[i]=='/' || infix[i]=='%')
	 {
	      while(getpri(stk[top]) >= getpri(infix[i]))
	      {
		  postfix[j] = POP();
		    j++;
	      }

		PUSH(infix[i]);
	 }
	 else if(infix[i] == ')')
	 {
	     while(stk[top] != '(')
	     {
		postfix[j] = POP();
		  j++;
	     }

		 POP();
	 }
     }

	   postfix[j] = '\0';

	printf("\n\n postfix = %s ", postfix);

       getch();
   }

