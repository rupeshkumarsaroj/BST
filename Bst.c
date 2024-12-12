#include <stdio.h>
#include <stdlib.h>

// Define the structure of a BST node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to count nodes within the range [l, h]
int countNodesInRange(struct Node* root, int l, int h) {
    if (root == NULL) {
        return 0;
    }

    // Node is within range
    if (root->data >= l && root->data <= h) {
        return 1 + countNodesInRange(root->left, l, h) + countNodesInRange(root->right, l, h);
    }

    // Node is smaller than the range
    if (root->data < l) {
        return countNodesInRange(root->right, l, h);
    }

    // Node is greater than the range
    return countNodesInRange(root->left, l, h);
}

// Function to perform in-order traversal (optional, for debugging purposes)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int n, value;

    printf("Enter the number of nodes to insert: ");
    scanf("%d", &n);

    printf("Enter the values to insert into the BST: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    int l = 5, h = 45;
    int count = countNodesInRange(root, l, h);

    printf("\nIn-order Traversal of the BST: ");
    inorderTraversal(root);

    printf("\nNumber of nodes in range [%d, %d]: %d\n", l, h, count);

    return 0;
}
