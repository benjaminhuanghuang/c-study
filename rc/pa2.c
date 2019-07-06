#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1024

///need to program a Node struct and a stack struct and supporting functions
typedef struct Node
{
    int label;
    double sink_cap;
    double wire_len;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct
{
    Node *data[MAXSIZE];
    int top;
} Stack;

Stack *initStack()
{
    Stack *stack;
    stack = (Stack *)malloc(sizeof(Stack));
    if (!stack)
    {
        printf("No memory...\n");
        return NULL;
    }
    stack->top = -1;
    return stack;
}

int isFull(Stack *stack)
{
    if (stack->top == MAXSIZE - 1)
    {
        printf("Stack is full...\n");
        return 1;
    }
    return 0;
}

int isEmpty(Stack *stack)
{
    if (stack->top == -1)
    {
        printf("Stack is empty...\n");
        return 1;
    }
    return 0;
}

void push(Stack *stack, Node *item)
{
    if (isFull(stack))
    {
        return;
    }
    stack->data[++stack->top] = item;
}

//出栈
Node *pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        return NULL;
    }
    return stack->data[stack->top--];
}

void preorderPrint(Node *root)
{
    if (root != NULL)
    {
        printf("label: %d  sink cap: %le, wire len: %le\n", root->label, root->sink_cap, root->wire_len);
        preorderPrint(root->left);
        preorderPrint(root->right);
    }
}

Node *contructRCTree(char *filename)
{
    ///open the file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("File open error!\n");
        return NULL;
    }

    ///First line is the 3 doubles
    ///read in to 3 different variables
    double buffRes, wireRes, wireCap;
    ///fscanf to read into these variables
    fscanf(fp, "%le %le %le", &buffRes, &wireRes, &wireCap);
    //-- Debug
    //printf("%le %le %le\n", buffRes, wireRes, wireCap);
    Stack *stack = initStack();
    int c;
    //input file contains post-order traversal of the binary tree
    while ((c = fgetc(fp)) != EOF)
    {
        Node* node = malloc(sizeof(Node));
        ///initialize all the fields in node
        if (c == '(')
        {
            ///this is an internal node
            double l_wire_len, r_wire_len;
            fscanf(fp, "%le %le", &l_wire_len, &r_wire_len);
            node->right = pop(stack);
            node->left = pop(stack);
            node->left->wire_len = l_wire_len;
            node->right->wire_len = r_wire_len;
        }
        else
        {
            // this is a sink(leaf) node
            fseek(fp, -1, SEEK_CUR);
            int id;
            double sink_cap;
            fscanf(fp, "%d(%le", &id, &sink_cap);
            node->label = id;
            node->sink_cap = sink_cap;
        }
        ///either case needs to do both of these
        fgetc(fp); //gets the ')'
        fgetc(fp); //gets the newline and carriage returns
        ///push the node to the top of the stack
        push(stack, node);
    }
    fclose(fp);
    return pop(stack);
}

int main(int argc, char **argv)
{
    ///get the filename
    Node *rcTree = contructRCTree(argv[1]);
    if(rcTree == NULL)
    {
        printf("Can not construct RC tree!\n");
        return 1;
    }
    ///do a traversal to print the tree;
    preorderPrint(rcTree);
    ///now do a downstream capacitance postorder traversal
    ///now do a delay preorder traversal
}
