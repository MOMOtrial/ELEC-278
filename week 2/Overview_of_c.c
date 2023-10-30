#include <stdio.h>

//We declare a variable by writing its type followed by its
//name:
//• int total; // An integer variable named 'total’
//• char first_initial; // A character variable
//• int numbers[10]; // An array of 10 numbers

int j, k, m;
char p, q, r;
float f;
short int a = 5;
char b = ‘Z’;
float pi = 3.14159;
double abigname99 = -3.7e-4;

// Strings in C are stored in arrays of characters.
char str1[12] = "Hello";
char str2[12] = "World";
char str3[12];
strcpy(str3, str1);
strcat( str1, str2); //output Hello World

//Arrays are sets of identical data items:
int g[100] – 100 integers, g[0] to g[99]
char s[50] – 50 chars, s[0] to s[49]
int sin[9];
int date_of_birth[8];
int date_of_death[8];

// STRUCT
// A user-defined data type
// used to group items of possibly different types into a
// single type.
// Syntax of struct:
struct structure_name {
    data_type member_name1;
    int member_name2;
    //....
};
// The items in the structure are called its member
struct tax_info {
    int sin[9];
    int date_of_birth[8];
    int date_of_death[8];
    int marital_status;
};

// Method 1: If structure_name has been created,
struct structure_name variable_name;
struct structure_name variable_name1, variable_name2;
// Example
struct tax_info my_tax_info;
struct tax_info Alice_tax_info, Bob_tax_info;

// Declare struct Variables
// Method 2: Create structure_name and declare variables.
struct structure_name {
    data_type member_name1;
    data_type member_name2;
    ....
}variables;
struct tax_info {
    int sin[9];
    int date_of_birth[8];
    int date_of_death[8];
    int marital_status;
} Alice_tax_info, Bob_tax_info, Carlos_family_tax[5];
// Carlos_family_tax[5] is a struct tax_info array of size 5.

//Assign values to structure members
// Curly brackets ‘{}’: initialize all the members
Struct tax_info Evetax= {{1,2,3,4,5,6,7,8,9},
             {1,9,9,8,0,3,1,3},
             {2,0,2,2,1,1,1,4}, 5};
struct Student{
    char name[50];
    int class;
    char section;
};

struct Student student1={“Alice" ,1,'A'};
//Access structure members
//Dot ‘.’ : Member operator
//Alice_tax_info.sin[9]={1,2,3,4,5,6,7,8,9};
//Bob_tax_info. marital_status=4;
struct Student {
    char name[50];
    int class;
    char section;
}student1;
strcpy(student1.name,“Alice");
student1.class = 1;
student1.section = 'A';


// ----------------
#include <stdio.h>
#include
// Define Data type
struct student {
    int id;
    char name[20];
    float percentage;
};
int main(){
    // Declare structure variable
    struct student record;
    // Assign values to structure members
    record.id = 1;
    strcpy(record.name, "Michael");
    record.percentage = 86.7;
    // Access structure members
    printf("Id is: %d\n", record.id);
    printf("Name is: %s\n", record.name);
    priontf("Percentage is: %f\n", record.percentage);
    return 0;
}

// Typedef: To create an alias name for data types.
// Used with structures to simplify the syntax of declaring variables
struct Student {
    char name[50];
    int class;
    char section;
};
Main(){
    Struct Student s1,s2;
}
//-->
typedef struct Student {
    char name[50];
    int class;
    char section;
}Students;
Main(){
    Students s1,s2;
}
struct Student {
    char name[50];
    int class;
    char section;
}Students;

// -------------
#include <stdio.h>
#include <string.h>
// Create structure student and an alias name for structure student
typedef struct student
{ int id;
    char name[20];
    float percentage;
}Students
int main()
{
    // Declare structure variable
    Students record;
    record.id = 1;
    strcpy(record.name, "Raju");
    record.percentage = 86.5;
    printf(" Id is: %d \n", record.id);
    printf(" Name is: %s \n", record.name);
    printf(" Percentage is: %f \n", record.percentage);
    return 0;
}

// ---------

struct tax_info {
    int sin[9];
    int date_of_birth[8];
    int date_of_death[8];
    int marital_status;
}
// -->
typedef char digit;
struct tax_info {
    digit sin[9];
    digit date_of_birth[8];
    digit date_of_death[8];
    int marital_status;
};


// NESTED STRUCTURES
struct complex {
    int imag;
    float real;
};
struct number {
    struct complex comp;
    int integers;
} num1, num2;

// To assign values to members:
num2.comp.imag = 11;
num2.integers=22

// Enmumeration (Enum)
// Enumerated Type Declaration: enum flag variable1;
// An enum variable can take only one value.
#include <stdio.h>
enum week {Sunday, Monday, Tuesday, Wednesday, Thursday,
            Friday, Saturday};
int main() {
    // creating today variable of enum week type today;
    enum week today;
    today = Wednesday;
    printf("Day %d",today+1);
    return 0;
}
// -----------
#include <stdio.h>
enum DAY
{
    MON=1, TUE, WED, THU, FRI, SAT, SUN
} day;
int main()
{
// traverse all elements in DAY
    for (day = MON; day <= SUN; day++) {
        printf(“enum values：%d\n", day);
    }
}

// NESTED STRUCTURE
typedef char digit;
enum maritage {
    MARRIED = 1,
    COMMON_LAW = 2,
    WIDOWED = 3,
    DIVORCED = 4,
    SEPARATED = 5,
    SINGLE = 6,
};
struct numeric_date {
    digit year[4];
    digit month[2];
    digit day[2];
};
struct tax_info {
    digit sin[9];
    struct numeric_date date_of_birth; // Always a valid date.
    struct numeric_date date_of_death; // Always a valid date, or all zeros if empty.
    enum maritage marital_status; // Always a valid enum value.
} my_tax_info;

// POINTERS
• Pointers: a variable that stores the memory address of another
variable as its value.
• Pointer Declaration:
    – int* p; //declared a pointer P of int type.
    – int *p1; //declared a pointer P1 of int type.
    – int* p3, p4; // declared a pointer p1 and a normal variable p2.
• Assigning addresses to Pointers
    int* pc, c;
    c = 5;
    pc = &c;

// Dereferencing a pointer is the process of accessing the value stored
// in the memory address specified in the pointer.
int main()
{ int var = 10;
    int* ptr; //declare pointer variable
    ptr = &var; //assign variable address to a pointer
    printf("Value at ptr = %p \n", ptr);
    printf("Value at var = %d \n", var);
    printf("Value at *ptr = %d \n", *ptr);
    return 0;
}
// ------------
#include <stdio.h>
void swap(int* a, int* b)
{ int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{ int a = 10, b = 20;
    printf("Values before swap:%d,%d\n", a, b);
    swap(&a, &b);
    printf("Values after swap:%d,%d", a, b);
    return 0;
}
//Integer pointers: int *ptr;
//Array pointers: char *ptr = &array_name;
//The array_name is the pointer to its first element.
int main()
{
    int arr[5] = { 1, 2, 3, 4, 5 };
    int* ptr_arr = &arr; // defining the pointer to array
    // traversing array using pointer arithmetic
    for (int i = 0; i < 5; i++) {
        printf("%d ", *ptr_arr++);
    }
    return 0;
}
//----------

//Integer Pointers: int *ptr;
//• Array Pointers: char *ptr = &array_name;
//– The array_name is the pointer to its first element.
//• Function Pointers: point to the function.
//– int (*ptr)(int, char); for int func (int, char)

#include <stdio.h>
void fun(int a)
{ printf("Value of a is %d\n", a);
}
int main()
{
    void (*fun_ptr)(int) = &fun; // a pointer to function fun()
//void (*fun_ptr)(int); fun_ptr = &fun;
    (*fun_ptr)(10); //Invoking fun() using fun_ptr
    return 0;
}

//----
//Integer Pointers: int *ptr;
//• Array Pointers: char *ptr = &array_name;
//– The array_name is the pointer to its first element.
//• Function Pointers: point to the function.
//– int (*ptr)(int, char); for int func (int, char)
//• Double Pointers: datatype ** pointer_name;
int var;
int *ptr1;
int **ptr2;
ptr1 = &var;
*ptr1 = 10;
ptr2 = &ptr1;
**ppj = 20;
//Integer Pointers: int *ptr;
//• Array Pointers: char *ptr = &array_name;
//– The array_name is the pointer to its first element.
//• Function Pointers: point to the function.
//– int (*ptr)(int, char); for int func (int, char)
//• Double Pointers: datatype ** pointer_name;
//• Structure Pointers

//Create pointers to struct: struct followed by structure name to which
//the pointer will point to followed by pointer name.
struct structure_name *structure_pointer;
//To initialize a structure variable, provide the address of the
//structure variable
structure_pointer = &structure_variable;
//The structure pointer can be initialized during declaration.
struct structure_type *structure_pointer = &structure_variable;

struct student{
    char name[10];
    int roll;
    int marks;
};
int main() {
    struct student Student1;
    struct student *ptr;
    ptr=&Student1;
}
// ---
Access the Structure Member Using Pointer
• 1. Using asterisk (*) and dot (.) operator
#include<stdio.h>
struct Coordinate {
    // declare structure members
    int x,y;
};
int main() {
    struct Coordinate first_point;
    struct Coordinate *cp;
    cp = &first_point;
    (*cp).x = 5;
    (*cp).y = 10;
    printf("First coordinate (x, y) = (%d, %d)", (*cp).x, (*cp).y);
    return 0;
}


• cp is a pointer that points to the
structure variable first_point
• *cp and first_point are
functionally identical

//--
Access the Structure Member Using Pointer
• 2. Using the arrow operator: pointer_name->member_name
#include<stdio.h>
struct Student {
    char name[30];
    int age;
    int roll_number;
};
int main() {
    struct Student student_1;
    struct Student *sp = &student_1;
    scanf ("%s", sp->name);
    scanf ("%d", &sp->age);
    scanf ("%d", &sp->roll_number);
    printf ("\tName: %s\n", sp->name);
    printf ("\tAge: %d\n", sp->age);
    printf ("\tRoll Number: %d", sp->roll_number);
    return 0;
}


• sp is a pointer that points to the
structure variable student_1
• xp-> members zaccess the
structure member

//--
Method 1: Pass the structure to a function by address.
• The structure can be accessed from called function by its address.
#include <stdio.h>
struct student {
    char name[50];
    int roll;
    float marks;
};
void display(struct student* st_obj) // struct student* st_obj=&st1；
{
    printf("Name: %s\n", st_obj->name);
    printf("Roll: %d\n", st_obj->roll);
    printf("Marks: %f\n", st_obj->marks);
}
int main()
{
    struct student st1={"Aman", 19, 8.5 };
    display(&st1); // Function call by reference
    return 0;
}
//--
Method 2: Pass the structure to a function by value.
• The structure can be accessed from called function by its value.
#include <stdio.h>
struct student {
    char name[50];
    int roll;
    float marks;
};
void display(struct student st_obj)
{
    printf("Name: %s\n", st_obj.name);
    printf("Roll: %d\n", st_obj.roll);
    printf("Marks: %f\n", st_obj.marks);
}
int main()
{
    struct student st1 = {"Aman", 19, 8.5};
    display(st1);
    return 0;
}

• Struct: Create Structure, Declare Variables, Assign Values, Access
Members
• Typedef: Create Alias Name
• Structure Pointers: Pointers, Pointer Types, Function Calls
• Enumeration: Create Enumeration, Declare Variables, Assign
Values, Access Enums
Homework:
• Unions: https://www.programiz.com/c-programming/c-unions
• File I/O: https://www.programiz.com/c-programming/c-file-input-
output
