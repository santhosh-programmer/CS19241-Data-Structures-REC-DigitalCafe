// Binary Search Tree is a node-based binary tree data structure which has the following properties:

// The left subtree of a node contains only nodes with keys lesser than the node’s key.
// The right subtree of a node contains only nodes with keys greater than the node’s key.
// The left and right subtree each must also be a binary search tree.

// Implement the Binary Search Tree for the following operations. (Ex. Option 1 specifies insertion, Option 2 specifies Deletion, Option 3 specifies Finding the minimum element, Option 4 specifies Finding the maximum element, Option 5 specifies inorder traversal of the tree)

// 1 - Insertion

// 2 - Deletion

// 3 - Find Min

// 4 - Find Max

// 5 - Inorder Display

// 6 - exit


#include <stdio.h>
#include <stdlib.h>
struct node
{
    int element;
    struct node *left;
    struct node *right;
};
typedef struct node node;
node *insert(node *tree, int x)
{
    if (tree == NULL)
    {
        node *newnode = malloc(sizeof(node));
        newnode->right = newnode->left = NULL;
        newnode->element = x;
        tree = newnode;
    }
    else if (x < tree->element)
    {
        tree->left = insert(tree->left, x);
    }
    else if (x > tree->element)
    {
        tree->right = insert(tree->right, x);
    }
    return tree;
}
void inorder(node *tree)
{
    if (tree != NULL)
    {
        inorder(tree->left);
        printf("%d ", tree->element);
        inorder(tree->right);
    }
}

node *searchMin(node *tree)
{
    if (tree == NULL)
    {
        return NULL;
    }
    else if (tree->left == NULL)
    {
        return tree;
    }
    else
    {
        return searchMin(tree->left);
    }
}
node *searchMax(node *tree)
{
    if (tree == NULL)
    {
        return NULL;
    }
    else if (tree->right == NULL)
    {
        return tree;
    }
    else
    {
        return searchMax(tree->right);
    }
}
node *delete (node *tree, int x)
{
    // Assigning temp to NULL because of compiler issues in Digital Cafe. temp can also be used without initializing it to NULL in VSCode (as mine works in it, even though it's the same GCC compiler!)
    node *temp=NULL;
    if (x < tree->element)
    {
        tree->left = delete (tree->left, x);
    }
    else if (x > tree->element)
    {
        tree->right = delete (tree->right, x);
    }
    else if (tree->left && tree->right)
    {
        temp = searchMin(tree->right);
        tree->element = temp->element;
        tree->right = delete (tree->right, tree->element);
    }
    else
    {
        if (tree->left == NULL)
        {
            tree = tree->right;
        }
        else if (tree->right == NULL)
        {
            tree = tree->left;
        }
        free(temp);
    }
    return tree;
}
int main()
{
    node *tree = NULL;
    int ch, x, n;
    do
    {
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            scanf("%d", &n);
            tree = insert(tree, n);
            break;
        case 2:
            scanf("%d", &x);
            delete (tree, x);
            break;
        case 3:
            if (searchMin(tree) != NULL)
            {
                printf("%d\n", searchMin(tree)->element);
            }
            else
            {
                printf("Tree is empty\n");
            }
            break;
        case 4:
            if (searchMax(tree) != NULL)
            {
                printf("%d\n", searchMax(tree)->element);
            }
            else
            {
                printf("Tree is empty\n");
            }
            break;
        case 5:
            inorder(tree);
            printf("\n");
            break;
        case 6:
            break;
        default:
            break;
        }
    } while (ch != 6);
    return 0;
}
