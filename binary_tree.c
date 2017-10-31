#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

struct node
{
    unsigned val;
    struct node *left;
    struct node *right;
};

//root, left, right
void print_nodes(struct node *nodes, size_t curr_height)
{
    ++curr_height;
    if (nodes)
    {
        printf("%u\n", nodes->val);
        print_nodes(nodes->left, curr_height);
        print_nodes(nodes->right, curr_height);
    }
}

void insert_val(struct node **curr_node, unsigned val)
{
    struct node *tmp = NULL;
    if (!(*curr_node))
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->left = NULL;
        tmp->right = NULL;
        tmp->val = val;
        *curr_node = tmp;
        return;
    }
    if (val <= (*curr_node)->val)
    {
        insert_val(&(*curr_node)->left, val);
    }
    else
    {
        insert_val(&(*curr_node)->right, val);
    }
}

void free_all_nodes(struct node *nodes)
{
    if (nodes)
    {
        free_all_nodes(nodes->left);
        free_all_nodes(nodes->right);
        free(nodes);
    }
}

int main()
{
    struct node *root;
    root = NULL;
    insert_val(&root, 5);
    insert_val(&root, 2);
    insert_val(&root, 7);
    insert_val(&root, 9);
    insert_val(&root, 6);
    insert_val(&root, 4);
    insert_val(&root, 3);
    insert_val(&root, 1);
    print_nodes(root, 0);
    printf("OoO\n");
    printf("oOo\n");
}

