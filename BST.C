/*
      BINARY SEARCH TREE
*/

   #include<stdio.h>
   #include<conio.h>

   struct node
   {
       int num;
       struct node *left;
       struct node *right;
   };

       struct node* INSERT(struct node* , int);

       void INORDER(struct node *);
       void PREORDER(struct node *);
       void POSTORDER(struct node *);

       void COUNT_ALL(struct node *);
       void COUNT_LEAF(struct node *);
       void COUNT_BRANCH(struct node *);

       struct node* FIND_MIN(struct node *);
       struct node* FIND_MAX(struct node *);

       struct node* DELETE(struct node* , int);

   int menu()
   {
	 int choice;

	 clrscr();

       printf("\n\n 1] INSERT A NODE ");
       printf("\n 2] INORDER TRAVERSAL ");
       printf("\n 3] PREORDER TRAVERSAL ");
       printf("\n 4] POSTORDER TRAVERSAL ");
       printf("\n 5] COUNT_ALL NODES ");
       printf("\n 6] COUNT_LEAF NODES ");
       printf("\n 7] COUNT_BRANCH NODES ");
       printf("\n 8] FIND_MIN ");
       printf("\n 9] FIND_MAX ");
       printf("\n 10] DELETE A NODE ");
       printf("\n 11] EXIT ");

       printf("\n\n Enter your choice : ");
	   scanf("%d" , &choice);

	   return choice;
   }

   int count=0;

   void main()
   {
      int ch, n;
      struct node *root = NULL, *temp;

       clrscr();

      do
      {
	  ch = menu();

	  switch(ch)
	  {
	      case 1:
		      printf("\n\n Enter a num : ");
			scanf("%d" , &n);

		      root = INSERT(root , n);
			break;
	     case 2:
		     printf("\n\n INORDER : ");
			INORDER(root);
			 break;
	     case 3:
		     printf("\n\n PREORDER : ");
			PREORDER(root);
			 break;
	     case 4:
		     printf("\n\n POSTORDER : ");
			POSTORDER(root);
			 break;
	     case 5:
			 count=0;
			COUNT_ALL(root);
			printf("\n\n count = %d ", count);
			 break;
	     case 6:
			 count=0;
			COUNT_LEAF(root);
			printf("\n\n count = %d ", count);
			 break;
	     case 7:
			 count=0;
			COUNT_BRANCH(root);
			printf("\n\n count = %d ", count);
			 break;
	     case 8:
		       temp = FIND_MIN(root);
		       printf("\n\n MIN = %d ", temp->num);
			  break;
	     case 9:
		       temp = FIND_MAX(root);
		       printf("\n\n MAX = %d ", temp->num);
			  break;
	      case 10:
		      printf("\n\n Enter a num to be deleted : ");
			scanf("%d" , &n);

		      root = DELETE(root , n);
			break;
	     case 11:
		    printf("\n\n EXIT ");
		      getch();
		      exit(0);
	     default:
		    printf("\n\n INVALID INPUT ");
	  }
	      getch();
      }while(ch != 11);
   }

     struct node* INSERT(struct node *root , int n)
     {
	  struct node *newnode;

	  if(root == NULL)
	  {
	      newnode = malloc(sizeof(struct node));
		newnode->num = n;
		newnode->left = NULL;
		newnode->right = NULL;
		root = newnode;
	  }
	  else if(n <= root->num)
	  {
	     root->left = INSERT(root->left , n);
	  }
	  else
	  {
	     root->right = INSERT(root->right , n);
	  }

	      return root;
     }

     void INORDER(struct node *root)
     {
	 if(root != NULL)
	 {
	     INORDER(root->left);
	     printf(" %d ", root->num);
	     INORDER(root->right);
	 }
     }

     void PREORDER(struct node *root)
     {
	 if(root != NULL)
	 {
	     printf(" %d ", root->num);
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
	     printf(" %d ", root->num);
	 }
     }


     void COUNT_ALL(struct node *root)
     {
	 if(root != NULL)
	 {
		count++;

	     COUNT_ALL(root->left);
	     COUNT_ALL(root->right);
	 }
     }

     void COUNT_LEAF(struct node *root)
     {
	 if(root != NULL)
	 {
	    if(root->left == NULL && root->right == NULL)
	    {
		count++;
	    }

	     COUNT_LEAF(root->left);
	     COUNT_LEAF(root->right);
	 }
     }

     void COUNT_BRANCH(struct node *root)
     {
	 if(root != NULL)
	 {
	    if(root->left != NULL || root->right != NULL)
	    {
		count++;
	    }

	     COUNT_BRANCH(root->left);
	     COUNT_BRANCH(root->right);
	 }
     }

       struct node* FIND_MIN(struct node *root)
       {
	    if(root->left == NULL)
	    {
		return root;
	    }
	    else
	    {
		FIND_MIN(root->left);
	    }
       }

       struct node* FIND_MAX(struct node *root)
       {
	    if(root->right == NULL)
	    {
		return root;
	    }
	    else
	    {
		FIND_MAX(root->right);
	    }
       }

       struct node* DELETE(struct node *root , int n)
       {
	     struct node *temp;

	     if(root == NULL)
	     {
		 printf("\n\n NUM NOT FOUND ");
	     }
	     else if(n < root->num)
	     {
		root->left = DELETE(root->left , n);
	     }
	     else if(n > root->num)
	     {
		root->right = DELETE(root->right , n);
	     }
	     else
	     {
		   if(root->left == NULL)
		   {
		       temp = root->right;
			 free(root);
			 root = temp;
		   }
		   else if(root->right == NULL)
		   {
		       temp = root->left;
			 free(root);
			 root = temp;
		   }
		   else
		   {
			temp = FIND_MAX(root->left);
			root->num = temp->num;
			root->left = DELETE(root->left , temp->num);
		   }
	     }

		 return root;
       }

