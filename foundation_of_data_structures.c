//
//The length is fixed and known when we’re writing the code
//• If the length is variable,

Struct variable_array {
        int array[100];
        size_t count;
};
struct variable_array varray1;

//This is not a particularly helpful approach:
//• A maximum size must be decided on and is fixed.
//• It uses a lot of memory even for a short list.
//How to achieve better use of memory for storing variable
//amounts of items?


// LINKED LIST
//A linked list is a set of nodes, and each node stores an
//element (data) and a pointer that points to the next node
//of the list.

// Linked list is a collection of nodes that collectively form a linear
//sequence.

// Head: the pointer to the first node of a linked list.
// A linked list instance must keep a pointer to the first node of the list.
//• Without the head pointer, there would be no way to locate the first node.
//• The pointer of the last node is NULL.
//Linked

struct node {
    int value;
    struct node *next;
};

struct node *head; /* Initialize nodes */
head = (struct node *) malloc(sizeof(struct node)); /* Allocate memory */
head->value = 14; /* Assign data values */
head->next = (struct node *) malloc(sizeof(struct node));
head->next->value=92;
head->next->next = (struct node *) malloc(sizeof( struct node));
head->next->next->value=27;
head->next->next->next=NULL;


// MEMORY ALLOCATION

//void *malloc(size_t size)
//– allocate the requested memory and returns a pointer to it.
//– parameter size: the size of the memory block, in bytes.
//– return value: a pointer to the allocated memory, or
//NULL if the request fails.
int *str == (int*)malloc(n * sizeof(int));

// OPERATIONS OF A LINKED LIST

// Traverse the list
//• Add a new node to list
//– append, i.e., at the end
//– prepend, i.e., the beginning
//– insert, i.e. in between or to an empty list
//• Locate a node in list
//• Delete a node from list
//– From end
//– From beginning
//– From somewhere in between
//– From empty list
//• Search a node
//• Update a node

// Traverse list
// Traverse: Starting at the head, and moving from one node to another
//by following each node’s next pointer, until reaching the tail.

struct node *ptr = head;
ptr->value;
ptr = ptr->next;

void printList(struct node *head) {
    struct node *ptr = head;
    printf("\n[ ");
//start from the beginning
    while(ptr != NULL) {
        printf("%d, ", ptr->value);
        ptr = ptr->next;
    }
    printf("]");
}

// Add to empty list - step 1
struct node *head; /* Initialize nodes */
head=NULL;

struct node *new; // New node created
new = (struct node *) malloc (sizeof (struct node));
new->next = NULL;
new->value = 27;
head = new;

// Add to empty list - step 2
// New node created
new = (struct node *) malloc (sizeof (struct node));
new->next = NULL;
new->value = 27;
// Check if list empty. If so, put new node at beginning.
// Otherwise, put it either at beginning or end, depending on
// problem being solved.
if (head == NULL) head = new;

// Append - Step 1
struct node *new; // New node created
new = (struct node *) malloc (sizeof (struct node));
new->next = NULL;
new->value = 27;

// Append - Step 2
struct node *new; // New node created
new = (struct node *) malloc (sizeof (struct node));
new->next = NULL;
new->value = 27;
struct node* tail;
tail = head; // Find end of list
while ((tail->next) != NULL) tail = tail->next;

// Append - Step 3
struct node *new; // New node created
new = (struct node *) malloc (sizeof (struct node));
new->next = NULL;
new->value = 27;
struct node* tail;
tail = head; // Find end of list
while ((tail->next) != NULL) tail = tail->next;

// Append - Step 4
struct node *new; // New node created
new = (struct node *) malloc (sizeof (struct node));
new->next = NULL;
new->value = 27;
struct node* tail;
tail = head; // Find end of list
while ((tail->next) != NULL) tail = tail->next;
tail->next = new;

// Prepend– Step 1
struct node *new; // New node created
new = (struct node *) malloc (sizeof (struct node));
new->next = NULL;
new->value = 27;

// Prepend– Step 2
struct node *new; // New node created
new = (struct node *) malloc (sizeof (struct node));
new->next = NULL;
new->value = 27;
new->next = head;

// Prepend– Step 3
struct node *new; // New node created
new = (struct node *) malloc (sizeof (struct node));
new->next = NULL;
new->value = 27;
new->next = head;
head = new;

// Prepend (Insert the First Node)
//insert link at the first location
struct node* insertFirst(struct node *head, int data)
{
    //create a node with the new element
    struct node *new = (struct node*) malloc(sizeof(struct node));
    new>value = data;
    //point it to old first node
    new->next = head;
    //point first to new first node
    head = new;
    return head;
}

// Insertion at middle
//Insert 27 after the node 14. (index=2)
//• Allocate a new node containing the new value.
struct node *new = (struct node*) malloc(sizeof(struct node));
new->value = value;

// Allocate a new node containing the new value.
//• Find the node behind which the new node should be inserted,
//as the current node.
struct node *ptr = head;
    for (size_t i = 0; i < index-1; i++) {
        if (ptr!= NULL)
        ptr = ptr->next;
    }

// • Allocate a new node containing the new value.
//• Find the node behind which the new node should be inserted,
//as the current node.
//• Redirect the pointer of the new node to the node behind the
//current node.
new->next = ptr->next;

// Allocate a new node containing the new value.
//• Find the node behind which the new node should be inserted,
//as the current node.
//• Redirect the pointer of the new node to the node behind the
//current node.
//• Redirect the pointer of the current node to the new node.
ptr->next = new;


void insert_at(struct node *head, size_t index, int value) {
// Traverse the list until we get to the desired index.
    struct node *ptr = head;
    for (size_t i = 0; i < index-1; i++) {
        if (ptr!= NULL)
            ptr = ptr->next;
    }
// Construct a new node to splice into the list.
    struct node *new = (struct node*) malloc(sizeof(struct node));;
    new->value = value;
    new->next = ptr->next;
    ptr->next = new;
}

// Remove the first item
//delete the first item 14 and return the deleted item
struct node* deleteFirst(struct node *head) {
    //save reference to first link
    //delete first item and return the deleted item
    struct node *tempLink = head;
    //mark next to first link as first
    //delete first item and the deleted item
    head = head->next;
    //return the deleted link
    //delete first item and the deleted item
    return tempLink;
}
//delete first item and the deleted item
struct node* deleteFirst(struct node *head) {
//save reference to first link
    struct node *tempLink = head;
//mark next to first link as first
    if (head!= NULL)
        head = head->next;
//return the deleted link
    return tempLink;
}

// Removing a target node
prev->next = curr->next

// Locating an item
//• Need to know what to look for: value >, ==, or < some
//value; n-th node in list, etc.
//• Start at beginning of list, apply criteria, if condition met
//then we’re done, otherwise move to next node in list.
//• Pay attention to next pointer – if it NULL, then there are
//no more nodes to visit.
//• Locating a node is usually required before deleting a
//node.

void SearchList(struct node *head, int aValue)
{
    struct node *curr = head;
    struct node *prev = NULL;
    //Scan the list to find the item
    while (curr!= NULL && curr->value != aValue)
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL)
        // No item is found
        printf("\n no item is found \n");
    else if (curr == head) {
        head = curr->next;
        // Item is in the front
        printf("\n item is the first node \n");
    }
    prev->next = curr->next;
    // Item is in the middle of the list
    printf("\n item is found \n");
}

//• Lists that we have described are called “single linked
//lists”.
//• Single linked lists can only be traversed in one direction.
//• Double linked lists allow traversal in both directions.

// Doubly linked lists
//• Like a singly linked list, a doubly linked list is a
//sequential structure
//• An element can be reached by
//– starting from the head, and moving forward using next
//– Starting from the tail, and moving backward using prev

// Inserting a new node

prevNoide = curr->prev

newNode->prev = curr-> prev;
prevNode->next = newNode;
curr->prev = newNode;
newNode->next = curr;


// Removing a node
succNode->prev = prevNode;
prevNode-> next = succNode;


// Linear data structures
// The data element are visited sequentially where only a
//single element can be directly reached:
//• List
//– Linked List
//– Array-based List
//• Stack
//• Queue


// Dynamic arrays
How to dynamically determine the length of an array?
• int *nums = malloc(count * sizeof(int));
We can access the elements by index the same way we can with fixed-length arrays:
nums[i] = 5;
Note: nums[0] and *nums have the same meaning

// • What do we need to represent a variable-size list using
//a dynamically-allocated array?
//• The pointer to the data itself.
//• The capacity (i.e., the number of elements we allocated for).
//• The length (i.e., the number of elements currently in the list).
//– Manipulation algorithms often need to shift around
//whole sections of the array
struct list {
    int *data;
    size_t capacity;
    size_t length;
};


// Insertion
//• How do we insert an element?
//• Suppose we have an array-backed list with capacity 10
//and elements:
//3, 5, 9, -10, 0, 14.
//• We wish to insert 23 at position 2: 3, 5, 23, 9, -10, 0, 14.
//• The elements after the insertion points had to be shifted
//to the right.

for (i = n-1; i >= pos+1; i--)
    arr[i] = arr[i-1];
arr[pos] = 23; // insert x at pos

// How do we insert an element?
//• Rather than creating a custom for loop to shift the
//elements over, we can use a function from the
//standard library:
//• void *memmove(void *destination, const
//void *source, size_t num);
//• This function copies num bytes from source to
//destination, correctly handling cases where the two
//ranges overlap (like our case!).

// Inserts a number at a given index in a list.
// Returns false if it was not possible (i.e., list was too short).
bool insert_at(list *nums, size_t index, int num) {
    // Make sure index is valid.
    if (index > nums->length)
        return false;
    // Shift existing elements over.
    memmove(&nums->data[index + 1], &nums->data[index],
            (nums->length - index) * sizeof(int));
    // Insert new element.
    nums->data[index] = num;
    nums->length++;
    return true;
}
//What if there is not enough capacity?

// REALLOCATION
//• We need to change the size of our allocation, which
//could involve moving the data to a new location.
//There is a standard library function for that as well:
void *realloc(void *ptr, size_t size);
//This function changes the allocation size, either by
//expanding the allocation at the same location (if
//available) or moving all the data to a new location.
//45

// MEMORY ALLOCATION FUNCTIONS IN C
• void *realloc(void *ptr, size_t size)
– attempt to resize the memory block pointed to by ptr
that was previously allocated with a call to malloc or
calloc
– parameter ptr: the pointer to a memory block
previously allocated with malloc, calloc or realloc to
        be reallocated.
– parameter size: the size of the memory block, in
bytes.
– return value: a pointer to the allocated memory, or
NULL if the request fails.
46



// Inserts a number at a given index in a list.
// Returns false if it was not possible (i.e., list was too
short).
bool insert_at(list *nums, size_t index, int num) {
// Make sure index is valid.
    if (index > nums->length)
        return false;
// Make sure we have enough capacity.
    if (nums->length == nums->capacity) {
        nums->capacity *= 2;
        nums->data = realloc(nums->data, nums->capacity);
    }
// Shift existing elements over.
    memmove(&nums->data[index + 1], &nums->data[index], (nums-
                                                         >length - index) * sizeof(int));
// Insert new element.
    nums->data[index] = num;
    nums->length++;
    return true;
}


// REMOVE
// Removes the element at a given index in a list.
// Returns false if it was not possible (i.e., list was
too short).
bool insert_at(list *nums, size_t index, int num) {
// Make sure index is valid.
    if (index >= nums->length)
        return false;
// Decrement and shift remaining elements over.
    nums->length--;
    memmove(&nums->data[index], &nums->data[index + 1],
            (nums->length - index) * sizeof(int));
    return true;
}

// Removes the element at a given index in a list.
// Returns false if it was not possible (i.e., list was
too short).
bool insert_at(list *nums, size_t index, int num) {
// Make sure index is valid.
    if (index >= nums->length)
        return false;
// Decrement and shift remaining elements over.
    nums->length--;
    memmove(&nums->data[index], &nums->data[index + 1],
            (nums->length - index) * sizeof(int));
// Shrink capacity if warranted.
    if (nums->length * 4 <= nums->capacity) {
        nums->capacity /= 2;
        nums->data = realloc(nums->data, nums->capacity);
    }
    return true;
}
• void free( void *ptr)
– deallocates the memory previously allocated by a call to
        calloc, malloc, or realloc.
– ptr -- This is the pointer to a memory block previously
        allocated with malloc, calloc or realloc to be deallocated. If a
null pointer is passed as argument, no action occurs.

