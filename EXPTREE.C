/*
     EXPRESSION TREE
*/

   #include<stdio.h>
   #include<conio.h>
   #include<string.h>
   #include<ctype.h>

   struct node
   {
	char ch;
	struct node *left;
	struct node *right;

   }*root = NULL;

   void INORDER(struct node *);
   void PREORDER(struct node *);
   void POSTORDER(struct node *);

   struct node *stk[30];
   int top=-1;

   void PUSH(struct node *n)
   {
	top++;
	stk[top] = n;
   }

   struct node* POP()
   {
       if(top != -1)
       {
	   return stk[top--];
       }
   }

   void main()
   {
      char post[30];
      int i;
      struct node *newnode;

       clrscr();

     printf("\n\n Enter postfix expression : ");
	     gets(post);

      for(i=0 ; i<strlen(post); i++)
      {
	   newnode = malloc(sizeof(struct node));

	     newnode->ch = post[i];
	     newnode->left = NULL;
	     newnode->right = NULL;

	    if( isalpha(post[i]) )
	    {
	       PUSH(newnode);
	    }
	    else
	    {
	       newnode->right = POP();
	       newnode->left = POP();

		 PUSH(newnode);
	    }
      }

	   root = POP();

	   printf("\n\n INORDER : ");
	     INORDER(root);

	   printf("\n\n PREORDER : ");
	     PREORDER(root);

	   printf("\n\n POSTORDER : ");
	     POSTORDER(root);

       getch();
   }


   void INORDER(struct node *root)
   {
	if(root != NULL)
	{
	   INORDER(root->left);
	   printf(" %c ", root->ch);
	   INORDER(root->right);
	}
   }

   void PREORDER(struct node *root)
   {
	if(root != NULL)
	{
	   printf(" %c ", root->ch);
	   PREORDER(root->left);
	   PREORDER(root->right);
	}
   }

   void POSTORDER(struct node *root)
   {
	if(root != NULL)
	{
	   POSTORDER(root->left);
	   POSTORDER(root->right);
	   printf(" %c ", root->ch);
	}
   }
