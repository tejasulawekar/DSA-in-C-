/*
      "HEAP SORT"
*/
      #include<stdio.h>
      #include<conio.h>

	  void HEAPSORT(int [], int );

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

	     HEAPSORT(x, size);

	  printf("\n\n List after sort : \n");
	     for(i=0 ; i<size ; i++)
	     {
		 printf(" %d ", x[i]);
	     }

	    getch();
     }

	  void HEAPSORT(int x[], int size)
	  {
	       int i, root, child, temp;


	       for(i=0; i<size ; i++)
	       {
		     child = i;

		     do
		     {
			   root = (child-1)/2;

			   if(x[child] > x[root])
			   {
				temp = x[child];
				x[child] = x[root];
				x[root] = temp;
			   }

			      child = root;

		     }while(child != 0);

			  temp = x[0];
			  x[0] = x[size-1];
			  x[size-1] = temp;
	       }

		    if(size > 1)
		    {
		       HEAPSORT(x , size-1);
		    }
	  }
