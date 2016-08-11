/*************************************************************************
	> File Name: shared_weak_ptr.cc
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Thu 25 Jun 2015 05:18:26 PM CST
 ************************************************************************/

#include<iostream>
#include<memory>

using namespace std;
class Child;
class Parent;
typedef std::shared_ptr<Child> Child_ptr;
typedef std::shared_ptr<Parent> Parent_ptr;

class Child
{
public:
	Child()
	{
		std::cout << "Child()" << std::endl;
	}

	~Child()
	{
		std::cout << "~Child()" << std::endl;
	}
	Parent_ptr parent_;//shared_ptr;
};

class Parent
{
public:
	Parent()
	{
		std::cout << "Parent()" << std::endl;
	}

	~Parent()
	{
		std::cout << "~Parent()" << std::endl;
	}

	Child_ptr child_;
};

int main(void)
{
	Parent_ptr parent(new Parent);
	Child_ptr child(new Child);

	std::cout << "parent's count = " << parent.use_count() << std::endl;
	if(parent.unique())
	{
		std::cout << "one" << std::endl;
	}
	else
	{
		std::cout << "not one" << std::endl;
	}

	std::cout << "child's count = " << child.use_count() << std::endl;
		
	parent->child_ = child;
	std::cout << "child's count = " << child.use_count() << std::endl;

	return 0;
}
