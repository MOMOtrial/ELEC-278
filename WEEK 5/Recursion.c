tdlib.h>
// Recursion

// A function which calls itself:
//int test() {
//    return test();
//}


unsigned int test(unsigned int x) {
    if (x == 0)
        return 1;
    else
        return x * test(x - 1);
}

int main() {
    test(2);
}


//The nth element of the Fibonacci sequence is fn = fn−1 + fn−2,
//where f0 = 0 and f1 = 1.
//This naturally gives a recursive function:
unsigned int fibonacci(unsigned int n) {
    if (n < 2)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

//Can we define an efficient way to compute an exponent using
//        recursion?
//To compute an, if n is even, we can do (an/2)2; if n is odd, we can
//do a(a(n−1)/2)2.
//Since (unsigned) integer division rounds down in C, we can do it this
//way:
int rec_pow(int a, unsigned int n) {
    if (n == 0)
        return 1;
    int y = rec_pow(a, n / 2);
    y *= y;
    if (n % 2 == 1)
        y *= a;
    return y;
}

//We defined singly linked lists in C like this:
typedef struct list_node *list;

struct list_node {
    int value;
    list tail;
};

// Observe that:
//A list is a pointer to a node.
//A node contains a list.
//This is recursive!


// Computes the sum of a list of numbers.
int sum(list nums) {
    int result = 0;
    while (nums != NULL) {
        result += nums->value;
        nums = nums->tail;
    }
    return result;
}

// recursive version
// Computes the sum of a list of numbers.
int sum(list nums) {
    return nums == NULL
           ? 0
           : nums->value + sum(nums->tail);
}

// Iterative version of indexing
// Gets the element at index 'n', storing it in '*out'.
// Returns false if the list is too short.
bool get_at(list nums, size_t n, int *out) {
// Traverse the list until we get to the desired
// index.
    for (size_t i = 0; i < index; i++) {
        if (nums == NULL)
            return false;
        nums = nums->tail;
    }
// Make sure the node there exists.
    if (nums == NULL)
        return false;
// Extract the value.
    *out = nums->value;
    return true;
}

// recursive version
// Gets the element at index 'n', storing it in '*out'.
// Returns false if the list is too short.
bool get_at(list nums, size_t n, int *out) {
    if (nums == NULL)
        return false;
    if (n == 0) {
        *out = nums->value;
        return true;
    }
    return get_at(nums->tail, n - 1, out);
}

//If p is a pointer, ∗p is the value it points to
//If ∗p = y for some y, then we can write p = &y
//A null pointer is denoted ε

//Now, let a list be a pointer which is either null or refers to a node
//x : l, where x is a value and l is another list.
//This is still recursive!
//Now, an example list would be written & (5 : & (7 : & (3 : ε)))
//An iterator is a pointer to a list, i = &l


// Iterative version
// Advances an iterator until it reaches the target.
iterator find(iterator i, int y) {
// Loop which exists when it reaches the end.
    for (; *i != NULL; i = &(*i)->tail) {
// Exit if the current node has the target value.
        if ((*i)->value == y)
            break;
    }
// We either found the target or reached the end.
    return i;
}

// recursive version
// Advances an iterator until it reaches the target.
iterator find(iterator i, int y) {
    return *i == NULL || (*i)->value == y
           ? i
           : find(&(*i)->tail, y);
}


// Given an iterator i, how would we remove all values less than y that
//occur after i?
//If ∗i = ε, do nothing.
//If ∗i = & (x : l), then:
//1 Let p := &l.
//2 Remove all values less than y after p.
//3 If x < y, then free the memory block at ∗i and set ∗i := p.


// Removes all values less than 'y'.
void filter_lt(iterator i, int y) {
    if (*i != NULL) {
        list p = (*i)->tail;
        filter_lt(&p, y);
        if ((*i)->value < y) {
            free(*i);
            *i = p;
        }
    }
}

// -----------
Today’s lecture included the following example of a recursive algorithm to
        filter out numbers less than a threshold y from a singly-linked list beginning at
an iterator i:
• If ∗i = , do nothing.
• If ∗i = & (x : l), then:
1. Let p := &l.
2. Remove all values less than y after p.
3. If x < y, then free the memory block at ∗i and set ∗i := p.
This was followed by a proposed implementation of the algorithm in C:
// Removes all values less than 'y'.
void filter_lt(iterator i, int y) {
    if (*i != NULL) {
        list p = (*i)->tail;
        filter_lt(&p, y);
        if ((*i)->value < y) {
            free(*i);
            *i = p;
        }
    }
}
It was rightfully pointed out to me after lecture that there is a bug in each
of these, which shows up slightly differently. In the case of the algorithm spec-
ification, the issue is that p is a pointer to l, which is one of the fields of the
        object pointed to by ∗i, and yet we use p after freeing the block at ∗i; this is
a use-after free bug! In the C code, the issue is that the recursive call is on
&p, but the value of p is only used after that if the current element is removed,
meaning that in other cases the tail field of the node is not correctly updated.
I admit it is embarrassing to have a bug on the slide in which I noted that this
“functional” style of programming, as opposed to the conventional imperative
approach, is a good method for avoiding bugs. . . but at the same time, I contend
1
that the bugs only happened in the part of the algorithm which was imperative!
So, as part of putting together a corrected version, I wanted to show how you
        could make this algorithm even less imperative and more functional, and use
that approach to help make sure that it is correct.
In its simplest form, the idea of functional programming is to, wherever you
        can, compute a new value rather than mutating an old one. This helps you avoid
the types of bugs we see here, such as use-after-free or issues where the wrong
version of a value is used because a variable is read or written at the wrong time.
In this case, we can think of this as computing a new list from an old list, even
if the pointer value of the new list is the same as the old one. Unfortunately,
needing to manually manage the memory (and the fact that we’re being asked
        to modify the list) means that we can’t eliminate all imperative components
        from the algorithm, but this is a good start.
First, let’s start with an algorithm specification at a higher level, ignoring
pointers; assume l is the list, in the earlier notation, and y is the threshold:
• If l = , the result is .
• If l = x : l′, then:
1. Let l′′ be the result of removing all elements less than y from l′.
2. If x < y, the result is l′′, otherwise it is x : l′′.
This specification is purely functional and describes the intended effect on
        the list at a conceptual level. We can convert this algorithm specification to be
at the level of iterators and pointers, with the same interface as our earlier one,
        by saying that, given an iterator i, the initial list comes from ∗i and the result
should likewise be stored in ∗i. Here is the new algorithm specification which
        results:
• If ∗i = , do nothing (or, equivalently, set ∗i := ).
• If ∗i = & (x : l), taking x and l to be local variables independent of ∗i,
then:
1. Remove all values less than y after &l.
2. If x < y, then free the memory block at ∗i and set ∗i := l.
3. If x ≥ y, then set ∗∗i := x : l.
Even though this is nearly identical to our earlier version, by thinking explic-
itly about where data is coming from and where it is going to, in line with the
purely functional version, we can avoid the earlier bugs. Here is the resulting
implementation:
// Removes all values less than 'y'.
void filter_lt(iterator i, int y) {
    if (*i != NULL) {
        list l = (*i)->tail;
        2
        filter_lt(&l, y);
        if ((*i)->value < y) {
            free(*i);
            *i = l;
        }
        else
            (*i)->tail = l;
    }
}
I also mentioned in lecture that there are some programming languages which
are designed entirely around this idea, rather than around imperative program-
ming and mutating objects. One such language is Haskell. In case you are
curious, here is what the equivalent algorithm would look like in Haskell (as a
        function which takes in a list of integers and an integer, and returns a list of
integers, as in the purely functional specification from above):
filter_lt :: [Int] -> Int -> [Int]
filter_lt [] _ = []
filter_lt (x : l) y =
let l' = filter_lt l y
in if x < y
        then l'
else x : l'
Again, as a reminder: none of the symbolic notation or fun facts about other
programming languages here are content that you will be assessed on in this
        course. However, I hope the examples and discussion help you to understand
the actual course content, which in the case of today’s lecture is how to write
algorithms which use recursion on data structures.

