/*************************************************************************
	> File Name: share_ptr.cc
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Wed 24 Jun 2015 02:38:51 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<memory>

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
	Parent_ptr parent_;
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

	Child_ptr child_;//shared_ptr
};

int main(void)
{
	Parent_ptr parent(new Parent);	
	Child_ptr child(new Child);
	
	std::cout << "parent count = " << parent.use_count() << std::endl;
	std::cout << "child count = " << child.use_count() << std::endl;

	std::cout << "复制之后" << std::endl;
	parent->child_ = child;
	std::cout << "child count = " << child.use_count() << std::endl;
	child->parent_ = parent;
	std::cout << "parent count = " << parent.use_count() << std::endl;

	return 0;
}
