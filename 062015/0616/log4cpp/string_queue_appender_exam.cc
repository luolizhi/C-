#include<iostream>
#include<log4cpp/OstreamAppender.hh>
#include<log4cpp/Category.hh>
#include<log4cpp/BasicLayout.hh>
#include<log4cpp/Priority.hh>
#include<log4cpp/StringQueueAppender.hh>

using namespace std;

int main(int argc, char* argv[])
{
	log4cpp::StringQueueAppender * strQAppender = new log4cpp::StringQueueAppender("strQAppender");
	strQAppender->setLayout(new log4cpp::BasicLayout());

	log4cpp::Category & root = log4cpp::Category::getRoot();
	root.addAppender(strQAppender);
	root.setPriority(log4cpp::Priority::DEBUG);

	root.error("hello log4cpp in a error Message!");
	root.warn("hello log4cpp in a Warning Meassage!");

	std::cout << "Get message from Memory Queue!" << std::endl;
	std::cout <<"--------------------------------" <<std::endl;

	queue<string>& myStrQ = strQAppender->getQueue();

	while(!myStrQ.empty())
	{
		std::cout << myStrQ.front();
		myStrQ.pop();
	}

	log4cpp::Category::shutdown();
	return 0;
}
