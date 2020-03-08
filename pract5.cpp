/*BATCH : H10
 ROLL NO : 23269
 PROBLEM STATEMENT : Implement binary search tree and perform following
operations:
a. Insert
b. Delete
c. Search
d. Mirror image
e. Display
f. Display level wise   */

#include<iostream>
using namespace std;

class Tnode
{
	int data;
	Tnode *left, *right;
	public:
		Tnode(int x)
		{
			data = x;
			left = right = NULL;
		}
		friend class bst;
};

class queue
{
	int front, rear;
	Tnode* data[100];
	public:
		queue()
		{
			front = rear = -1;
		}
		void enqueue(Tnode* x)
		{
			if(rear == -1)
			{
				front = rear = 0;
				data[rear] = x;
			}
			else
			    data[++rear] = x;
		}
		Tnode* dequeue()
		{
			if(!empty())
				return data[front++];
			return NULL;
		}
		int empty()
		{
			if(front == rear + 1)
				return 1;
			return 0;
		}
};

class bst
{
	Tnode *root, *copy;
	public:
		bst()
		{
			root = NULL;
		}
		void insert(int);
		Tnode* remove(Tnode*, int);
		void delet(int);
		int search(int);
		Tnode* mirror_img(Tnode*);
		void mirror();
		void display();
		void print(Tnode*);
		void print_level(Tnode*);
		void display_level();
		Tnode* find_min(Tnode*);
};

Tnode* bst :: find_min(Tnode *t)
{
    while(t->left != NULL)
        t = t->left;
    return t;
}

void bst :: delet(int key)
{
     root = remove(root, key);
}

Tnode* bst :: remove(Tnode *root, int key)
{
     Tnode *p = root, *temp;
     if(p == NULL)
     {
         cout<<"\nElement not found.";
         return p;
     }
     if(key < p->data)
     {
        p->left = remove(p->left, key);
        return p;
     }
     if(key > p->data)
     {
        p->right = remove(p->right, key);
        return p;
     }
     if(p->right == NULL && p->left == NULL)
     {
         temp = p;
         delete temp;
         return NULL;
     }
     if(p->left == NULL)
     {
        temp = p;
        p = p->right;
        delete temp;
        return p;
     }
     if(p->right == NULL)
     {
        temp = p;
        p = p->left;
        delete temp;
        return p;
     }
     temp = find_min(p->right);
     p->data = temp->data;
     p->right = remove(p->right, temp->data);
     return p;
}

void bst :: display_level()
{
     cout<<"\nLevel order traversal of tree = ";
	print_level(root);
}

void bst :: print_level(Tnode *root)
{
	Tnode *p = root;
	queue q;
	q.enqueue(p);
	while(!q.empty())
	{
		p = q.dequeue();
		cout<<p->data<<" ";
		if(p->left != NULL)
            q.enqueue(p->left);
		if(p->right != NULL)
		    q.enqueue(p->right);
	}
}

void bst :: insert(int x)
{
	if(root == NULL)
		root = new Tnode(x);
	else
	{
		Tnode *p = root, *q = root;
		while(q != NULL && x != p->data)
		{
			p = q;
			if(x < p->data)
				q = p->left;
			else if(x > p->data)
				q = p->right;
		}
		if(x == p->data)
			cout<<"\nDuplication not allowed.";
		else if(x < p->data)
			p->left = new Tnode(x);
		else
			p->right = new Tnode(x);
	}
}

int bst :: search(int x)
{
	Tnode *p = root;
	while(p != NULL)
	{
		if(x == p->data)
			return 1;
		else if(x < p->data)
			p = p->left;
		else
			p = p->right;
	}
	return 0;
}

void bst :: display()
{
     cout<<"\nInorder traversal of tree = ";
	print(root);
}

void bst :: print(Tnode *p)
{
	if(p != NULL)
	{
		print(p->left);
		cout<<p->data<<" ";
		print(p->right);
	}
}

void bst :: mirror()
{
	copy = mirror_img(root);
	print(copy);
}

Tnode* bst :: mirror_img(Tnode *root)
{
	Tnode *p = root, *temp = NULL;
	if(p != NULL)
	{
		temp = new Tnode(p->data);
		temp->right = mirror_img(p->left);
		temp->left= mirror_img(p->right);
	}
	return temp;
}

int main()
{
	bst b;
	int choice, x;
	char ch;
	do
	{
		cout<<"\nMENU :\n1. Insert a node\n2. Delete a node\n3. Search a node\n4. Create a mirror image\n5. Display\n6. Display level wise\n7. Exit\nEnter your choice = ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				do
				{
					cout<<"\nEnter data to be inserted. ";
					cin>>x;
					b.insert(x);
					cout<<"\nDo you want to insert another node(y / n)? ";
					cin>>ch;
				}while(ch == 'y');
				cout<<"\nTREE IS CREATED SUCESSFULLY!!";
				break;
			case 2:
				cout<<"\nEnter data to be deleted. ";
				cin>>x;
				b.delet(x);
				cout<<"DATA "<<x<<" DELETED SUCCESSFULLY!!";
				break;
			case 3:
				cout<<"\nEnter data to be searched. ";
				cin>>x;
				if(b.search(x))
					cout<<"\nData "<<x<<" is found in tree";
				else
					cout<<"\nData not found.";
				break;
			case 4:
				cout<<"\nOriginal tree : ";
				b.display();
				cout<<"\nMirror image of tree : ";
				b.mirror();
				break;
			case 5:
				b.display();
				break;
			case 6:
				b.display_level();
				break;
			case 7:
				return 0;
			default:
				cout<<"\nEnter valid choice.";
		}
	}while(1);
};

/* OUTPUT : 

MENU :
1. Insert a node
2. Delete a node
3. Search a node
4. Create a mirror image
5. Display
6. Display level wise
7. Exit
Enter your choice = 1

Enter data to be inserted. 45

Do you want to insert another node(y / n)? y

Enter data to be inserted. 7

Do you want to insert another node(y / n)? y

Enter data to be inserted. 21

Do you want to insert another node(y / n)? y

Enter data to be inserted. 76

Do you want to insert another node(y / n)? y

Enter data to be inserted. 1

Do you want to insert another node(y / n)? y

Enter data to be inserted. 54

Do you want to insert another node(y / n)? y

Enter data to be inserted. 22

Do you want to insert another node(y / n)? y

Enter data to be inserted. 4

Do you want to insert another node(y / n)? y

Enter data to be inserted. 86

Do you want to insert another node(y / n)? n

MENU :
1. Insert a node
2. Delete a node
3. Search a node
4. Create a mirror image
5. Display
6. Display level wise
7. Exit
Enter your choice = 3

Enter data to be searched. 76

Data 76 is found in tree
MENU :
1. Insert a node
2. Delete a node
3. Search a node
4. Create a mirror image
5. Display
6. Display level wise
7. Exit
Enter your choice = 3

Enter data to be searched. 67

Data not found.
MENU :
1. Insert a node
2. Delete a node
3. Search a node
4. Create a mirror image
5. Display
6. Display level wise
7. Exit
Enter your choice = 4

Original tree : 1 4 7 21 22 45 54 76 86
Mirror image of tree : 86 76 54 45 22 21 7 4 1
MENU :
1. Insert a node
2. Delete a node
3. Search a node
4. Create a mirror image
5. Display
6. Display level wise
7. Exit
Enter your choice = 5
1 4 7 21 22 45 54 76 86
MENU :
1. Insert a node
2. Delete a node
3. Search a node
4. Create a mirror image
5. Display
6. Display level wise
7. Exit
Enter your choice = 6
45 7 76 1 21 54 86 4 22
MENU :
1. Insert a node
2. Delete a node
3. Search a node
4. Create a mirror image
5. Display
6. Display level wise
7. Exit
Enter your choice = 2

Enter data to be deleted. 76

MENU :
1. Insert a node
2. Delete a node
3. Search a node
4. Create a mirror image
5. Display
6. Display level wise
7. Exit
Enter your choice = 5
1 4 7 21 22 45 54 86
MENU :
1. Insert a node
2. Delete a node
3. Search a node
4. Create a mirror image
5. Display
6. Display level wise
7. Exit
Enter your choice = 2

Enter data to be deleted. 21

MENU :
1. Insert a node
2. Delete a node
3. Search a node
4. Create a mirror image
5. Display
6. Display level wise
7. Exit
Enter your choice = 5
1 4 7 22 45 54 86
MENU :
1. Insert a node
2. Delete a node
3. Search a node
4. Create a mirror image
5. Display
6. Display level wise
7. Exit
Enter your choice = 2

Enter data to be deleted. 4

MENU :
1. Insert a node
2. Delete a node
3. Search a node
4. Create a mirror image
5. Display
6. Display level wise
7. Exit
Enter your choice = 5
1 7 22 45 54 86  */

