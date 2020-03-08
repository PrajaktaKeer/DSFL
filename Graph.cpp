#include "Graph.h"
#include<iostream>
#include<string.h>
#include<queue>
using namespace std;

vertex :: vertex()
{	
	visited = false;
	friends = 0;
}

graph :: graph()
{
	head = NULL;
}

void graph :: birthday()
{
	int cur_month, flag = 0;
	cout<<"\nEnter current month. ";
	cin>>cur_month;
	vertex *p = head;
	while(p != NULL)
	{
		if(p->b.month == cur_month)
		{
			cout<<p->name<<" has birthday in this month.";
			flag = 1;
		}
		p = p->down;
	}
	if(flag == 0 && p == NULL)
		cout<<"\nNobody has birthday in this month.";
}

void graph :: clear()
{
	vertex *p = head;
	while(p != NULL)
	{	
		p->visited = false;
		p = p->down;
	}
}

void graph :: BFS(vertex *p, int key, int ch)
{
	vertex *i;
	clear();
	node *edge;
	queue<vertex*> q;
	q.push(p);
	while(!q.empty()) 
	{
		p = q.front();
		q.pop();
		p->visited = true;
		if(p->comment == key) 
		{
			if(ch == 1)
				cout << "\n" << p->name << " has made maximum number of comments " << key << "." << endl;
			else if(ch == 0)
				cout << "\n" << p->name << " has made minimum number of comments " << key << "." << endl;
			break;
		}
		edge = p->next;
		while(edge != NULL) 
		{
			i = head;
			while(i != NULL)
			{
				if(strcmp(i->name, edge->name) == 0)
					break;
				i = i->down;
			}
			if(i->visited == false)
			{
				q.push(i);
				i->visited = true;
			}
			edge = edge->next;
		}
	}
}

void graph :: DFS(vertex *p, int max)
{
	p->visited = true;
	if(p->friends == max)
	{
		cout<<p->name<<" has maximum number of friends = "<<max<<endl;
		return;
	}
	if(p != NULL)
	{
		while(p->down->visited == false)
			DFS(p->down, max);
	}
	else
		return;
}

void graph :: comments()
{
	vertex *p = head;
	int max = p->comment, min = p->comment;
	while(p != NULL)
	{
		if(p->comment > max)
			max = p->comment;
		if(p->comment < min)
			min = p->comment;
		p = p->down;
	}
	BFS(head, min, 0);
	BFS(head, max, 1);
}

void graph :: max_friend()
{
	vertex *p = head;
	int max = p->friends;
	while(p != NULL)
	{
		if(p->friends > max)
			max = p->friends;
		p = p->down;
	}
	DFS(head, max);
}

void graph ::  create()
{
	char ch;
	vertex *temp = new vertex;
	if(head == NULL)
		head = temp;
	do
	{
		cout<<"\nEnter name. ";
		cin>>temp->name;
		cout<<"\nEnter date of birth(day, month, year).";
		cin>>temp->b.day>>temp->b.month>>temp->b.year;
		cout<<"\nEnter number of comments. ";
		cin>>temp->comment;
		temp->next = NULL;
		cout<<"Do you want to add another user? ";
		cin>>ch;
		if(ch == 'y' || ch == 'Y')
		{
			temp->down = new vertex;
			temp = temp->down;
		}
		else
			temp->down = NULL;
	}while(ch == 'y' || ch == 'Y');
}

void graph :: add_friends()
{
	int flag;
	char ch;
	vertex *p = head, *q;
	node *temp, *t;
	while(p != NULL)
	{
			flag = 0;
			cout<<"Does "<<p->name<<" have a friend(y / n)? ";
			cin>>ch;
			while(ch == 'y' || ch == 'Y')
			{
				q = head;
				if(p->next == NULL)
				{
					temp = new node;
					p->next = temp;
				}
				else
				{
					for(temp = p->next; temp->next != NULL; temp = temp->next);
					temp->next = new node;
					temp = temp->next;
				}

				cout<<"\nEnter friend's name. ";
				cin>>temp->name;
				p->friends++;
				temp->next = NULL;
				while(q != NULL)
				{
					if(strcmp(q->name, temp->name) == 0)
					{
						flag = 1;
						if(q->next == NULL)
						{
							q->next = new node;
							t = q->next;
						}
						else
						{
							for(t = q->next; t->next != NULL; t = t->next);
							t->next = new node;
							t = t->next;
						}
						strcpy(t->name, p->name);
						t->next = NULL;
						q->friends++;
					}
					q = q->down;
				}
				if(flag == 0)
			    {
					cout<<"\n"<<temp->name<<" is not a registered user.";
					continue;
				}
				cout<<"Does "<<p->name<<" have any other friend(y / n)? ";
				cin>>ch;
			}
			p = p->down;
	}
}

void graph :: display()
{
	vertex *p = head;
	node *q;
	while(p != NULL)
	{
		q = p->next;
		cout<<p->name<<" -> ";
		while(q != NULL)
		{
			cout<<q->name<<" ->";
			q = q->next;
		}
		cout<<endl;
		p = p->down;
	}
}

