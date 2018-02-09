#include<stdio.h>

#include<stdbool.h>

struct node{
int data;
struct node*next;
};

struct node*newNode(int data){
struct node*temp ;
temp=(struct node*)malloc(sizeof(struct node));
temp->data = data;
temp->next = NULL;
return temp;
}

void pushFront(struct node**head,int data){
struct node* first = newNode(data);

if(*head==NULL){
 *head = first;
}
else{
    first->next = (*head);
    *head = first;
    }
}

void print(struct node*head)
{
	printf("\nLinked list : ");
	struct node *temp=head;
	while(temp!=NULL)
	{
		printf("%d -> ",temp->data);
		temp=temp->next;
	}
	printf("NULL");
}

void swap(struct node **head)
{
	struct node*current=*head;
	struct node*n=current->next;
	struct node*prev=NULL;
	*head=n;
	while(current!=NULL && n!=NULL)
	{
		
		if(prev!=NULL)
		{
			prev->next=n;
		}
		
		current->next=n->next;
		n->next=current;
		prev=current;
		current=current->next;
		if(current!=NULL)
		{
			n=current->next;
		}
	}
	
}
int main(){
struct node*head1=NULL;
struct node*head2=NULL;
pushFront(&head1,1);
pushFront(&head1,2);
pushFront(&head1,4);
pushFront(&head1,3);
pushFront(&head1,5);
pushFront(&head1,7);
pushFront(&head1,6);
pushFront(&head1,8);
print(head1);
printf("After Swapping");
swap(&head1);
print(head1);
return 0;
}
