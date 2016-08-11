#include<stdlib.h>
#include<iostream>
#include<log4cpp/Category.hh>

#include<log4cpp/Appender.hh>
#include<log4cpp/FileAppender.hh>
#include<log4cpp/RollingFileAppender.hh>
#include<log4cpp/OstreamAppender.hh>

#include<log4cpp/PatternLayout.hh>
#include<log4cpp/Priority.hh>

using namespace std;

//1.实现日志文件信息在终端上显示
//2.实现日志文件信息在终端和日志文件同时显示
//3.实现回滚备份，替换掉2即可
class Mylog
{
	public:
		Mylog();
		~Mylog();
	public:
		void error(const char * msg);
		void warn(const char * msg);
		void info(const char * msg);
		void debug(const char * msg);

		void set_priority(const char *);

	private:
		//布局
		log4cpp::PatternLayout * pLayout_cout_;
		
		//依附目标文件
		log4cpp::OstreamAppender * osAppender_;
		
		//种类
		log4cpp::Category & root_;
};

//引用必须用初始化列表初始化
Mylog::Mylog():root_(log4cpp::Category::getInstance("infoCategory"))
{
	std::cout << "Mylog()" << std::endl;
	pLayout_cout_ = new log4cpp::PatternLayout();
	pLayout_cout_ -> setConversionPattern("%d: %p %c %x: %m%n");
	
	osAppender_ = new log4cpp::OstreamAppender("osAppender_", &std::cout); 
	osAppender_ -> setLayout(pLayout_cout_);

	//log4cpp::Category & root_ = log4cpp::Category::getInstance("infoCategory");

	root_.addAppender(osAppender_);
}


void Mylog::set_priority(const char * prioritylevel)
{
	if(prioritylevel == "DEBUG")
		root_.setPriority(log4cpp::Priority::DEBUG);
	else if(prioritylevel == "ERROR")
		root_.setPriority(log4cpp::Priority::ERROR);
	else if(prioritylevel == "WARN")
		root_.setPriority(log4cpp::Priority::WARN);
	else if(prioritylevel == "INFO")
		root_.setPriority(log4cpp::Priority::INFO);
	else
		root_.setPriority(801);
}

void Mylog::error(const char * msg)
{
	std::cout << "error()" << std::endl;
	root_.error(msg);
}

void Mylog::warn(const char * msg)
{
	std::cout << "warn()" << std::endl;
	root_.warn(msg);
}
void Mylog::info(const char * msg)
{
	std::cout << "info()" << std::endl;
	root_.info(msg);
}

void Mylog::debug(const char * msg)
{
	std::cout << "debug()" << std::endl;
	root_.debug(msg);
}

Mylog::~Mylog()
{
	std::cout << "~Mylog()" << std::endl;
	log4cpp::Category::shutdown();
}


int main(int argc, char * argv[])
{
	const char * msg = "hello,world";
	const char * priority = "DEBUG";
	Mylog mylog;
	mylog.set_priority(priority);
	mylog.error(msg);
	mylog.warn(msg);
	mylog.info(msg);
	mylog.debug(msg);

	return 0;
}


