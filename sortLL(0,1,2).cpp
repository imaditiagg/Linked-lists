#include<iostream>
#include<stack>
using namespace std;
class node
{
		public:
	int data;
	node *next;

	node(int d)
	{
		next=NULL;
		data=d;
	}
};
void print(node*head){
	while(head!=NULL){
		cout<<head->data<<"-->";
		head = head->next;
	}
	cout<<"NULL";
}
void insertAtHead(node*&head,int d){
	node* n = new node(d);
	n->next = head;
	head = n;
}
void takeInput(node*&head){
	int d;
	cin>>d;
	while(d!=-1){
		insertAtHead(head,d);
		cin>>d;
	}
}
void sort(node*&head)
{
	node*a=NULL;
	node*b=NULL;
	node*c=NULL;
	node*temp=head;
	while(temp!=NULL)
	{
		if(temp->data==0)
		{
         insertAtHead(a,0);
		
	    }
	else if(temp->data==1)
		{
         insertAtHead(b,1);
		
	}
	else
		{
        insertAtHead(c,2);
		}
		
	temp=temp->next;
}

temp=a;
while(temp->next!=NULL)
{
	temp=temp->next;
}
temp->next=b;
temp=b;
while(temp->next!=NULL)
{
	temp=temp->next;
}
temp->next=c;

head=a;

}



int main()
{
	node*head=NULL;
	cout<<"Enter a LL containing 0's, 1's and 2's only: ";
	takeInput(head);
	sort(head);
	cout<<"After sorting ";
	print(head);
}
