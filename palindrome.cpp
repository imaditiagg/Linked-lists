//palindrome or not
#include<iostream>
using namespace std;
#include<stack>
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
bool check(node*head)
{
	stack<int>  s;
	node*temp=head;
	while(temp!=NULL)
	{
		s.push(temp->data);
		temp=temp->next;
	}
	temp=head;
	
	while(temp!=NULL)
	{
		 if(s.top() != temp->data)
		  return 0 ;
	    else if(s.top() == temp->data)
		{
		temp=temp->next;
    	s.pop();
        }
	}
	return 1;
	
	
	
}
int main()
{
	node *head=NULL;
	takeInput(head);
	print(head);
	if(check(head))
	{
		cout<<"Palindrome";
	}
	else
	cout<<"Not Palindrome";
}
