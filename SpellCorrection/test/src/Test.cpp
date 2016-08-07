#include "Test.h"


Test::Test()
{
    //ctor
}

Test::~Test()
{
    //dtor
}


/*
回文数字判断
描述：有这样一类数字，他们顺着看和倒着看是相同的数，例如：121，656，2332等，这样的数字就称为：回文数字。判断某数字是否是回文数字。
运行时间限制：10Sec
内存限制：128MByte
输入：整型数字
输出：0：不是回文数字；1：是回文数字。
样例输入：121
样例输出：1
*/

int Test::huiwen(char str[])
{
    int flag=1;
    int len= strlen(str);
    if (len<=0 || !isdigit(str[len/2]))
        return 0;
    //判断是否含有非数字
    for(int i =0;i<len/2;i++)
    {
        if(!isdigit(str[i]) || !isdigit(str[len-i-1]) || str[i]!=str[len-i-1])
        {
            flag = 0;
            break;
        }
    }

    return flag;
}


/*
整数排序
描述：实现输入一组大于等于0的整数，根据从小到大的顺序排序后输出，排序后有连续数时，只输出连续数中最小和最大的两个数。
运行时间限制：无限制
内存限制：无限制
输入：一组大于等于0的整数，不考虑非法输入，各个整数之间以逗号（“，”）分割，输入字符串的总长度小于等于100个字节。
输出：排序后的值，各个整数之间以空格分隔。
样例输入：1，4，3，110，2，90，7
样例输出：1 4 7 90 110
*/

vector<int> Test::sort_number(string str)
{
    int size = str.size()
    vector<int> vec;
    if (0 == size)
    {
        return vec;
    }
    //int num = 0;
    const char * split = ",";
    char * p;
    p = strtok(str,split);
    while(P!=NULL)
    {
        vec.push_back(p);
        p = strtok(NULL, split);
    }
    sort(vec.begin(),vec.end());
    int count = vec.size();
    int start = 0;
    for(int i = 1; i<= count; i++)
    {
        if(i==count || vec[i] != vec[i-1]+1)
        {
            for(int j=start+1;j<= i-2;j++)
            {
                vec[j]=-1;
            }
            start =i;
        }
    }
    return vec;
}



















