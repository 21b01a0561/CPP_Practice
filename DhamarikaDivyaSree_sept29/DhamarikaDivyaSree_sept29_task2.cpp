//task-2

//8.4 For each of the following, write a single statement that performs the specified task. Assume that floating-point variables number1 and number2 have been declared and that number1 has been initialized to 7.3. Assume that variable ptr is of type char *. Assume that arrays s1 and s2 are each
100-element char arrays that are initialized with string literals.

//solution:

double number1=7.3;
double number2;
char *ptr;
char s1[100]="Hello";
char s2[100]="World";

//a) Declare the variable fPtr to be a pointer to an object of type double.

double *fPtr;

//b) Assign the address of variable number1 to pointer variable fPtr.

fPtr=&number1;

//c) Print the value of the object pointed to by fPtr.

std::cout << *fPtr << std::endl;

//d) Assign the value of the object pointed to by fPtr to variable number2.

number2=*fPtr;

//e) Print the value of number2.

std::cout << number2 << std::endl;

//f) Print the address of number1.

std::cout << &number1 << std::endl;

//g) Print the address stored in fPtr. Is the value printed the same as the address of number1?

std::cout << fPtr << std::endl;

