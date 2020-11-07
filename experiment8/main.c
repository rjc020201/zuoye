#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
** 文件名: experiment5
** 创建人: 容津程
** 日 期: 2020.11.1
** 修改人: 容津程
** 日 期: 2020.11.1
** 描 述: 学生成绩管理系统
*/

typedef struct students{
int number;
char name[30];
int score[7];
int allScore;
double scoreAverage;
}STUDENT;
/*
计算总数平均数的函数
** 函数名:calculatenumber
** 输 入: 学生组，人数位置，分数数  
** 输 出: 无. 
** 功能描述:计算学生组的总分和平均分。
*/
void calculateStudents(STUDENT stu[30],int wai,int scoreNumber){
    int i=0,j=0;
    for(i=0;i<wai;i++){
        stu[i].scoreAverage=0;
        stu[i].allScore=0;
    }
    for(i=0;i<wai;i++){
        for(j=0;j<scoreNumber;j++){
                stu[i].allScore+=stu[i].score[j];
        }
        stu[i].scoreAverage=stu[i].allScore/(scoreNumber*1.0);
    }
}
/*
输入数据的函数
** 函数名:Input 
** 输 入: 学号，分数，学生组，人数位置，分数数，计数变量  
** 输 出: 无. 
** 功能描述:向学生组中插入人数
*/
void Input(int number,int score,int wai,int scoreNumber,int u,STUDENT stu[],char stName[30]){
        stu[wai].number=number;
        strcpy(stu[wai].name,stName);
        stu[wai].score[u]=score;
}


/*
** 函数名: Sort
** 输 入: 学生组 
** 输 出: 无 
** 功能描述: 对学生组排序
** 全局变量: 无
** 调用模块: 调用指针函数asort
*/
void Sort(STUDENT stu[30],int (*compare)(int ,int ),int scoreNumber,int wai){
    int i,j,k;
    int isum=0;
    double Iave=0;
    for(i=0;i<wai-1;i++){
        for(j=0;j<wai-i-1;j++){

            if((*compare)(stu[j].allScore,stu[j+1].allScore)){
                STUDENT temp;
                temp=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=temp;
                }
        }

    }
    for(i=0;i<wai;i++){
        printf("NO.%d is %s\n",i+1,stu[i].name);
    }

}
/* 
** 函数名: Numbersort
** 输 入: 学生组
** 输 出: 无 
** 功能描述: 对学生组学号排序
** 全局变量: 无
** 调用模块: 指针函数排序
*/
void NumberSort(STUDENT stu[],int (*compare)(int ,int ),int scoreNumber,int wai){
    int i,j;
    int k;
    for(i=0;i<wai-1;i++){
        for(j=0;j<wai-i-1;j++){
            if((*compare)(stu[j].number,stu[j+1].number)){
                   STUDENT temp=stu[j];
                   stu[j]=stu[j+1];
                   stu[j+1]=temp;
                }
            }
        }
    for(i=0;i<wai;i++){
        printf("NO.%d\tscore is:",stu[i].number);
        for(j=0;j<scoreNumber;j++){
            printf("%d\t",stu[i].score[j]);
        }
        printf("\n");
    }
}

/* 
** 函数名: bijiao
** 输 入: 学生组,外计数，分数数
** 输 出: 无 
** 功能描述: 比较名字的字典数并排序
** 全局变量: 无
** 调用模块: StudentNumber
*/

void bijiao(STUDENT stu[30],int wai,int scoreNumber){
    int i,j;
    int k;
    for(i=0;i<wai-1;i++){
        for(j=0;j<wai-i-1;j++){
            if(strcmp(stu[j].name,stu[j+1].name)>0){
                STUDENT temp=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=temp;
            }
        }
    }
   for(i=0;i<wai;i++){
        printf("NO.%d\tname is:%s\tscore is:",i+1,stu[i].name);
        for(j=0;j<scoreNumber;j++){
            printf("%d\t",stu[i].score[j]);
        }
        printf("\n");
    }
}

/* 
** 函数名: asort
** 输 入:  a,b
** 输 出: 比较a和b的大小并返回二者比较的大小
**　１：ａ大于ｂ
＊＊　０：ａ小于ｂ
** 功能描述: 比较a和b的大小并返回二者比较的大小
** 全局变量: 无
** 调用模块: 无
*/
int asort(int a,int b){
    return a>b;
}
/*
** 函数名: resort
** 输 入:  a,b
** 输 出: 比较a和b的大小并返回二者比较的大小
**　１：ａ小于ｂ
＊＊　０：ａ大于ｂ
** 功能描述: 比较a和b的大小并返回二者比较的大小
** 全局变量: 无
** 调用模块: 无
*/
int resort(int a,int b){
    return a<b;
}

/*
** 函数名: Require
** 输 入: 查询的学号大小，学生组，分数数，外计数
** 输 出: 查到的成绩和对应名字
** 功能描述: 查寻出成绩和对应名字
** 全局变量: 无
** 调用模块: StudentNumber
*/
void Require(int WhatYouWant,STUDENT stu[30],int scoreNumber,int wai){
    int i=0;
    int isture=0;
    int j;
    int k;
    for(i=0;i<wai-1;i++){
        for(j=0;j<wai-i-1;j++){
            if(resort(stu[j].number,stu[j+1].number)){
                STUDENT temp2=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=temp2;
            }
        }
    for(i=0;i<wai;i++){
        if(stu[i].number==WhatYouWant){
            isture=1;
            printf("students:number:%d\tNO.%d\n",stu[i].number,i+1);
            int j;
            for(j=0;j<scoreNumber;j++){
                int temp=j+1;
                printf("score %d :%d\t",temp,stu[i].score[j]);
            }
            printf("\nname is %s\n",stu[i].name);
        }
    }
    if(isture==0){
    printf("sorry i can't find!\n");
    }
}
}
/*
** 函数名: Require2
** 输 入: 学生组,学生姓名组，学科数，查询的名字，外计数
** 输 出: 输出组中名字相同情况，或者查询不到
** 功能描述: 输出组中名字相同情况
** 全局变量: 无
** 调用模块: StudentNumber

*/
void Require2(STUDENT stu[],int scoreNumber,char WhatYouWantName[],int wai){
    int i,j,k;
    int isture=0;
    int studentNumber=wai;
    for(i=0;i<studentNumber-1;i++){
        for(j=0;j<studentNumber-i-1;j++){
            if(resort(stu[j].number,stu[j+1].number)){
                STUDENT temp=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=temp;
            }
        }
    }
    for(i=0;i<studentNumber;i++){
        if(strcmp(stu[i].name,WhatYouWantName)==0){
            printf("%s's number is:%d,%s's NO.%d\n",stu[i].name,stu[i].number,stu[i].name,i+1);
            for(j=0;j<scoreNumber;j++){
                int temp=j+1;
                printf("score %d:%d\t",temp,stu[i].score[j]);
                isture=1;
            }
            printf("\n");
        }
    }
    if(isture==0){
        printf("sorry!I didn't got it!\n");
    }
}
/*
** 函数名: Tongji
** 输 入: 学生组，学科数，外计数
** 输 出: 输出组中成绩大小的分组
** 功能描述: 统计组中成绩的大小
** 全局变量: 无
** 调用模块: 无
*/
void Tongji(STUDENT stu[],int scoreNumber,int wai){
    int i,j;
    int temp;
    double best=0,better=0,good=0,bad=0,worse=0,wuyong;
    double ibest=0,ibetter=0,igood=0,ibad=0,iworse=0;
    for(j=0;j<scoreNumber;j++){
       for(i=0;i<wai;i++){
             int injudge;
                temp=j+1;
            injudge=stu[i].score[j]/10;
            if(stu[i].score[j]<10 && stu[i].score[j]>0){
                worse++;
            }
            switch(injudge){
                case 10:best++;
                        break;
                case 9:best++;
                        break;
                case 8:better++;
                        break;
                case 7:good++;
                        break;
                case 6:bad++;
                        break;
                case 0:wuyong++;
                        break;
                default:worse++;
                        break;
            }
        double studentNumber=(double)wai;
        ibest=best/studentNumber,ibetter=better/studentNumber,igood=good/studentNumber,ibad=bad/studentNumber,iworse=worse/studentNumber;
        }
        printf("scorce %d is:\nbest:%.2lf people:%.0lf\nbetter:%.2lf people:%.0lf\ngood:%.2lf people:%.0lf\nbad:%.2lf people:%.0lf\nworse:%.2lf people=%.0lf\n",temp,ibest,best,ibetter,better,igood,good,ibad,bad,iworse,worse);
         best=0,better=0,good=0,bad=0,worse=0,wuyong=0;
         ibest=0,ibetter=0,igood=0,ibad=0,iworse=0;
    }
}
/*
** 函数名: Alloutput
** 输 入: 学生组，分数数，外计数
** 输 出: 学生组全体和对应的统计情况
** 功能描述: 输出学生组和对应的统计情况
** 全局变量: 无
** 调用模块: Tongji函数
*/
void Alloutput(STUDENT stu[],int scoreNumber,int wai){
    int i=0,j=0;
    for(i=0;i<wai;i++){
            printf("name is :%s\n",stu[i].name);
            printf("number:%d\t",stu[i].number);
            for(j=0;j<scoreNumber;j++){
                int temp=j+1;
                printf("scorce %d is:%d\t",temp,stu[i].score[j]);
            }
            printf("\n");
        }
    Tongji(stu,scoreNumber,wai);
}
int main()
{
   /***
    请用户输入选项
    ****/
    int wai=0,allNumber;
    int choice=9,number,scoreNumber;
    int scorce=0;
    int whatYouWant;
    int b,v;
    STUDENT stu[30];
    for(v=0;v<30;v++){
        stu[v].number=-1;
        stu[v].name[30]='\0';
        stu[v].score[7]=0;
        stu[v].allScore=0;
        stu[v].scoreAverage=0;
    }
    char checki=0;
    int ExitThis=0;
    int scorcesTotal[6]={0};
    double scorcesAverage[6]={0};
    int jilu=0;
    char c;
    int k;
    char studentsName[30];
    char WhatYouWantName[30];
    while(ExitThis==0){
    printf("1. Input record\n2.Calculate total and average score of every course\n3.Calculate total and average score of every student\n4.Sort in descending order by total score of every student\n5.Sort in ascending order by total score of every student\n6.Sort in ascending order by number\n7.Sort in dictionary order by name\n8.Search by number\n9.Search by name\n10.Statistic analysis for every course\n11.List record\n0.Exit\nPlease enter your choice:");
    while(1){
            scanf("%d",&choice);
            checki=getchar();
            if(checki=='\n'&&choice<12&&choice>-1){
                fflush(stdin);
                break;
            }else{
                printf("your enter is wrong!please enter again!\n");
                printf("please enter again:");
                fflush(stdin);
            }
    }
    switch(choice){
        case 1:
            printf("if you want to stop it please enter -1to any form\n");
            do{printf("please input the people's number(it's all student's number!):");
            scanf("%d",&allNumber);
            c=getchar();
            if(allNumber>30||allNumber<=0||c!='\n'){
                printf("your input is wrong!\nplease input again!");
                fflush(stdin);
            }
            fflush(stdin);
            }
            while(allNumber>30||allNumber<=0||c!='\n');
            if(jilu==0){
                do{printf("please input the people's score's number:");
                    scanf("%d",&scoreNumber);
                    char c;
                    c=getchar();
                    if(scoreNumber>6||scoreNumber<=0||c!='\n')
                        printf("it is a wrong number you can't input!\n");
                        fflush(stdin);
                    }
                    while(scoreNumber>6||scoreNumber<=0);
                jilu=1;
            }
            while(wai<allNumber){
                printf("please input student's number:");
                int number,scorce;
                int boolin=0;
                do{
                    boolin=1;
                    char c;
                    do{int ret=scanf("%d",&number);
                        c=getchar();
                        if(c!='\n'||ret!=1){
                            printf("it is a wrong input!\nplease input again:");
                            fflush(stdin);
                        }
                    }while(c!='\n');
                    int q=0;
                    boolin=0;
                    for(q=0;q<wai;q++){
                        if(stu[q].number==number){
                            printf("this number you hava been input before.please input another number!\n");
                            boolin=0;
                            }
                        }
                }while(boolin==1);
            fflush(stdin);
            printf("the student's name is :");
            gets(studentsName);
            fflush(stdin);
                int u;
                for(u=0;u<scoreNumber;u++){
                    printf("and it's NO.%d scorce:",u+1);
                    do{
                    scanf("%d",&scorce);
                    char c;
                    c=getchar();
                    if(scorce==-1||number==-1){
                        goto out;
                    }
                    if(scorce<101 && scorce>=0&&c=='\n'){
                        Input(number,scorce,wai,scoreNumber,u,stu,studentsName);
                        calculateStudents(stu,wai,scoreNumber);
                        break;
                    }else{
                        printf("please input right score:");
                        fflush(stdin);
                    }
                    }while(1);
                }
                wai++;
                calculateStudents(stu,wai,scoreNumber);
            }
            if(wai>allNumber){
                printf("please input students' number which is bigger than before input!\n");
            }
                out:;
                break;


        case 2:if(stu[0].number==-1){
                    printf("please input you information firstly!\n");
                    break;
                }
                printf(" Calculate total and average score of course is:\n");
                int i;
                for(i=0;i<scoreNumber;i++){
                    for(k=0;k<wai;k++){
                        scorcesTotal[i]+=stu[k].score[i];
                    }
                    scorcesAverage[i]=scorcesTotal[i]/wai;
                    int j=i+1;
                    printf("NO.%d scorce's total is:%d\nNO.%d scorce's average is:%lf\n",j,scorcesTotal[i],j,scorcesAverage[i]);
                }
                memset(scorcesAverage,0,sizeof(scorcesAverage)+1);
                memset(scorcesTotal,0,sizeof(scoreNumber)+1);
                break;


       case 3:if(stu[0].number==-1){
                printf("please input data firstly!\n");
                }else{
                for(i=0;i<wai;i++){
                    printf("NO.%d student's score:%d\taverage:%lf\n",stu[i].number,stu[i].allScore,stu[i].scoreAverage);
                }
                }
                break;
       case 4:if(stu[0].number==-1){
                printf("please input data firstly!\n");
                }else{
                Sort(stu,resort,scoreNumber,wai);
               // Output(students);
                }
                break;

        case 5:if(stu[0].number==-1){
                printf("please input data firstly!\n");
                }else{
                Sort(stu,asort,scoreNumber,wai);
                //Output(students);
                }
                break;

        case 6:if(stu[0].number==-1){
                printf("please input data firstly!\n");
                }else{
                NumberSort(stu,asort,scoreNumber,wai);
                //Output( students);
                }
                break;

        case 7:if(stu[0].number==-1){
                printf("please input data firstly!\n");
                }else{
                    bijiao(stu,wai,scoreNumber);
                }
                break;

        case 8:if(stu[0].number==-1){
                printf("please input data firstly!\n");
                }else{
                while(1){
                    printf("please input what you want to require:");
                    scanf("%d",&whatYouWant);
                    checki=getchar();
                    if(checki=='\n'&&whatYouWant>-1){
                        fflush(stdin);
                        break;
                    }else{
                    printf("your enter is wrong!please enter again!\n");
                    fflush(stdin);
                    }
                }
                Require(whatYouWant, stu,scoreNumber,wai);
                }
                break;

        case 9:if(stu[0].number==-1){
                    printf("please input data firstly!\n");
                }else{
                    printf("please input what you want to require:");
                    gets(WhatYouWantName);
                    Require2(stu,scoreNumber,WhatYouWantName,wai);
                }
                break;

        case 10:if(stu[0].number==-1){
                printf("please input data firstly!\n");
                }else{Tongji(stu,scoreNumber,wai);
                }
                break;

       case 11:if(stu[0].number==-1){
                printf("please input data firstly!\n");
                }else{Alloutput(stu,scoreNumber,wai);
                }
                break;
        case 0:ExitThis=1;
                break;

        }
    }
    printf("good bye");

    return 0;
}
