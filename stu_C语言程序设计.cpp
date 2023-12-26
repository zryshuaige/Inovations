#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h> 

#define stu_max 30
 
int stu_num();//统计学生人数函数 

char menu_tips();//操作函数 

void stu_information(long num[],float score[],int n);

void sum_aver(float score[],int n);

void exchange_long(long *a,long *b);

void exchange_float(float *a,float *b);

void output_score(long num[],float score[],int n);

void output_num(long num[],float score[],int n);

void query(long num[],float score[],int n);

void score_pro(float score[],int n);

void output(long num[],float score[],int n);

void clean();
////
void min_score(float score[],int n);//搜索最小成绩 
void max_score(float score[],int n);//搜索最大成绩 
void cul_sd(float score[],int n);//计算标准差 
void  Readtxt(void);//读取文件
void Writetxt(int n);//写入文件 


struct student {
	long num[stu_max];
	float score[stu_max];	
}student1;

int main()
{
    int n,i;
    long num[stu_max];
    float score[stu_max];
    n=stu_num(); 
    while(1)
    {
        i=menu_tips();
        switch(i)
        {
            case '1':printf("1"),stu_information(num,score,n);break;//system("cls");break;
            case '2':printf("2"),sum_aver(score,n),clean();break;
            case '3':printf("3"),output_score(num,score,n),clean();break;
            case '4':printf("4"),output_num(num,score,n),clean();break;
            case '5':printf("5"),query(num,score,n),clean();break;
            case '6':printf("6"),score_pro(score,n),clean();break;
            //case '7':printf("7"),output(num,score,n),clean();break;
            case '7':printf("7"),Readtxt(),clean();break;
            case '8':printf("8"),max_score(score,n),min_score(score,n),clean();break;
            case '9':printf("9"),cul_sd(score,n),clean();break;
            case '0':printf("0"),exit(0);break;
            default:printf("Input error!\n"),clean();
        }
    }
}



int stu_num()
{
    int n;
    printf("Input student number(n<30):\n");
    scanf("%d",&n);
    system("cls");
    return n;
}


char menu_tips()
{
    printf(" -----------------------------------------------------------\n");
    printf("|              Management for Students' scores              |\n");
    printf(" -----------------------------------------------------------\n");
    printf("|       1.Input record                                      |\n");
    printf("|       2.Calculate total and average score of course       |\n");
    printf("|       3.Sort in descending order by score                 |\n"); //下降的顺序 
    printf("|       4.Sort in ascending order by number                 |\n");//增长的顺序 
    printf("|       5.Search by number                                  |\n");
    printf("|       6.Statistic analysis                                |\n");
    printf("|       7.List record                                       |\n");
    //printf("|       0.Exit                                              |\n");
    ///自定义 
    printf("|       8.search max_score&min_score                        |\n");
    printf("|       9.culculate Standard deviation                      |\n");
    printf("|       0.Exit                                              |\n");
    printf(" -----------------------------------------------------------\n");
    printf("\nPlease Input your choice:\n");
    char i;
    i=getch();//获取键值
    return i;
}


void stu_information(long num[],float score[],int n)
{
    int i;
    printf("\nInput student's ID and score:\n");
    for(i=0;i<n;i++)
        scanf("%ld%f",&student1.num[i],&student1.score[i]);
    Writetxt(n);    
}

void sum_aver(float score[],int n)
{
    int i;
    float sum,aver;
    for(i=0,sum=0;i<n;i++)
        sum+=student1.score[i];
    aver=sum/n;
    printf("\nsum=%.0f,aver=%.2f\n",sum,aver);
}


void exchange_long(long *a,long *b)//用指针直接交换 
{
    long t;
    t=*a;
    *a=*b;
    *b=t;
}


void exchange_float(float *a,float *b)
{
    float t;
    t=*a; *a=*b; *b=t;
}


void output_score(long num[],float score[],int n)
{
    int i,j;
    for(j=n-1;j>0;j--)
    {
        for(i=0;i<j;i++)
            if(student1.score[i]<student1.score[i+1])
        {
            exchange_float(&student1.score[i],&student1.score[i+1]); 
            exchange_long(&student1.num[i],&student1.num[i+1]); 
        }
    }
    printf("\nSort in descending order by score:");
    output(student1.num,student1.score,n);
}

void output_num(long num[],float score[],int n)
{
    int i,j;
    for(j=n-1;j>0;j--)
    {
        for(i=0;i<j;i++)
            if(student1.num[i]>student1.num[i+1])
        {
            exchange_float(&student1.score[i],&student1.score[i+1]);
            exchange_long(&student1.num[i],&student1.num[i+1]);
        }
    }
    output(student1.num,student1.score,n);
}


void query(long num[],float score[],int n)
{
    printf("\nEnter the ID to query:\n");
    long temp;
    scanf("%ld",&temp);
    int i;
    for(i=0;i<n;i++)
    {
        if(student1.num[i]==temp)
        {
            printf("%ld\t%.0f\n",student1.num[i],student1.score[i]);
            return;
        }
    }
    printf("\nNot found!\n");
}


void score_pro(float score[],int n)//统计各个分段的人数 
{
    int t[6]={0,0,0,0,0,0};
    
    int i,m;
    for(i=0;i<n;i++)
    {
        if(student1.score[i]>=90&&student1.score[i]<100) t[0]++;
        if(student1.score[i]>=80&&student1.score[i]<=89) t[1]++;
        if(student1.score[i]>=70&&student1.score[i]<=79) t[2]++;
        if(student1.score[i]>=60&&student1.score[i]<=69) t[3]++;
        if(student1.score[i]>=0 &&student1.score[i]<=59) t[4]++;
        if(student1.score[i]==100)                       t[5]++;
    }

 
    for(i=0,m=9;i<6;i++)
    {
        if(i==4)
            printf("<60\t%d\t%.2f%%\n",t[4],(float)t[4]/n*100);//%%指的是输出的值是一个百分数 
        if(i==5)
            printf("%d\t%d\t%.2f%%\n",100,t[5],(float)t[5]/n*100);
        if(i!=4&&i!=5)
        {
            if(i==0)
                printf("\n");
            printf("%d-%d\t%d\t%.2f%%\n",m*10,m*10+9,t[i],(float)t[i]/n*100);
            m--;
        }
    }
}


void output(long num[],float score[],int n)//普通输出 
{
    int i;
    for(i=0;i<n;i++)
    {
        if(i==0)
            printf("\n");
        printf("%ld\t%.0f\n",student1.num[i],student1.score[i]);
    }
}

void clean()
{
    system("pause");
    system("cls");
}

/////增加函数 
void min_score(float score[],int n)
{
	int mink=0;//k
	for(int i=1;i<n;i++)
		if(student1.score[i]<student1.score[mink])	mink=i;
	printf("min=%.2f\n",student1.score[mink]);
}

void max_score(float score[],int n)
{
	int maxk=0;//k
	for(int i=1;i<n;i++)
		if(student1.score[i]>student1.score[maxk])	maxk=i;
	printf("\nmax=%.2f\n",student1.score[maxk]);
}

void cul_sd(float score[],int n)
{
	double mean_sd,sumf=0,cnt=0;
	for(int i=0;i<n;i++)
		sumf+=student1.score[i];
	mean_sd=1.0*sumf/n;
	for(int i=0;i<n;i++)
		cnt+=(student1.score[i]-mean_sd)*(student1.score[i]-mean_sd);
	if(n<=1)
		printf("数据量过于小或者无法输入"); 
	else
		printf("\n成绩的标准差是%.2f\n",cnt/(n-1));
}

void  Readtxt(void)
{
	FILE *fp;int num;float grades;
	if((fp=fopen("学生数据.txt","r"))==NULL)
	{
		printf("读取文件错误"); 
		exit(0); 
	}
	while(!feof(fp))
	{
		fscanf(fp,"%d %f\n",&num,&grades);
		printf("\n%d %.2f\n",num,grades);
	}
	fclose(fp);
	fp=NULL;
}

void Writetxt(int n)
{
	FILE *fp;
	if((fp=fopen("学生数据.txt","w"))==NULL)
	{
		printf("读取文件错误"); 
		exit(0); 
	}
	for(int i=0;i<n;i++)
	{
		fprintf(fp,"%d %f\n",student1.num[i],student1.score[i]);
		//fprintf(fp,"%f\n",student1.score[i]);
	}
	printf("\n写入文件成功\n"); 
	fclose(fp);
	fp=NULL;
}

