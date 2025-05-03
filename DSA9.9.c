#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

// Define structure for a node in the SCLL
typedef struct Node {
    int coeff; // Coefficient
    int x_exp; // Exponent of x
    int y_exp; // Exponent of y
    int z_exp; // Exponent of z
    struct Node *next; // Pointer to the next node
} Node;

// Function to create a new node
Node* createNode(int coeff, int x_exp, int y_exp, int z_exp) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->x_exp = x_exp;
    newNode->y_exp = y_exp;
    newNode->z_exp = z_exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node into the circular linked list
void insertNode(Node **head, int coeff, int x_exp, int y_exp, int z_exp) {
    Node *newNode = createNode(coeff, x_exp, y_exp, z_exp);
    if (*head == NULL) {
        *head = createNode(0, 0, 0, 0); // Header node
        (*head)->next = *head; // Circular reference
    }
    Node *temp = (*head)->next;
    (*head)->next = newNode;
    newNode->next = temp;
}

// Function to evaluate the polynomial for given x, y, z
int evaluatePolynomial(Node *head, int x, int y, int z) {
    int result = 0;
    Node *current = head->next;
    while (current != head) {
        result += current->coeff * pow(x, current->x_exp) * pow(y, current->y_exp) * pow(z, current->z_exp);
        current = current->next;
    }
    return result;
}

// Function to display the polynomial
void displayPolynomial(Node *head) {
    Node *current = head->next;
    while (current != head) {
        printf("%+dx^%dy^%dz^%d ", current->coeff, current->x_exp, current->y_exp, current->z_exp);
        current = current->next;
    }
    printf("\n");
}

// Function to add two polynomials and store the result in POLYSUM
Node* addPolynomials(Node *poly1, Node *poly2) {
    Node *polySum = NULL;
    insertNode(&polySum, 0, 0, 0, 0); // Header node

    Node *p1 = poly1->next, *p2 = poly2->next;
    while (p1 != poly1 || p2 != poly2) {
        if (p1 != poly1 && (p2 == poly2 || (p1->x_exp > p2->x_exp || 
            (p1->x_exp == p2->x_exp && (p1->y_exp > p2->y_exp || 
            (p1->y_exp == p2->y_exp && p1->z_exp > p2->z_exp)))))) {
            insertNode(&polySum, p1->coeff, p1->x_exp, p1->y_exp, p1->z_exp);
            p1 = p1->next;
        } else if (p2 != poly2 && (p1 == poly1 || (p2->x_exp > p1->x_exp || 
            (p2->x_exp == p1->x_exp && (p2->y_exp > p1->y_exp || 
            (p2->y_exp == p1->y_exp && p2->z_exp > p1->z_exp)))))) {
            insertNode(&polySum, p2->coeff, p2->x_exp, p2->y_exp, p2->z_exp);
            p2 = p2->next;
        } else {
            int sumCoeff = p1->coeff + p2->coeff;
            if (sumCoeff != 0) {
                insertNode(&polySum, sumCoeff, p1->x_exp, p1->y_exp, p1->z_exp);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    return polySum;
}

// Main function
int main() {
    Node *POLY1 = NULL, *POLY2 = NULL, *POLYSUM = NULL;

    // Representing POLY1 = 6x^2y^2z - 4yz^5 + 3x^3yz + 2xy^5z - 2xyz^3
    insertNode(&POLY1, 6, 2, 2, 1);
    insertNode(&POLY1, -4, 0, 1, 5);
    insertNode(&POLY1, 3, 3, 1, 1);
    insertNode(&POLY1, 2, 1, 5, 1);
    insertNode(&POLY1, -2, 1, 1, 3);

    // Representing POLY2 = 3x^2y^2z + 5x^3yz^2 - 7xyz^3
    insertNode(&POLY2, 3, 2, 2, 1);
    insertNode(&POLY2, 5, 3, 1, 2);
    insertNode(&POLY2, -7, 1, 1, 3);

    printf("POLY1: ");
    displayPolynomial(POLY1);

    printf("POLY2: ");
    displayPolynomial(POLY2);

    // Adding the two polynomials
    POLYSUM = addPolynomials(POLY1, POLY2);
    printf("POLYSUM: ");
    displayPolynomial(POLYSUM);

    // Evaluate POLY1 for x=1, y=2, z=3
    int result = evaluatePolynomial(POLY1, 1, 2, 3);
    printf("Evaluation of POLY1 for x=1, y=2, z=3: %d\n", result);

    return 0;
}
