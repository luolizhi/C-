#include<iostream>
#include<pthread.h>

class Mutexlock
{
	public:
		Mutexlock()
		{
			std::cout << "Mutexlock()" << std::endl;
			pthread_mutex_init(&mutex_,NULL);
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
		
		pthread_mutex_t * getMutexlockPtr()
		{
			return &mutex_;
		}
		~Mutexlock()
		{
			std::cout << "~Mutexlock()" << std::endl;
			pthread_mutex_destroy(&mutex_);
		}
	private:
		pthread_mutex_t mutex_;
	private:
		Mutexlock(const Mutexlock & rhs);//禁止复制和赋值
		Mutexlock & operator=(const Mutexlock & rhs);
};


class Condition
{
	public:
		Condition(Mutexlock & mutex):mutex_(mutex)
		{
			std::cout << "Condition()" << std::endl;
			pthread_cond_init(&cond_,NULL);
		}
		
		void wait()
		{
			std::cout << "wait()" << std::endl;
			pthread_cond_wait(&cond_, mutex_.getMutexlockPtr());
		}

		void signal()	//pthread_cond_wait(&cond,&mutex);
		{
			std::cout << "signal()" << std::endl;
			pthread_cond_signal(&cond_);
		}

		void signal_all()
		{
			std::cout << "broadcast()" << std::endl;
			pthread_cond_broadcast(&cond_);
		}
		~Condition()
		{
			std::cout << "~Condition()" << std::endl;
			pthread_cond_destroy(&cond_);
		}

	private:
		pthread_cond_t cond_;
		Mutexlock & mutex_ ;
	private:
		Condition(const Condition & rhs);//禁止复制和赋值
		Condition & operator=(const Condition & rhs);
};

int main()
{
	Mutexlock mutex;
	Condition cond(mutex);
	cond.wait();
	std::cout << "hello world" << std::endl;
	cond.signal();

	return 0;
}
