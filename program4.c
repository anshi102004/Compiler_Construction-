#include <stdio.h>
#include <stdlib.h>

/* Structure for a tree node */
struct Node {
    char data;
    struct Node *left;
    struct Node *right;
};

/* Function to create a new node */
struct Node* createNode(char data)
{
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* Inorder Traversal */
void inOrder(struct Node* root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%c", root->data);
        inOrder(root->right);
    }
}

/* Preorder Traversal */
void preOrder(struct Node* root)
{
    if (root != NULL)
    {
        printf("%c", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

/* Postorder Traversal */
void postOrder(struct Node* root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%c", root->data);
    }
}

int main()
{
    struct Node* root;
    root = createNode('=');
    root->left = createNode('a');
    root->right = createNode('+');
    root->right->left = createNode('b');
    root->right->right = createNode('*');
    root->right->right->left = createNode('c');
    root->right->right->right = createNode('d');

    /* Display traversal */
    printf("Inorder Traversal : ");
    inOrder(root);

    printf("\nPreorder Traversal : ");
    preOrder(root);

    printf("\nPostorder Traversal : ");
    postOrder(root);
    printf("\n");

    return 0;
}

