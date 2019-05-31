#include<iostream>
using namespace std;

class node									//class node
{
	public:
	int data;
	node* next;
	node(int newvalue)
	{
		data= newvalue;
		next=NULL;
	}
};
	
class linkedlist							//class linkedlist
{	
	public:
	node* head;
	linkedlist()
	{
		head=NULL;
	}
	
	void insert_head(int value)				//function that inserts at head
	{
		node* temp=new node(value);
		
		if (head==NULL)
		{
			head=temp;
		}
		else
		{
			temp->next=head;
			head=temp;
		}
	}
	
	void insert_tail(int value)				//function that insert at tail		
	{
		node* temp=new node(value);
		
		if(head==NULL)
		{
			head=temp;
		}
		else
		{
			node* curr=head;
			while(curr->next!=NULL)
			{
				curr=curr->next;
			}
			curr->next=temp;
		}
	}
	
	int number_of_nodes()
	{
		node* curr= head;
		int i=1;
		while(curr->next!=NULL)
		{
			curr=curr->next;
			i++;
		}
		return i;
	}
	
	node* pointer_before_nth_position(int n)
	{
		node* curr=head;
		int j=1;
		while(j!=(n-1))
		{
			curr=curr->next;
			j++;
		}
		return curr;
	}
	
	void insertat_front(int pos,int value)
	{
		node* temp= new node(value);
		int x =number_of_nodes() + 1;
		
		if(pos==1)
		{
			insert_head(value);
		}
		else if(pos<1 || pos>x)
		{
			cout<<"that is a invalid position";
			cout<<endl;
		}
		else
		{
			node* curr=pointer_before_nth_position(pos);
			temp->next=curr->next;
			curr->next=temp;
		}
	}
	
	void display()
	{
		node* curr=head;
		while(curr!=NULL)
		{
			cout<<curr->data;
			cout<<"->";
			curr=curr->next;
		}
	}
	
	void reverse_print(node* curr)
	{
		if(curr->next==NULL)
		{
			cout<<curr->data;
			cout<<"->";
		}
		else
		{
			reverse_print(curr->next);
			cout<<curr->data;
			cout<<"->";
		}
	}
	
	void reverse_display()
	{
		reverse_print(head);
	}
	
	void countitems()
	{
		int i=1;
		node* curr=head;
		while(curr->next!=NULL)
		{
			curr=curr->next;
			i++;
		}
		cout<<"the number of nodes are "<<i;
		cout<<endl;
	}
	
	void reverse()														//needs modification
	{
		node* currp;
		node* curr;
		node* currn;
		currp=head;
		curr=head;
		currn=head->next;
		
		if(curr==head)
		{
			curr->next=NULL;
			curr=currn;
			currn=currn->next;
		}
		
		else if(curr->next=NULL)
		{
			head=curr;
			curr->next=currp;
		}
		
		else
		{
			curr->next=currp;
			currp=curr;
			curr=currn;
			currn=currn->next;
		}
	}
};
	
int main()
{
	linkedlist l1;
	l1.insert_head(0);
	l1.insert_head(1);
	l1.insert_head(2);
	l1.insert_head(3);
	l1.insert_tail(4);
	l1.insert_tail(5);
	l1.insert_tail(6);
	l1.insertat_front(4,7);
	l1.insertat_front(6,8);
	l1.insertat_front(1,9);
	l1.insertat_front(11,10);
	l1.display();
	cout<<endl;
	l1.countitems();
	l1.reverse();
	l1.display();
	return 0;
}
	
	
	
		
	
