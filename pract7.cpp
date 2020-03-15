/*   BATCH : H10
 * ROLL NO : 23269
 * PROBLEM STATEMENT : Represent any real world graph using adjacency list /adjacency matrix find minimum
spanning tree using Kruskal‘s algorithm.   */

#define MAX 100
#include <iostream>
using namespace std;

class graph
{
	int adj_mat[MAX][MAX], spanning_mat[MAX][MAX], cost, edge_count;
	bool selected[MAX][MAX];
	typedef struct edge
	{
		int source, dest, weight;
	}edge;
	typedef struct subset
	{
		int parent, rank;
	}subset;
	edge s[MAX], temp;
	subset sub[MAX];
public:
	void create(int);
	void display(int);
	int convert_sparse(int);
	void kruskal(int);
	int find(int);
	void unio(int, int);
};

int graph :: find(int key)
{
	if (sub[key].parent != key) 
		sub[key].parent = find(sub[key].parent); 
	return sub[key].parent;
}

void graph :: unio(int x, int y)
{
	int xroot = find(x); 
	int yroot = find(y); 

	if (sub[xroot].rank < sub[yroot].rank) 
		sub[xroot].parent = yroot; 
	else if (sub[xroot].rank > sub[yroot].rank) 
		sub[yroot].parent = xroot; 
	else
	{ 
		sub[yroot].parent = xroot; 
		sub[xroot].rank++; 
	}
}

void graph :: create(int vertices)
{
	int i, j;
	for(i = 0; i < vertices; i++)
	{
		for(j = 0; j < vertices; j++)
		{
			if(i != j && selected[j][i] == false)
			{
				cout << "\nEnter the weight of edge ("<<i+1<<", "<<j+1<<"). ";
				cin>>adj_mat[i][j];
				selected[i][j] = true;
			}
			if(i == j)
				adj_mat[i][j] = 0;
			if(selected[j][i] == true)
				adj_mat[i][j] = adj_mat[j][i];
		}
	}
}

void graph :: display(int vertices)
{
	int i, j;
	for(i = 0; i < vertices; i++)
	{
		for(j = 0; j < vertices; j++)
			cout <<adj_mat[i][j] << " ";
		cout<<endl;
	}
}

int graph :: convert_sparse(int vertices)
{
	int i, j, k = 0;
	//convert to sparse matrix form
	for(i = 0; i < vertices; i++)
	{
		for(j = i + 1; j < vertices; j++)
		{
			if(adj_mat[i][j] != 0)
			{
				s[k].source = i + 1;
				s[k].dest = j + 1;
				s[k].weight = adj_mat[i][j];
				k++;
			}
		}
	}
	//sort the sparse matrix
	for(i = 0; i < k - 1; i++)
	{
		for(j = 0; j < k - i - 1; j++)
		{
			if(s[j].weight > s[j+1].weight)
			{
				temp.source = s[j].source;
				temp.dest = s[j].dest;
				temp.weight = s[j].weight;
				s[j].source = s[j+1].source;
				s[j].dest = s[j+1].dest;
				s[j].weight = s[j+1].weight;
				s[j+1].source = temp.source;
				s[j+1].dest = temp.dest;
				s[j+1].weight = temp.weight;
			}
		}
	}
	for(i = 0; i < k; i++)
		cout<<s[i].source <<"\t"<<s[i].dest<<"\t"<<s[i].weight<<endl;
	return k;
}

void graph :: kruskal(int vertices)
{
	int k = convert_sparse(vertices), i, j;
	cost = 0, edge_count = 0;
	for (int v = 0; v < vertices; ++v) 
	{ 
		sub[v].parent = v; 
		sub[v].rank = 0; 
	}
	//spanning tree must contain (vertices - 1) edges
	for(i = 0; i < k && edge_count < vertices - 1; i++)
	{
		int x = find(s[i].source); 
		int y = find(s[i].dest); 
		if (x != y) 
		{ 
			spanning_mat[s[i].source - 1][s[i].dest - 1] = s[i].weight;
			spanning_mat[s[i].dest - 1][s[i].source - 1] = s[i].weight; 
			edge_count++;
			cost += s[i].weight;
			unio(x, y); 
		} 
	}
	cout<<"\nThe minimum spanning tree is\n";
	for(i = 0; i < vertices; i++)
	{
		for(j = 0; j < vertices; j++)
			cout <<spanning_mat[i][j] << " ";
		cout<<endl;
	}
	cout<<"\nCost of spanning tree = "<<cost;
}

int main()
{
	int choice, vertices;
	graph g;
	do
	{
		cout << "\nMENU :\n1. Create a graph\n2. Display the graph\n3. Find minimum spanning tree\n4. Exit\nEnter your choice : ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				cout << "\nEnter number of vertices. ";
				cin >> vertices;
				g.create(vertices);
				break;
			case 2:
				cout<<"\nThe adjacency matrix of graph is :\n";
				g.display(vertices);
				break;
			case 3:
				g.kruskal(vertices);
				break;
			case 4:
				return 0;
		}
	}while(1);
	return 0;
}

/*OUTPUT:
MENU :
1. Create a graph
2. Display the graph
3. Find minimum spanning tree
4. Exit
Enter your choice : 1

Enter number of vertices. 7

Enter the weight of edge (1, 2). 1

Enter the weight of edge (1, 3). 0

Enter the weight of edge (1, 4). 4

Enter the weight of edge (1, 5). 0

Enter the weight of edge (1, 6). 0

Enter the weight of edge (1, 7). 0

Enter the weight of edge (2, 3). 2

Enter the weight of edge (2, 4). 0

Enter the weight of edge (2, 5). 7

Enter the weight of edge (2, 6). 0

Enter the weight of edge (2, 7). 0

Enter the weight of edge (3, 4). 0

Enter the weight of edge (3, 5). 5

Enter the weight of edge (3, 6). 8

Enter the weight of edge (3, 7). 0

Enter the weight of edge (4, 5). 3

Enter the weight of edge (4, 6). 0

Enter the weight of edge (4, 7). 4

Enter the weight of edge (5, 6). 8

Enter the weight of edge (5, 7). 0

Enter the weight of edge (6, 7). 3

MENU :
1. Create a graph
2. Display the graph
3. Find minimum spanning tree
4. Exit
Enter your choice : 3
1	2	1
2	3	2
4	5	3
6	7	3
1	4	4
4	7	4
3	5	5
2	5	7
3	6	8
5	6	8

The minimum spanning tree is
0 1 0 4 0 0 0 
1 0 2 0 0 0 0 
0 2 0 0 0 0 0 
4 0 0 0 3 0 4 
0 0 0 3 0 0 0 
0 0 0 0 0 0 3 
0 0 0 4 0 3 0 

Cost of spanning tree = 17  */
