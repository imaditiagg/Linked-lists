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
bool isPresent (struct node *head, int data)
{
    struct node *t = head;
    while (t != NULL)
    {
        if (t->data == data)
            return 1;
        t = t->next;
    }
    return 0;
}
struct node* intersection(struct node*head1,struct node*head2)
{
	struct node*temp3=NULL;
	struct node*temp1=head1;

	
	while(temp1!=NULL)
	{
		
			if(isPresent(head2,temp1->data))
			{
				pushFront(&temp3,temp1->data);
				
			}
			
		temp1=temp1->next;
	}
	
	return temp3;
}
struct node *getUnion(struct node *head1, struct node *head2)
{
    struct node *result = NULL;
    struct node *t1 = head1, *t2 = head2;
 
    // Insert all elements of list1 to the result list
    while (t1 != NULL)
    {
        pushFront(&result, t1->data);
        t1 = t1->next;
    }
 
    // Insert those elements of list2 which are not
    // present in result list
    while (t2 != NULL)
    {
        if (!isPresent(result, t2->data))
            pushFront(&result, t2->data);
        t2 = t2->next;
    }
 
    return result;
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


print(head1);
pushFront(&head2,5);
pushFront(&head2,6);
pushFront(&head2,7);
pushFront(&head2,8);
pushFront(&head2,9);
pushFront(&head2,10);
pushFront(&head2,11);
print(head2);

struct node*head3=NULL;
head3=intersection(head1,head2);
printf("\nIntersection: ");
print(head3);
printf("\nUnion: ");
head3=getUnion(head1,head2);
print(head3);
return 0;
}
