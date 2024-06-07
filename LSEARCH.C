/*
       LINEAR SEARCH
*/

   #include<stdio.h>
   #include<conio.h>

   void main()
   {
     int size, x[30], i, num , pos=0;

       clrscr();

     printf("\n\n Enter size : ");
       scanf("%d" , &size);

     printf("\n\n Enter nums : \n");
       for(i=0 ; i<size ; i++)
       {
	  scanf("%d" , &x[i]);
       }

     printf("\n\n Enter num to be searched : ");
	scanf("%d" , &num);

       for(i=0 ; i<size ; i++)
       {
	   if(num == x[i])
	   {
		pos = i+1;
		break;
	   }
       }

       if(pos == 0)
       {
	   printf("\n\n NUM NOT FOUND ");
       }
       else
       {
	   printf("\n\n pos = %d ", pos);
       }

       getch();
   }










