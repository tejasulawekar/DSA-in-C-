/*
      SELECTION SORT
*/

   #include<stdio.h>
   #include<conio.h>

   void main()
   {
      int x[30], size, i,j,temp, small, pos;

       clrscr();

       printf("\n\n Enter size : ");
	  scanf("%d" , &size);

       printf("\n\n Enter nums : \n");
	 for(i=0 ; i<size ; i++)
	 {
	     scanf("%d" , &x[i]);
	 }

	 for(i=0 ; i<size ; i++)
	 {
	      small = x[i];
	      pos = i;

	      for(j=i+1 ; j<size ; j++)
	      {
		   if(small > x[j])
		   {
		       small = x[j];
		       pos = j;
		   }
	      }

		  temp = x[i];
		  x[i] = x[pos];
		  x[pos] = temp;

	   printf("\n\n List : ");
	   for(j=0 ; j<size ; j++)
	   {
	       printf(" %d ", x[j]);
	   }
	  }

       getch();
   }

