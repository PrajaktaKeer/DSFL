/*BATCH : H10
 ROLL NO : 23269
 PROBLEM STATEMENT : Consider a friends‘ network on face book social web site. Model it as a graph to
represent each node as a user and a link to represent the friend relationship between
them. Store data such as date of birth, number of comments for each user.
1. Find who is having maximum friends
2. Find who has post maximum and minimum comments
3. Find users having birthday in this month   */

#include "Graph.h"
#include<iostream>
#include<string.h>
using namespace std;

class facebook
{
	graph g;
	public:
		void register_users();
		void add_f();
		void max_f();
		void comm();
		void bday();
		void print();
};

void facebook :: print()
{
	g.display();
}

void facebook :: register_users()
{
	g.create();
}

void facebook :: add_f()
{
	g.add_friends();
}

void facebook :: max_f()
{
	g.max_friend();
}

void facebook :: comm()
{
	g.comments();
}

void facebook :: bday()
{
	g.birthday();
}

int main()
{
	int choice;
	facebook f;
	do
	{
		cout<<"\nMENU :\n1. Register the users\n2. Add friends\n3. Display the graph\n4. Find maximum friends\n5. Find maximum and minimum comments\n6. Find birthdays in this month\n7. Exit\nEnter your choice = ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				f.register_users();
				break;
			case 2:
				f.add_f();
				break;
			case 3:
				f.print();
				break;
			case 4:
				f.max_f();
				break;
			case 5:
				f.comm();
				break;
			case 6:
				f.bday();
				break;
			case 7:
				return 0;
			default:
				cout<<"\nEnter valid choice. ";
		}
	}while(1);
}

/*OUTPUT :
MENU :
1. Register the users
2. Add friends
3. Display the graph
4. Find maximum friends
5. Find maximum and minimum comments
6. Find birthdays in this month
7. Exit
Enter your choice = 1

Enter name. sara

Enter date of birth(day, month, year).20	2	2001

Enter number of comments. 2
Do you want to add another user? y

Enter name. jyoti

Enter date of birth(day, month, year).5	        8	2001

Enter number of comments. 4
Do you want to add another user? y

Enter name. fiza

Enter date of birth(day, month, year).1	1	2001

Enter number of comments. 1
Do you want to add another user? y

Enter name. rose

Enter date of birth(day, month, year).6	6	2001

Enter number of comments. 3
Do you want to add another user? n

MENU :
1. Register the users
2. Add friends
3. Display the graph
4. Find maximum friends
5. Find maximum and minimum comments
6. Find birthdays in this month
7. Exit
Enter your choice = 2
Does sara have a friend(y / n)? y

Enter friend's name. jyoti
Does sara have any other friend(y / n)? n
Does jyoti have a friend(y / n)? y

Enter friend's name. fiza
Does jyoti have any other friend(y / n)? y

Enter friend's name. rose
Does jyoti have any other friend(y / n)? n
Does fiza have a friend(y / n)? n
Does rose have a friend(y / n)? n

MENU :
1. Register the users
2. Add friends
3. Display the graph
4. Find maximum friends
5. Find maximum and minimum comments
6. Find birthdays in this month
7. Exit
Enter your choice = 3
sara -> jyoti ->
jyoti -> sara ->fiza ->rose ->
fiza -> jyoti ->
rose -> jyoti ->

MENU :
1. Register the users
2. Add friends
3. Display the graph
4. Find maximum friends
5. Find maximum and minimum comments
6. Find birthdays in this month
7. Exit
Enter your choice = 4
jyoti has maximum number of friends = 3

MENU :
1. Register the users
2. Add friends
3. Display the graph
4. Find maximum friends
5. Find maximum and minimum comments
6. Find birthdays in this month
7. Exit
Enter your choice = 5

fiza has made minimum number of comments 1.

jyoti has made maximum number of comments 4.

MENU :
1. Register the users
2. Add friends
3. Display the graph
4. Find maximum friends
5. Find maximum and minimum comments
6. Find birthdays in this month
7. Exit
Enter your choice = 6

Enter current month. 8
jyoti has birthday in this month.  */


