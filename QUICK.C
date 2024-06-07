/*
      QUICK SORT
*/

   #include<stdio.h>
   #include<conio.h>

      void QUICK(int [], int, int);

   void main()
   {
      int size, x[30], i;

       clrscr();

     printf("\n\n Enter size : ");
       scanf("%d" , &size);

     printf("\n\n Enter nums : \n");
       for(i=0 ; i<size ; i++)
	  scanf("%d" , &x[i]);

	 QUICK(x, 0, size-1);

     printf("\n\n List after sort : \n");
	for(i=0 ; i<size ; i++)
	{
	  printf(" %d ", x[i]);
	}

       getch();
   }

      void QUICK(int x[], int f, int l)
      {
	  int i,j,pivot,temp;

	  if(f < l)
	  {
	      i=pivot=f;
	      j = l;


	     while(i < j)
	     {
		 while(x[i] <= x[pivot] && i<l)
		 {
		     i++;
		 }

		 while(x[j] > x[pivot])
		 {
		     j--;
		 }

		 if(i < j)
		 {
		     temp = x[i];
		     x[i] = x[j];
		     x[j] = temp;
		 }
	     }

		  temp = x[j];
		  x[j] = x[pivot];
		  x[pivot] = temp;

		  QUICK(x, f, j-1);
		  QUICK(x, j+1, l);
	  }
      }

