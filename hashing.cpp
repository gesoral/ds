/*
ASSIGNMENT NO:B-13
Title:Consider telephone book database of N clients. Make use of a hash table implementation to
quickly look up client‘s telephone number.
linear probing without replacement without chaining
Class:-SE-A
Batch:-SA-3
Roll no.:-46*/

#include<iostream>
#include<string.h>
using namespace std;

class hashtable
{
	public:
		char name[10];
		int no;
		hashtable()
		{
			strcpy(name,"NULL");
		}
};
class client
{
	hashtable hash[25];
	public:
		char a[10];
		int b;
	int returnVal(char x)
	{
		return (int)x-97;
	}
	int insert()
	{
		int w=0;
		char m;
		int i,j;
		do
		{
			cout<<"Enter name and telephone no:"<<endl;
			cin>>a;
			cin>>b;
			int k;
			char s=a[0];
			k=returnVal(s);
			hashtable p;
			strcpy(p.name,a);
			p.no=b;
			
			if(strcmp(hash[k].name,"NULL")==0)
			{
				hash[k]=p;
			}
			else
			{
				for(j=k;strcmp(hash[j].name,"NULL")!=0;j++);
				hash[j]=p;
			}
			w++;
			cout<<"do you want to add another name:"<<endl;
			cin>>m;
		}while(m!='n');
		cout<<"w="<<w<<endl;
		return w;
	}
	void display(int k)
	{
		int i;
		cout<<"telephone book database:"<<endl;
		for(i=0;i<25;i++)
		{
			if(strcmp(hash[i].name,"NULL")==0)
			{
				cout<<i<<"name:__________  number:_____________"<<endl;
			}
			else
			{
				cout<<i<<"name: "<<hash[i].name<<"        "<<"number: "<<hash[i].no<<endl;
			}
		}
	}
	void search(int k)
	{
		int q,i;
		int y=0;
		cout<<"Enter name of client:"<<endl;
		cin>>a;
		char s=a[0];
		q=returnVal(s);
		if(strcmp(hash[q].name,a)==0)
		{
			cout<<"client no is: "<<hash[q].no<<endl;
			y=1;
		}
		else
		{
			for(i=q;i<k;i++)
			{
				if(strcmp(hash[i].name,a)==0)
				{
					cout<<"client no is: "<<hash[i].no<<endl;
						y=1;
					break;
				}
			}
		}
		if(y==0)
		cout<<"client no not found!"<<endl;
		else
		cout<<"client no found succesfully!"<<endl;
	}
					
};
int main()
{
	client c;
	int o;
	o=c.insert();
	c.display(o);
	c.search(o);
	return 0;
}		


