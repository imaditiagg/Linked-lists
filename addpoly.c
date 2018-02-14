#include<stdio.h>
struct node
{
int coeff;
int pow;
struct node *next;
};

struct node*newNode(int coeff,int exp)
{
struct node*temp;
temp=(struct node*)malloc(sizeof(struct node));
temp->coeff=coeff;
temp->pow=exp;
temp->next = NULL;
return temp;
}

void pushFront(struct node**head,int coeff,int exp)
{
struct node* first = newNode(coeff,exp);
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
	printf("\nRepresentation of polynomial in the form of Linked list : ");
	struct node *temp=head;
	while(temp!=NULL)
	{
		printf("%dx^%d-->",temp->coeff,temp->pow);
		temp=temp->next;
	}
	printf("NULL");
}

void polyadd(struct node *poly1, struct node *poly2, struct node *poly)
{
while(poly1->next && poly2->next)
    {
        // If power of 1st polynomial is greater then 2nd, then store 1st as it is
        // and move its pointer
        if(poly1->pow > poly2->pow)
        {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
         
        // If power of 2nd polynomial is greater then 1st, then store 2nd as it is
        // and move its pointer
        else if(poly1->pow < poly2->pow)
        {
            poly->pow = poly2->pow;
            poly->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
         
        // If power of both polynomial numbers is same then add their coefficients
        else
        {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff+poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
         
        // Dynamically create new node
        poly->next = (struct node *)malloc(sizeof(struct node));
        poly = poly->next;
        poly->next = NULL;
    }
while(poly1->next || poly2->next)
    {
        if(poly1->next)
        {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        if(poly2->next)
        {
            poly->pow = poly2->pow;
            poly->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        poly->next = (struct node *)malloc(sizeof(struct node));
        poly = poly->next;
        poly->next = NULL;
    }
}
int main()
{
struct node *head1=NULL;
struct node *head2=NULL;

printf("Insertion in 1st");
pushFront(&head1,0,0);
pushFront(&head1,1,1);
pushFront(&head1,2,2);
pushFront(&head1,3,3);
print(head1);
printf("\nInsertion in 2nd");
pushFront(&head2,0,0);
pushFront(&head2,1,1);
pushFront(&head2,2,2);
pushFront(&head2,3,3);
print(head2);
struct node *head3;
head3 = (struct node *)malloc(sizeof(struct node));
printf("\n\nAfter addition:- ");
polyadd(head1,head2,head3);
print(head3);

return 0;
}
