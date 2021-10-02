#include<stdio.h>
#include<stdlib.h>
struct Student_Node
{
    int data;
    char name[20];
    float score;
    struct Student_Node* next;
};
struct Student_Node *CreatHead()
{
    struct Student_Node * Head_Node = (struct Student_Node*)malloc(sizeof(struct Student_Node));
    Head_Node->next=NULL;
    //Head_Node->data=10085;  //this just is a test for printing data;
    return Head_Node;
}
void OutputList(struct Student_Node *headList)
{   char PrintIndex=0;
    struct Student_Node * PrintList = (struct Student_Node*)malloc(sizeof(struct Student_Node));
    PrintList=headList;
    if (PrintList!=NULL)
        {
            do
            {   PrintIndex++;
                printf("the %d is ID: %d  Name :%s  Score: %f \n",PrintIndex,PrintList->data,PrintList->name,PrintList->score);
                PrintList=PrintList->next;
            } while (PrintList!=NULL);
            
        }   
}
struct Student_Node *InputList(struct Student_Node *headList)
{
    char ScanIndex=0;
    struct Student_Node *Node_p1 = (struct Student_Node*)malloc(sizeof(struct Student_Node));
    struct Student_Node *Node_p2 = (struct Student_Node*)malloc(sizeof(struct Student_Node));
    struct Student_Node *ScanList = (struct Student_Node*)malloc(sizeof(struct Student_Node));
    printf("please enter the first data\n");
    scanf("%d %s %2f",&Node_p1->data,&Node_p1->name,&Node_p1->score);
    while(Node_p1->data!=0)
    {
        ScanIndex++;
        if(ScanIndex==1)
        {headList=Node_p1;}
        else
        {
            Node_p2->next=Node_p1;
        }
        Node_p2=Node_p1;
        Node_p1=(struct Student_Node*)malloc(sizeof(struct Student_Node));
        printf("please continue enter the next data\n");
        scanf("%d %s %2f",&Node_p1->data,&Node_p1->name,&Node_p1->score);

    }
    Node_p2->next=NULL;
    OutputList(headList);
    return headList;

}
int main()
{

    struct Student_Node *head =(struct Student_Node*)malloc(sizeof(struct Student_Node));
    head=CreatHead();
    head=InputList(head);
    //printf("the num is %d \n",head->data);
    //OutputList(head);
    system("pause");
    return 0;

}











// struct Node *createList()
// {
//     struct Node *headNode = (struct Node*)malloc(sizeof(struct Node));
//     //headNode->data=10;
//     headNode->next =NULL;
//     return headNode;
// }
// struct Node* createNode(int data)
// {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data=data;
//     newNode->next=NULL;
//     return newNode;
// }

// int main()
// {
//     struct Node* list = createList();
//     //struct Node* new;
//     printf("list:%d\n",list->data);
//     system("pause");
//     return 0;

// }
