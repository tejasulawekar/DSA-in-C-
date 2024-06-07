/*
      BREADTH FIRST SEARCH
*/

       #include<stdio.h>
       #include<conio.h>

     int n, adj[10][10]={0}, visited[10]={0};

	 void BFS(int);

     void main()
     {
	 int e, v1, v2, node, i;

	  clrscr();

	  printf("\n\n Enter no of nodes : ");
	    scanf("%d" , &n);

	  printf("\n\n Enter no of edges : ");
	    scanf("%d" , &e);

	  printf("\n\n Enter edges : \n");
	    for(i=0 ;i<e ; i++)
	    {
		   scanf("%d%d", &v1, &v2);

		adj[v1-1][v2-1] = adj[v2-1][v1-1] = 1;
	    }

	    printf("\n\n Enter starting node : ");
		 scanf("%d" , &node);

	       printf("\n\n BFS : ");
		    BFS(node-1);

	  getch();
     }

	void BFS(int node)
	{
	      int i, Q[10], f=-1, r=-1, nd;

		 Q[++r] = node;
		 visited[node] = 1;

		 while(f != r)
		 {
		      nd = Q[++f];
		      printf(" %d ",nd+1);

		      for(i=0 ; i<n ; i++)
		      {
			  if(adj[nd][i] == 1 && visited[i] == 0)
			  {
				Q[++r] = i;
				visited[i] = 1;
			  }
		      }
		 }
	}




