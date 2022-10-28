#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int key;
    struct node *left, *right;
};
struct node *newNode(int item)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->key=item;
    temp->left=temp->right=NULL;
    return temp;
}
void inorder(struct node *root,FILE *fp){
    if(root!=NULL)
    {
        inorder(root->left,fp);
        fprintf(fp,"%d ",root->key);
        inorder(root->right,fp);
    }
}
void preorder(struct node *root,FILE *fp){
    if(root!=NULL)
    {
        fprintf(fp,"%d ",root->key);
        preorder(root->left,fp);
        preorder(root->right,fp);
    }
}
void postorder(struct node *root,FILE *fp){
    if(root!=NULL)
    {
        postorder(root->left,fp);
        postorder(root->right,fp);
        fprintf(fp,"%d ",root->key);
    }
}
struct node* insert(struct node* node, int key)
{
    
    if (node == NULL)
        return newNode(key);
 
    
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
 
    
    return node;
}
struct node *input(int n)
{
    struct node* root = NULL;
    int i,val;
    printf("Enter Value:");
    scanf("%d",&val);
    root = insert(root,val);
    for ( i = 1; i < n; i++)
    {
        printf("Enter Value:");
        scanf("%d",&val);
        insert(root,val);
    }
    return root;
}

int main()
{
    struct node* root = NULL;
    FILE *fp;
    int n,i,val;
    fp=fopen("Input.txt","r");
    fscanf(fp,"%d",&val);
    root = insert(root,val);
    while(!feof(fp))
    {
        fscanf(fp,"%d",&val);
        insert(root,val);
    }
    fclose(fp);
    fp=fopen("Inorder.txt","w");
    inorder(root,fp);
    fclose(fp);
    fp=fopen("Preorder.txt","w");
    preorder(root,fp);
    fclose(fp);
    fp=fopen("Postorder.txt","w");
    postorder(root,fp);
    fclose(fp);
    return(0);
}