
/*
1)Mr. Ram is developing a software application to manage his
inventory, which initially can hold a maximum of ten product
packets. He allocates memory for ten packets at the start.
However, as the market demand changes, he needs to
dynamically update the allocated memory to store more or fewer
packets without wasting memory or running out of space. Explain
the concept of dynamic memory allocation and how Mr. Ram can
effectively manage his inventory size using this concept.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
} Packet;

void printInventory(Packet* inventory, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        printf("Packet ID: %d, Name: %s\n", inventory[i].id, inventory[i].name);
    }
}

int main() {
    size_t capacity = 10; 
    size_t size = 0;     

    Packet* inventory = (Packet*)malloc(capacity * sizeof(Packet));
    if (inventory == NULL) {
        perror("Failed to allocate memory");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < 5; ++i) {
        if (size == capacity) {
            capacity *= 2; // Double the capacity
            Packet* new_inventory = (Packet*)realloc(inventory, capacity * sizeof(Packet));
            if (new_inventory == NULL) {
                perror("Failed to reallocate memory");
                free(inventory);
                return EXIT_FAILURE;
            }
            inventory = new_inventory;
        }
        inventory[size].id = i + 1;
        snprintf(inventory[size].name, sizeof(inventory[size].name), "Packet %d", i + 1);
        ++size;
    }

    printf("Current Inventory:\n");
    printInventory(inventory, size);
    if (size > 0) {
        --size; // Reduce the size
    }

    printf("\nUpdated Inventory:\n");
    printInventory(inventory, size);
    free(inventory);

    return EXIT_SUCCESS;
}

/*
2)Mr. John is playing the game Subway Surfers. The game has a
total of five treasures with different weights, that he needs to
collect. Write a C program to count the total number of weights
he collected from the treasures during the game.
*/

#include <stdio.h>

int main() {
    int weights[5];
    int totalWeight = 0;
    printf("Enter the weights of the 5 treasures:\n");
    for (int i = 0; i < 5; i++) {
        printf("Weight %d: ", i + 1);
        scanf("%d", &weights[i]);
    }

    for (int i = 0; i < 5; i++) {
        totalWeight += weights[i];
    }
    printf("The total weight of the treasures collected is: %d\n", totalWeight);

    return 0;
}

/*
3)Consider an object Shape that encompasses both a Square and a
Rectangle as the data members. The Square object should have an
attribute for its area, while the Rectangle object should have
attributes for length and breadth. Identify the most suitable data
structures for this scenario and write a C program to define the
structure and demonstrate their usage.
*/

#include <stdio.h>
typedef struct {
    float area; // Attribute for the area of the square
} Square;

typedef struct {
    float length;
    float breadth;
} Rectangle;
typedef struct {
    Square square;
    Rectangle rectangle;
} Shape;

void calculateSquareArea(Square *sq, float side) {
    sq->area = side * side;
}

float calculateRectangleArea(Rectangle *rect) {
    return rect->length * rect->breadth;
}
void displaySquare(Square *sq) {
    printf("Square Area: %.2f\n", sq->area);
}
void displayRectangle(Rectangle *rect) {
    printf("Rectangle Length: %.2f\n", rect->length);
    printf("Rectangle Breadth: %.2f\n", rect->breadth);
    printf("Rectangle Area: %.2f\n", calculateRectangleArea(rect));
}
int main() {
    Shape shape;
    float side = 5.0;
    calculateSquareArea(&shape.square, side);
    shape.rectangle.length = 4.0;
    shape.rectangle.breadth = 6.0;
    printf("Shape Details:\n");
    displaySquare(&shape.square);
    displayRectangle(&shape.rectangle);
    
    return 0;
}


/*
4)In a classroom, the teacher wants to create a list of students who
have submitted their assignments. As students submit their work,
the teacher needs to add each student&#39;s name to the list in the
order of submission. Help the teacher by guiding them on how to
use a proper data structure to insert each student&#39;s name into the
list as they submit their assignment. Write a C program that uses
an array to manage the list and demonstrates how to insert new
student names into the array.
*/

#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100  
#define NAME_LENGTH 50      
void addStudent(char students[][NAME_LENGTH], int *count, const char *name);
void displayStudents(const char students[][NAME_LENGTH], int count);

int main() {
    char students[MAX_STUDENTS][NAME_LENGTH]; 
    int studentCount = 0; 

    int choice;
    char name[NAME_LENGTH];

    while (1) {
        printf("\nStudent Assignment Submission System\n");
        printf("1. Add student\n");
        printf("2. Display all students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                if (studentCount < MAX_STUDENTS) {
                    printf("Enter student name: ");
                    fgets(name, NAME_LENGTH, stdin);
                    name[strcspn(name, "\n")] = '\0';
                    addStudent(students, &studentCount, name);
                } else {
                    printf("The list is full. Cannot add more students.\n");
                }
                break;
            case 2:
                displayStudents(students, studentCount);
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
void addStudent(char students[][NAME_LENGTH], int *count, const char *name) {
    strcpy(students[*count], name);
    (*count)++;
    printf("Student '%s' added successfully.\n", name);
}
void displayStudents(const char students[][NAME_LENGTH], int count) {
    if (count == 0) {
        printf("No students have submitted their assignments yet.\n");
    } else {
        printf("List of students who have submitted their assignments:\n");
        for (int i = 0; i < count; i++) {
            printf("%d. %s\n", i + 1, students[i]);
        }
    }
}


/*
5)Students need to check the availability of a book in the library
based on its ID. Create an ordered list which will contain only
book id. Implement a C program to search whether a particular
book is available in the list or not.
*/

#include <stdio.h>
int binarySearch(int arr[], int size, int target);

int main() {
    int bookIDs[] = {101, 105, 108, 112, 115, 120, 125}; 
    int size = sizeof(bookIDs) / sizeof(bookIDs[0]);
    int targetID;
    int result;
    printf("List of Book IDs (sorted):\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", bookIDs[i]);
    }
    printf("\n");
    printf("Enter the book ID to check availability: ");
    scanf("%d", &targetID);
    result = binarySearch(bookIDs, size, targetID);
    if (result != -1) {
        printf("Book ID %d is available in the library.\n", targetID);
    } else {
        printf("Book ID %d is not available in the library.\n", targetID);
    }

    return 0;
}
int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid; 
        } else if (arr[mid] < target) {
            low = mid + 1; 
        } else {
            high = mid - 1; 
        }
    }

    return -1; // Return -1 if the target is not found
}

/*
6)A = B =
Write a C program to perform Matrix addition for the above two
matrices.
*/

int main() {
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rows, cols;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    printf("Enter elements of matrix A:\n");
    inputMatrix(A, rows, cols);
    printf("Enter elements of matrix B:\n");
    inputMatrix(B, rows, cols);

    addMatrices(A, B, result, rows, cols);

    printf("Matrix A:\n");
    printMatrix(A, rows, cols);
    printf("Matrix B:\n");
    printMatrix(B, rows, cols);
    printf("Resultant Matrix (A + B):\n");
    printMatrix(result, rows, cols);

    return 0;
}


/*
7)Create a structure for student data base with following
members (Register number, Name, Age, CGPA). Write a C
program to perform the following operations (i) Get user
input for 5 students record (ii) Find the student’s name
with greatest CGPA.
*/

#include <stdio.h>
#include <string.h>

#define NUM_STUDENTS 5
#define NAME_LENGTH 50

typedef struct {
    int registerNumber;
    char name[NAME_LENGTH];
    int age;
    float cgpa;
} Student;

void inputStudentData(Student students[], int numStudents);
void findStudentWithHighestCGPA(Student students[], int numStudents);

int main() {
    Student students[NUM_STUDENTS];

    printf("Enter data for %d students:\n", NUM_STUDENTS);
    inputStudentData(students, NUM_STUDENTS);

    findStudentWithHighestCGPA(students, NUM_STUDENTS);

    return 0;
}

void inputStudentData(Student students[], int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Register Number: ");
        scanf("%d", &students[i].registerNumber);
        getchar();
        printf("Name: ");
        fgets(students[i].name, NAME_LENGTH, stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';
        printf("Age: ");
        scanf("%d", &students[i].age);
        printf("CGPA: ");
        scanf("%f", &students[i].cgpa);
        getchar();
        printf("\n"

/*
8)(i) Illustrate how asymptotic notations can be used to
analyze an algorithm? (6Marks)
(ii) Calculate time and space complexity for the
following code (6Marks)
*/

#include&lt;stdio.h&gt;
int main() {
int i = 1, sum = 0, n;
while (i&lt;= n){
i=i+1;
sum = sum +i;
}}


/*(i) Asymptotic Notations
Asymptotic notations help us understand how the running time or space of an algorithm grows as the size of the input increases. Here’s what they mean:

Big O Notation (O):
Describes: Worst-case scenario.
Example: O(n) means the time grows linearly with the input size n.

Omega Notation (Ω):
Describes: Best-case scenario.
Example: Ω(n) means the time grows at least linearly with n.

Theta Notation (Θ):
Describes: Exact growth rate.
Example: Θ(n^2) means the time grows exactly like n^2.

Little o Notation (o):
Describes: Strictly less than a given growth rate.
Example: o(n^2) means the time grows slower than n^2.

Little ω Notation (ω):
Describes: Strictly more than a given growth rate.
Example: ω(n) means the time grows faster than n.

(ii)Time Complexity:
The while loop runs from i = 1 to i = n.
Each iteration of the loop does a constant amount of work.
Therefore, if n is the input size, the loop will run n times.
Time Complexity: O(n)

Space Complexity:
The program uses a few integer variables (i, sum, and n).
The space used by these variables does not depend on n and is constant.
Space Complexity: O(1)


9)Given a number ‘n’, write an algorithm and the subsequent
‘C’ program to count the number of two-digit prime
numbers in it when adjacent digits are taken. For example,
if the value of ‘n’ is 114 then the two-digit numbers that
can be formed by taking adjacent digits are 11 and 14. 11 is
prime but 14 is not. Therefore print 1.
*/

#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    char number[100];
    int count = 0;

    printf("Enter the number: ");
    scanf("%s", number);

    int length = 0;
    while (number[length] != '\0') {
        length++;
    }

    for (int i = 0; i < length - 1; i++) {
        int twoDigitNumber = (number[i] - '0') * 10 + (number[i + 1] - '0');
        if (isPrime(twoDigitNumber)) {
            count++;
        }
    }

    printf("Count of two-digit prime numbers: %d\n", count);

    return 0;
}

/*
10)Demonstrate the usage of list and perform all the
possible operation using array with suitable examples.
*/

#include <stdio.h>
#define MAX_SIZE 100

void displayList(int list[], int size);
void insertElement(int list[], int *size, int element, int position);
void deleteElement(int list[], int *size, int position);
int searchElement(int list[], int size, int element);

int main() {
    int list[MAX_SIZE];
    int size = 0;
    int choice, element, position;

    while (1) {
        printf("\nList Operations Menu:\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Display List\n");
        printf("4. Search Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position (0-based index): ");
                scanf("%d", &position);
                insertElement(list, &size, element, position);
                break;
            case 2:
                printf("Enter position (0-based index) to delete: ");
                scanf("%d", &position);
                deleteElement(list, &size, position);
                break;
            case 3:
                displayList(list, size);
                break;
            case 4:
                printf("Enter element to search: ");
                scanf("%d", &element);
                position = searchElement(list, size, element);
                if (position != -1) {
                    printf("Element %d found at position %d.\n", element, position);
                } else {
                    printf("Element %d not found.\n", element);
                }
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void displayList(int list[], int size) {
    if (size == 0) {
        printf("List is empty.\n");
        return;
    }
    printf("List elements are: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

void insertElement(int list[], int *size, int element, int position) {
    if (position < 0 || position > *size || *size >= MAX_SIZE) {
        printf("Invalid position or list is full.\n");
        return;
    }
    for (int i = *size; i > position; i--) {
        list[i] = list[i - 1];
    }
    list[position] = element;
    (*size)++;
    printf("Element %d inserted at position %d.\n", element, position);
}

void deleteElement(int list[], int *size, int position) {
    if (position < 0 || position >= *size) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = position; i < *size - 1; i++) {
        list[i] = list[i + 1];
    }
    (*size)--;
    printf("Element at position %d deleted.\n", position);
}

int searchElement(int list[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (list[i] == element) {
            return i;
        }
    }
    return -1;
}