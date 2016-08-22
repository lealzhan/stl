#include <iostream>

//common
//multi-thread unsafe
class Singelton
{
private:
	Singelton(){};
	~Singelton(){};
	static Singelton* m_instance;
public:
	
	static Singelton* GetInstance()
	{
		if (m_instance == nullptr)
			m_instance = new Singelton();

		return m_instance;
	};

	static void DestroyInstance()                  // 销毁单例对象的空间
	{
		if (m_instance != nullptr)
		{
			delete m_instance;
			m_instance = nullptr;
			std::cout << "singelton destroyed" << std::endl;
		}
	};
};


//Singelton* Singelton::instance;  //or?
//Singelton* Singelton::instance = nullptr;  //or?
Singelton* Singelton::m_instance = new Singelton();



int main()
{
	Singelton* singelton0 =  Singelton::GetInstance();
	Singelton* singelton1 = Singelton::GetInstance();

	if (singelton0 == singelton1)
		std::cout << "singelton works" << std::endl;

	Singelton::DestroyInstance();
	return 0;
}