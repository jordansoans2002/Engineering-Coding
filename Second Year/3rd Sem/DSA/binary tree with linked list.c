#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* right;
    struct Node* left;
}Node;

Node *mainRoot;

Node* newNode(int data){
    Node* n=(Node*)malloc(sizeof(Node));
    n->data=data;
    n->right=NULL;
    n->left=NULL;
    return n;
}

void insert(Node* root,int data){
    if(root==NULL){
        if(mainRoot==NULL)
            mainRoot=newNode(data);
        else
            root=newNode(data);
        printf("inserted at root\n");
    }
    else if(root->data<data){
        if(root->right==NULL){
            root->right=newNode(data);
            printf("inserted to right\n");
        }
        else
            insert(root->right,data);
    }
    else if(root->data>data){
        if(root->left==NULL){
            root->left=newNode(data);
            printf("inserted to left\n");
        }else
            insert(root->left,data);
    }
    else{
        printf("invalid input\n");
    }
}

void inorder(Node *root){
    if(root!=NULL){
        inorder(root->left);
        //if(root->data!=-1)
            printf("%d  ",root->data);
        inorder(root->right);
    }
}

void preorder(Node *root){
    if(root!=NULL){
        preorder(root->left);
        preorder(root->right);
        printf("%d ",root->data);
    }
}

void postorder(Node *root){
    if(root!=NULL){
        printf("%d ",root->data);
        postorder(root->left);
        postorder(root->right);

    }
}

Node* search(Node* root,int find){
    if(root==NULL){
        printf("not found\n");
        return NULL;
    }
    else if(root->data==find){
        printf("found\n");
        return root;
    }
    else if(root->data>find)
        search(root->left,find);
    else//(root->data<find)
        search(root->right,find);
}

Node* min(Node* root){
    if(root->left!=NULL)
        min(root->left);
    else
        return root;
}

Node* max(Node* root){
    if(root->right!=NULL)
        max(root->right);
    else
        return root;
}

void delete(Node *root,int val){
    Node *temp=(Node*)malloc(sizeof(Node));
    temp->left=NULL;
    if(root==NULL)
        printf("value not found\n");
    else if(val==root->data){
        //temp=root;
        if(root->right!=NULL&&root->left!=NULL){
            root->data=max(root->left)->data;
            delete(max(root->left),max(root->left)->data);
        }
        else if(root->left)
            *root=*root->left;
        else if(root->right)
            *root=*root->right;
        else{
            //free(root);
            root->left=NULL;
            printf("reached")
            *root=*root->left;
        }

    }
    else if(val>root->data)
        delete(root->right,val);
    else
        delete(root->left,val);
    free(temp);
}

void main(){
    int ch=1,data;
    while(ch!=0){
        printf("1.insert 2.traverse 3.search 4.min 5.max 6.delete 0 to exit\n");
        scanf("%d",&ch);
        if(mainRoot==NULL&&ch>1){
            printf("invalid input, tree is empty\n");
            continue;
        }
        switch(ch){
            case 0:
                break;
            case 1:
                printf("enter the data\n");
                scanf("%d",&data);
                if(data==-1){
                    printf("invalid input\n");
                    continue;
                }
                insert(mainRoot,data);
                break;
            case 2:
                printf("1.inorder 2.preorder 3.postorder\n");
                int c;
                scanf("%d",&c);
                switch(c){
                    case 1:
                        inorder(mainRoot);
                        break;
                    case 2:
                        preorder(mainRoot);
                        break;
                    case 3:
                        postorder(mainRoot);
                        break;
                    default:
                        printf("invalid input\n");
                        break;
                }
                printf("\n");
                break;

                case 3:
                    printf("enter value to be found\n");
                    scanf("%d",&data);
                    search(mainRoot,data);
                    break;

                case 4:
                    printf("minimum value in tree is %d\n",min(mainRoot)->data);
                    break;
                case 5:
                    printf("maximum value in tree is %d\n",max(mainRoot)->data);
                    break;

                case 6:
                    printf("Enter node to be deleted ");
                    scanf("%d",&data);
                    delete(mainRoot,data);
                    inorder(mainRoot);
                    printf("\n");
                    break;

            default:
                printf("invalid option\n");
        }
    }
}
