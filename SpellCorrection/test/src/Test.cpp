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
���������ж�
������������һ�����֣�����˳�ſ��͵��ſ�����ͬ���������磺121��656��2332�ȣ����������־ͳ�Ϊ���������֡��ж�ĳ�����Ƿ��ǻ������֡�
����ʱ�����ƣ�10Sec
�ڴ����ƣ�128MByte
���룺��������
�����0�����ǻ������֣�1���ǻ������֡�
�������룺121
���������1
*/

int Test::huiwen(char str[])
{
    int flag=1;
    int len= strlen(str);
    if (len<=0 || !isdigit(str[len/2]))
        return 0;
    //�ж��Ƿ��з�����
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
��������
������ʵ������һ����ڵ���0�����������ݴ�С�����˳�������������������������ʱ��ֻ�������������С��������������
����ʱ�����ƣ�������
�ڴ����ƣ�������
���룺һ����ڵ���0�������������ǷǷ����룬��������֮���Զ��ţ����������ָ�����ַ������ܳ���С�ڵ���100���ֽڡ�
�����������ֵ����������֮���Կո�ָ���
�������룺1��4��3��110��2��90��7
���������1 4 7 90 110
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



















