/*
       Radix Sort
*/

      #include<stdio.h>
      #include<conio.h>

	 void RADIX(int [], int);

     void main()
     {
	 int x[30], size, i;

	    clrscr();

	 printf("\n\n Enter size : ");
	    scanf("%d" , &size);

	 printf("\n\n Enter nums : \n");
	   for(i=0 ; i<size ; i++)
	   {
	       scanf("%d" , &x[i]);
	   }

	       RADIX(x, size);

	  printf("\n\n List after sort : \n");
	    for(i=0; i<size ; i++)
	    {
	       printf(" %d ", x[i]);
	    }

	    getch();
     }

	void RADIX(int x[], int size)
	{
	      int i,j,k, max, rem, bucket[10][10], bc[10];
		 int NOP=0, pass, div=1;

		   max = x[0];

	       for(i=1 ; i<size ; i++)
	       {
		   if(max < x[i])
		   {
		      max = x[i];
		   }
	       }

		  while(max != 0)
		  {
		       NOP++;
		      max = max / 10;
		  }

	     for(pass=1; pass<=NOP ; pass++)
	     {
		 for(i=0 ; i<10 ; i++)
		 {
		     bc[i] = 0;
		 }


		 for(i=0 ; i<size ; i++)
		 {
		      rem = (x[i] / div) % 10;

		      bucket[rem][bc[rem]] = x[i];

			 bc[rem]++;
		 }

			div = div * 10;

			 k=0;

		for(i=0 ; i<10 ; i++)
		{
		    for(j=0 ;j<bc[i]; j++)
		    {
			 x[k] = bucket[i][j];
			   k++;
		    }
		}
	     }
	}

