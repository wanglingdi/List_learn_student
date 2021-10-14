#include"list.h"
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
        {Mode_Choose(head);
    //存储链表到TXT文件里收尾
        FileClose(head);}
    //system("pause");
    return 0;
}
