S)
//  Data Compression (Huffman Trees)
//  Bitcoin (Merkle Trees)
//  Medical Diagnosis (Decision Trees)

struct BinaryTreeNode* newNode(int data)
{
    struct BinaryTreeNode *node = (struct BinaryTreeNode
    *)malloc(sizeof( struct BinaryTreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
} // allocates a new node with the given data.


struct BinaryTreeNode *q, *r, *p, *s, *t, *root;
q=newNode(17);
r = newNode(-115);
q->right = r;
p= newNode(-33);
root= newNode(5);
root->left = p; root->right = q;
s= newNode(53);
t= newNode(91);
p->left = s; p->right = t;

// A tree can have more than 2 children
struct node {
    int data;
    struct node* child1;
    struct node* child2;
    struct node* child3;
}; //Structure of each node of the tree

struct BinaryTreeNode* newNode(int data)
{
    struct BinaryTreeNode *node = (struct BinaryTreeNode
    *)malloc(sizeof( struct BinaryTreeNode));
    node->data = data;
    node->child1 = NULL;
    node->child2 = NULL;
    node->child3 = NULL;
    return node;
}

struct BinaryTreeNode* newNode(int data)
{
    struct BinaryTreeNode *node = (struct
            BinaryTreeNode *)malloc(sizeof( struct
            BinaryTreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Simple Tree example
struct node {
    int data;
    struct node* left;
    struct node* right;
}; //Structure of each node of the tree

struct BinaryTreeNode* newNode(int data)
{
    struct BinaryTreeNode *node = (struct BinaryTreeNode
    *)malloc(sizeof( struct BinaryTreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
} // allocates a new node with the given data.

struct BinaryTreeNode* pRoot, temp
        pRoot= newNode(5);
temp=newNode(7);
pRoot->left=temp;
temp=newNote(-3);
pRoot->right=temp;

1. Process the nodes in the left
sub-tree.
2. Process the nodes in the right
sub-tree.
3. Process the current node.

preorderOutput(struct BinaryTreeNode *cur)
{
    if (cur=NULL) return; //If empty, return
    else {
        printf(“%d \n”,cur->data);
        preorderOutput(cur->left); //Process nodes in left subtree
        preorderOutput(cur->right); //Process nodes in left subtree
    }
}

preorderOutput(struct BinaryTreeNode *cur)
{
    if (cur=NULL) return; //If empty, return
    else {
        preorderOutput(cur->left); //Process nodes in left subtree
        printf(“%d \n”,cur->data);
        preorderOutput(cur->right); //Process nodes in left subtree
    }
}


preorderOutput(struct BinaryTreeNode *cur)
{
    if (cur=NULL) return; //If empty, return
    else {
        preorderOutput(cur->left); //Process nodes in left subtree
        preorderOutput(cur->right); //Process nodes in left subtree
        printf(“%d \n”,cur->data);
    }
}

//recursively process subtree

//Method 1 use function to print a given level
printLevelorder(tree)
for d = 1 to height(tree)+1
    printGivenLevel(tree, d);
/*Function to print all nodes at a
given level*/
printGivenLevel(tree, level)

1. Use a temp variable and a queue
2. Insert the root node into the
queue.
3. While the queue is not empty:
A. Dequeue the top node and put it in temp.
B. Process the node.
C. Enqueue the node’s children
to queue if they are not None.

// Letter order traversal
void LevelOrderTraversal (BinaryTreeNode *node) {
    Queue *queue;
    if (node != null)
        enqueue(node); //inserting the node in the queue
    while (!isEmpty()) //continue the iterative process until the queue is empty
    {
// dequeue a node, and output the value
        struct BinaryTreeNode *temp;
        dequeue(&temp);
        printf(“%d, “, temp->data);
        if (temp->left != null) //if a left child exists, insert it in the queue
            enqueue(temp->left);
        if (temp->right != null) // if a right child exists, insert it in the queue
            enqueue(temp->right);
    }
}


PreOrder(Node cur):
    if (cur == None)
    return
print(cur.value)
PostOrder(cur.left)
PostOrder(cur.right)


// What algorithm can print in alphabetical order


preorderOutput(struct BinaryTreeNode *cur)
{
    if (cur=NULL) return; //If empty, return
    else {
        preorderOutput(cur->left); //Process nodes in left subtree
        printf(“%d \n”,cur->data);
        preorderOutput(cur->right); //Process nodes in left subtree
    }
}

Output:
bill
danny
frank
jane
waa

//Searching a bst
int search(int V, BinaryTreeNode *ptr)
{
    while(ptr!= Null)
    {
        if(V == ptr->data)
            return 1; //find V
        else if(V < ptr->data)
            ptr = ptr->left; //search the left subtree
        else
            ptr = ptr->right; //search the right subtree
    }
    return 0 // not find
}

// Searching a BST
int search(BinaryTreeNode *ptr, int V)
{
    if(ptr==NULL)
        return 0; // not find
    if(V == ptr->data)
        return 1; //find
    else if(V < ptr->data)
        return search(ptr->left, V); //search the left subtree
    else
        return search(ptr->right,V); //search the right subtree
}

search(BinaryTreeNode *ptr, int V)
{
    if(ptr==NULL)
        return 0;
    if(V == ptr->data)
        return 1;
    else if(V < ptr->data)
        return search(ptr->left,V);
    else
        return search(ptr->right,V);
}

Main:
    bool bFnd
    bFnd = search(14,Root)


BinaryTreeNode * Insert(BinaryTreeNode *node, int V)
{
    // This creates a new node, stores value V
    struct BinaryTreeNode *temp=newNode(V);
    struct BinaryTreeNode *current;
    if (node==Null)
        return temp;
    else
        current = node;
    while (current!= NULL) {
        // Left or right subtree
        if(V >(current->data))
            if(current->right == Null)
                // Insert if has empty space
                current->right = temp;
            else
                // Otherwise move to right
                current = current->right;
        else if (V < (current->data))
            if (current->left == Null)
                // Insert if has empty space
                current-> = temp;
            else
                // Otherwise move to left
                current = current->left;
        return current;
    }
}



// Inserting a new value into a bst
BinaryTreeNode * Insert(BinaryTreeNode *node, int V)
{
    if(node==NULL)
    { BinaryTreeNode *temp=newNode(V);
        return temp;
    }
    if(V >(node->data))
        node->right = Insert(node->right, V);
    else if(V < (node->data))
        node->left = Insert(node->left, V);
    return node;
}



BinaryTreeNode * Delete(BinaryTreeNode *node, int data)
{
    BinaryTreeNode *temp;
    if(node==NULL)
        return NULL;
    // Case 1- Our target Node is a leaf
    else if(data < node->data)
        node->left = Delete(node->left, data);
    else if(data > node->data)
        node->right = Delete(node->right, data);
    // -
    else
    {
        /* Now We can delete this node and replace with either minimum element
        in the right sub tree or maximum element in the left subtree */
        if(node->right && node->left)
        {
            // Case 3 - Our target node has 2 children
            /* Here we will replace with minimum element in the right sub tree */
            temp = FindMin(node->right);
            node -> data = temp->data;
            /* As we replaced it with some other node, we have to delete that node */
            node -> right = Delete(node->right, temp->data);
            // -
        }
        else
        {
            /* If there is only one or zero children then we can directly
            remove it from the tree and connect its parent to its child */
            temp = node;
            // Case 2 - Target node has 1 child
            if(node->left == NULL)
                node = node->right;
            else if(node->right == NULL)
                node = node->left;
            free(temp); /* temp is no longer required */
            // -
        }
    }
    return node;
}


BinaryTreeNode*
FindMin(BinaryTreeNode *node)
{
    if(node==NULL)
    {return NULL }
    else if(node->left!=null )
        return FindMin(node->left);
    else
        return node;
}

BinaryTreeNode*
FindMax(BinaryTreeNode *node)
{
    if(node==NULL)
    {return NULL }
    else if(node->right!=null )
        return FindMax(node->right);
    else
        return node;
}

// Height of a node
int getHeight(struct BinaryTreeNode *t) {
    int heightLeft, heightRight, heightval;
    if (t == null)
        return heightval = 0;
    else {
        heightLeft = getHeight(t->left);
        heightRight = getHeight(t->right);
        heightval = 1 + ((heightLeft > heightRight) ?
                         heightLeft : heightRight); // max(height(X->left), height(X->right))+1
    }
    return heightval;
}


struct node {
    int data;
    int height;
    struct node* left;
    struct node* right;
}; //Structure of each node of the tree
