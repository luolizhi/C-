#include<iostream>
#include<unistd.h>
class Mutex
{

	public:
		//构造函数
		Mutex()
		{
			std::cout << "Mutex()" << std::endl;
			pthread_mutex_init(&mutex_, NULL);
		}
		
		void lock()
		{
			std::cout << "lock()" << std::endl;
			pthread_mutex_lock(&mutex_);
		}
		void unlock()
		{
			std::cout << "unlock()" << std::endl;
			pthread_mutex_unlock(&mutex_);
		}

		//析构函数
		~Mutex()
		{
			std::cout << "~Mutex()" << std::endl;
			pthread_mutex_destroy(&mutex_);
		}
	private:
		pthread_mutex_t mutex_;
	private:
		Mutex(const Mutex &rhs);	//禁止复制构造函数
		Mutex & operator=(const Mutex &rhs);
};


int main()
{
	Mutex m1;
	m1.lock();
	sleep(3);
	m1.unlock();

	return 0;
}
