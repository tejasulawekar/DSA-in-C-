/*
     INSERTION SORT
*/

   #include<stdio.h>
   #include<conio.h>

   void main()
   {
      int x[30], size, i,j,temp;

       clrscr();

       printf("\n\n Enter size : ");
	  scanf("%d" , &size);

       printf("\n\n Enter nums : \n");
	 for(i=0 ; i<size ; i++)
	 {
	     scanf("%d" , &x[i]);
	 }

	 for(i=1 ; i<size ; i++)
	 {
	      j=i-1;
	      temp = x[i];

	      while(j>=0 && x[j] > temp)
	      {
		  x[j+1] = x[j];
		    j--;
	      }

		 x[j+1] = temp;

	   printf("\n\n List : ");
	   for(j=0 ; j<size ; j++)
	   {
	       printf(" %d ", x[j]);
	   }
	}

       getch();
   }
