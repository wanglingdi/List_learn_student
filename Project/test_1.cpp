#include"list.h"

//Define a FUCT to Creat a List head , and return a pointer
//定义了一个函数，返回一个链表的头结点地址
struct Student_Node *CreatHead()//creat a List to *head;
{   //给头地址分配空间
    struct Student_Node * Head_Node = (struct Student_Node*)malloc(sizeof(struct Student_Node));
    //初始化链表的数据，置零
    Head_Node->next=NULL;
    Head_Node->data=NULL;
    Head_Node->score=RESET;
    //返回链表头结点
    return Head_Node;
}
//Define a FUCT to get a pointer like as *headList to print now list;
//定义了一个打印函数，输入链表的头地址，输出整个链表
void OutputList(struct Student_Node *headList)//print list data by head list;
{   //初始化计数索引
    char PrintIndex=RESET;
    //定义一个链表指向接口输入的链表表头
    struct Student_Node * PrintList = (struct Student_Node*)malloc(sizeof(struct Student_Node));
    PrintList=headList;
    //判断是不是空链表
    if (PrintList!=NULL)
        {   //进入输出循环直到链表指向尾
            do
            {   //计数索引累加
                PrintIndex++;
                //输出链表的数据
                printf("the %d is ID: %d  Name :%s  Score: %f \n",PrintIndex,PrintList->data,PrintList->name,PrintList->score);
                //指向下一个结点
                PrintList=PrintList->next;
            } while (PrintList!=NULL);
        }
 
}
//Define a FUCT to get a pointer of list to input by keyboard,and return a list pointer headList ;
//定义一个函数，输入的数据连接到headlist链表的后面
struct Student_Node *InputList(struct Student_Node *headList)//input the date by input to *head
{   //定义链表的计数索引
    char ScanIndex=RESET;
    //定义一个bool变量判断是否为空链表
    bool flag=false;
    //开启一个空间给中间指针
    struct Student_Node *Node_temporary = (struct Student_Node*)malloc(sizeof(struct Student_Node));
    Node_temporary=headList;
    struct Student_Node *Node_p1 = (struct Student_Node*)malloc(sizeof(struct Student_Node));
    struct Student_Node *Node_p2 = (struct Student_Node*)malloc(sizeof(struct Student_Node));
    struct Student_Node *ScanList = (struct Student_Node*)malloc(sizeof(struct Student_Node));
    printf("please enter the first data\n");
    //第一次输入数据
    while(scanf("%d %s %f",&Node_p1->data,&Node_p1->name,&Node_p1->score),Node_p1->data!=EXIT)
        {
            if(Node_p1->data>10000&&Node_p1->data<20000)
            break;
            printf("Please input a id from 10000 to 20000 \n");
        }
    //如果第一次就输入 0 0 0  则直接退出函数

    if(EXIT==Node_p1->data)
    {
        flag=START;
    }
    else
    {
        
        flag=STOP;
        //如果输入不为0，则进入下列循环
        while(Node_p1->data!=EXIT)
        {   //计数累加
            ScanIndex++;
            //第一个数据存入头结点
            if(ScanIndex==1)
            {ScanList=Node_p1;}
            //第一次输入之后的输入分别通过P1 P2互相指向开辟动态链表 
            else
            {
                Node_p2->next=Node_p1;
            }
            Node_p2=Node_p1;
            Node_p1=(struct Student_Node*)malloc(sizeof(struct Student_Node));
            printf("please continue enter the next data\n");
            while(scanf("%d %s %f",&Node_p1->data,&Node_p1->name,&Node_p1->score),Node_p1->data!=EXIT)
            {
                if(Node_p1->data>10000&&Node_p1->data<20000)
                break;
                printf("Please input a id from 10000 to 20000 \n");
            }
            
        }
    //保证链表的尾部指向空
    Node_p2->next=NULL;
    // link two list 
    //连接输入的链表与之前创建的链表
    //如果第一个链表是空链表则直接让第一个链表的指针指向第二个链表即可
    if (Node_temporary->next==NULL)
    {
        headList=ScanList;
        Node_temporary=ScanList;
        
    }
    //反之，将第一个链表的指针指向第二个指针的头结点即可完成两个结点的连接
    else
    {   headList=Node_temporary;
        //循环指向尾部
        while(Node_temporary->next)
        {   
            Node_temporary=Node_temporary->next;
        }
        //连接两个链表
        Node_temporary->next=ScanList;
    }
    }
    return headList;

}
//Define a FUCT to get the pointer of list like *head to Open file ,and return a new pointer of list;
//定义函数，读取文件并且将内容导出到链表Head中
struct Student_Node* FileOpen(struct Student_Node *head)//input from File to *head;
{   //初始化中间变量
    struct Student_Node *FileTemporary = (struct Student_Node*)malloc(sizeof(struct Student_Node));
    struct Student_Node *Temporary = (struct Student_Node*)malloc(sizeof(struct Student_Node));
    struct Student_Node *Node_p2 = (struct Student_Node*)malloc(sizeof(struct Student_Node));
    int File_index=RESET;
    //打开TXT文件
    fp=fopen("student.txt","r");
    //如果读取不到输出错误
    if(NULL==fp)
    {
        printf("Error[00003]:the file is error");
        exit(EXIT);
    }
    //读取文件直到为空
    while(fscanf(fp,"%d %s %f",&Temporary->data,&Temporary->name,&Temporary->score)!=EOF)
    {
        //计数累加
        File_index++;
        //头结点单独输入一次
        if(File_index==1){FileTemporary=Temporary;}
        //后续结点通过Temporary指针依次存到head链表中
        else{Node_p2->next=Temporary;}
        Node_p2=Temporary;
        Temporary=(struct Student_Node*)malloc(sizeof(struct Student_Node));
    }
    //对链表尾结点的NEXT进行清零
    Node_p2->next=NULL;
    //关闭文件
    fclose(fp);
    //返回链表的头地址
    return FileTemporary;
}
//Define a FUCT to get pointer of list to Close file ;
//定义一个函数，输入链表的头地址，将链表到处到TXT文件中
void FileClose(struct Student_Node *head)//print the data to File from *head;
{
    //初始化指针变量 
    struct Student_Node *FileTempopary = (struct Student_Node*)malloc(sizeof(struct Student_Node));
    printf("the system is saving your date ......\n");
    FileTempopary=head;
    //打开TXT文件
    fp=fopen("student.txt","w+");
	//如果链表打不开输出错误
    if(NULL==fp)
	{
		printf("Error[00003]:the file is error");
		exit(EXIT);
	}
    //如果存储空文件，需要管理员权限
    if(FileTempopary==NULL)
    {
        printf("you have no data to save \n Thank for your using \n");
        printf("if you want to clean file please have the password of administrator\n");
        return;
    }
    //正常修改不需要管理员权限
    else
    {   //遍历链表导出到TXT文档中
        while(FileTempopary)
        {
            //输出到文件中
            fprintf(fp,"%d %s %f\n",FileTempopary->data,FileTempopary->name,FileTempopary->score);
            //通过指针遍历
            FileTempopary=FileTempopary->next;
        }
        //关闭文件
        fclose(fp);
    }
}
//Define a FUCT to get the pointer of list of Student_Node to analyse score,and return a new pointer of list;
//定义函数，分析head为头地址的链表，主要分析学生的平均分和最高分
struct Student_Node analyse_score(struct Student_Node *HeadList)// get Average and Max score from *HeadList;
{   
    //初始化变量和指针
    float AverageScore=RESET;
    int Count=RESET;
    struct Student_Node *Tempopary = (struct Student_Node*)malloc(sizeof(struct Student_Node)); 
    struct Student_Node MaxStudent;
    Tempopary=HeadList;
    MaxStudent=*HeadList;
    //遍历链表并且判断最大值和累加总分
    while (Tempopary!=NULL)
    {   
        //最大值判断
        if(MaxStudent.score<Tempopary->score)
            MaxStudent=*Tempopary;
        //总分累加
        AverageScore+=Tempopary->score;
        //人数累加
        Count++;
        //指针移动
        Tempopary=Tempopary->next;
    }

    printf(" Max id : %d  Max name :   %s  Max score %f\n",MaxStudent.data,MaxStudent.name,MaxStudent.score);
    printf("Sum Score is %f  Average Score is : %f\n",AverageScore,AverageScore/Count);
    //返回头地址
    return MaxStudent;
}

//Define a FUCt to get a pointer of list to Delete some element,return a pointer of list;
//定义一个函数，删除指定的ID的结点，以及删除两个链表相同部分
struct Student_Node* Delete_Score(struct Student_Node *HeadList)//delete from File to *HeadList;
{   
    //初始变量
    //初始化模式选择变量
    int choose=RESET;   
    //初始ID
    int SameId=RESET;
    //初始化计数器
    int index=RESET;
    //初始化可否继续执行代码状态
    int flag=STOP;
    //初始化中间指针
    struct Student_Node *SaveTempopary = (struct Student_Node*)malloc(sizeof(struct Student_Node));
    struct Student_Node *FastTempopary = (struct Student_Node*)malloc(sizeof(struct Student_Node));
    struct Student_Node *Fast1Tempopary = (struct Student_Node*)malloc(sizeof(struct Student_Node));
    struct Student_Node *LastTempopary = (struct Student_Node*)malloc(sizeof(struct Student_Node));
    struct Student_Node *NowTempopary = (struct Student_Node*)malloc(sizeof(struct Student_Node));
    struct Student_Node *CmdTempopary = (struct Student_Node*)malloc(sizeof(struct Student_Node));
    FastTempopary=HeadList;
    NowTempopary=HeadList;
    CmdTempopary=HeadList;
    printf("please choose the way of delete \n  1:delete same id           2:delete same list element\n");
    //输出模式选择变量
    scanf("%d",&choose);
    //第一个模式ID模式
    if (FIRST==choose)
    {   
        //输入删除的ID
        printf("please inputer a id to delete same element\n");
        scanf("%d",&SameId);
        //遍历链表
        while (FastTempopary!=NULL)
        {   //计数器累加
            index++;
            //头结点单独考虑
            if(1==index)
            {   //检测到头节点是相同ID的结点
                if(FastTempopary->data==SameId)
                {   //头指针指向第二个结点的地址
                    NowTempopary=FastTempopary->next;
                    CmdTempopary=NowTempopary;
                    LastTempopary=FastTempopary;
                    //释放掉头地址的空间
                    free(LastTempopary);
                    FastTempopary=NowTempopary;
                }
            }
            else
            {   //检测到相同ID的结点
                if(FastTempopary->data==SameId)
                {
                    NowTempopary->next=FastTempopary->next;
                    LastTempopary=FastTempopary;
                    //FastTempopary=FastTempopary->next;
                    //释放掉多余结点的空间
                    free(LastTempopary);
                }
            NowTempopary=FastTempopary;
            FastTempopary=FastTempopary->next;
        }
    }
        

    }
    //进入两个链表删除相同元素模式
    if (SECOND ==choose)
    {   //初始化指针变量
        printf("please inputer some data to make up a new list to delete same element\n");
        FastTempopary = (struct Student_Node*)malloc(sizeof(struct Student_Node));
        FastTempopary=CreatHead();
        //FastTempopary=NULL;
        Fast1Tempopary=InputList(FastTempopary); 
        NowTempopary=HeadList;
        FastTempopary=Fast1Tempopary;
        //对链表遍历
        while (NowTempopary!=NULL)
        {   //计数器累加
            index++;
            //将Fast指向链表的表头地址            
            FastTempopary=Fast1Tempopary;
            //对表头的数据进行单独处理
            if (FIRST==index)
            {
                 while (FastTempopary!=NULL)
                {   
                    //对输入的链表进行遍历
                    if (FastTempopary->data==NowTempopary->data)
                    {
                        CmdTempopary=NowTempopary->next;
                        //break;
                        //free(NowTempopary);
                    }
                    FastTempopary=FastTempopary->next;
                
                }
            }
            //如果进入的不是第一个结点走下面的程序
            else
            {   //遍历要删除相同结点的链表
                while (FastTempopary!=NULL)
                {   
                    //检测到相同的Data进行删除
                    if (FastTempopary->data==NowTempopary->data)
                    {   //falg=START代表进行了一次删除指令
                        flag=START;
                        SaveTempopary->next=NowTempopary->next;
                        LastTempopary=NowTempopary;
                        //free(NowTempopary);
                        break;
                    }
                    //SaveTempopary=FastTempopary;
                    //链表遍历
                    FastTempopary=FastTempopary->next;
                }
            }
            //falg=STOP代表上一次循环没有检测到相同的元素进行删除
            if (STOP==flag)
            {
                //用SaveTempopary来记录上一个地址
                SaveTempopary=NowTempopary;
                //NowTempopary继续向下遍历
                NowTempopary=NowTempopary->next;
            }
            //此时代表falg=START代表上一次循环发现了相同元素并且删除了有一个空位
            else
            {   
                //此时SaveTempopary不需要指向其他地址，继续遍历并且重置flag
                NowTempopary=NowTempopary->next;
                flag=STOP;
            }
            
        }
                  
    }
    return CmdTempopary;
}
//定义一个密码检测的函数，密码正确返回ture；
bool PasswordCheck(void)
{   //初始化局部变量密码
    int iPassword=RESET;
    printf("Please input the password of Administrator:");
    if(scanf("%d",&iPassword),g_Passowrd==iPassword)
        return true;
    return false;
}
//定义一个模式选择函数
void Mode_Choose(struct Student_Node *Head)
{   //初始化判断变量
    
    
    int judge=EXIT;
    struct Student_Node test ;
    printf("Please input your comand\n 1:input 2:output 3:analyse 4:delete\n ");
    //进入输入循环，直到输入0时候才结束。
    while (scanf("%d",&judge),EXIT!=judge){
    switch (judge)
    {
    case INPUT:
        Head=InputList(Head);
        //首先判断是不是一个环链表
        if(hasCycle(Head))
            Head=sortList(Head);
        else
            printf("Error[00001]:the list is a cycle list\n Please Cheak your List \n");
        printf("Please input your comand\n 1:input 2:output 3:analyse 4:delete\n ");
        break;
    case OUTPUT:
        OutputList(Head);
        printf("Please input your comand\n 1:input 2:output 3:analyse 4:delete\n ");
        break;
    case ANLYSE:
        test=analyse_score(Head);
        printf("Please input your comand\n 1:input 2:output 3:analyse 4:delete\n ");
        break;
    case DELETE:
        Head=Delete_Score(Head);
        printf("Please input your comand\n 1:input 2:output 3:analyse 4:delete\n ");
        break;
    default:
        printf("Error[00002]:sorry, you scanf a illegal number\nplease again input your comand\n1:input 2:output 3:analyse 4:delete\n");
        break;
    }
    }
    
}
// This FUCT is to print a start;
void PrintInterFace(void)
{
    
}

// judge cycle List
//判断这是不是一个环链表
bool hasCycle(struct Student_Node *HeadList)
 {
    //初始化两个快慢指针
    struct Student_Node *Fast =(struct Student_Node*)malloc(sizeof(struct Student_Node));
    struct Student_Node *Slow =(struct Student_Node*)malloc(sizeof(struct Student_Node));
    //先判断空链表的特殊情况
    if(HeadList==NULL)
        return false;
    Fast=HeadList;
    Slow=HeadList;
    int index=RESET;
    //如果链表第一第二个节点都不为空则开始循环，直到走到空指针的时候暂停
    while(Slow&&Fast&&Fast->next)
    {   index++;
    //判断链表是不是只有一个结点，此时不成环
        if(FIRST==index)
        {
            if(Slow->next==NULL)
            return false;
        }
    //快慢指针移动，相遇的时候则返回TURE
        else
        {
           
            Slow=Slow->next;
            Fast=Fast->next->next;
             if(Slow==Fast)
                return true;
        }
    }
    //如果跳出循环了，说明链表有尾，输出FLASE
    return false;
}

//完成归并算法的 治 ，将分好的有限个组进行排序组合
struct Student_Node* merge(struct Student_Node* head1, struct Student_Node* head2) {
    //初始化指针变量
    struct Student_Node* dummyHead = (struct Student_Node*)malloc(sizeof(struct Student_Node));
    dummyHead->data = RESET;
    struct Student_Node *temp = dummyHead, *temp1 = head1, *temp2 = head2;
    //对接口输入的两个链表进行遍历 进行排序合并
    while (temp1 != NULL && temp2 != NULL) {
        //如果temp1的data较小，则排在temp的下一个结点上
        if (temp1->data <= temp2->data) {
            temp->next = temp1;
            temp1 = temp1->next;}
        //如果temp2的data较小，则排在temp的下一个结点上 
        else {
            temp->next = temp2;
            temp2 = temp2->next;
        }
        //完成一次遍历排序后将指向下一个结点
        temp = temp->next;
    }
    //当temp1或者temp2一个遍历到尾结点后，将其作为最后一个结点连接到链表temp上
    if (temp1 != NULL) {
        temp->next = temp1;
    } else if (temp2 != NULL) {
        temp->next = temp2;
    }
    //最后返回temp的头结点的next，也就是第二个结点的地址
    return dummyHead->next;
}
//利用双指针寻找中间结点,完成归并算法排序的 分 
struct Student_Node* toSortList(struct Student_Node* HeadList, struct Student_Node* tail) {
    //首先进行空链表进行检测
    if (HeadList == NULL) {
        return HeadList;
    }
    //然后进行单结点链表的检测
    if (HeadList->next == tail) {
        HeadList->next = NULL;
        return HeadList;
    }
    //初始化双指针变量
    struct Student_Node *slow = HeadList, *fast = HeadList;
    //快指针走两个结点，慢指针走一个
    while (fast != tail) {
        slow = slow->next;
        fast = fast->next;
        if (fast != tail) {
            fast = fast->next;
        }
    }
    //记录最后的中间结点位置
    struct Student_Node* mid = slow;
    //进行递归 对链表分解
    return merge(toSortList(HeadList, mid), toSortList(mid, tail));
}
//定义归并排序函数的接口
struct Student_Node* sortList(struct Student_Node* HeadList) {
    return toSortList(HeadList, NULL);
}
int main()
{
    //初始化模式判断变量，
    int judge=EXIT;
    //初始化平均值
    int average_num=RESET;
    //初始化头结点
    struct Student_Node *head =(struct Student_Node*)malloc(sizeof(struct Student_Node));
    //初始化打印图案
    PrintInterFace();
    //给头结点置零
    head=CreatHead();
    //打开TXT文件读出数据存到HEAD链表内
    head=FileOpen(head);
    //打印解释
    printf("Account Show: \n");
    //屏幕输出链表HEAD的数值
    OutputList(head);
    //进入模式选择此时要进行一次管理员密码确认
    if(PasswordCheck())
        Mode_Choose(head);
    //存储链表到TXT文件里收尾
    FileClose(head);
    //system("pause");
    return 0;
}
