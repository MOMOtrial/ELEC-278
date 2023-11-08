// Inserts a number at a given index in a list.
// Returns false if it was not possible (i.e., list was too short).
bool insert_at(list *nums, size_t index, int num) {
// Traverse the list until we get to the desired index.
    for (size_t i = 0; i < index; i++) {
        if (*nums == NULL)
            return false;
        nums = &(*nums)->tail;
    }
// Construct a new node to splice into the list.
    struct list_node *new_node = malloc(sizeof(struct list_node));
    new_node->value = num;
// 'nums' now points to the 'tail' slot where we need to insert the node.
    new_node->tail = *nums;
    *nums = new_node;
    return true;
}


//---------- Recusion function



// Program to find the factorial of a number n
int factorial (int n)
{
    int temp;
    if (n == 0) temp = 1;
    else {
        temp = n * factorial (n-1);
    }
    return temp;
} //factorial()
int ans;
void main (void)
{
    int x = 2;
    ans = factorial (x);
} //main()




// fibonacci recursive
int fibonacci (int n) {
    int temp:
    if (n == 0) return 0;
    if (n == 1) return 1;
    temp = fibonacci(n-1) + fibonacci(n-2);
    return temp;
}




// Squaring
Algorithm Power(x, n):
Input: A number x and integer n = 0
Output: The value x n
if n = 0 then
    return 1
if n is odd then
    y = Power(x, (n - 1)/ 2)
    return x · y ·y
else
    y = Power(x, n/ 2)
    return y · y
