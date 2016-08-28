//#include <iostream>
//#include <thread>
//using namespace std;
//
//void thread_entry(const char* arg)
//{
//	cout << "thread " << this_thread::get_id() << " created: " << arg << endl;
//}
//
//int main()
//{
//	thread thrd(thread_entry, "hello world");
//	thrd.join();
//	return 0;
//
//
//
//}

//// example for thread::join
//#include <iostream>       // std::cout
//#include <thread>         // std::thread, std::this_thread::sleep_for
//#include <chrono>         // std::chrono::seconds
//
//void pause_thread(int n)
//{
//	std::this_thread::sleep_for(std::chrono::seconds(n));
//	std::cout << "pause of " << n << " seconds ended\n";
//}
//
//std::thread* create_thread()
//{
//	std::thread* new_thread = new std::thread(pause_thread, 4);
//	//std::cout << "create thread"<< std::endl;
//	return new_thread;
//}
//
//int main()
//{
//	std::cout << "Spawning 4 threads...\n";
//	std::thread t1(pause_thread, 1);
//	std::thread t2(pause_thread, 2);
//	std::thread t3(pause_thread, 3);
//	std::thread* t4 = create_thread();
//	
//	std::cout << "Done spawning threads. Now waiting for them to join:\n";
//	t1.join();
//	t2.join();
//	t3.join();
//	t4->join();
//	std::cout << "All threads joined!\n";
//
//
//	
//
//	return 0;
//}

///////////////////////////////// -- vector -- ////////////////////////////////////
// //example for thread::join
//#include <iostream>       // std::cout
//#include <thread>         // std::thread, std::this_thread::sleep_for
//#include <chrono>         // std::chrono::seconds
//#include <vector>
//#include <mutex>
//using  namespace std;
//
//class PrintClass
//{
//public:
//	PrintClass() :m_i(0)
//	{
//	}
//	PrintClass(int _i)
//	{
//		m_i = _i;
//	}
//	
//	void print()
//	{
//		//std::cout <<"task:"<<m_i << " ";// << std::endl;
//		long xx = 0;
//		while (xx<300000000)
//		{
//			xx++;
//		}
//		//std::cout << "task:" << m_i << std::endl;
//	}
//
//	int m_i;
//};
//
//std::mutex mtx;           // locks access to counter
//
//void ThreadFunc(const int t_i, const vector<PrintClass*> &vPrintClass, const int task_start_id, const int task_end_id)
//{
//	//cout << "new thread:" << i << " generated" << endl;
//	//std::this_thread::sleep_for(std::chrono::seconds(1));
//
//	cout << "new thread:" << t_i << " start" << endl;
//	//std::cout << "thread id " << std::this_thread::get_id() << std::endl;
//	//std::this_thread::sleep_for(std::chrono::seconds(5));
//	
//	for (int i = task_start_id; i < task_end_id; i++)
//	{
//		vPrintClass[i]->print();
//		
//		mtx.lock();
//			cout << "thread:" << t_i << " finishes a new task" << endl;
//		mtx.unlock();
//		
//	}
//	mtx.lock();
//	cout << "new thread:" << t_i << " end" << endl << endl;
//	mtx.unlock();
//}
//
//int main()
//{
//	time_t start, stop;
//	start = time(NULL);
//
//	const int taskNumber = 100;
//	int thread_number = 1;// thread::hardware_concurrency(); //main thread is already busy?
//
//	if (!thread_number)
//	{
//		std::cout << "thread number is null" << std::endl;
//		return false;
//	}
//
//	vector<PrintClass*> vPrintClass;
//	for (int i = 0; i < taskNumber; i++)
//	{
//		PrintClass* print_calss = new PrintClass(i);
//		vPrintClass.push_back(print_calss);
//	}
//
//	int tasksPerThread =  taskNumber / thread_number;
//	vector<thread*> v_tThreads;
//	//thread 0 ~ thread_number-1
//	for (int i = 0; i < thread_number - 1; i++)
//	{
//		std::cout << "thread id of the generate-thread-loop " << std::this_thread::get_id() << std::endl;
//		
//		int task_start_id = i * tasksPerThread;
//		int task_end_id = (i+1) * tasksPerThread;
//		thread* temp = new thread(ThreadFunc, i, vPrintClass, task_start_id, task_end_id);
//		v_tThreads.push_back(temp);
//		//std::this_thread::sleep_for(std::chrono::seconds(1));
//		
//	}
//	//thread thread_number (lask thread)
//	{
//		int i = thread_number - 1;
//		int task_start_id = i * tasksPerThread;
//		int task_end_id = taskNumber - 1;
//		thread* temp = new thread(ThreadFunc, i, vPrintClass, task_start_id, task_end_id);
//		v_tThreads.push_back(temp);
//	}
//	
//	for (int i = 0; i < v_tThreads.size(); i++)
//	{
//		v_tThreads[i]->join();
//	}
//
//	stop = time(NULL);
//	printf("Use Time:%ld\n", (stop - start));
//
//	system("pause");
//	return 0;
//}



////////////////////////////// -- set -- ////////////////////////////////////
//example for thread::join
#include <iostream>       // std::cout
#include <thread>         // std::thread, std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <set>
#include <vector>
#include <mutex>
using  namespace std;

class PrintClass
{
public:
	PrintClass() :m_i(0)
	{
	}
	PrintClass(int _i)
	{
		m_i = _i;
	}

	void print()
	{
		//std::cout <<"task:"<<m_i << " ";// << std::endl;
		long xx = 0;
		while (xx<300000000)
		{
			xx++;
		}
		//std::cout << "task:" << m_i << std::endl;
	}

	int m_i;
};

std::mutex mtx;           // locks access to counter

void ThreadFunc(const int t_i, const set<PrintClass*> &sPrintClass, const set<PrintClass*>::iterator start_it, const set<PrintClass*>::iterator end_it)
{
	//cout << "new thread:" << i << " generated" << endl;
	//std::this_thread::sleep_for(std::chrono::seconds(1));

	cout << "new thread:" << t_i << " start" << endl;
	//std::cout << "thread id " << std::this_thread::get_id() << std::endl;
	//std::this_thread::sleep_for(std::chrono::seconds(5));

	for (set<PrintClass*>::iterator it = start_it; it != end_it; it++)
	{
		(*it)->print();

		mtx.lock();
		cout << "thread:" << t_i << " finishes a new task" << endl;
		mtx.unlock();

	}
	mtx.lock();
	cout << "new thread:" << t_i << " end" << endl << endl;
	mtx.unlock();
}

int main()
{
	time_t start, stop;
	start = time(NULL);

	const int taskNumber = 100;
	int thread_number = thread::hardware_concurrency()-1; //main thread is already busy?

	if (!thread_number)
	{
		std::cout << "thread number is null" << std::endl;
		return false;
	}

	set<PrintClass*> sPrintClass;
	for (int i = 0; i < taskNumber; i++)
	{
		PrintClass* print_calss = new PrintClass(i);
		sPrintClass.insert(print_calss);
	}

	int tasksPerThread = taskNumber / thread_number;
	vector<thread*> v_tThreads;
	//thread 0 ~ thread_number-1
	set<PrintClass*>::iterator start_it = sPrintClass.begin();
	set<PrintClass*>::iterator end_it = sPrintClass.begin();
	for (int j = 0; j < tasksPerThread; j++)
		end_it++;

	for (int i = 0; i < thread_number - 1; i++)
	{
		std::cout << "thread id of the generate-thread-loop " << std::this_thread::get_id() << std::endl;

		thread* temp = new thread(ThreadFunc, i, sPrintClass, start_it, end_it);
		v_tThreads.push_back(temp);
		for (int j = 0; j < tasksPerThread; j++)
			start_it++;
		for (int j = 0; j < tasksPerThread; j++)
			end_it++;
	}
	//thread thread_number (lask thread)
	{
		int i = thread_number;
		end_it = sPrintClass.end();
		thread* temp = new thread(ThreadFunc, i, sPrintClass, start_it, end_it);
		v_tThreads.push_back(temp);
	}

	for (int i = 0; i < v_tThreads.size(); i++)
	{
		v_tThreads[i]->join();
	}

	stop = time(NULL);
	printf("Use Time:%ld\n", (stop - start));

	system("pause");
	return 0;
}