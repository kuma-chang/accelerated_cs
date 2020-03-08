
// YOUR NAME:
// Michael Chang

// Kruskal's Algorithm Lab

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
         // for qsort
#include <unistd.h>
         // for usleep




#define INF  1000000
   // infinity

// The adjacency matrix for the graph :
int N ; // number of nodes (vertices)
int A[100][100] ; // adjacency matrix of the graph


int input_graph()
{
  int r,c ;
  char w[10] ;

  scanf("%d",&N) ;
  
  // scan the first row of labels....not used
  for (c = 0 ; c < N ; c++) {
    scanf("%s",w) ;
  }
  

  for (r = 0 ; r < N ; r++) {
    scanf("%s",w) ; // label ... not used
    for (c = 0 ; c < N ; c++) {
      scanf("%s",w) ;
      if (w[0] == '-') {
	A[r][c] = -1 ;
      } else {
	A[r][c] = atoi(w) ;// ascii to integer
      }
      
    }
  }
  
}




int print_graph()
{
  int r,c ;

  printf("\n%d\n\n",N) ;
  
  printf("  ") ;
  for (c = 0 ; c < N ; c++) {
    printf("   %c",c+'A') ;
  }
 
  printf("\n") ;  
  
  for (r = 0 ; r < N ; r++) {
    printf("%c  ",r+'A') ;
    for (c = 0 ; c < N ; c++) {
      if (A[r][c] == -1) {
	printf("  - ") ;
      } else {
	printf("%3d ",A[r][c]) ;
      }
    }
    printf("\n") ;
  }
  printf("\n") ;  
}






typedef
struct {
  int vstart ;
  int vend ;
  int vlen ;
}
Edge ;

Edge elist[100] ;

int compare (const void *p1,  const void *p2)
{
  Edge *a, *b ;
  a = (Edge *) p1 ;
  b = (Edge *) p2 ;
  if ((*a).vlen < (*b).vlen) {
    return -1 ;
  } else if ((*a).vlen > (*b).vlen) {
    return 1 ;
  } else {
    return 0 ;
  }
}



int  print_edge_list(Edge *elist, int N)
{
  int i ;
  printf("\n") ;  
  for (i = 0 ; i < N ; i++) {
    printf("<%c, %c, %d> ",
	   'A'+elist[i].vstart, 'A'+elist[i].vend,elist[i].vlen) ;
  }
  printf("\n") ;
}


int print_array(int *x, int n)
{
  int i ;
  for (i = 0 ; i < n ; i++) {
    printf(" %3d",x[i]) ;
  }  
}

// Use merge sort for sorint the edge list
void merge(Edge arr[], int left, int middle, int right)
{
	int n1 = middle - left + 1;
	int n2 = right - middle;
	Edge L[n1], R[n2];
	
	int i = 0;
	int j = 0;//for the while loop to merge
	int k = left;//counter for the merged array


	//copying the two temp array prepare to be merge
	for(int i = 0; i < n1; i++)
		L[i] = arr[left + i];
	for(int j = 0; j < n2; j++)
		R[j] = arr[middle + 1 + j];

	while(i < n1 && j < n2)
	{
		if (L[i].vlen <= R[j].vlen)
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}
 
void merge_sort(Edge arr[], int left, int right)
{
	if (left < right)
	{
		int middle = left + (right - left)/2;

		merge_sort(arr, left, middle);
		merge_sort(arr, middle + 1, right);

		merge(arr, left, middle, right);
	}
}



int kruskal()
{
  // a tree has the property that |E| = |V| - 1
  
  // 1 .make a list of all edges
  // 2. sort this list (FOR FULL CREDIT use a time 
  //    complexity n*log(n) sorting algorithm discussed in class)
  // 3. starting with the shortest edge in the sorted list and
  // continuing until you have N -1 edges (or realize that you can't)
  // adjoin this edge to your potential tree list unless it would
  // create a cyle.

  // assume an undirected graph, hence only need the upper right
  // part of the adjacency matrix :

  // code below creates and then prints array of edges
  
  int e,r,c ;
	
  
  e = 0 ; // number of edges
  for (r = 0 ; r < N ; r++) {
    for (c = r+1 ; c < N ; c++) {
      if (A[r][c] != -1) {
	elist[e].vstart = r ; // start vertex of edge
	elist[e].vend = c ; // end vertex of edge
	elist[e].vlen = A[r][c] ;
	e++ ;
      }
    }
  }
  
  if (e < N-1) {
    printf("there aren't enough edges to build a spanning tree\n") ;
    return 0 ;
  }
  
  print_edge_list(elist, e) ;
  
  //  YOUR CODE GOES BELOW! 
  //  Note:  this function should call print_edge_list() at the 
  //         end to give the edges in a minimum spanning tree

	// use merge_sort to sort the edge list by the weight of each edge
	merge_sort(elist, 0, e-1);
	printf("\n\n[Edge list after sorted with merge sort]\n");
  print_edge_list(elist, e) ;
	
	Edge mst[100];
	int mst_e = 0;
	int e_count = 0;
	int cycle_check[r];
	int cycle_count = 0;
	int start, end, check_buffer;

	// initializing the cycle check table all to 0
	for(int i = 0; i < r; i++)
		cycle_check[i] = cycle_count;

	while(mst_e < r-1)
	{
		start = elist[e_count].vstart;
		end = elist[e_count].vend;
		if(cycle_check[start] == 0 || cycle_check[end] == 0)
		{
			if(cycle_check[start] != cycle_check[end])
			{
				if(cycle_check[start] < cycle_check[end])
					cycle_check[start] = cycle_check[end]; 
				else
					cycle_check[end] = cycle_check[start]; 
			}
			else
			{
				cycle_count++;
				cycle_check[start] = cycle_count; 
				cycle_check[end] = cycle_count; 
			}
			mst[mst_e] = elist[e_count];
			mst_e++;
		}
		else if(cycle_check[start] != cycle_check[end])
		{
			if(cycle_check[start] < cycle_check[end])
			{
				check_buffer = cycle_check[end];
				for(int i = 0; i < r; i++)
					if(cycle_check[i] == check_buffer)
						cycle_check[i] = cycle_check[start];
			}
			else
			{
				check_buffer = cycle_check[start];
				for(int i = 0; i < r; i++)
					if(cycle_check[i] == check_buffer)
						cycle_check[i] = cycle_check[end];
			}
			mst[mst_e] = elist[e_count];
			mst_e++;
		}

		e_count++;

		/* prints the cycle check tabe with each new edge for checking
		printf("cycle count: %d\n", cycle_count);
		printf("e_count %d :", e_count);
		for(int i = 0; i < r; i++)
			printf("%d ", cycle_check[i]);
		printf("\n");
		*/
	}

	printf("\n\n[The edge list for minimum spanning tree]\n");
  print_edge_list(mst, mst_e) ;

}



int main()
{
  // Before modifying this skeleton, try compiling and then
  // try running with ./a.out < graph08.input
  input_graph() ;// N, A{}{}  
  print_graph() ;
  kruskal() ;
}

