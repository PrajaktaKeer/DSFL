/*   BATCH : H10
 * ROLL NO : 23269
 * PROBLEM STATEMENT : Represent any real world graph using adjacency list /adjacency matrix  and find shortest path using Dijiktra's algorithm.*/

#define MAX 100
#include <iostream>
#include<algorithm>
using namespace std;

class graph
{
	int adj_mat[MAX][MAX];
	bool selected[MAX][MAX];
public:
	void create(int);
	void display(int);
	void dijiktra(int);
};

void graph :: dijiktra(int vertices)
{
	int dist[vertices], i, j, result[vertices][vertices], min = INT32_MAX, sel_ver, k, x;
	bool visited[vertices];
	for(i = 0; i < vertices; i++)
	{
		//initialize distance and visited matrices
		cout<<"\nLIST "<<i+1<<endl;
		
		for(j = 0; j < vertices; j++)
		{
			dist[j] = adj_mat[i][j];
			if(adj_mat[i][j] == 0)
				visited[j] = true;
			else
				visited[j] = false;
		}
		
		cout<<"\nINITIALLY\nDistance\t";
		for(x = 0; x < vertices; x++)
			cout<<dist[x]<<"\t";
		cout<<"\nVisited\t\t";
		for(x = 0; x < vertices; x++)
			cout<<visited[x]<<"\t";
		cout<<endl;
		
		for(j = 0; j < vertices - 1; j++)
		{
			cout<<"\n--------------------ITERATINO "<<j+1<<" -------------\n";
			min = INT32_MAX;
			//loop to find min value
			for(k = 0; k < vertices; k++)
			{
				if(dist[k] < min && dist[k] != 0 && visited[k] == false)
				{
					min = dist[k];
					sel_ver = k;
				}
			}
			cout<<"\nMIN VALUE = "<<min<<endl;
			visited[sel_ver] = true;
			//loop to update distance matrix
			for(k = 0; k < vertices; k++)
			{
				if(dist[k] != 0 && visited[k] == false && adj_mat[sel_ver][k] != INT32_MAX)
					dist[k] = std :: min(dist[k], adj_mat[sel_ver][k] + min);
			}
			
			cout<<"\nDistance\t";
			for(x = 0; x < vertices; x++)
				cout<<dist[x]<<"\t";
			cout<<"\nVisited\t\t";
			for(x = 0; x < vertices; x++)
				cout<<visited[x]<<"\t";
			cout<<endl;
			
		}
		for(k = 0 ; k < vertices; k++)
			result[i][k] = result[k][i] = dist[k];
	}
	cout<<"\nThe shortest path matrix is\n";
	for(i = 0; i < vertices; i++)
	{
		for(j = 0; j < vertices; j++)
			cout<<result[i][j]<<"\t";
		cout<<endl;
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
				if(adj_mat[i][j] == 0)
					adj_mat[i][j] = INT32_MAX; 
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

int main()
{
	int choice, vertices;
	graph g;
	do
	{
		cout << "\nMENU :\n1. Create a graph\n2. Display the graph\n3. Find shotest path\n4. Exit\nEnter your choice : ";
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
				g.dijiktra(vertices);
				break;
			case 4:
				return 0;
		}
	}while(1);
	return 0;
}

/*OUTPUT :
MENU :
1. Create a graph
2. Display the graph
3. Find shotest path
4. Exit
Enter your choice : 1

Enter number of vertices. 5

Enter the weight of edge (1, 2). 10

Enter the weight of edge (1, 3). 0

Enter the weight of edge (1, 4). 30

Enter the weight of edge (1, 5). 100

Enter the weight of edge (2, 3). 50

Enter the weight of edge (2, 4). 0

Enter the weight of edge (2, 5). 0

Enter the weight of edge (3, 4). 20

Enter the weight of edge (3, 5). 10

Enter the weight of edge (4, 5). 60

MENU :
1. Create a graph
2. Display the graph
3. Find shotest path
4. Exit
Enter your choice : 3

LIST 1

INITIALLY
Distance	0	10	2147483647	30	100	
Visited		1	0	0	0	0	

--------------------ITERATINO 1 -------------

MIN VALUE = 10

Distance	0	10	60	30	100	
Visited		1	1	0	0	0	

--------------------ITERATINO 2 -------------

MIN VALUE = 30

Distance	0	10	50	30	90	
Visited		1	1	0	1	0	

--------------------ITERATINO 3 -------------

MIN VALUE = 50

Distance	0	10	50	30	60	
Visited		1	1	1	1	0	

--------------------ITERATINO 4 -------------

MIN VALUE = 60

Distance	0	10	50	30	60	
Visited		1	1	1	1	1	

LIST 2

INITIALLY
Distance	10	0	50	2147483647	2147483647	
Visited		0	1	0	0	0	

--------------------ITERATINO 1 -------------

MIN VALUE = 10

Distance	10	0	50	40	110	
Visited		1	1	0	0	0	

--------------------ITERATINO 2 -------------

MIN VALUE = 40

Distance	10	0	50	40	100	
Visited		1	1	0	1	0	

--------------------ITERATINO 3 -------------

MIN VALUE = 50

Distance	10	0	50	40	60	
Visited		1	1	1	1	0	

--------------------ITERATINO 4 -------------

MIN VALUE = 60

Distance	10	0	50	40	60	
Visited		1	1	1	1	1	

LIST 3

INITIALLY
Distance	2147483647	50	0	20	10	
Visited		0	0	1	0	0	

--------------------ITERATINO 1 -------------

MIN VALUE = 10

Distance	110	50	0	20	10	
Visited		0	0	1	0	1	

--------------------ITERATINO 2 -------------

MIN VALUE = 20

Distance	50	50	0	20	10	
Visited		0	0	1	1	1	

--------------------ITERATINO 3 -------------

MIN VALUE = 50

Distance	50	50	0	20	10	
Visited		1	0	1	1	1	

--------------------ITERATINO 4 -------------

MIN VALUE = 50

Distance	50	50	0	20	10	
Visited		1	1	1	1	1	

LIST 4

INITIALLY
Distance	30	2147483647	20	0	60	
Visited		0	0	0	1	0	

--------------------ITERATINO 1 -------------

MIN VALUE = 20

Distance	30	70	20	0	30	
Visited		0	0	1	1	0	

--------------------ITERATINO 2 -------------

MIN VALUE = 30

Distance	30	40	20	0	30	
Visited		1	0	1	1	0	

--------------------ITERATINO 3 -------------

MIN VALUE = 30

Distance	30	40	20	0	30	
Visited		1	0	1	1	1	

--------------------ITERATINO 4 -------------

MIN VALUE = 40

Distance	30	40	20	0	30	
Visited		1	1	1	1	1	

LIST 5

INITIALLY
Distance	100	2147483647	10	60	0	
Visited		0	0	0	0	1	

--------------------ITERATINO 1 -------------

MIN VALUE = 10

Distance	100	60	10	30	0	
Visited		0	0	1	0	1	

--------------------ITERATINO 2 -------------

MIN VALUE = 30

Distance	60	60	10	30	0	
Visited		0	0	1	1	1	

--------------------ITERATINO 3 -------------

MIN VALUE = 60

Distance	60	60	10	30	0	
Visited		1	0	1	1	1	

--------------------ITERATINO 4 -------------

MIN VALUE = 60

Distance	60	60	10	30	0	
Visited		1	1	1	1	1	

The shortest path matrix is
0	10	50	30	60	
10	0	50	40	60	
50	50	0	20	10	
30	40	20	0	30	
60	60	10	30	0	*/
