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

void swap(node *p1, node*p2) //swap data
{
	int temp = p1->data;
	p1->data = p2->data;
	p2->data = temp;
}
void SelectionSort(node *&head)
{
	node *start = head;
	node *traverse;
	node *min;
	
	while(start->next) //no. of iterations
	{
		min = start;
		traverse = start->next;
		
		while(traverse)
		{
			/* Find minimum element */
			if( min->data > traverse->data )
			{
				min = traverse;
			}
			
			traverse = traverse->next;
		}
		swap(start,min);			// Put minimum element on starting location
		start = start->next;
	}
} 
int main()
{
	node*head=NULL;
	takeInput(head);
	SelectionSort(head);
	print(head);
	return 0;
}
	
