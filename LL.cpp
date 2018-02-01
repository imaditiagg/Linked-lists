#include<iostream>
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
node * midpoint(node*head) //without computing length of LL
{
	node*slow=head;
	node*fast=head->next;
	while(fast!=NULL && fast->next!=NULL) //when fast reaches end of list slow reaches the mid
	{
		fast=fast->next->next;
		slow=slow->next;
	}
	return slow;
}

void reverse(node*&head) //without recursion
{
	node *prev=NULL;
	node*current=head;
	node *n;
	while(current!=NULL)
	{
		n=current->next; //contains the add of next node of current
		current->next=prev; //reverse the links
		prev=current;
		current=n;
	}
	head=prev;
	
}
node *merge(node *a,node*b)
{
	if(a==NULL)
	return b;
	else if(b==NULL)
	return a;
	
	node*newhead;
	if(a->data <b->data)
	{
		newhead=a;
		a->next=merge(a->next,b);
		
	}
	else
	{
		newhead=b;
		b->next=merge(a,b->next);
		
	}
	return newhead;
}
node * mergesort(node*head)
{
	//base case
	if(head==NULL || head->next==NULL)
	return head;
	//recursive 
	//break the list
	node *mid=midpoint(head);
	node *a=head;
	node *b=mid->next;
	mid->next=NULL;
	//sort
	a=mergesort(a);
	b=mergesort(b);
	//merge
return merge(a,b);	
	
	
	}
int length(node*head){
	int len=0;
	while(head!=NULL){
		len++;
		head = head->next;
	}
	return len;
}
void bubblesort(node*&head)
{
	int n=length(head);
	for(int i=0;i<n-1;i++)//no. of iterations
	{
		node *prev=NULL;
		node *N=NULL;
		node*current=head;
		while(current!=NULL && current->next!=NULL)
		{
			//swapping
		if(current->data > current->next->data)
		{
				
			if(prev==NULL)//head needs to be updated
			{
				N=current->next;
				current->next=N->next;
				N->next=current;
				head=N;
				prev=N;
			}
			else
			{
				N=current->next;
				current->next=N->next;
				prev->next=N;
				N->next=current;
				prev=N;
			}
			
			
		}
		//not swapping
		else
		{
			prev=current;
			current=current->next;
		}
		
		
		
		
		}
		
	}
	
}
int main()
{
	node *head=NULL;
	takeInput(head);
	print(head);
	/*node * m = midpoint(head);
	cout<<"\nData of mid point is : "<<m->data;
	cout<<"\nReverse of LL : ";
	reverse(head);
	print(head);*/
//	node *head2=mergesort(head);
	cout<<"\nAfter sorting: ";
	bubblesort(head);
	print(head);
	return 0;
}
