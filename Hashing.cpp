/*   BATCH : H10
 * ROLL NO : 23269
 * PROBLEM STATEMENT : Store data of students with telephone number and name in the structure using hashing function for telephone number and implement chaining with and without replacement.*/

#include <iostream>
using namespace std;
#define MAX 10
// Hash function can be defined as macro
//division method or other methods of hashing may be used to get the index/location

struct student{
	string name;
	long tel_number;
};

struct HT{
	student stud;
	int flag;
	int chain;
};

class LP_withreplacement{

	HT Records[MAX];
public:
	//functions for insertion, display and search
	void insert_withreplacement(int);
	void display_withreplacement(int);
	int search_withreplacement(int);
	LP_withreplacement();
};

class LP_withoutreplacement{

	HT Records[MAX];
public:
	//functions for insertion, display and search
	void insert_withoutreplacement(int);
	void display_withoutreplacement(int);
	int search_withoutreplacement(int);
	LP_withoutreplacement();
};

int LP_withoutreplacement :: search_withoutreplacement(int num)
{
	int i = 0, loc, n = 10;
	long int key;
	cout<<"\nEnter telephone number to be searched. ";
	cin>>key;
	loc = key % n;
	while(i < n && Records[loc].flag == 1 && Records[loc].stud.tel_number % n != loc)
	{
		loc = (loc + 1) % n;
		i++;
	}
	if(Records[loc].flag != 1 || i == n)
		return -1;
	else
	{
		while(loc != -1)
		{
			if(Records[loc].stud.tel_number == key)
				return loc;
			else
				loc = Records[loc].chain;
		}
	}
	return -1;
}

int LP_withreplacement :: search_withreplacement(int num)
{
	int i = 0, loc, n = 10;
	long int key;
	cout<<"\nEnter telephone number to be searched. ";
	cin>>key;
	loc = key % n;
	while(loc != -1)
	{
		if(Records[loc].stud.tel_number == key)
			return loc;
		else
			loc = Records[loc].chain;
	}
	return -1;
}

LP_withoutreplacement :: LP_withoutreplacement()
{
	for(int i = 0; i < 10; i++)
	{
		Records[i].flag = 0;
		Records[i].chain = -1;
	}
}

LP_withreplacement :: LP_withreplacement()
{
	for(int i = 0; i < 10; i++)
	{
		Records[i].flag = 0;
		Records[i].chain = -1;
	}
}

void LP_withreplacement :: insert_withreplacement(int num)
{
	int x, loc, i, n = 10, j;
	string na;
	long int no;
	for(x = 0; x < num; x++)
	{
		cout<<"\nEnter name. ";
		cin>>na;
		cout<<"\nEnter telephone number. ";
		cin>>no;
		loc = no % n;
		i = 0;
		j = loc;
		if(Records[loc].flag == 0)
		{
			Records[loc].stud.name = na;
			Records[loc].stud.tel_number = no;
			Records[loc].flag = 1;
			continue;
		}
		while(i < n && Records[j].flag == 1)
		{
			j = (j + 1) % n;
			i++;
		}
		if(i == n)
		{
			cout<<"\nTable is full!!";
			return;
		}
		if(Records[loc].stud.tel_number % n != loc)
		{
			i = Records[loc].stud.tel_number % n;
			while(Records[i].chain != loc)
				i = Records[i].chain;
			Records[i].chain = Records[loc].chain;
			while(Records[i].chain != -1)
				i = Records[i].chain;
			Records[i].chain = j;
			Records[j].stud.name = Records[loc].stud.name;
			Records[j].stud.tel_number = Records[loc].stud.tel_number;
			Records[j].flag = 1;
			Records[j].chain = -1;
			Records[loc].stud.name = na;
			Records[loc].stud.tel_number = no;
			Records[loc].flag = 1;
			Records[loc].chain = -1;
			continue;
		}
		if(Records[loc].stud.tel_number % n == loc)
		{
			Records[j].stud.name = na;
			Records[j].stud.tel_number = no;
			Records[j].flag = 1;
			Records[j].chain = -1;
			i = loc;
			while(Records[i].chain != -1)
				i = Records[i].chain;
			Records[i].chain = j;
			continue;
		}
	}
}

void LP_withoutreplacement :: insert_withoutreplacement(int num)
{
	int loc, i, j, n = 10, x;
	string na;
	long int no;
	for(x = 0; x < num; x++)
	{
		cout<<"\nEnter name. ";
		cin>>na;
		cout<<"\nEnter telephone number. ";
		cin>>no;
		loc = no % n;
		i = 0;
		j = loc;
		while(i < n && Records[j].flag == 1)
		{
			if(Records[j].stud.tel_number % n == no % n)
				break;
			j = (j + 1) % n;
			i++;
		}
		if(i == n)
		{
			cout<<"\nTable is full!!";
			return;
		}
		while(Records[j].chain != -1)
			j = Records[j].chain;
		loc = j;
		while(Records[loc].flag && i < n)
		{
			loc = (loc + 1) % n;
			i++;
		}
		if(i == n)
		{
			cout<<"\nTable is full!!";
			return;
		}
		Records[loc].stud.name = na;
		Records[loc].stud.tel_number = no;
		Records[loc].flag = 1;
		if(j != loc)
			Records[j].chain = loc;
	}
}

void LP_withreplacement :: display_withreplacement(int num)
{
	cout<<"\n------------------------------------------------------------\n";
	cout<<"\nINDEX\tRECORD\t\tCHAIN\n";
	cout<<"\n------------------------------------------------------------\n";
	for(int i = 0; i < num; i++)
		cout<<i<<"\t"<<Records[i].stud.name<<"\t"<<Records[i].stud.tel_number<<"\t"<<Records[i].chain<<endl;
}

void LP_withoutreplacement :: display_withoutreplacement(int num)
{
	cout<<"\n------------------------------------------------------------\n";
	cout<<"\nINDEX\tRECORD\t\tCHAIN\n";
	cout<<"\n------------------------------------------------------------\n";
	for(int i = 0; i < num; i++)
		cout<<i<<"\t"<<Records[i].stud.name<<"\t"<<Records[i].stud.tel_number<<"\t"<<Records[i].chain<<endl;
}

int main() {

	LP_withreplacement LPWR;
	LP_withoutreplacement LPWTR;
	int choice1, choice2, num_rec, loc;
	do
	{
		cout<<"\nMENU:\n1. Linear probing with replacement\n2. Linear probing without repalcement\n3. Exit\nEnter your choice. ";
		cin>>choice1;
		switch(choice1)
		{
			case 1:
				do
				{
					cout<<"\n1. Insert\n2. Display\n3. Search\n4. Exit\n";
					cin>>choice2;
					switch(choice2)
					{
						case 1:
							cout<<"\nHow many records do you want to enter? ";
							cin>>num_rec;
							LPWR.insert_withreplacement(num_rec);
							break;
						case 2:
							LPWR.display_withreplacement(num_rec);
							break;
						case 3:
							loc = LPWR.search_withreplacement(num_rec);
							if(loc == -1)
								cout<<"\nElement not found.";
							else
								cout<<"\nElement found at location "<<loc;
							break;
						case 4:
							break;
						default:
							cout<<"\nEnter valid choice.";
					}
				}while(choice2 != 4);
				break;
			case 2:
				do
				{
					cout<<"\n1. Insert\n2. Display\n3. Search\n4. Exit\n";
					cin>>choice2;
					switch(choice2)
					{
						case 1:
							cout<<"\nHow many records do you want to enter? ";
							cin>>num_rec;
							LPWTR.insert_withoutreplacement(num_rec);
							break;
						case 2:
							LPWTR.display_withoutreplacement(num_rec);
							break;
						case 3:
							loc = LPWTR.search_withoutreplacement(num_rec);
							if(loc == -1)
								cout<<"\nElement not found.";
							else
								cout<<"\nElement found at location "<<loc;
							break;
						case 4:
							break;
						default:
							cout<<"\nEnter valid choice.";
					}
				}while(choice2 != 4);
				break;
			case 3:
				return 0;
			default:
				cout<<"\nEnter valid choice.";
		}
	}while(1);

	//case 1 : LP with replacement.....nested case for insert, display and search operations
	//case 2 : LP without replacement.....nested case for insert, display and search operations
}

/*OUTPUT :
MENU:
1. Linear probing with replacement
2. Linear probing without repalcement
3. Exit
Enter your choice. 1

1. Insert
2. Display
3. Search
4. Exit
1

How many records do you want to enter? 10

Enter name. sonakshi

Enter telephone number. 7719916409

Enter name. rohit

Enter telephone number. 7719916445

Enter name. tanya

Enter telephone number. 7719916413

Enter name. rohan

Enter telephone number. 7719916459

Enter name. veena

Enter telephone number. 7719916412

Enter name. naren

Enter telephone number. 7719916475

Enter name. suman

Enter telephone number. 7719916488

Enter name. nishi

Enter telephone number. 7719916411

Enter name. pooja

Enter telephone number. 7719916106

Enter name. ajit

Enter telephone number. 7719916446

1. Insert
2. Display
3. Search
4. Exit
2

------------------------------------------------------------

INDEX		RECORD			CHAIN

------------------------------------------------------------
0	rohan		7719916459	-1
1	nishi		7719916411	-1
2	veena		7719916412	-1
3	tanya		7719916413	-1
4	ajit		7719916446	-1
5	rohit		7719916445	7
6	pooja		7719916106	4
7	naren		7719916475	-1
8	suman		7719916488	-1
9	sonakshi	7719916409	0

1. Insert
2. Display
3. Search
4. Exit
3

Enter telephone number to be searched. 7719916475

Element found at location 7
1. Insert
2. Display
3. Search
4. Exit
3

Enter telephone number to be searched. 0

Element not found.
1. Insert
2. Display
3. Search
4. Exit
4

MENU:
1. Linear probing with replacement
2. Linear probing without repalcement
3. Exit
Enter your choice. 2

1. Insert
2. Display
3. Search
4. Exit
1

How many records do you want to enter? 10

Enter name. sonakshi

Enter telephone number. 7719916409

Enter name. rohit

Enter telephone number. 7719916445

Enter name. tanya

Enter telephone number. 7719916413

Enter name. rohan

Enter telephone number. 7719916459

Enter name. veena

Enter telephone number. 7719916412

Enter name. naren

Enter telephone number. 7719916475

Enter name. suman

Enter telephone number. 7719916488

Enter name. nishi

Enter telephone number. 7719916411

Enter name. pooja

Enter telephone number. 7719916106

Enter name. ajit

Enter telephone number. 7719916446

1. Insert
2. Display
3. Search
4. Exit
2

------------------------------------------------------------

INDEX		RECORD			CHAIN

------------------------------------------------------------
0	rohan		7719916459	-1
1	nishi		7719916411	-1
2	veena		7719916412	-1
3	tanya		7719916413	-1
4	ajit		7719916446	-1
5	rohit		7719916445	6
6	naren		7719916475	-1
7	pooja		7719916106	4
8	suman		7719916488	-1
9	sonakshi	7719916409	0

1. Insert
2. Display
3. Search
4. Exit
3

Enter telephone number to be searched. 7719916475

Element found at location 6
1. Insert
2. Display
3. Search
4. Exit
3

Enter telephone number to be searched. 0
*/
