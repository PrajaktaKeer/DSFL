#ifndef GRAPH_H_
#define GRAPH_H_

class node
{
	char name[30];
	node *next;
public:
	friend class graph;
	friend class vertex;
};

class vertex
{
	typedef struct DOB
	{
		int day, month, year;
	}DOB;
	DOB b;
	int comment, friends;
	char name[30];
	bool visited;
	vertex *down;
	node *next;
	public :
		friend class graph;
		vertex();
};

class graph
{
	vertex *head;
	public:
		graph();
		void display();
		void max_friend();
		void create();
		void add_friends();
		void comments();
		void birthday();
		void clear();
		void DFS(vertex*, int);
		void BFS(vertex*, int, int);
		friend class facebook;
};

#endif /* GRAPH_H_ */
