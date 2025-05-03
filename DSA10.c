#include <stdio.h>
#include <stdlib.h>

struct BST {
    int data;
    struct BST *left;
    struct BST *right;
};
typedef struct BST NODE;

// Function to create a new node or insert a new value into the BST
NODE* createtree(NODE *root, int data) {
    if (root == NULL) {
        NODE *temp = (NODE*) malloc(sizeof(NODE));
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }
    if (data < root->data) {
        root->left = createtree(root->left, data);
    } else if (data > root->data) {
        root->right = createtree(root->right, data);
    }
    return root;
}

// Function for Inorder Traversal (Left -> Root -> Right)
void inorder(NODE *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

// Function for Preorder Traversal (Root -> Left -> Right)
void preorder(NODE *root) {
    if (root != NULL) {
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function for Postorder Traversal (Left -> Right -> Root)
void postorder(NODE *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
    }
}

// Function to search for a value in the BST
NODE* search(NODE *root, int data) {
    if (root == NULL) {
        printf("\nElement not found\n");
        return NULL;
    } else if (data < root->data) {
        return search(root->left, data);
    } else if (data > root->data) {
        return search(root->right, data);
    } else {
        printf("\nElement found is: %d\n", root->data);
        return root;
    }
}

// Main function
int main() {
    int data, ch, i, n;
    NODE *root = NULL;

    while (1) {
        printf("\n1. Creation of Binary Search Tree");
        printf("\n2. Inorder Traversal");
        printf("\n3. Preorder Traversal");
        printf("\n4. Postorder Traversal");
        printf("\n5. Search");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter the number of elements (N): ");
                scanf("%d", &n);
                printf("\nEnter the values to create the BST (e.g., 6, 9, 5, 2):\n");
                for (i = 0; i < n; i++) {
                    scanf("%d", &data);
                    root = createtree(root, data);
                }
                break;

            case 2:
                printf("\nInorder Traversal:\n");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("\nPreorder Traversal:\n");
                preorder(root);
                printf("\n");
                break;

            case 4:
                printf("\nPostorder Traversal:\n");
                postorder(root);
                printf("\n");
                break;

            case 5:
                printf("\nEnter the element to search: ");
                scanf("%d", &data);
                search(root, data);
                break;

            case 6:
                exit(0);

            default:
                printf("\nWrong option! Please try again.\n");
                break;
        }
    }
    return 0;
}

