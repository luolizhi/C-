#include <iostream>
#include "Test.h"

using namespace std;

int main()
{
    #if 0
    char str[100];
    //std::cin>>std::noskipws>>str;
    std::cin.get(str,100);
    Test* test;
    std::cout<< test->huiwen(str) << std::endl;
    std::cout<< test->sort_number() << std::endl;
    #endif // 0

    string str;
    vector<int> vec;
    int size;
    while (cin >> str)
    {
        Test* test;
        vec = test->sort_number(str);
        size = vec.size();
        for (int i = 0; i < size; ++i)
        {
            if (vec[i] == -1)
            {
                continue;
            }

            if (i == 0)
            {
                cout << vec[i];
            }
            else
            {
                cout << " " << vec[i];
            }
        }
        cout << endl;
    }
    cout << "Hello world!" << endl;
    return 0;
}
