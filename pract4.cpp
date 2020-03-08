/* BATCH : H10
  ROLL NO : 23269
 PROBLEM STATEMENT : Construct and expression tree from postfix/prefix expression and perform recursive and non- recursive In-order, pre-order and post-order traversals.*/

#include<iostream>
#include<string.h>
using namespace std;

class Tnode
{
	char data;
	Tnode *right, *left;
	public:
		friend class exptree;
};

class stacknode
{
		Tnode *data;
		int flag;
	public:
		friend class exptree;
};

class stack
{
	int top;
	Tnode *data1[100];
	stacknode data2[100];
	public:
		stack()
		{
			top = -1;
		}
		void push(Tnode* x)
		{
			data1[++top] = x;
		}
		void push(stacknode x)
		{
             data2[++top] = x;
        }
		Tnode* pop()
		{
			return data1[top--];
		}
		stacknode pop1()
		{
            return data2[top--];
        }
		int empty()
		{
			if(top == 0)
				return 1;
			return 0;
		}
		friend class exptree;
};

class exptree
{
	Tnode *root;
	stack s;
	public:
		void create_postfix(char[]);
		void create_prefix(char[]);
		void inorder_rec(Tnode *);
		void preorder_rec(Tnode *);
		void postorder_rec(Tnode *);
		void inorder(Tnode *);
		void preorder(Tnode *);
		void postorder(Tnode *);
		void in();
		void pre();
		void post();
};

void exptree :: preorder_rec(Tnode *root)
{
	if(root != NULL)
	{
		cout<<root->data;
		preorder_rec(root->left);
		preorder_rec(root->right);
	}
}

void exptree :: postorder_rec(Tnode *root)
{
	if(root != NULL)
	{
		postorder_rec(root->left);
		postorder_rec(root->right);
		cout<<root->data;
	}
}

void exptree :: inorder(Tnode *root)
{
	while(1)
	{
		while(root != NULL)
		{
			s.push(root);
			root = root->left;
		}
		if(s.empty())
			return;
		root = s.pop();
		cout<<root->data;
		root = root->right;
	}
}

void exptree :: preorder(Tnode *root)
{
	while(1)
	{
		while(root != NULL)
		{
			cout<<root->data;
			s.push(root);
			root = root->left;
		}
		if(s.empty())
			return;
		root = s.pop();
		root = root->right;
	}
}

void exptree :: postorder(Tnode *root)
{
	stacknode st;
	Tnode *p;
	while(root != NULL)
	{
        st.data = root;
        st.flag = 0;
        s.push(st);
        root = root->left;
    }
    while(!s.empty())
    {
        st = s.pop1();
        if(st.flag == 0)
        {
            st.flag = 1;
            s.push(st);
            root = st.data;
            root = root->right;
            while(root != NULL)
            {
               st.data = root;
               st.flag = 0;
               s.push(st);
               root = root->left;
            }
        }
        else
        {
               p = st.data;
               cout<<p->data;
        }
    }
}

void exptree :: in()
{
	int c;
	cout<<"\nDo you want \n1. Recursive\n2. Non-recursive call\n";
	cin>>c;
	switch(c)
	{
		case 1:
			cout<<"\nThe inorder traversal of tree = ";
			inorder_rec(root);
			break;
		case 2:
			cout<<"\nThe inorder traversal of tree = ";
			inorder(root);
			break;
		default:
			cout<<"\nEnter valid choice.";
	}

}

void exptree :: pre()
{
	int c;
	cout<<"\nDo you want \n1. Recursive\n2. Non-recursive call\n";
	cin>>c;
	switch(c)
	{
		case 1:
			cout<<"\nThe preorder traversal of tree = ";
			preorder_rec(root);
			break;
		case 2:
			cout<<"\nThe preorder traversal of tree = ";
			preorder(root);
			break;
		default:
			cout<<"\nEnter valid choice.";
	}
}

void exptree :: post()
{
	int c;
	cout<<"\nDo you want \n1. Recursive\n2. Non-recursive call\n";
	cin>>c;
	switch(c)
	{
		case 1:
			cout<<"\nThe postorder traversal of tree = ";
			postorder_rec(root);
			break;
		case 2:
			cout<<"\nThe postorder traversal of tree = ";
			postorder(root);
			break;
		default:
			cout<<"\nEnter valid choice.";
	}
}

void exptree :: create_postfix(char exp[])
{
	int i;
	for(i = 0; exp[i] != '\0'; i++)
	{
		if(isalnum(exp[i]))
		{
			Tnode *temp1 = new Tnode;
			temp1->data = exp[i];
			temp1->right = temp1->left = NULL;
			s.push(temp1);
		}
		if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '%' || exp[i] == '^')
		{
			Tnode *temp2 = new Tnode;
			temp2->data = exp[i];
			temp2->right = s.pop();
			temp2->left = s.pop();
			s.push(temp2);
			root = temp2;
		}
	}
}

void exptree :: inorder_rec(Tnode *root)
{
	if(root != NULL)
	{
		if(isalnum(root->data))
			cout<<root->data;
		else
		{
			cout<<"(";
			inorder_rec(root->left);
			cout<<root->data;
			inorder_rec(root->right);
			cout<<")";
		}
	}
}

void exptree :: create_prefix(char exp[])
{
	char e[100];
	int i, l = strlen(exp), j;
	for(i = 0, j = l - 1; j >= 0; i++, j--)
		e[i] = exp[j];
	e[i] = '\0';
	for(i = 0; e[i] != '\0'; i++)
	{
		if(isalnum(e[i]))
		{
			Tnode *temp1 = new Tnode;
			temp1->data = e[i];
			temp1->right = temp1->left = NULL;
			s.push(temp1);
		}
		if(e[i] == '+' || e[i] == '-' || e[i] == '*' || e[i] == '/' || e[i] == '%' || e[i] == '^')
		{
			Tnode *temp2 = new Tnode;
			temp2->data = e[i];
			temp2->left = s.pop();
			temp2->right = s.pop();
			s.push(temp2);
			root = temp2;
		}
	}
}

int main()
{
	int choice;
	char exp[100];
	exptree e;
	do
	{
		cout<<"\nMENU:\n1. Create expression tree from prefix expression\n2. Create expression tree from postfix expression\n3. Inorder traversal\n4. Preorder traversal\n5. Post traversal\n6. Exit\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"\nEnter prefix expression. ";
				cin>>exp;
				e.create_prefix(exp);
				break;
			case 2:
				cout<<"\nEnter postfix expression. ";
				cin>>exp;
				e.create_postfix(exp);
				break;
			case 3:
				e.in();
				break;
			case 4:
				e.pre();
				break;
			case 5:
				e.post();
				break;
			case 6:
				return 0;
			default:
				cout<<"\nEnter valid choice.";
		}
	}while(1);
}

/*OUTPUT : 
MENU:
1. Create expression tree from prefix expression
2. Create expression tree from postfix expression
3. Inorder traversal
4. Preorder traversal
5. Post traversal
6. Exit
1
Enter prefix expression. -a*b^c^de
MENU:
1. Create expression tree from prefix expression
2. Create expression tree from postfix expression
3. Inorder traversal
4. Preorder traversal
5. Post traversal
6. Exit
3
Do you want
1. Recursive
2. Non-recursive call
1
The inorder traversal of tree = (a-(b*(c^(d^e))))
MENU:
1. Create expression tree from prefix expression
2. Create expression tree from postfix expression
3. Inorder traversal
4. Preorder traversal
5. Post traversal
6. Exit
3
Do you want
1. Recursive
2. Non-recursive call
2
The inorder traversal of tree = a-b*c^d^e
MENU:
1. Create expression tree from prefix expression
2. Create expression tree from postfix expression
3. Inorder traversal
4. Preorder traversal
5. Post traversal
6. Exit
5
Do you want
1. Recursive
2. Non-recursive call
1
The postorder traversal of tree = abcde^^*-
MENU:
1. Create expression tree from prefix expression
2. Create expression tree from postfix expression
3. Inorder traversal
4. Preorder traversal
5. Post traversal
6. Exit
5
Do you want
1. Recursive
2. Non-recursive call
2
The postorder traversal of tree = abcde^^*-
MENU:
1. Create expression tree from prefix expression
2. Create expression tree from postfix expression
3. Inorder traversal
4. Preorder traversal
5. Post traversal
6. Exit
2
Enter postfix expression. abc^/d*e+
MENU:
1. Create expression tree from prefix expression
2. Create expression tree from postfix expression
3. Inorder traversal
4. Preorder traversal
5. Post traversal
6. Exit
3
Do you want
1. Recursive
2. Non-recursive call
1
The inorder traversal of tree = (((a/(b^c))*d)+e)
MENU:
1. Create expression tree from prefix expression
2. Create expression tree from postfix expression
3. Inorder traversal
4. Preorder traversal
5. Post traversal
6. Exit
3
Do you want
1. Recursive
2. Non-recursive call
2
The inorder traversal of tree = a/b^c*d+e
MENU:
1. Create expression tree from prefix expression
2. Create expression tree from postfix expression
3. Inorder traversal
4. Preorder traversal
5. Post traversal
6. Exit
4
Do you want
1. Recursive
2. Non-recursive call
1
The preorder traversal of tree = +*/a^bcde
MENU:
1. Create expression tree from prefix expression
2. Create expression tree from postfix expression
3. Inorder traversal
4. Preorder traversal
5. Post traversal
6. Exit
4
Do you want
1. Recursive
2. Non-recursive call
2
The preorder traversal of tree = +*/a^bcde  */
