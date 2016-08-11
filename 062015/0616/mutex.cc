#include<iostream>

class Mutex
{
	public:
		//构造函数
		Mutex():isLocking_(false)
		{
			std::cout << "Mutex()" << std::endl;
			pthread_mutex_init(&mutexlock_, NULL);	
		}
		bool isLocked()
		{
			return isLocking_;
		}
		
		void lock()
		{
			std::cout << "lock()" << std::endl;
			pthread_mutex_lock(&mutexlock_);
			isLocking_ = true;
		}
		void unlock()
		{
			std::cout << "unlock()" << std::endl;
			pthread_mutex_unlock(&mutexlock_);
			isLocking_ = false;
		}

		//析构函数
		~Mutex()
		{
			std::cout << "~Mutex()" << std::endl;
			pthread_mutex_destroy(&mutexlock_);
		}

	private:
		pthread_mutex_t mutexlock_;
		bool isLocking_;
	private:
		Mutex(const Mutex & rhs);
		Mutex & operator=(const Mutex & rhs);
};

int main()
{
	Mutex mlock;
	if(!mlock.isLocked())
	{
	mlock.lock();
	std::cout << "hello world" <<std::endl;
	mlock.unlock();
	}
	return 0;
}
