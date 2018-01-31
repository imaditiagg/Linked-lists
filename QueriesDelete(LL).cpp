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
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
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

node* deleteQ(node *head,int k)
{
node *temp=head;
if(k==0)
{
    head=head->next;
    delete temp;
}
int i=1;
while(i<k)
{
    temp=temp->next;
    i++;
}
temp->next=temp->next->next;

return head;

}





int main()
{
    int N,Q;
    cin>>N;
    cin>>Q;
    node *head=NULL;
    int i=1,d=0;
	while(i<=N)
    {
        cin>>d;
        insertatTail(head,d);
        i++;
    }


    int count=1,query[Q];
    while(count<=Q)
    {
        cin>>query[count];
        count++;
    }

    count=1;
    while(count<=Q)
    {
        head=deleteQ(head,query[count]);
        print(head);
        count++;
    }



return 0;
}
