/*
    POLYNOMIAL ADDITION USING LINKED LIST
*/

#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coeff;
    int power;
    struct node *next;
};

     void  create(struct node*);
     void  disp(struct node*);
     void  addpoly(struct node *, struct node *, struct node *);

  int menu()
  {
       int choice;

       clrscr();

       printf("\n 1] Create first poly ");
       printf("\n 2] Display first poly ");
       printf("\n 3] Create second poly ");
       printf("\n 4] Display second poly ");
       printf("\n 5] Add poly ");
       printf("\n 6] Display addition");
       printf("\n 7] EXIT ");

       printf("\n\n Enter your choice : ");
	    scanf("%d", &choice);

	    return choice;
  }

void main()
{
   int ch;
   struct node *start1 , *start2 , *start3;

  clrscr();

       do
       {
	    ch = menu();

	    switch(ch)
	    {
		case 1:
			 start1 = malloc(sizeof(struct node));
			 create(start1);
			 disp(start1);
			 break;
		case 2:
			 disp(start1);
			 break;
		case 3:
			 start2 = malloc(sizeof(struct node));
			 create(start2);
			 disp(start2);
			 break;
		case 4:
			 disp(start2);
			 break;
		case 5:
			 start3 = malloc(sizeof(struct node));
			 addpoly(start1 , start2 , start3);
			 disp(start3);
			 break;
		case 6:
			 disp(start3);
			 break;
		case 7:
			  printf("\n\n EXIT ");
			     getch();
			     exit(0);
		default:
			  printf("\n INVALID INPUT ");
	    }
	      getch();
       }while(ch != 7);
}

     void create(struct node *first)
     {
		int ch;

	   printf("\n\n Enter coeff : ");
	    scanf("%d" , &first->coeff);

	   printf("\n\n Enter power : ");
	    scanf("%d" , &first->power);

	   printf("\n\n Do you want to continue (1/0)? : ");
		scanf("%d",&ch);

	   if(ch == 1)
	   {
	      first->next = malloc(sizeof(struct node));
	       create(first->next);
	   }
	   if(ch == 0)
	   {
		first->next = NULL;
	   }
     }

     void disp(struct node *first)
     {
	if(first == NULL)
	{
	     printf("\n EMPTY");
	}
	else
	{
	       printf("\n\n");

	     while(first != NULL)
	     {
		 printf(" %dx^%d ", first->coeff, first->power);
		 printf("+");
		 first = first->next;
	     }

		   printf("\b ");
	}
     }


     void addpoly(struct node *f1 , struct node *f2 ,struct node *f3)
     {
	 if(f1->power == f2->power)
	 {
	    f3->coeff = f1->coeff + f2->coeff;
	    f3->power = f1->power;

	       f1 = f1->next;
	       f2 = f2->next;
	 }
	 else if(f1->power > f2->power)
	 {
	    f3->coeff = f1->coeff;
	    f3->power = f1->power;
	    f1 = f1->next;
	 }
	 else if(f2->power > f1->power)
	 {
	    f3->coeff = f2->coeff;
	    f3->power = f2->power;
	    f2 = f2->next;
	 }
	 if(f1 == NULL && f2 == NULL)
	 {
	       f3->next = NULL;
	       return;
	 }

	     f3->next = malloc(sizeof(struct node));
		addpoly(f1 , f2 , f3->next);
     }

