/*
     SHELL SORT
*/

       #include<stdio.h>
       #include<conio.h>

       void SHELL(int[] , int);

     void main()
     {
       int x[30] , size , i;

	 clrscr();

	 printf("\n\n Enter size : ");
	   scanf("%d" , &size);

	 printf("\n\n Enter nums : \n");
	   for(i=0 ;i<size ; i++)
	   {
	       scanf("%d" , &x[i]);
	   }

	     SHELL(x , size);

	  printf("\n\n List after sort : \n");
	     for(i=0 ;i<size ; i++)
	     {
		printf(" %d ", x[i]);
	     }

	 getch();
     }

	 void SHELL(int x[] , int size)
	 {
	      int i , gap=size , temp;

	      while(gap > 1)
	      {
		   gap = (gap+1) / 2;

		   for(i=0 ; i<(size-gap) ; i++)
		   {
			if(x[i] > x[gap+i])
			{
			     temp = x[i];
			     x[i] = x[gap+i];
			     x[gap+i] = temp;
			}
		   }
	      }
	 }

