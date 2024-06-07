/*
	 MERGE SORT
*/

       #include<stdio.h>
       #include<conio.h>

	void merge(int [], int , int, int);
	void mergesort(int [], int, int);

     void main()
     {
	 int size , x[30] , i;

	 clrscr();

	 printf("\n\n Enter size : ");
	  scanf("%d" , &size);

	printf("\n\n Enter nums :\n");
	 for(i=0 ;i<size ; i++)
	 {
	      scanf("%d" , &x[i]);
	 }

	    mergesort(x , 0 , size-1);

	 getch();
     }

	void mergesort(int x[] , int beg , int end)
	{
		int mid;

	     if(beg < end)
	     {
		 mid = (beg + end)/2;
		 mergesort(x , beg , mid);
		 mergesort(x, mid+1 , end);

		 merge(x, beg , mid , end);
	     }
	}

	void merge(int x[], int beg, int mid, int end)
	{
	     int i=beg , j=mid+1 , k=beg , temp[100];

	       while(i<=mid && j<=end)
	       {
		   if(x[i] < x[j])
		   {
		      temp[k] = x[i];
			i++; k++;
		   }
		   else
		   {
		       temp[k] = x[j];
			j++; k++;
		   }
	       }

		  while(i <= mid)
		  {
		      temp[k++] = x[i++];
		  }

		  while(j <= end)
		  {
		      temp[k++] = x[j++];
		  }

		  printf("\n\n List : ");
		  for(i=beg ; i<k ; i++)
		  {
		      x[i] = temp[i];

		      printf(" %d ", x[i]);
		  }
	}
