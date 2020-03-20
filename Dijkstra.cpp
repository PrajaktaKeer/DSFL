/*   BATCH : H10
 * ROLL NO : 23269
 * PROBLEM STATEMENT : Represent any real world graph using adjacency list /adjacency matrix  and find shortest path using Dijiktra's algorithm.*/

#include<iostream>
using namespace std;
#define inf 999999
class Graph
{
	int G[20][20];
	int cost[20][20];
	int n;
	public:
		Graph()
		{
			cout<<"\nEnter the no of vertices in graph : ";
			cin>>n;
		}
		void create();
		void display();
		void dijkstra();
};
void Graph::create()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			G[i][j]=0;
		}
	}
	while(1)
	{
		cout<<"\nEnter start vertex (-1 to stop): ";
		cin>>i;
		if(i==-1)
			break;
		cout<<"\nEnter end vertex: ";
		cin>>j;
		cout<<"\nEnter distance between the 2 vertices: ";
		cin>>G[i][j];
		G[j][i]=G[i][j];
		cost[i][j]=G[i][j];
		cost[j][i]=cost[i][j];
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(G[i][j]==0)
			cost[i][j]=inf;
		}
	}
}
void Graph::display()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		cout<<"\n";
		for(j=0;j<n;j++)
		{
			cout<<G[i][j]<<" ";
		}
	}
}
void Graph::dijkstra()
{
	int visit[10];
	int dist[10];
	int from[10];
	int source,i,j,ne,u,v,mindist,mincost=0;
	cout<<"\nEnter source: ";
	cin>>source;
	ne=n-1;
	visit[source]=1;
	for(i=0;i<n;i++)
	{
		if(i!=source)
		{
			from[i]=source;
			visit[i]=0;
			dist[i]=cost[source][i];
		}
	}
	while(ne>0)
	{
		mindist=inf;
		for(i=0;i<n;i++)
		{
			if(visit[i]==0 && dist[i]<mindist)
			{
				mindist=dist[i];
				v=i;
			}
		}
		visit[v]=1;
		u=from[v];
		for(i=0;i<n;i++)
		{
			if(visit[i]==0 && dist[i]> dist[v] + cost[v][i])
			{
				dist[i]=dist[v] + cost[v][i];
				from[i]=v;
			}
		}
		ne--;
	}
	cout<<"\nThe shortest path from source "<<source<<" to all other verices are: \n";
	for(i=0;i<n;i++)
	{
		j=i;
		while(j!=source)
		{
			cout<<j<<"->";
			mincost=mincost+cost[j][from[j]];
			j=from[j];
		}
		cout<<source<<" The cost from source to vertex  "<<i<<" is:  "<<mincost<<"\n";
		mincost=0;
	}
}
int main()
{
	Graph obj;
	obj.create();
	obj.display();
	obj.dijkstra();
	return 0;
}
