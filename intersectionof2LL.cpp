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
void intersection(node *head1,node *head2)
{
	stack<node*> s1,s2;
	//push the elements of both the linked list in stack
	for(node *h1=head1;h1!=NULL;h1=h1->next)
	{
		s1.push(h1);
	}
	for(node *h2=head2;h2!=NULL;h2=h2->next)
	{
		s2.push(h2);
	}
	node*n=NULL;
	//pop until stacks will be having different nodes at the top
	while(!s1.empty()&& !s2.empty() && s1.top()== s2.top())
	{
		n=s1.top();
		s1.pop();
		s2.pop();
	}
	if(n!=NULL)
	{
	cout<<"\nNode is "<<n<<" And Data is :"<<n->data; //intersection pt.
}
else
cout<<"\nNo intersection";


	
}
int main()
{
	node *head1=NULL,*head2=NULL;
	cout<<"Enter list 1 : ";
	takeInput(head1);
	cout<<"Enter list 2 : ";
	takeInput(head2);
	head2->next->next = head1->next; //making intersection at a point
	print(head1);
	cout<<"\n";
	print(head2);
	intersection(head1,head2);
	return 0;
}
