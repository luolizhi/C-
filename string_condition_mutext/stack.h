/*************************************************************************
	> File Name: stack.h
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Mon 22 Jun 2015 09:29:29 AM CST
 ************************************************************************/

#pragma once
class SStack
{
	public:
		SStack(void);
		~SStack(void);

		int getTop();
		int push(int value);
		int pop();//delete the element of top
		int getLength();
		int traverse();
		bool isFull();
		bool isEmpty();

	private:
		int * data;
};
