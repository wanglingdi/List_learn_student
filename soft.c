#include<stdio.h>
#include<stdlib.h>
struct Student_Node
{
    int data;
    char name[20];
    float score;
    struct Student_Node* next;
};
FILE* fp;
//int i=1;
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
struct Student_Node *InputList(struct Student_Node *headList)//continue the date by input
{
    char ScanIndex=0;
    
    struct Student_Node *Node_temporary = (struct Student_Node*)malloc(sizeof(struct Student_Node));
    Node_temporary=headList;
    struct Student_Node *Node_p1 = (struct Student_Node*)malloc(sizeof(struct Student_Node));
    struct Student_Node *Node_p2 = (struct Student_Node*)malloc(sizeof(struct Student_Node));
    struct Student_Node *ScanList = (struct Student_Node*)malloc(sizeof(struct Student_Node));
    printf("please enter the first data\n");
    scanf("%d %s %f",&Node_p1->data,&Node_p1->name,&Node_p1->score);
    while(Node_p1->data!=0)
    {
        ScanIndex++;
        if(ScanIndex==1)
        {ScanList=Node_p1;}
        else
        {
            Node_p2->next=Node_p1;
        }
        Node_p2=Node_p1;
        Node_p1=(struct Student_Node*)malloc(sizeof(struct Student_Node));
        printf("please continue enter the next data\n");
        scanf("%d %s %f",&Node_p1->data,&Node_p1->name,&Node_p1->score);
    }
    Node_p2->next=NULL;
    while(Node_temporary->next)
    {
       
        //printf("%d \n",Node_temporary->data);
        Node_temporary=Node_temporary->next;
    }
    Node_temporary->next=ScanList;
    //OutputList(headList);
    
    return headList;

}
struct Student_Node* FileOpen(struct Student_Node *head)//input from File to *head;
{    struct Student_Node *FileTemporary = (struct Student_Node*)malloc(sizeof(struct Student_Node));
   
    struct Student_Node *Temporary = (struct Student_Node*)malloc(sizeof(struct Student_Node));
    //+struct Student_Node *Node_P1 = (struct Student_Node*)malloc(sizeof(struct Student_Node));
    struct Student_Node *Node_p2 = (struct Student_Node*)malloc(sizeof(struct Student_Node));

    int File_index=0;

    fp=fopen("student.txt","r");
    if(NULL==fp)
    {
        printf("the file is error");
        exit(0);
    }
    // while(fscanf(fp,"%d %s %2f",&Temporary->data,&Temporary->name,&Temporary->score)!=EOF)
    // {

    //     File_index++;
    //     if(File_index==1){FileTemporary=Temporary;}
    //     else{Node_p2->next=Node_P1;}
    //     Node_p2=Node_P1;
    //     Node_P1=(struct Student_Node*)malloc(sizeof(struct Student_Node));
    //     Node_P1=Temporary;
    //     Temporary = (struct Student_Node*)malloc(sizeof(struct Student_Node));
    // }
        while(fscanf(fp,"%d %s %f",&Temporary->data,&Temporary->name,&Temporary->score)!=EOF)
    {

        File_index++;
        if(File_index==1){FileTemporary=Temporary;}
        else{Node_p2->next=Temporary;}
        Node_p2=Temporary;
        Temporary=(struct Student_Node*)malloc(sizeof(struct Student_Node));
        //Node_P1=Temporary;
        //Temporary = (struct Student_Node*)malloc(sizeof(struct Student_Node));
    }
    Node_p2->next=NULL;
    fclose(fp);
    //OutputList(head);
    return FileTemporary;
}
void FileClose(struct Student_Node *head)//print the data to File from *head;
{
     
    struct Student_Node *FileTempopary = (struct Student_Node*)malloc(sizeof(struct Student_Node));
    printf("the system is saving your date \n");
    FileTempopary=head;
    fp=fopen("student.txt","w+");
	if(NULL==fp)
	{
		printf("无法打开后台文件");
		exit(0);
	}
    while(FileTempopary->next)
    {
        fprintf(fp,"%d %s %f\n",FileTempopary->data,FileTempopary->name,FileTempopary->score);
        FileTempopary=FileTempopary->next;
    }
    fprintf(fp,"%d %s %f\n",FileTempopary->data,FileTempopary->name,FileTempopary->score);
    fclose(fp);
}
int main()
{

    struct Student_Node *head =(struct Student_Node*)malloc(sizeof(struct Student_Node));
    head=CreatHead();
    
    //printf("the num is %d \n",head->data);
    head=FileOpen(head);
    printf("已有账号：\n");
    OutputList(head);
    printf("please input new data");
    head=InputList(head);
    OutputList(head);
    FileClose(head);
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
