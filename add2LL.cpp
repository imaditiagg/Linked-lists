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
void insertAtEnd(node*&head,int d){
	node* n = new node(d);
	if(head==NULL)
	{
		head=n;
		
	}
	else
	{
    node*temp=head;
    while(temp->next!=NULL)
    {
    	temp=temp->next;
	}
	temp->next=n;
    }
    
}
node* add(node *h1,node *h2)
{
	node*temp1=h1;
	node*temp2=h2;
	node *h3=NULL;
	int c=0,sum=0;
	while(temp1!=NULL || temp2!=NULL)
	{
		sum= c+ (temp1?temp1->data: 0) + (temp2?temp2->data: 0);
	
		insertAtHead(h3,sum%10);
		c=sum/10;
		if(temp1) temp1=temp1->next;
		if(temp2) temp2=temp2->next;
	}
	if(c>0)
	{
		insertAtHead(h3,c);
	}
	return h3;
}
int main()
{
	node*head1=NULL;
	node*head2=NULL;
	cout<<"Enter number 1: ";
	takeInput(head1);
	cout<<"Enter number 2: ";
	takeInput(head2);
	//print(head1);
	cout<<"\n";
	//print(head2);
	node *head3=add(head1,head2);
	cout<<"\nResult After addition: ";
	print(head3);	
}
