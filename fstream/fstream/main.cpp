//http://www.cnblogs.com/JCSU/articles/1190685.html
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	ifstream inputfile("TODO_LIST.txt");
	if (!inputfile) // (!inputfile.is_open())  //works too
	{
		cerr << "error" << endl;
	}


	//-- getline of ifstream --
	const int LINE_LENGTH = 256;// 100; //too small
	char str[LINE_LENGTH];
	while (inputfile.getline(str, LINE_LENGTH)) //note if one line exceed LINE_LENGTH, this while while be borken
	{
		cout  << str << endl;
	}

	/*string s;  
	while (inputfile.getline(s))   //no such func
	{
		cout << str << endl;
	}*/

	//-- getline of ifstream END --


	//-- getline in string.h --
	if (0)
	{
		string s;
		while (getline(inputfile, s, '*'))
		{
			cout << s << endl;
		}

		while (getline(inputfile, s))
		{
			cout << s << endl;
		}

		while (getline(inputfile, s, '\n'))
		{
			cout << s << endl;
		}
	}
	//-- getline in string.h -- END


	return 0;
}