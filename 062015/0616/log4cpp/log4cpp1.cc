#include<iostream>
#include<log4cpp/Category.hh>
#include<log4cpp/OstreamAppender.hh>
#include<log4cpp/BasicLayout.hh>
#include<log4cpp/Priority.hh>

using namespace std;





int main(int argc, char* argv[])
{
	log4cpp::OstreamAppender* osAppender = new log4cpp::OstreamAppender("osAppender",&std::cout);
	osAppender->setLayout(new log4cpp::BasicLayout());

	log4cpp::Category & root = log4cpp::Category::getRoot();
	root.addAppender(osAppender);
	root.setPriority(log4cpp::Priority::DEBUG);

	root.error("hello log4cpp in a error message!");
	root.warn("hello log4cpp in a warning message!");

	log4cpp::Category::shutdown();

	return 0;
}
