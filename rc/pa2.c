#include <stdio.h>

///need to program a Node struct and a stack struct and supporting functions
typedef struct Node
{
    float value;
    struct Node *left;
    struct Node *right;
} Node;

void contructRCTree(char *filename)
{
    ///open the file
    FILE *fp = fopen("10.txt", "r");
    if (fp == NULL)
    {
        printf("File open error!\n");
        return;
    }

    ///First line is the 3 doubles
    ///read in to 3 different variables
    double buffRes, wireRes, wireCap;
    ///fscanf to read into these variables
    fscanf(fp, "%le %le %le", &buffRes, &wireRes, &wireCap);
    // printf("%le %le %le\n", buffRes, wireRes, wireCap);
    /*
    int c;
    while ((c = fgetc(fp)) != EOF)
    {
        Node *node = malloc(sizeof(Node));
        ///initialize all the fields in node
        if (c = '(')
        {
            ///this is an internal node
            double l_wire_len, r_wire_len;
            fscanf(fp, "%le %le", &l_wire_len, &r_wire_len);
            node->right =    ///stack.pop();
                node->left = ///stack.pop();
                node->left->wire_len = l_wire_len;
            node->right->wire_len = r_wire_len;
        }
        else
        {
            fseek(fp, -1, SEEK_CURR);
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
    }
    */
    fclose(fp);
}

int main(int argc, char **argv)
{
    ///get the filename
    contructRCTree(argv[1]);

    ///do a traversal to print the tree;

    ///now do a downstream capacitance postorder traversal
    ///now do a delay preorder traversal
}
