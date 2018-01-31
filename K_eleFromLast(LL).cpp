#include<iostream>
#include<stack>
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
	while(head!=NULL){
		cout<<head->data<<"-->";
		head = head->next;
	}
}

void insertatTail(node*&head,int d)
{
    node *n=new node(d);
    if(head==NULL)
        head=n;
    else{
    node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
    }
}

void takeInput(node*&head){
	int d;
	cin>>d;
	while(d!= -1)
    {

    insertatTail(head,d);
    cin>>d;
	}
}

int Kth_element_from_last(node* head,int k)
{
    node* firstptr=head;
    node* secondptr=head;
    int i=1;
    while(i<=k)
    {
        firstptr=firstptr->next;
        i++;
    }

    while(firstptr!=NULL)
    {

        firstptr=firstptr->next;
        secondptr=secondptr->next;

    }

    return secondptr->data;
}


int main()
{
    node*head=NULL;
    takeInput(head);
   //print(head);
    int k;
    cin>>k;
    cout<<Kth_element_from_last(head,k);
    return 0;
}









