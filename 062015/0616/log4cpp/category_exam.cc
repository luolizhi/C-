#include<iostream>
#include<log4cpp/Category.hh>
#include<log4cpp/OstreamAppender.hh>
#include<log4cpp/FileAppender.hh>
#include<log4cpp/BasicLayout.hh>
#include<log4cpp/Priority.hh>

using namespace std;

int main(int argc, char* argv[])
{
	log4cpp::OstreamAppender * osAppender1 = new log4cpp::OstreamAppender("osAppender1",&std::cout);
	osAppender1->setLayout(new log4cpp::BasicLayout());
	
	log4cpp::OstreamAppender * osAppender2 = new log4cpp::OstreamAppender("osAppender2",&std::cout);
	osAppender2->setLayout(new log4cpp::BasicLayout());

	log4cpp::Category & root = log4cpp::Category::getRoot();
	root.setPriority(log4cpp::Priority::DEBUG);

	log4cpp::Category & sub1 = root.getInstance("sub1");
	sub1.addAppender(osAppender1);
	sub1.setPriority(log4cpp::Priority::DEBUG);
	sub1.error("sub error");
	
	log4cpp::Category &sub2 = root.getInstance("sub2");
	sub2.addAppender(osAppender2);
	sub2.setPriority(101);
	sub2.warn("sub2 warning");
	sub2.fatal("sub2 fatal");
	sub2.alert("sub2 alert");
	sub2.crit("sub2 crit");

	log4cpp::Category::shutdown();

	return 0;

}
