/*
     DEPTH FIRST SEARCH
*/

       #include<stdio.h>
       #include<conio.h>

       int n, adj[10][10]={0} , visited[10]={0};

	 void DFS(int);

     void main()
     {
	 int e, v1, v2, node, i;

	  clrscr();

	  printf("\n\n Enter no of nodes : ");
	    scanf("%d" , &n);

	  printf("\n\n Enter no of edges : ");
	    scanf("%d" , &e);

	  printf("\n\n Enter edges : \n");
	    for(i=1 ; i<=e ; i++)
	    {
		scanf("%d%d", &v1, &v2);

		adj[v1-1][v2-1] = adj[v2-1][v1-1] = 1;
	    }

	  printf("\n\n Enter starting node : ");
		 scanf("%d" , &node);

		  printf("\n\n DFS : ");
		    DFS(node-1);

	  getch();
     }


	 void DFS(int node)
	 {
		  int i;

		 printf(" %d ", node+1);
		  visited[node] = 1;

	       for(i=0 ; i<n ; i++)
	       {
		  if(adj[node][i] == 1 && visited[i] == 0)
		  {
		       DFS(i);
		  }
	       }
	 }






