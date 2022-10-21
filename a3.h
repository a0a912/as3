#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;


//Question 1:
// PARAM: arr is array to print the Cartesian product of, n is size of arr
int cartesianProduct(int arr[], int n)
{
       int i = 0; // 1
       int ops = 1; //initializes cost for the first statements
       while (i < n) { //n
              int j = 0; //n
              while (j < n) { //n^2 + 1 more // Also barometer operation
                     cout << "{" << arr[i] << "," << arr[j] << "}"; //n^2
                     j++;   //n^2
                     cout << " "; //n^2
                     
                     ops += 5;
              }

              cout << endl; //n
              i++; //n
              ops += 5;
       }
       
       return ops;
}

//Total Cost (worst case) = 4n^2 + 6n + 3   
//O notation (worst case) = O(n^2)
//Barometer =  while (j < n)

/* My Notes:
Nothing too complicated here. It's a simple O(n^2) function. Just gotta count up each of the lines and add as needed. Best case should either be O(1) when an array is size 0, or O(n^2) since it has to go through and print every element no matter what

*/

//Question 2:



//This function prints a triangle of numbers (which doesn't look very pretty if the numbers have more than one digit).
//1+ 2*[4n+1] + 2n*[n+1] 
// 1 + 8n + 2 + 2n^2 + 2n = 2n^2 + 10n + 3
int triangle(int x)
{
       int i = 0;// 1
       int ops = 1;
       while (i < x) { //n*4 + 1 more 
              int j = 0; //n
              ops += 2;
              while (j <= i) { // n*(n+1)
                     cout << j << " "; //n^2 
                     j++; //n^2
                     //n^2+n
                     ops += 3;
              }
              cout << endl; //n
              i++; //n              
              ops+= 3;
       }
        ops+= 1;
       while (i > 0) { //n + 1 more
              i--; //n
              int j = 0; //n
               ops+= 3;
              while (j <= i) { //n^2 + 1
                     cout << j << " "; //n^2
                     j++; //n^2
                      ops+= 3;
              }
              cout << endl; //n
               ops+= 3;
       }
       ops+= 1; //When While (i > 0) is false
       return ops;
}


//Total Cost (worst case) = 2n^2 + 10n + 3
//O notation (worst case) = O(n^2)
//Barometer =  while (j <= i)

// Correction
// Inner j loop executes i times for each value of i. So in total it executes 1 + 2+ ....x times. This is equivalent to the sum of first n natural numbers given by the formula [n*(n+1)]/2.  Since there are two statements inside it, this becomes n*(n+1). 

/* My Notes:
I noticed this function is symmetrical. (while i < x) has a (while i > x) that goes the other way. So it is possible to add up the Cost of one half and then double it to get the total cost.

One thing to note is the (while j<= i). It's not a straightforward n^2 as I thought earlier but a n^2/2 + n/2. But seeing as each while has 3 entries, I can multiply by 3 to ease up calculations.


Best case would either be 0 assuming 0 for x or it would O(n^2) just like the worst case because it's going through and printing every element.

*/


//Question 3

//This function returns a vector which contains the contents of its input array with any duplicates removed.

// PARAM: arr is array from which duplicates are to be removed, n is size of arr
vector<int> removeDuplicates(int arr[], int n, int &ops )
{
       vector<int> result; //1
       int i = 0; //1
       ops = 2;
       while (i < n) { //n + 1 more
              int iResult = 0; //n
              bool duplicate = false; //n             
              ops += 3;
              while (iResult < (int)result.size() && !duplicate) { //note 4 //n^2             
                    ops += 1;
                     if (arr[i] == result[iResult]) { //n^2
                           duplicate = true; //n^2
                            ops += 1;
                     }
                
                     iResult++; //n^2
                      ops += 2;
              }

              if (!duplicate) { //n
                     result.push_back(arr[i]); //note 4 //n
                      ops += 1;
              }

              i++; //n
              ops += 2;
       }
       return result;// doesn't count
}
/*
1, 2, 3, 4
0, 1, 2, 3
ir = 1,2,3*

//Inner while loop: depends on location of duplicate elements
i=0 ; inner_loop = 0
i=1 ; inner_loop = 1
i=2 ; inner_loop = 2
i=n-1 ; inner_loop = n-1 times
total number of runs when there is no duplicate = 0+ 1 + ...n 
= [n-1(n)]/2

try with  n = 4 and array as 1,2,3,3*/
/*
Notes

    The function should be modified to include an integer reference parameter the value of which should be set to the operation count
    Answer questions B, C and D of the General Requirements for both the worst-case and best-case running times of the function, and
    Describe, and give examples of input that constitutes the best and worst case for the algorithm
    The size and push_back methods of a vector run in constant time, therefore lines that include calls to these methods still only count as a single operation as per rule 1
*/


//Total Cost(worse case) = 4n^2 + 6n + 3 (e.g it needs to check every element if it's a duplicate or not. if it isn't, it then needs to push it into the result vector) Best Case:  4n^2 + 4n + 2  (e.g if there were no duplicates or only duplicates since then it would only have to do one set of instructions)
//O notation = O(n^2) for worst case. O(n^2) for best case
//Barometer =  while (iResult < (int)result.size() && !duplicate) 

/* My Notes:
I'm confused were the if (!duplicate) should be categorized. Or how much should be different from best or worst case since either way it's doing something of roughly equal value wheter arr[i] is a duplicate or not.

*/

// Returns the index of a 1d array representing a matrix
// given row (r) and column (c) values
int rcIndex(int r, int c, int columns)
{
       return r * columns + c;
}

//This is just here to work better with Q4 and not give an error.

/*
Question 4

This function returns an array in dynamic memory that represents the matrix that is the result of multiplying the matrix (array) parameter by itself.
*/
// PRE: m represents a square matrix of size rows * rows
// PARAM: rows represents the number of both rows and columns
// POST: Returns a pointer to an array (matrix) of the same size as m
// NOTE: values are indexed r0c0,r0c1,…,r0cn-1,r1c0,…
int* matrixSelfMultiply(int* m, int rows,  int & ops)
{
       // Create result array
       int columns = rows; //1
       int* result = new int[rows * columns]; //1
       int r = 0; //1
        ops = 3;
       while (r < rows) { //n + 1 more
              int c = 0; //n
              
              ops += 2;
              while (c < columns) { //columns = rows //m*n + 1 more
                     int next = 0; //m*n
                     int iNext = 0; //m*n
                     
                        ops += 2;

                     while (iNext < rows) { //mn^2  + 1 more
                           next += m[rcIndex(r, iNext, columns)] * m[rcIndex(iNext, c, columns)]; //n^3
                           iNext++; //n^3
                           
                              ops += 2;
                     }

                     result[rcIndex(r, c, columns)] = next; //n^2
                     c++; //n^2
                        ops += 4;
              }
              r++; //n
                 ops += 1;
       }
       return result;
}

/*
Notes

    The function should be modified to include an integer reference parameter the value of which should be set to the operation count
    The input size is the number of rows of the matrix
    Lines that include call(s) to the rcIndex function (which has a constant time complexity) still only count as a single operation as per rule 1
*/


//Total Cost (worst case) = 3n^3+ 5n^2 + 3n + 6
//O notation (worst case) = O(n^3)
//Barometer =    while (iNext < rows)

/* My Notes:
Another "go through every element and print/do something" type function. Only with 3 layers of nested while loops bumping it up to O(n^3)

*/

/*
Question 5

This function is a recursive version of selection sort.
*/
// PARAM: arr is array to be sorted, n is size of array, i should initially = 0
int ssort(int arr[], int n, int i)
{
        int ops = 0;
       if (i < n-1) { //(n-1)
              // Find and swap smallest remaining
              int next = i + 1; //(n-1)
              int smallest = i; //(n-1)
              ops += 2;
              //n-1 + n-2 + ... 1 
              while (next < n) { //n^2
                     if (arr[next] < arr[smallest]) { //n^2
                          smallest = next; //n^2
                          ops+=1;
                     }
                     next++; //n^2
                     ops += 3;
              }

              // Swap i with smallest
              int temp = arr[i]; //(n-1)
              arr[i] = arr[smallest]; //(n-1)
              arr[smallest] = temp; //(n-1)
              ssort(arr, n, i + 1); //(n-1)
              ops += 4;
       }
       
       ops+= 1;
       return ops;
}
/*
Notes

    Answer questions B, C and D of the General Requirements for the best-case running time of the function
    Answer questions C and D (not B) for the worst-case running time of the function
    Describe, and give an example of input that constitutes the best and worst case for the algorithm
    Do not count the actual call to a recursive function as an operation – that is you must include the number of operations performed by the recursive call as per rule 2, but the call itself does not count as an operation
*/


//Total Cost (best case) = 2n^2 + 3n - 3 
//O notation(best case) = O(1)
//O notation(worst case) = O(n^2)
//Barometer =    while (next < n) 

//Question 6

//This function prints a pattern.

// PRE: n is a power of 2 greater than zero.
// PRE: Initial call should be to i = 0
// e.g. pattern(8, 0)
int pattern(int n, int i)
{
    int ops = 0;
       if (n > 0) { //n
              pattern(n/2, i);// doesn't count
              // Print i spaces
              cout << string(i, ' '); // NOTE: counts as ONE operation //n
               
              // A loop to print n asterisks, each one followed by a space
              int ast = 0; //n
               ops += 2;
              while (ast < n) { //n^2 + 1 more
                     cout << "* "; //n^2
                     ast++;  //n^2
                      ops += 2;
              }
                 ops += 1;
              cout << endl; //n
              i += n;  //n
              pattern(n / 2, i); //doesn't count
               ops += 2;
       }
       ops += 1;
       return ops;
}
/*
Notes

    Note the cost of printing the spaces stated in a comment
    Do not count the actual call to a recursive function as an operation – that is you must include the number of operations performed by the recursive call as per rule 2, but the call itself does not count as an operation
*/


//Total Cost (worst case) = 3n^2 + 5n + 1
//O notation (worst case) = O(n^2)
//Barometer =   while (ast < n) { 
/*
int main(){
int test[10];
test[0] = 1;
test[1] = 5;
test[2] = 3;
test[3] = 1;
test[4] = 3;
test[5] = 9;
test[6] = 98;
test[7] = 980;
test[7] = 920;
int ops;
int n = 4;
vector<int> returna = removeDuplicates(test, n, ops);
cout << ops << endl;
}
*/
/*

In this assignment you are to analyze the running times of six functions. 

Please read the requirements carefully, paying attention to the names and input and output requirements of the class and its methods. We will be testing your class in our test program, so if you do not follow the requirements the test program will not compile, and will not be marked. As usual refer to the General Requirements page.
Requirements

For each of the functions described in questions 1 to 6 you are to:

    Modify the function to count the number of operations performed when the function executes. Some questions will specify whether this is for the worst or best case. See the section on counting operations below for more detail.
    Determine a detailed cost function for the function. This function should be written in the form wnx + yn + z where w, x, y and z are real numbers and n is a variable referring to the size of the function's input. If necessary, you should adapt this format to include other terms such as log2(n).
    Identify (one of) the barometer operations for the function.
    Identify the O notation running time of the function.

Questions 3 and 5 have additional or different requirements. There is a detailed example after the sixth question.
Counting Operations

If the function's return type is void it should be modified to return the count of its operations. Otherwise, if the function already has a return value, the count should be assigned to an integer reference parameter. This reference parameter should always be the last parameter in the function's parameter list. When counting operations follow these rules - make sure you read them carefully (and follow them).

    An executable statement (a line of code that ends in a semi-colon) or a comparison counts as one operation regardless of its complexity – see exceptions 2 and 5. Therefore, the statement x = 4; counts as a single operation as does the statement int w = x + y + z;.
    Exception to 1 – if a statement includes a function call that does not run in constant time its operation count should be the number of operations performed by that function call. This only applies to questions 5 and 6.
    Note to 1 and 2 – statements that include the output operator (<<) follow rule 1 not rule 2. That is, an output statement that uses cout counts as a single operation regardless of its complexity. If it also includes unrelated function calls then rule 2 applies.
    The execution of an if statement or while loop comparison counts as one operation. Make sure that you count comparisons that result in false as well as true – so don't forget to include the terminating comparison for while loops. Note that there are no for loops in any of the functions as this allowed me to simplify these instructions somewhat.
    Return statements should not be included in the operation count.

Question 1

This function prints the Cartesian product of its input array with itself.

// PARAM: arr is array to print the Cartesian product of, n is size of arr
void cartesianProduct(int arr[], int n)
{
       int i = 0;
       while (i < n) {
              int j = 0;
              while (j < n) {
                     cout << "{" << arr[i] << "," << arr[j] << "}";
                     j++;  
                     cout << " ";
              }

              cout << endl;
              i++;
       }
}

Notes

    The function should be modified to return the operation count as an integer

Question 2

This function prints a triangle of numbers (which doesn't look very pretty if the numbers have more than one digit).

void triangle(int x)
{
       int i = 0;
       while (i < x) {
              int j = 0;
              while (j <= i) {
                     cout << j << " ";
                     j++;
              }

              cout << endl;
              i++;
       }

       while (i > 0) {
              i--;
              int j = 0;
              while (j <= i) {
                     cout << j << " ";
                     j++;
              }
              cout << endl;
       }
}

Notes

    The function should be modified to return the operation count as an integer

Question 3

This function returns a vector which contains the contents of its input array with any duplicates removed.

// PARAM: arr is array from which duplicates are to be removed, n is size of arr
vector<int> removeDuplicates(int arr[], int n)
{
       vector<int> result;
       int i = 0;
       while (i < n) {
              int iResult = 0;
              bool duplicate = false;

              while (iResult < (int)result.size() && !duplicate) { //note 4
                     if (arr[i] == result[iResult]) {
                           duplicate = true;
                     }

                     iResult++;
              }

              if (!duplicate) {
                     result.push_back(arr[i]); //note 4
              }

              i++;
       }
       return result;
}

Notes

    The function should be modified to include an integer reference parameter the value of which should be set to the operation count
    Answer questions B, C and D of the General Requirements for both the worst-case and best-case running times of the function, and
    Describe, and give examples of input that constitutes the best and worst case for the algorithm
    The size and push_back methods of a vector run in constant time, therefore lines that include calls to these methods still only count as a single operation as per rule 1

Question 4

This function returns an array in dynamic memory that represents the matrix that is the result of multiplying the matrix (array) parameter by itself.

// PRE: m represents a square matrix of size rows * rows
// PARAM: rows represents the number of both rows and columns
// POST: Returns a pointer to an array (matrix) of the same size as m
// NOTE: values are indexed r0c0,r0c1,…,r0cn-1,r1c0,…
int* matrixSelfMultiply(int* m, int rows)
{
       // Create result array
       int columns = rows;
       int* result = new int[rows * columns];
       int r = 0;

       while (r < rows) {
              int c = 0;
              while (c < columns) { //columns = rows
                     int next = 0;
                     int iNext = 0;

                     while (iNext < rows) {
                           next += m[rcIndex(r, iNext, columns)] * m[rcIndex(iNext, c, columns)];
                           iNext++;
                     }

                     result[rcIndex(r, c, columns)] = next;
                     c++;
              }
              r++;
       }
       return result;
}

// Returns the index of a 1d array representing a matrix
// given row (r) and column (c) values
int rcIndex(int r, int c, int columns)
{
       return r * columns + c;
}

Notes

    The function should be modified to include an integer reference parameter the value of which should be set to the operation count
    The input size is the number of rows of the matrix
    Lines that include call(s) to the rcIndex function (which has a constant time complexity) still only count as a single operation as per rule 1

Question 5

This function is a recursive version of selection sort.

// PARAM: arr is array to be sorted, n is size of array, i should initially = 0
void ssort(int arr[], int n, int i)
{
       if (i < n-1) {
              // Find and swap smallest remaining
              int next = i + 1;
              int smallest = i;

              while (next < n) {
                     if (arr[next] < arr[smallest]) {
                          smallest = next;
                     }
                     next++;
              }

              // Swap i with smallest
              int temp = arr[i];
              arr[i] = arr[smallest];
              arr[smallest] = temp;
              ssort(arr, n, i + 1);
       }
}

Notes

    Answer questions B, C and D of the General Requirements for the best-case running time of the function
    Answer questions C and D (not B) for the worst-case running time of the function
    Describe, and give an example of input that constitutes the best and worst case for the algorithm
    Do not count the actual call to a recursive function as an operation – that is you must include the number of operations performed by the recursive call as per rule 2, but the call itself does not count as an operation

Question 6

This function prints a pattern.

// PRE: n is a power of 2 greater than zero.
// PRE: Initial call should be to i = 0
// e.g. pattern(8, 0)
void pattern(int n, int i)
{
       if (n > 0) {
              pattern(n/2, i);
              // Print i spaces
              cout << string(i, ' '); // NOTE: counts as ONE operation

              // A loop to print n asterisks, each one followed by a space
              int ast = 0;
              while (ast < n) {
                     cout << "* ";
                     ast++;
              }

              cout << endl;
              i += n;
              pattern(n / 2, i);
       }
}

Notes

    Note the cost of printing the spaces stated in a comment
    Do not count the actual call to a recursive function as an operation – that is you must include the number of operations performed by the recursive call as per rule 2, but the call itself does not count as an operation

Example

This function computes the sum of squares of its array parameter.

int sumSquares(int arr[], int n)
{
       int i = 0;
       int sum = 0;
       while (i < n) {
              sum += arr[i] * arr[i];
              i++;
       }

       return sum;
}

The function returns an integer (the sum of the squares of its integer array parameter) so an integer reference parameter will be used to access the operations count. The amended function is shown below and would be the answer to part A.

int sumSquares(int arr[], int n, int & ops)
{
       int i = 0;
       int sum = 0;
       ops = 2; //initializes cost for the first two statements
       while (i < n) {
              sum += arr[i] * arr[i]; //counts as one operation – rule 1
              i++;
              ops += 3; //while comparison and above two lines
       }
       ops++; //terminating while comparison
       return sum; //not included in count – rule 5
}

Note that the while comparison is executed once for each time the loop body is executed (so its count is inside the loop) and once when the comparison is false and the loop ends (the count for which is outside the loop).

The cost function for this function is t(sumSquares) = 3n + 3, which would be the answer to part B. The loop runs n times, performing 3 operations in each iteration. The function performs three operations outside the loop. Note that your cost function should match the number of operations counted – and that this is quite simple to test.

void sumSquareTest()
{
       cout << "SUM OF SQUARES TEST" << endl;
       int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
       int n = 10;
       int cost = 0;
       cout << "sum of squares = " << sumSquares(arr, n, cost);
       cout << endl << "cost = " << cost;
       cout << endl << "t(sumSquares): 3n+3 = " << 3 * n + 3;
       cout << endl << "--------------" << endl << endl;
}

I would strongly recommend writing similar tests to the above, but they should not be included in your submission.

The function's barometer operation is the while loop comparison, the assignment to sum or the increment of the loop control variable (i). That is, one of the two operations inside the loop or the loop control statement. Stating any (or all) of these operations would be acceptable as the answer to part C.

The function's O notation running time is O(n), which would be the answer to part D.


*/


