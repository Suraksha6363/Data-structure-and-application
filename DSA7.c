#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count = 0;

struct node {
    char usn[20], name[20], branch[10];
    int sem;
    long int phno;
    struct node *next;
} *first = NULL, *last = NULL;

void create() {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter USN, NAME, BRANCH, SEMESTER, PHNUM of student:\n");
    scanf("%s %s %s %d %ld", temp->usn, temp->name, temp->branch, &temp->sem, &temp->phno);
    temp->next = NULL;
    count++;
    if (first == NULL) {
        first = last = temp;
    }
}

void insert_at_first() {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter USN, NAME, BRANCH, SEMESTER, PHNUM of student:\n");
    scanf("%s %s %s %d %ld", temp->usn, temp->name, temp->branch, &temp->sem, &temp->phno);
    temp->next = first;
    first = temp;
    count++;
    if (last == NULL) last = first;
}

void insert_at_last() {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter USN, NAME, BRANCH, SEMESTER, PHNUM of student:\n");
    scanf("%s %s %s %d %ld", temp->usn, temp->name, temp->branch, &temp->sem, &temp->phno);
    temp->next = NULL;
    if (last != NULL) {
        last->next = temp;
    }
    last = temp;
    if (first == NULL) first = temp;
    count++;
}

void display() {
    struct node *temp = first;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("\nLinked list elements:\n");
    printf("USN\tName\tBranch\tSemester\tPhone\n");
    while (temp != NULL) {
        printf("%s\t%s\t%s\t%d\t\t%ld\n", temp->usn, temp->name, temp->branch, temp->sem, temp->phno);
        temp = temp->next;
    }
    printf("Total number of students = %d\n", count);
}

void delete_end() {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = first;
    if (first->next == NULL) {
        printf("Deleted student: %s %s %s %d %ld\n", temp->usn, temp->name, temp->branch, temp->sem, temp->phno);
        free(temp);
        first = last = NULL;
    } else {
        while (temp->next != last) {
            temp = temp->next;
        }
        printf("Deleted student: %s %s %s %d %ld\n", last->usn, last->name, last->branch, last->sem, last->phno);
        free(last);
        last = temp;
        last->next = NULL;
    }
    count--;
}

void delete_front() {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = first;
    printf("Deleted student: %s %s %s %d %ld\n", temp->usn, temp->name, temp->branch, temp->sem, temp->phno);
    first = first->next;
    free(temp);
    if (first == NULL) last = NULL;
    count--;
}

int main() {
    int choice;
    printf("\nMENU:\n");
    printf("1 - Create a SLL of n students\n");
    printf("2 - Display from beginning\n");
    printf("3 - Insert at end\n");
    printf("4 - Delete at end\n");
    printf("5 - Insert at beginning\n");
    printf("6 - Delete at beginning\n");
    printf("7 - Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                insert_at_last();
                break;
            case 4:
                delete_end();
                break;
            case 5:
                insert_at_first();
                break;
            case 6:
                delete_front();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}
