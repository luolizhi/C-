/*************************************************************************
	> File Name: log.h
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Mon 27 Jul 2015 10:30:56 AM CST
 ************************************************************************/

#ifndef __LOG_H__
#define __LOG_H__

//singelton
class Log
{
public:
	static Log *getInstance();//本类实例
	void writeLog(const std::string &log_msg,
				 const char *file = __FILE__,
				 int line = __LINE__,
				 const char *date = __DATE__,
				 const char *timer = __TIME__,
				 const char *func = __PRETTY_FUNCTION__
			);

private:
	Log();
	virtual ~Log();
	static Log *loger_;
	static MutexLock locker_;
	std::ofstream writer_;
};

#define WRITE_STR(str) {Log *p_log = Log::getInstance(); p_log->writeLog(str,__FILE__,__LINE__,__DATE__,__TIME__,__PRETTY_FUNCTION__);}

#define WRITE_NUM(str,n) {char *buf = new char[20]; sprintf(buf, "%d", n); std::string len(buf); str += len; delete []buf; WRITE_STR(str);}

#endif


