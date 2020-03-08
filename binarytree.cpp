/* BATCH : H10
  ROLL NO : 23269
 PROBLEM STATEMENT : Create binary tree and perform following operations:
 	 	 	 	 	 1. Insert	2. Display 	3. Depth of tree
 	 	 	 	 	 4. Display leaf nodes	5. Create a copy of tree  */

#include<iostream>
using namespace std;

class Tnode
{
	int data;
	Tnode *right, *left;
	public:
		friend class btree;
};

class btree
{
	Tnode *root, *cpy;
	public:
		Tnode* create_rec();
		void create_nrec();
		void insert();
		void display(Tnode*);
		void print();
		int find_depth();
		int depth(Tnode*);
		void print_leaf(Tnode*);
		void display_leaf();
		Tnode* copy(Tnode*);
		void replicate();
};

class queue
{
	int front,rear;
	Tnode *data[100];
	public:
		queue()
		{
			front  = rear = -1;
		}
		int isempty()
		{
            if(front == rear + 1)
                     return 1;
            return 0;
        }
		void enqueue(Tnode *T)
		{
             if(front == -1)
		        front = 0;
             data[++rear] = T;
        }
		Tnode *dequeue()
		{
            if(!isempty())
                return data[front++];
            return NULL; 
        }
};

void btree :: insert()
{
     //root = create_rec();
     create_nrec();
}

Tnode* btree :: create_rec()
{
	Tnode *temp = new Tnode;
	cout<<"\nEnter data(-1 for no data). ";
	cin>>temp->data;
	if(temp->data != -1)
	{
		cout<<"\nEnter left child of "<<temp->data<<". ";
		temp->left = create_rec();
		cout<<"\nEnter right child of "<<temp->data<<". ";
		temp->right = create_rec();
		return temp;
	}
	else
		return NULL;
}

void btree :: create_nrec()
{
	Tnode *p;
	root = new Tnode;
	int x;
	queue q;
	cout<<"\nEnter data: ";
	cin>>root->data;
	root->left = root->right = NULL;
	if(root->data == -1)
		return;
	q.enqueue(root);
	while(!q.isempty())
	{
		p = q.dequeue();
		cout<<"\nEnter left of "<<p->data<<": ";
		cin>>x;
		if(x != -1)
		{
			p->left = new Tnode;
			p->left->data = x;
			p->left->left = p->left->right = NULL;
			q.enqueue(p->left);
		}
		cout<<"\nEnter right of "<<p->data<<": ";
		cin>>x;
		if(x != -1)
		{
			p->right = new Tnode;
			p->right->data = x;
			p->right->left = p->right->right = NULL;
			q.enqueue(p->right);
		}
	}
}

void btree :: print()
{
     display(root);
}

void btree :: display(Tnode *root)
{
	Tnode *p = root;
	if(p != NULL)
	{
		display(p->left);
		cout<<p->data<<" ";
		display(p->right);
	}
}

int btree :: find_depth()
{
    return depth(root);
}

int btree :: depth(Tnode *root)
{
	Tnode *p = root;
	int htl = 0, htr = 0;
	if(p == NULL)
		return 0;
	else
	{
		htl = depth(root->left) + 1;
		htr = depth(root->right) + 1;
	}
	if(htl > htr)
		return htl;
	else
		return htr;
}

void btree :: display_leaf()
{
     print_leaf(root);
}

void btree :: print_leaf(Tnode *root)
{
	Tnode *p = root;
	if(p != NULL)
	{
		if(p->left == NULL && p->right == NULL)
			cout<<p->data<<" ";
		print_leaf(p->left);
		print_leaf(p->right);
	}
}

void btree :: replicate()
{
     cpy = copy(root);
     display(cpy);
}

Tnode* btree :: copy(Tnode *root)
{
	Tnode *temp = NULL, *p = root;
	if(p != NULL)
	{
		temp = new Tnode;
		temp->data = p->data;
		temp->left = copy(p->left);
		temp->right = copy(p->right);
	}
	return temp;
}

int main()
{
	int choice, ch;
	btree b;
	do
	{
		cout<<"\nMENU :\n1. Create tree\n2. Display tree\n3. Find depth of tree\n4. Display leaf nodes\n5. Create copy of tree\n6. Exit\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				b.insert();
				break;
			case 2:
				cout<<"\nInorder form = ";
				b.print();
				break;
			case 3:
				cout<<"\nThe depth of tree = "<<b.find_depth();
				break;
			case 4:
				cout<<"\nThe leaf nodes are = ";
				b.display_leaf();
				break;
			case 5:
				cout<<"\nOriginal tree = ";
				b.print();
				cout<<"\nCopy of original tree = ";
				b.replicate();
				break;
			case 6:
				return 0;
			default:
				cout<<"\nEnter valid choice.";
		}
	}while(1);
}

/* OUTPUT:

MENU :
1. Create tree
2. Display tree
3. Find depth of tree
4. Display leaf nodes
5. Create copy of tree
6. Exit
1

Enter data(-1 for no data). 1

Enter left child of 1.Enter data(-1 for no data). 2
Enter left child of 2.Enter data(-1 for no data). 4
Enter left child of 4.Enter data(-1 for no data). 8
Enter left child of 8.Enter data(-1 for no data). -1
Enter right child of 8.Enter data(-1 for no data). -1
Enter right child of 4.Enter data(-1 for no data). 9
Enter left child of 9.Enter data(-1 for no data). -1
Enter right child of 9.Enter data(-1 for no data). -1

Enter right child of 2.Enter data(-1 for no data). 5

Enter left child of 5.Enter data(-1 for no data). -1

Enter right child of 5.Enter data(-1 for no data). 10

Enter left child of 10.Enter data(-1 for no data). -1

Enter right child of 10.Enter data(-1 for no data). -1

Enter right child of 1.Enter data(-1 for no data). 3

Enter left child of 3.Enter data(-1 for no data). 6

Enter left child of 6.Enter data(-1 for no data). -1

Enter right child of 6.Enter data(-1 for no data). 7

Enter left child of 7.Enter data(-1 for no data). -1

Enter right child of 7.Enter data(-1 for no data). -1

Enter right child of 3.Enter data(-1 for no data). -1

MENU :
1. Create tree
2. Display tree
3. Find depth of tree
4. Display leaf nodes
5. Create copy of tree
6. Exit
2

Inorder form = 8 4 9 2 5 10 1 6 7 3
MENU :
1. Create tree
2. Display tree
3. Find depth of tree
4. Display leaf nodes
5. Create copy of tree
6. Exit
3

The depth of tree = 4
MENU :
1. Create tree
2. Display tree
3. Find depth of tree
4. Display leaf nodes
5. Create copy of tree
6. Exit
4

The leaf nodes are = 8 9 10 7
MENU :
1. Create tree
2. Display tree
3. Find depth of tree
4. Display leaf nodes
5. Create copy of tree
6. Exit
5

Original tree = 8 4 9 2 5 10 1 6 7 3
Copy of original tree = 8 4 9 2 5 10 1 6 7 3    */

