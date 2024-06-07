/*
       BINARY SEARCH
*/

   #include<stdio.h>
   #include<conio.h>

   void main()
   {
     int size, x[30], i, num , pos=0;
	int beg, mid, end;

       clrscr();

     printf("\n\n Enter size : ");
       scanf("%d" , &size);

     printf("\n\n Enter nums (in asc order): \n");
       for(i=0 ; i<size ; i++)
       {
	  scanf("%d" , &x[i]);
       }

     printf("\n\n Enter num to be searched : ");
	scanf("%d" , &num);

	beg=0, end=size-1;

	while(beg <= end)
	{
	    mid = (beg + end)/2;

	    if(num == x[mid])
	    {
		pos = mid+1;
		break;
	    }
	    else if(num < x[mid])
	    {
		end = mid-1;
	    }
	    else
	    {
	       beg = mid+1;
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











