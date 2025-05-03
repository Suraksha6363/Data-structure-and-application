
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Employee structure
struct Employee {
    char SSN[15];
    char Name[50];
    char Dept[20];
    char Designation[20];
    float Sal;
    char PhNo[15];
    struct Employee* prev;
    struct Employee* next;
};

// Function to create a new Employee node
struct Employee* createEmployee(char ssn[], char name[], char dept[], char designation[], float sal, char phno[]) {
    struct Employee* newNode = (struct Employee*)malloc(sizeof(struct Employee));
    strcpy(newNode->SSN, ssn);
    strcpy(newNode->Name, name);
    strcpy(newNode->Dept, dept);
    strcpy(newNode->Designation, designation);
    newNode->Sal = sal;
    strcpy(newNode->PhNo, phno);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert an employee at the end of the DLL
void insertAtEnd(struct Employee** head, struct Employee* newEmployee) {
    if (*head == NULL) { // List is empty
        *head = newEmployee;
    } else {
        struct Employee* temp = *head;
        while (temp->next != NULL) { // Traverse to the end
            temp = temp->next;
        }
        temp->next = newEmployee;
        newEmployee->prev = temp;
    }
}

// Function to insert an employee at the beginning of the DLL
void insertAtFront(struct Employee** head, struct Employee* newEmployee) {
    if (*head == NULL) { // List is empty
        *head = newEmployee;
    } else {
        newEmployee->next = *head;
        (*head)->prev = newEmployee;
        *head = newEmployee;
    }
}

// Function to delete an employee at the front of the DLL
void deleteAtFront(struct Employee** head) {
    if (*head == NULL) { // List is empty
        printf("DLL is empty. Nothing to delete.\n");
        return;
    }

    struct Employee* temp = *head; // Node to be deleted

    if ((*head)->next == NULL) { // If only one node in the list
        *head = NULL; // Update head to NULL
    } else {
        *head = (*head)->next; // Move head to the next node
        (*head)->prev = NULL;  // Update the new head's prev pointer to NULL
    }

    free(temp); // Free the memory of the old head node
    printf("Employee deleted from the front.\n");
}

// Function to delete an employee at the end of the DLL
void deleteAtEnd(struct Employee** head) {
    if (*head == NULL) { // List is empty
        printf("DLL is empty. Nothing to delete.\n");
        return;
    }

    struct Employee* temp = *head;

    if (temp->next == NULL) { // If only one node in the list
        *head = NULL;
    } else {
        while (temp->next != NULL) { // Traverse to the last node
            temp = temp->next;
        }
        temp->prev->next = NULL; // Remove the link to the last node
    }

    free(temp); // Free the memory of the last node
    printf("Employee deleted from the end.\n");
}

// Function to display the employees in the DLL
void displayDLL(struct Employee* head) {
    if (head == NULL) {
        printf("DLL is empty.\n");
        return;
    }

    printf("\nEmployees in DLL:\n");
    struct Employee* temp = head;
    while (temp != NULL) {
        printf("SSN: %s, Name: %s, Dept: %s, Designation: %s, Salary: %.2f, Phone: %s\n",
               temp->SSN, temp->Name, temp->Dept, temp->Designation, temp->Sal, temp->PhNo);
        temp = temp->next;
    }
}

// Function to count nodes in the DLL
int countNodes(struct Employee* head) {
    int count = 0;
    struct Employee* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Main function
int main() {
    struct Employee* head = NULL; // Initialize the DLL as empty
    int choice;
    char ssn[15], name[50], dept[20], designation[20], phno[15];
    float sal;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at end\n");
        printf("2. Insert at front\n");
        printf("3. Delete at front\n");
        printf("4. Delete at end\n");
        printf("5. Display list\n");
        printf("6. Count nodes\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter SSN: ");
                scanf("%s", ssn);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Dept: ");
                scanf("%s", dept);
                printf("Enter Designation: ");
                scanf("%s", designation);
                printf("Enter Salary: ");
                scanf("%f", &sal);
                printf("Enter Phone: ");
                scanf("%s", phno);
                insertAtEnd(&head, createEmployee(ssn, name, dept, designation, sal, phno));
                break;

            case 2:
                printf("Enter SSN: ");
                scanf("%s", ssn);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Dept: ");
                scanf("%s", dept);
                printf("Enter Designation: ");
                scanf("%s", designation);
                printf("Enter Salary: ");
                scanf("%f", &sal);
                printf("Enter Phone: ");
                scanf("%s", phno);
                insertAtFront(&head, createEmployee(ssn, name, dept, designation, sal, phno));
                break;

                     case 3:
                deleteAtFront(&head);
                break;

            case 4:
                deleteAtEnd(&head);
                break;

            case 5:
                displayDLL(head);
                break;

            case 6:
                printf("Number of employees: %d\n", countNodes(head));
                break;

            case 7:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

