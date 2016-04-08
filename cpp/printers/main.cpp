#include <iostream>
#include <vector>

using namespace std;


/**
 * 功能: 遍历vector容器进行打印
 * 说明: c++模板类/模板函数的声明与定义应该放在头文件里，不要分开来写类中函数的声明与定义(会导致连接错误)
 */
template <typename T>
void printByIter(T vec)
{
    for(typename T::iterator it=vec.begin(); it!=vec.end(); ++it)
    {
        cout << *it << endl;
    }
}

template <typename T>
void printByIndex(T vec)
{
    for(typename T::size_type ix=0; ix!=vec.size(); ++ix)
    {
        cout << vec[ix] << endl;
    }
}


int main()
{
    vector<int> intVec;
    intVec.push_back(1);
    intVec.push_back(2);
    printByIter(intVec);

    vector<char> charVec;
    charVec.push_back('a');
    charVec.push_back('b');
    printByIndex(charVec);

    return 0;
}
