#include<iostream>
using namespace std;

class node{
public:
	int data;
	node* next;
public:
	node(int d){
		data = d;
		next = NULL;
	}
};
void print(node*head){
	node*temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

void insertAtHead(node*&head,int d){
	node* n = new node(d);
	n->next = head;
	head = n;
}
node* merge(node*a,node*b){
    node* newHead=NULL;
	if(a==NULL){
		return b;
	}
	else if(b==NULL){
		return a;
	}

	if(a->data > b->data){
		newHead = a;
		newHead->next = merge(a->next,b);
	}
	else{
		newHead = b;
		newHead->next = merge(a,b->next);
	}
	return newHead;
}


node* midPoint(node*head){
	node*slow = head;
	node*fast = head->next;

	while(fast!=NULL && fast->next!=NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
node* mergeSort(node*head){
	//Base Case
	if(head==NULL||head->next==NULL){
		return head;
	}

	//Recursive Case
	//1. Break the list
	node* mid = midPoint(head);
	node*a = head;
	node*b = mid->next;
	mid->next = NULL;

	//2. Recursive Sort
	a = mergeSort(a);
	b = mergeSort(b);

	//3. Merge

	return merge(a,b);
}
int kth_largest( node*head,int k)
{
	
    node*head2=NULL;
    head2=mergeSort(head);
    print(head2);
     
	node*temp=head2;
	int i=1;

	while(i<k)
	{
		temp=temp->next;
		i++;
		
	}
	return temp->data;
}
int main()
{
    int N;
    cin>>N;
    node *head=NULL;
    int i=1,d=0;
	while(i<=N)
    {
        cin>>d;
        insertAtHead(head,d);
        i++;
    }

    cout<<"\n";
    int k=4;
    int x=kth_largest(head,k);
    cout<<"\nkth largest element is: "<<x;
}
