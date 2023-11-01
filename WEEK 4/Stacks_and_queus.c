// Stacks and Queues

//• Stacks
//– Array version
//– Linked-list version
//– Applications
//• Queues
//– Linked-list version
//– Array version
//– Deques

// only the last item added to the stack can be accessed or removed
// When an item is added, it goes to the top of the stack.
// The only item that can be removed is the item at the top of the stack

push(item) // puts an item on the top of the stack
item = pop() // retrieves the top item from the stack


// Push number 13 on the stack.
Push(4)
Push(7)
Push(13) // 13 at top

// Pop the item from the stack
Push(4)
Push(7)
Push(13)
Pop()  // 13 doesn't get removed but it becomes unavailable since stack pointer is "below it"

Push(4)
Push(7)
Push(13)
Pop()
Push(8) // where the stack is stored 13 is overwritten by 8

// Last-in First-out
Applications of LIFO:
• Reverse a word. You push a given word to stack -
letter by letter - and then pop letters from the stack.
• Internet Web browsers store the addresses of recently visited sites in a stack.
• Undo function.

int top = -1;
int stack [100];
void push (int n)
{
    stack[++top] = n;
}
int pop (void)
{
    return stack[top--];
}

• This creates stack that puts first element in stack[0], next one in stack[1], etc.

int top = -1;
int stack [100];
int push (int n)
{
    if (top == 99) return 0;
    stack[++top] = n;
    return 1;
}
int pop (int *value)
{
    if (top == -1) return 0;
    *value = stack[top--];
    return 1;
}

int main (void)
{
    // %2d allow an integer at least two digits long
    int i, value;
    for (i=0; i<5; i++)
    {
        push (20+i);
    }
    while (pop (&value))
    { printf (" %2d", value);
        putchar ('\n’);
    }
    return 0;
}
//int putchar(int char) writes a
//character (an unsigned char)
//specified by the argument char to stdout.

int main (void)
{
    int i, value;
    int *pi;
    for (i=0; i<5; i++) { push (20+i); }
    while (pop (&value)) {
        printf (" %2d", value);
        putchar ('\n’);
    }
    for (i=0; i<5; i++) { push (100+i); }
    while (pop (&value)) {
        printf (" %2d", value);
        if (tos (&pi))
            *pi = *pi +50;
    }
    putchar ('\n');
    return 0;
}
//*tos()-allows access to top
//item on stack
//
//int tos(int **ptop)
//{
//    if (top == -1) return 0;
//    *ptop= &stack[top];
//    return 1;
//}

1) Insert new data at the tail of the LinkedList
-> Pop means remove the tail from the LinkedList

2) Insert new data at the head of the LinkedList
-> Pop means remove the head from the LinkedList

// Implementing stack using linked list

//Map required functions onto what we already have:
//push(item) – same as insertFirst(item) for a linked list
//item = pop() – same as item=deleteFirst() for a linked
//list

typedef struct _stk_node {
    struct _stk_node *next;
    int nodval;
} StkNode;

StkNode *head = NULL;

void push (int n)
{
    StkNode *p = malloc(sizeof(StkNode));
    p->nodval = n;
    p->next = head;
    head = p;
}
int pop (void)
{
    StkNode *p = head;
    int rslt = p->nodval;
    head = p->next;
    free (p); //discard node
    return rslt;
}




typedef struct _stk_node {
    struct _stk_node *next;
    int nodval;
} StkNode;
StkNode *head = NULL;
StkNode *head2 = NULL;
void push (StkNode *stkHead, int n)
{
    StkNode *p = malloc(sizeof(StkNode));
    p->nodval = n;
    p->next = stkHead;
    *this = p;
}
int pop (StkNode *stkHead)
{
    StkNode *p = stkHead;
    int rslt = p->nodval;
    stk = p->next;
    return rslt;
}
// *tos()-allows access to top item
//on stack
int *tos (StkNode *stkHead)
{
    return &(stkHead->nodval);
}

// Brace matching using stack

1. Push if it is an opening grouping symbol.
2. Pop if it is a closing grouping symbol.
3. If popped symbol doesn’t match with
the closing grouping symbol, or nothing
to match, or left non-empty stack,
return False.

int areBracketsBalanced(char exp[])
{
    int i = 0;
    struct sNode* stack = NULL;
    while (exp[i]) {
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
            push(exp[i]);
        if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') {
            if (stack == NULL)
                return 0;
            else if (!isMatchingPair(pop( ), exp[i]))
                return 0;
        }
        i++; }
    if (stack == NULL)
        return 1; // balanced
    else
        return 0; // not balanced
}
// Returns 1 if chara1 and chara2 are
//matching left and right Brackets
int isMatchingPair(char chara1, char chara2)
{
    if (chara1 == '(' && chara2 == ')')
        return 1;
    else if (chara1 == '{' && chara2 == '}')
        return 1;
    else if (chara1 == '[' && chara2 == ']')
        return 1;
    else
        return 0;
}

// Convert Infix to Prefix/Postfix
A + B * C -> B and C are
multiplied first, and A is then added
to that result.

(A + B) * C -> “()” forces the
addition of A and B to be done first
before the multiplication.

1. Scan left to right, use a stack to
keep the operators.
2. The top of the stack will always be
the most recently saved operator.
3. Whenever we read a new operator,
we will need to consider how that
operator compares in precedence
with the operators, if any, already
on the stack.

// Infix-to-Postfix Conversion
Infix-to-Postfix Conversion
1. Create an empty stack opstack for keeping operators. Create an empty list for
output.
2. Scan the token list from left to right.
– If the token is an operand, append it to the end of the output list.
– If the token is a left parenthesis, push it on the opstack.
– If the token is a right parenthesis, pop the opstack until the corresponding left
        parenthesis is removed. Append each operator to the end of the output list.
– If the token is an operator, *, /, +, or -, push it on the opstack. However, first
        remove any operators already on the opstack that have higher or equal
        precedence and append them to the output list.
3. When the input expression has been completely processed, check the opstack.
Any operators still on the stack can be removed and appended to the end of the
output list

• Implement evaluating postfix expressions by handling
– +, -, *, /
– the operands are only one-digit numbers
– Read the numbers from the keyboard

1 printf("Enter an RPN expression: ");
2 for( ; ; ) {
3 scanf(" %1c", &ch);
4
5 if (ch >= '0' && ch <= '9')
6 push((int) ch - '0');
7 else if ( ch == '+')
8 push(pop() + pop());
9 else if ( ch == '-')
10 substract();
11 else if ( ch == '*')
12 push(pop() * pop());
13 else if ( ch == '/')
14 divide();
15 else
16 break;
17 }
18
19 if (ch == '=') {
20 value = pop();
21 } else {
22 /* Quit - neither an operator nor a digit operand */
23 break;
24 }
25 }

void subtract(void)
{
    int right = pop();
    int left = pop();
    push(left – right);
}

void divide(void)
{
    int divisor = pop();
    int dividend = pop();
    push(dividend / divisor);
}


// Queue
• A linear data structure that is open at both ends and the
operations are performed in First In First Out (FIFO) order.
• All additions to the list are made at one end.
• All deletions from the list are made at the other end.
• A line waiting to purchase tickets, where the first person in
line is the first person served.

• Front (Head) : The first item that can be removed from the
        queue.
• End (Tail): The position of the last item in the queue, that
        is, the one most recently added.


• Need a pointer to the end so that new nodes can be
added quickly
• Need a pointer to the front so that nodes can be removed
quickly
• Empty list – both pointers are NULL
• Could also have an integer count to make check faster.

// Empty queue
• Need a pointer to the end so that new nodes can be
added quickly
• Need a pointer to the front so that nodes can be removed
quickly
• Empty list – both pointers are NULL
• Could also have an integer count to make check faster.
bool isEmpty (void)
{
    return (count == 0);
}




struct item {
    struct item *next;
    int value;
}
struct item *front, *end;
int count = 0;

bool isEmpty(void)
{
    return (count == 0);
}

void enqueue (int n)
{
    struct item *pnew = malloc (sizeof(struct
            item));
    pnew -> value = n;
    pnew -> next = NULL;
// update current end node (if there is one)
    if (end != NULL)
        end -> next = pnew;
    end = pnew;
// if queue was empty, new node is also front
    node
    if (front == NULL)
        front = pnew;
    count++;
}

int dequeue (int *n)
{
    struct item *temp = front;
    n = &(front->value);
    front = front->next;
    free (temp);
    count--;
}
int dequeue ()
{
    struct item *temp = front;
    int n = front->value;
    front = front->next;
    free (temp);
    count--;
    return n;
}




struct item {
    struct item *next;
    int value;
}
struct item *front = NULL, *end = NULL;
int count = 0;

void enqueue (int n)
{
    struct item *pnew = malloc (sizeof(struct item));
    pnew -> value = n;
    pnew -> next = NULL;
// update current end node (if there is one)
    if (end != NULL)
        end -> next = pnew;
    end = pnew;
// if queue was empty, new node is also front node
    if (front == NULL)
        front = pnew;
    count++;
}

bool isEmpty(void)
{
    return (count == 0);
}
bool dequeue (int *n)
{
    struct item *temp = front;
    if (count == 0) return false;
    *n = front->value;
    front = front->next;
    free (temp);
    count--;
    return true;
}

// Implement queue with array
• Need to know front and end positions
int front = -1, end = -1;
• Need to know how many int count = 0;
• Need to know if empty (count==0)
• Need to know if full (count==MAX_SIZE)
• Need to handle wrap-around.

• To have the indices head and tail cycle within the bounds of
the array, we use the % operator
• Each insertion or deletion, increment the index by 1, and
        assign it a new value module the array size
• When the indices move past the end of the array, their values
        are reset to the start of the array
• Move front forward:
– front= (front + 1) % array_size
• Move end forward:
– end = (end + 1)% array_size

#define MAX_SIZE 10
int q [MAX_SIZE];
int count = 0,
        front = -1,
        end = -1;
bool isEmpty(void)
{
    return (count == 0);
}
bool isFull(void)
{
    return (count==MAX_SIZE);
}
bool enqueue (int n)
{
// already full?
    if (isFull()) return false;
// add to end of queue
    end = (end + 1) % MAX_SIZE;
    q[end] = n;
    return true;
}

bool enqueue(int n)
{
// already full?
    if (isFull()) return false;
// add to end of queue
    end = (end + 1) % MAX_SIZE;
    q[end] = n;
    count++;
// was this first add?
    if (front == -1) front = end;
    return true;
}

bool dequeue (int *n)
{
// empty?
    if (isEmpty()) return false;
// remove from front of queue
    *n = q[front];
    front= (front + 1) % MAX_SIZE;
    count--;
// did we just empty the queue?
    if (isEmpty()) front=end= -1;
    return true;
}
void enqueueHead (int n)
{
    struct item *pnew = malloc
            (sizeof(struct item));
    pnew -> value = n;
    pnew -> next = NULL;
// update current front node (if there is
    one)
    if (front != NULL)
        pnew->next= front;
    front = pnew;
// if queue was empty, new node is
    also end node
    if (end == NULL)
        end = pnew;
    count++;
}
void enqueueTail (int n)
{
    struct item *pnew = malloc
            (sizeof(struct item));
    pnew -> value = n;
    pnew -> next = NULL;
// update current end node (if there
    is one)
    if (end != NULL)
        end -> next = pnew;
    end = pnew;
// if queue was empty, new node is
    also front node
    if (front == NULL)
        front = pnew;
    count++;
}
bool dequeueHead (int *n)
{
    struct item *temp = front;
    if (count == 0) return false;
    *n = front->value;
    front = front->next;
    free (temp);
    count--;
    return true;
}
bool dequeueTail (int *n)
{
    struct item *temp = tail;
    if (count == 0) return false;
    *n = tail->value;
    tail->next=NULL;
    free (temp);
    count--;
    return true;
}
