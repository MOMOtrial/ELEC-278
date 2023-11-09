// Algorithem analysis >>>>> linked listed

//--------------------- LEARN THIS
// Average running times
// Worst-Case running Times
// Best-Case running times
// Asymptotic Upper Bound - Big Oh

Insert at head          Insert immediately O(1)
Delete at head          Delete immediately O(1)
Insert at end           Transverse from the head to find the tail O(n)
Delete at end           Transverse from the head to find the tail O(n)
Insert particular       Transverse to find the place to insert O(n)
Delete at middle        Transverse to find the middle place O(n)


Axiom 1
• The time required to fetch an integer operand from
memory is a constant, T fetch, and the time required to
store an integer result in memory is a constant, T store.
• Example:
y=x
y=1
Running time: T fetch +T store



Axiom 2
• The times required to perform elementary operations on
integers, such as addition, subtraction, multiplication,
division, and comparison, are all constants. These are
denoted as T +, T−, T ×, T ÷, and T <.
• y=y+1; running time: 2T fetch + T + + T store
• How about y++; y+=1, ++y?


Axiom 3
• The time required to call a function is a constant, Tcall,
and the time to return from a function is a constant,
Treturn.

Axiom 4
• The time required to pass an integer argument to a
function is the same as the time required to store an
integer in memory, T store.
• y=f(x)
running time: T fetch + 2T store + T call + T f(x)
where T f(x) is the running time of function f(x) for input x.

Axiom 5
• The time required for the address calculation implied by
an array subscripting operation, e.g. a[i], is a constant,
T [.] . This time does not include the time to compute the
subscript expression, nor does it include the time to
access (i.e. fetch or store) the array element.
• y = a[i]
running time: 3T fetch + T store + T [.]

Axiom 6
• The time required to allocate a memory space is a
constant, τ new. This time doesn’t include any time taken
to initialize the variables.
