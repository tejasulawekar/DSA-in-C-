/*
      Tower of Hanoi
*/

       #include<stdio.h>
       #include<conio.h>

	void move(int n , char src , char aux , char dest);

     void main()
     {
	  int n;

	  clrscr();

	  printf("\n\n Enter no of discs : ");
	     scanf("%d" , &n);

	  move(n , 'A' , 'B' , 'C');

	  getch();
     }

	void move(int n , char src , char aux , char dest)
	{
	    if(n >= 1)
	    {
	       move(n-1 , src , dest , aux);

	       printf("\n\n move %c to %c ", src , dest);

	       move(n-1, aux , src , dest);
	    }
	}







/*
     FOR n = 3

	x move(3, A, B, C);
	   x move(2, A, C, B)
	       x move(1, A, B, C)
		   move(0, A, C , B)
    Print A to C
		move(0, )
    Print A to B
	    x move(1, C, A, B)
	      move(0,)
    Print C to B
	      move(0, )
    Print A to C

	     x move(2, B, A, C)
		x move(1, B, C, A)
		    move(0, )
    Print B to A
		move(0, )
    Print B to C
		x move(1, A, B , C)
		   move(0, )
    Print A to C
		move(0, )
*/
















