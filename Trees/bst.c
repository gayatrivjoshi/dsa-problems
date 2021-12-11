//Binary Search Tree
#include <stdio.h>
#include <stdlib.h>

typedef struct BinarySearchTree
{
    int data;
    struct BinarySearchTree *left;
    struct BinarySearchTree *right;
} bst;

int insert(bst *root, int val)
{
    bst *ptr = (bst *)malloc(sizeof(bst));
    ptr->data = val;
    ptr->right = NULL;
    ptr->left = NULL;
    if (root == NULL)
    {
        root = ptr;
        return root;
    }
    bst *temp = root;
    bst *parent = NULL;
    while (temp != NULL)
    {
        if (val < temp->data)
        {
            parent = temp;
            temp = temp->left;
        }
        else
        {
            parent = temp;
            temp = temp->right;
        }
    }
    if (parent->data > val)
    {
        parent->left = ptr;
        return root;
    }
    parent->right = ptr;
    return root;
}

int Delete(bst *root, int num)
{
    bst *temp = root;
    bst *parent = NULL;
    if (temp == NULL)
    {
        printf("\nThe Tree is Empty\n");
        return root;
    }
    if (root->data == num && root->left == NULL && root->right == NULL)
    {
        root = NULL;
        return root;
    }
    while (temp != NULL)
    {
        if (num == temp->data)
        {
            break;
        }
        if (num < temp->data)
        {
            parent = temp;
            temp = temp->left;
        }
        else
        {
            parent = temp;
            temp = temp->right;
        }
    }
    if (temp == NULL)
    {
        printf("\nElement NOT Found\n");
        return root;
    }

    if (temp->left == NULL && temp->right == NULL)
    {
        if (temp == root)
        {
            free(temp);
            return root;
        }
        if (parent->left == temp)
            parent->left = NULL;
        else
            parent->right = NULL;
        free(temp);
        return root;
    }
    if (temp->left != NULL && temp->right == NULL)
    {
        if (temp == root)
        {
            root = root->left;
            free(temp);
            return root;
        }
        if (parent->left == temp)
            parent->left = temp->left;
        else
            parent->right = temp->left;
        free(temp);
        return root;
    }
    if (temp->left == NULL && temp->right != NULL)
    {
        if (temp == root)
        {
            root = root->right;
            free(temp);
            return root;
        }
        if (parent->left == temp)
            parent->left = temp->right;
        else
            parent->right = temp->right;
        free(temp);
        return root;
    }

    if (temp->left != NULL && temp->right != NULL)
    {
        bst *lt, *plt;
        lt = temp->left;
        if (lt->right == NULL)
        {
            temp->data = lt->data;
            temp->left = lt->left;
            free(lt);
            return root;
        }
        while (lt->right != NULL)
        {
            plt = lt;
            lt = lt->right;
        }
        temp->data = lt->data;
        plt->right = lt->left;
        free(lt);
        return root;
    }
}

int inorder(bst *temp)
{
    if (temp != NULL)
    {
        inorder(temp->left);
        printf("%4d", temp->data);
        inorder(temp->right);
    }
}

int preorder(bst *current)
{
    if (current != NULL)
    {
        printf("%4d", current->data);
        preorder(current->left);
        preorder(current->right);
    }
}

int postorder(bst *current)
{
    if (current != NULL)
    {
        postorder(current->left);
        postorder(current->right);
        printf("%4d", current->data);
    }
}

int main()
{
    int opt, n, del, a = 0;
    bst *root = NULL;
    printf("Welcome to Binary Search Tree Implementation Using Linked List\n");
    do
    {
        printf("\nEnter Your Choice \n1) -> Insert \n2) -> Delete \n3) -> Inorder \n4) -> Preorder \n5) -> Postorder \n6) -> Exit\n");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("\nEnter the Element : ");
            scanf("%d", &n);
            root = insert(root, n);
            break;
        case 2:
            printf("\nEnter the Element you want to Delete : ");
            scanf("%d", &del);
            root = Delete(root, del);
            break;
        case 3:
            if (root == NULL)
            {
                printf("\nTree is Empty\n");
                break;
            }
            printf("\nIn-order Display : ");
            inorder(root);
            printf("\n");
            break;
        case 4:
            if (root == NULL)
            {
                printf("\nTree is Empty\n");
                break;
            }
            printf("\nPre-order Display : ");
            preorder(root);
            printf("\n");
            break;
        case 5:
            if (root == NULL)
            {
                printf("\nTree is Empty\n");
                break;
            }
            printf("\nPost-order Display : ");
            postorder(root);
            printf("\n");
            break;
        case 6:
            printf("\nThank You");
            a = 1;
            break;
        default:
            printf("\nInvalid Choice\n");
        }
    } while (a == 0);

    /*insert(1);
    insert(3);
    insert(5);
    insert(2);
    insert(4);
    insert(6);
    inorder(root);
    printf("\n");
    Delete(1);
    inorder(root);
    printf("\n");
    Delete(5);
    inorder(root);*/
}