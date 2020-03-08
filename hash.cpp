#include<iostream>
using namespace std;
 
 
typedef struct ht
{
	int data, flag, chain;
}ht;

class hash
{
	ht h[100];
	public:
		void insert();
		hash();
		void display();
};

void hash :: display()
{
	int i;
	for(i = 0; i < 10; i++)
	{
		cout<<h[i].data<<"\t"<<h[i].chain<<endl;
	}
}

hash :: hash()
{
	for(int i = 0; i<10; i++)
	{
		h[i].flag = 0;
		h[i].chain = -1;
	}
}

void hash :: insert()
{
	int key, loc, i, j, n = 10;
	char ch;
	do
	{
		cout<<"\nEnter element to be inserted. ";
		cin>>key;
		loc = key % n;
		i = 0;
		j = loc;
		while(i < n && h[j].flag == 1)
		{
			if(h[loc].data % n == key % n)
				break;
			i++;
			j = (j + 1) % n;
		}
		if(i == n)
		{
			cout<<"\nTable is full.";
			return;
		}
		while(h[j].chain != -1)
		{
			j = h[j].chain;
			
		}
		loc = j;
		while(h[loc].flag && i < n)
		{
			loc = (loc + 1) % n;
			i++;
		}
		if(i == n)
		{
			cout<<"\nTable is full.";
			return;
		}
		h[loc].data = key;
		h[loc].flag = 1;
		if(j != loc)
			h[j].chain = loc;
		cout<<"\nDo you want to enter another element? ";
		cin>>ch;
	}while(ch == 'Y' || ch == 'y');
}

int main()
{
	hash obj;
	obj.insert();
	obj.display();
}
