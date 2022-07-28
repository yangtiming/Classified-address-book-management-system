//test数据：guizhou liping fuyenao 557300 yang timing 1999 10 23 h 18785562227 guizhou guiyang naiming 475858 zhang lili 1998 10 13 f 18288761633 liaoning dalian ganjingzi 475858 wang dasi 1997 10 30 b 18678892230
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
void sequence(void);
void people_search(void);
void date_search(void);
void sort_people(void);

struct addresstype /*地址*/
{
    char prvince[50];
    char city[50];
    char street[50];
    int mailnumber;
};
struct personType/*姓 与 名*/
{
    char first_name[30];
    char last_name[30];
};
struct dateType/*出生日期年月日*/
{
    int year;
    int month;
    int day;
};

struct extPersontype/*分别包含地址 姓与名 出生日期年月日 以及 电话号码*/
{
    struct addresstype address;
    struct personType person;
    struct dateType date;
    char sort;
   int tel[11];
} addressbook[30];
static int n;/*用于控制流程看进行了几次输入*/
int main()
{
    int i;
	
    char t;
	n=0;
    printf("please write down \n the address(prvince,city,street)\n the name\n the date(year,month,day)\n the person kinds(famliy is h,friend is f business is b)\n the tel \n");
    for (i = 0; i < 30; i++)
    {
        /*-----------------scanf------------------------------------*/
        /*各种内容的输入*/
        scanf(" %s%s%s%d%s%s%d%d%d %c%s",
			addressbook[i].address.prvince,
			addressbook[i].address.city,
			addressbook[i].address.street,
			&addressbook[i].address.mailnumber, 
			addressbook[i].person.first_name, 
			addressbook[i].person.last_name,
			&addressbook[i].date.year, 
			&addressbook[i].date.month,
			&addressbook[i].date.day,
			&addressbook[i].sort,
			&addressbook[i].tel);
        n++;
        if (getchar()=='\n')
        {
            break;
        }
	}
        printf("-----------------------输入预览------------------------------");
    
		for(i=0;i<n;i++)
		{ printf("\n name: %s %s\n \n address:\n privnce: %s\t\tcity: %s \t \t street: %s \n\n mail number is %d\n \n birthday:\n %d year \t\t %d month \t\t%d day \n \n sort %c \t\t tel: %s\n \n", addressbook[i].person.first_name,addressbook[i].person.last_name, addressbook[i].address.prvince,
		addressbook[i].address.city,
		addressbook[i].address.street,
		addressbook[i].address.mailnumber,
		addressbook[i].date.year,
		addressbook[i].date.month,
		addressbook[i].date.day,
		addressbook[i].sort,
		addressbook[i].tel);
		printf("\n------------------------------------------------------------------\n");}
    
    
    sequence();
    printf("\n\n\n\n");
    printf("\n\t************************function choose***********************\t\n\n");
    
    printf("choose the selection you want: \n\n a：people_search \t\t b:date_search_people \t\t c:sort_people\n\n");
    
    scanf("%c", &t);
    getchar();
    switch (t)
    {
        case 'a':
            people_search();
            break;
        case 'b':
            date_search();
            break;
        case 'c':
            sort_people();
            break;
        default:
            printf("error!\n");
    }
    
    return 0;
}
void sequence()/*进行按姓名排序*/
{
    int i, j;
    struct extPersontype temp;
    
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            if (strcmp(addressbook[j].person.first_name, addressbook[j + 1].person.first_name) > 1)
            {
                temp = addressbook[j];
                addressbook[j] = addressbook[j + 1];
                addressbook[j + 1] = temp;
            }
        }
    }
}

void people_search()/*分别输入姓与名*/
{
    int i=0;
     
    char first_name[50];
	char last_name[50];
    printf("please write down the first_name you want to search\n");
    
    while((first_name[i]=getchar())!='\n')
     {i++;}
first_name[i]='\0';
	  printf("please write dwon the last_name\n");
    gets(last_name);

    for (i = 0; i < n; i++)
    {
          if (!strcmp(addressbook[i].person.first_name,first_name))
		{
         if (!strcmp(addressbook[i].person.last_name,last_name))
        {
        
            printf("\n\t---------------------person information----------------------------\t\n");
            printf("\n name: %s %s\n \n address:\n privnce: %s\t\tcity: %s \t \t street: %s \n\n mail number is %d\n \n birthday:\n %d year \t\t %d month \t\t%d day \n \n sort %c \t\t tel: %s\n \n", addressbook[i].person.first_name,
				addressbook[i].person.last_name,
				addressbook[i].address.prvince,
				addressbook[i].address.city,
				addressbook[i].address.street,
				addressbook[i].address.mailnumber,
				addressbook[i].date.year,
				addressbook[i].date.month, 
				addressbook[i].date.day, 
				addressbook[i].sort, 
				addressbook[i].tel);
            printf("\n------------------------------------------------------------------\n");
        }
		}
    }
}
void date_search()/*输入两个日期，查找人*/
{
    int s1_year, s2_year;
    int s1_month, s2_month;
    int s1_day, s2_day;
    int power_s1, power_s2;
    int i;
    char *fn = "d:\\text.txt";
    FILE *fp;
    fp = fopen(fn, "w+");
    if (fp == NULL)
    {
        printf("can not open %s\n", fn);
        exit(0);
    }
    
    printf("\n\t\t___please write dwon two date to find out some poeple___\t\t\n\n");
    printf("\t\tFormat such as xxxx xx xx xxxx xx xx\n\n");
    scanf("%d%d%d%d%d%d", &s1_year, &s1_month, &s1_day, &s2_year, &s2_month, &s2_day);
    
    power_s1 = s1_year * 10000 + s1_month * 100 + s1_day;
    power_s2 = s2_year * 10000 + s2_month * 100 + s2_day;
    
    printf("\n_________________________________________________\n");
    for (i = 0; i < n; i++)
    {
        int power_i = addressbook[i].date.year * 10000 + addressbook[i].date.month * 100 + addressbook[i].date.day;
        if(power_i>=power_s1 && power_i <= power_s2)
        {
            printf("\nthe person is %s %s\n",addressbook[i].person.first_name, addressbook[i].person.last_name);
            fputs(addressbook[i].person.first_name, fp);
            fputs(addressbook[i].person.last_name, fp);
        }
    }
    
    fclose(fp);
}

void sort_people()/*按照种类进行分类*/
{
    int i;
    printf("\n\n+++++++++++++++++++famly person sort+++++++++++++++++++++++++\n\n");
    for (i = 0; i < n; i++)
    {
        
        if (addressbook[i].sort == 'h')
        {
            printf("number:\t%s %s\n", addressbook[i].person.first_name,addressbook[i].person.last_name);
        }
    }
    printf("\n\n+++++++++++++++++++friend person sort+++++++++++++++++++++++++\n\n");
    for (i = 0; i < n; i++)
    {
        if (addressbook[i].sort == 'f')
        {
          printf("number:\t%s %s\n", addressbook[i].person.first_name,addressbook[i].person.last_name);
        }
    }
    
    printf("\n\n+++++++++++++++++++business person sort+++++++++++++++++++++++++\n\n");
    for (i = 0; i < n; i++)
    {
        if (addressbook[i].sort == 'b')
        {
             printf("number:\t%s %s\n", addressbook[i].person.first_name,addressbook[i].person.last_name);
        }
    }
}
