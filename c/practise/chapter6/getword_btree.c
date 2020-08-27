/*
读取所有的单词，放在一个二叉树里
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

typedef struct tnode *TreePtr;
typedef struct tnode
{
    char *word;
    int count;
    TreePtr left;
    TreePtr right;
} TreeNode;

TreePtr addtree(TreePtr, char *);
void treeprint(TreePtr);
int getword(char *, int);

int main()
{
    TreePtr root;
    char word[MAXWORD];
    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word);
    treeprint(root);
    return 0;
}

char *str_dup(char *);

TreePtr addtree(TreePtr p, char *w)
{
    int cond;
    if (p == NULL)
    { // 新单词，创建一个新节点，并分配内存
        p = (TreePtr)malloc(sizeof(TreeNode));
        p->word = str_dup(w);
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(w, p->word)) == 0)
    {
        p->count++;
    }
    else if (cond < 0)
    {
        p->left = addtree(p->left, w);
    }
    else
    {
        p->right = addtree(p->right, w);
    }
    return p;
}

void treeprint(TreePtr t)
{
    if (t != NULL)
    {
        treeprint(t->left);
        printf("%4d: %s \n", t->count, t->word);
        treeprint(t->right);
    }
}

// 把传入的字符串复制到一个安全的位置
char *str_dup(char *s)
{
    char *p;
    p = (char *)malloc(strlen(s) + 1);
    if (p != NULL)
    {
        strcpy(p, s);
    }
    return p;
}

// 从输入中读取下一个单词
int getword(char *word, int lim)
{
    int c, getch();
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c))
    {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++)
        if (!isalnum(*w = getch()))
        {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}