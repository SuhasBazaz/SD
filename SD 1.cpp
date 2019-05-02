#include<iostream> 
using namespace std;

class sets{
public:
	int set[20];
	int size;
	
	sets(){
		size = 0;
	}
	void create();
	void print();
	int isPresent(int a);
	sets* intersection(sets *b);
	void AddToSet(int a);
	sets* UnionOf(sets *b);
	sets* Difference(sets *b);
	int ReturnSize();
	void Delete(int a);
};

void sets::Delete(int a)
{
	if(this->isPresent(a))
		{
			int i = 0;
			while(this->set[i] != a)
				i++;
				for(int j=i;j<size-1;j++)
					set[j]=set[j+1];
					size--;
			
		}
	else
		cout<<"NO SUCH ELEMENT IN THE SET."<<endl;
}
int sets::ReturnSize() 
{
	return this->size;
}

sets* sets::Difference(sets *b)
{
	sets *c = new sets;
	for(int i = 0; i<size; i++)
		if(!(b->isPresent(set[i])))
			c->AddToSet(set[i]);
	return c;
	
}

sets* sets::UnionOf(sets *b)
{
	sets *c = new sets;
	for(int i = 0; i<size; i++)
		c->AddToSet(set[i]);
	for(int i = 0; i<b->size; i++)
		if( !(isPresent(b->set[i])))
			c->AddToSet(b->set[i]);
	return c;
}

void sets::AddToSet(int a)
{
	int m = size;
	set[m] = a;
	size++;
}



sets* sets::intersection(sets *b)
{
	sets *c = new sets;
	int m = size;
	int n = b->size;
	
	if(m<= n) 
	{
		for(int i = 0; i<m; i++)
		{
			int ofFirst = set[i];
			if(b->isPresent(ofFirst))
				c->AddToSet(ofFirst);
		}
	}
	
	else
	{
		for(int i = 0; i<n; i++)
		{
			int ofSecond = b->set[i];
			if(isPresent(ofSecond))
				c->AddToSet(ofSecond);
		}
	}
	
	return c;
	
	
}
	
int sets::isPresent(int a)
{
	for(int i = 0; i<size; i++)
		if(a == set[i])
			return 1;
	return 0;
}

void sets::create() 
{
	cout<<"ENTER SIZE."<<endl;
	cin>> size;
	cout<<"ENTER ELEMENTS."<<endl;
	for(int i = 0; i<this->size;i++)
		cin>>set[i];
}

void sets::print() 
{
	for(int i = 0; i<size; i++)
		cout<<set[i]<<" ";
	cout<<endl;
}

int main(){
	
	char ch = 'y';
	int switch_choice;
	int case_choice;
	sets *a = new sets;
	sets *b = new sets;
	
	while(ch == 'y') 
	{
		cout<<"1.CREATE 2.PRINT 3.INTERSECTION 4.UNION 5.DIFFERENCE 6.SIZE 7.DELETE ELEMENT 8.EXIT"<<endl;
		cin>>switch_choice;
		
		switch(switch_choice) 
		{
		case 1:
		{	
			cout<<"1.SET A \n2.SET B"<<endl;

			cin>>case_choice;
			switch(case_choice)
			{
				case 1:
				a->create();
				break;
				
				case 2:
				b->create();
				break;
			}
			break;
		}
		
		case 2:
		{	
			cout<<"1.SET A \n2.SET B"<<endl;

			cin>>case_choice;
			switch(case_choice)
			{
				case 1:
				a->print();
				break;
				
				case 2:
				b->print();
				break;
			}
			break;
		}
		
		case 3:
		{
			cout<<"FOR SET A: "<<endl;
			a->create();
			cout<<"FOR SET B: "<<endl;
			b->create();
			sets *c = new sets;
			c = a->intersection(b);
			cout<<"THE INTERSECTION SET IS: "<<endl;
			c->print();
			break;
		}
		
		case 4:
		{
			cout<<"FOR SET A: "<<endl;
			a->create();
			cout<<"FOR SET B: "<<endl;
			b->create();
			sets *c = new sets;
			c = a->UnionOf(b);
			cout<<"THE UNION SET IS: "<<endl;
			c->print();
			break;
		}
		
		case 5:
		{
			cout<<"FOR SET A: "<<endl;
			a->create();
			cout<<"FOR SET B: "<<endl;
			b->create();
			sets *c = new sets;
			c = a->Difference(b);
			cout<<"THE DIFFERENCE SET IS: "<<endl;
			c->print();
			break;
		}
		
		case 6:
		{	
			cout<<"1.SET A \n2.SET B"<<endl;

			cin>>case_choice;
			switch(case_choice)
			{
				case 1:
				cout<<"SIZE OF A: "<<a->ReturnSize()<<endl;
				break;
				
				case 2:
				cout<<"SIZE OF B: "<<b->ReturnSize()<<endl;
				break;
			}
			break;
		}
		
		case 7:
			{
				int del;
				cout<<"1. SET A \n 2.SET B"<<endl;
				cin>>case_choice;
				switch(case_choice)
				{
					case 1:
						cout<<"Enter element to be deleted "<<endl;
						cin>>del;
						a->Delete(del);
						break;
						
					case 2:
						cout<<"Enter element to be deleted "<<endl;
						cin>>del;
						b->Delete(del);
						break;
				}
				break;
			}
		
		case 8:
		{
			ch = 'n';
			cout<<"EXITING..."<<endl;
			break;
		}
		
		}
		
		
	}
return 0;}
