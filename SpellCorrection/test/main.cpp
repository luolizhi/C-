#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
using namespace std;
int main()
{
    char *num1, *num2;
    char *sum;

    //string s;
    int len_num1,len_num2;
    int len_max, len_min;
    num1 = (char*)malloc(sizeof(char));
    num2 = (char*)malloc(sizeof(char));

    printf("输入两个长整型数据：\n");
    scanf("%s%s",num1,num2);
    printf("num1=%s\nnum2=%s\n",num1,num2);
    len_num1 = strlen(num1);
    len_num2 = strlen(num2);
    printf("len_num1=%d\nlen_num2=%d\n",len_num1,len_num2);
    len_max = (len_num1>=len_num2)?len_num1:len_num2;
    len_min = (len_num1<=len_num2)?len_num1:len_num2;

    //len_max += 1;
    int len_max1 = len_max;
    sum = (char*)malloc(sizeof(char)*(len_max));
    memset(sum,0x00,len_max);
    for(;len_num1>0&&len_num2>0;len_num1--,len_num2--)
    {
        printf("%d,",(num1[len_num1-1]-'0'));
        printf("%d,",(num2[len_num2-1]-'0'));
        sum[len_max--] = ((num1[len_num1-1]-'0') + (num2[len_num2-1]-'0'));

    }
     printf("\nlen_num1=%d\nlen_num2=%d\n",len_num1,len_num2);
    if(len_num1>0)
    {
        sum[len_max--]=num1[len_num1- 1 ]-'0';
        len_num1--;
    }

         if(len_num2>0)
         {
            sum[len_max--]=num2[len_num2- 1]-'0';
            len_num2--;
         }

         printf("len_max=%d\nlen_min=%d\n",len_max,len_min);
    for (int j=len_max1;j>=0;j--)
    {
        printf("%d\n",sum[j]);
        if(sum[j]>9)
        {

            sum[j-1]= sum[j-1]+sum[j]/10;
            //sum[j-1] +=1;//和上面等效只能是加1
            sum[j] = sum[j]%10;
        }
    }
    for(int i = 0;i <=len_max1;i++){
        printf("%d,",sum[i]);
    }
printf("\n%d\n",sum);
}
