// Insertion
void push ()
{
int data;
struct node *pointer = (struct node*)malloc(sizeof(struct node));
if(pointer == NULL)
{
printf("Stack overflow");
}
else
{
printf("Enter the element to be inserted: ");
scanf("%d",&data);
if(temp == NULL)
{
pointer -> data = data;
pointer -> next = NULL;
temp = pointer;
}
else
{
pointer -> data = data;
pointer -> next = temp;
temp = pointer;
}
}
}


// Deletion
void pop()
{
int item;
struct node *pointer;
if (temp == NULL)
{
printf("Stack Underflow\n");
}
else
{
item = temp -> data;
pointer = temp;
temp = temp -> next;
free(pointer);
printf("The deleted item is %d\n",item);
}
}


//Display
void display()
{
int i;
struct node *pointer;
pointer = temp;
if(pointer == NULL)
{
printf("Stack underflow\n");
}
else
{
printf("The elements of the stack are:\n");
while(pointer!= NULL)
{
printf("%d\n",pointer -> data);
pointer = pointer -> next;
}
}
}
