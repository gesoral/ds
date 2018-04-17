/**********ASSIGNMENT: (GROUP C-15)****************************
Problem Statement: Implement all the functions of a dictionary (ADT) using hashing.
Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable, Keys
must be unique
Standard Operations: Insert(key, value), Find(key), Delete(key).

DIV: A
BATCH: SA-2
ROLL NO: 30
********************************************************************/

#include<iostream>
using namespace std;
#define MAX 10

class HashTab
{
	private:
			struct DCT
			{
				int k;
				int val;
			}a[MAX];
	public:
			int DivMethod(int);
			void init();
			void insert(int,int,int);
			void display();
			void size();
			int search(int);
			void deleteRec(int);
};

void HashTab :: init()
{
	for (int i = 0; i < MAX; ++i)
	{
		a[i].k=-1;
		a[i].val=-1;

	}
}

int HashTab :: DivMethod(int num)
{
	int key;
	key=num%10;
	return key;
}

void HashTab :: insert(int index,int key,int value)
{
	int flag,i,cnt=0;
	flag=0;
	if(a[index].k==-1)
	{
		a[index].k=key;
		a[index].val=value;
	}
	else
	{
		i=0;
		while(i<MAX)
		{
			if(a[i].k!=-1)
				cnt++;
			i++;
		}
		if(cnt==MAX)
			cout<<"\nEntry Table is Full";
	}
	for (int i =index+1; i < MAX; ++i)
	{
		if(a[i].k==-1)
		{
			a[i].k=key;
			a[i].val=value;
			flag=1;
			break;
		}
		for (int i = 0; i < index && flag==0; ++i)
		{
			if(a[i].k==-1)
			{
				a[i].k=key;
				a[i].val=value;
				flag=1;
				break;
			}
		}
	}
}

void HashTab :: display()
{
	int i;
	cout<<"\n Dictionary Table: ";
	cout<<"\n-------------------------------------------------";
	for (int i = 0; i < MAX; ++i)
	{
		cout<<"\n "<<i<<" "<<a[i].k<<" "<<a[i].val;

	}
	cout<<"\n-------------------------------------------------------";
}

void HashTab :: size()
{
	int len=0,i;
	for (int i = 0; i < MAX; ++i)
	{
		if(a[i].k!=-1)
			len++;
	}
	cout<<"\nThe size of dictionary is "<<len;
	
}

int HashTab :: search(int search_key)
{
	int i,j,status=0;
	i=DivMethod(search_key);
	if(a[i].k==search_key)
	{
		cout<<"\n The record is present at location "<<i;
		status=1;
		return i;
	}
	if(a[i].k!=search_key)
	{
		for (int j = i; j< MAX; j++)
		{
			if(a[j].k==search_key)
			{
				cout<<"\n The record is present at location "<<j;
				status=1;
				return j;
			}
		}
		for (int j= 0; j<i;j++)
		{	
			if(a[j].k==search_key)
			{
				cout<<"\n The record is present at location "<<j;
				status=1;
				return j;
			}
			
		}
	}
		if(status== 0)
		{
			cout<<"\n The record is not present.";
			return -99;
		}

}

void HashTab :: deleteRec(int key)
{
	int index;
	index=search(key);
	if(index!=-99)
	{
		a[index].k=-1;
		a[index].val=-1;
		cout<<"\nThe record is deleted.";

	}
}

int main()
{
	int key,value,Hkey,search_key,choice;
	char ans;
	int index;
	HashTab obj;
	cout<<"\nDictionary using Hashing function.";
	obj.init();
	do
	{
		cout<<"\n1.Insert.\n2.Display.\n3.Search.\n4.Deletion.\n5.exit";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1: cout<<"\nEnter key: ";
					cin>>key;
					cout<<"\nEnter value: ";
					cin>>value;
					Hkey=obj.DivMethod(key);
					obj.insert(Hkey,key,value);
			break;

			case 2: obj.display();
					obj.size();
			break;

			case 3: cout<<"\nEnter key to be searched: ";
					cin>>search_key;
					index=obj.search(search_key);
			break;

			case 4: cout<<"\nEnter key to be deleted: ";
					cin>> search_key;
					obj.deleteRec(search_key);
			break;
			case 5: break;
		}
	}while(choice!=5);
		}



	
