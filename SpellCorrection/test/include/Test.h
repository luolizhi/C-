#ifndef TEST_H
#define TEST_H
#include <cstring>
#include <cctype>
#include <vector>
class Test
{
    public:
        Test();
        virtual ~Test();

    public:
        //�ж��ַ����Ƿ��ǻ���
        int huiwen(char str[]);

        vector<int> sort_number(string str);

    protected:

    private:
};

#endif // TEST_H
