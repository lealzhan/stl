// sort algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector

bool myfunction (int i,int j) { return (i<j); }
bool decending (int i,int j) { return (i>j); }

struct myclass {
	bool operator() (int i,int j) { return (i<j);}
} myobject;

int main () {
	int myints[] = {32,71,12,45,26,80,53,33};
	std::vector<int> myvector (myints, myints+8);               // 32 71 12 45 26 80 53 33

	

	//// using default comparison (operator <):
	//std::sort (myvector.begin(), myvector.begin()+4);           //(12 32 45 71)26 80 53 33

	//// using function as comp
	//std::sort (myvector.begin()+4, myvector.end(), myfunction); // 12 32 45 71(26 33 53 80)

	//// using object as comp
	//std::sort (myvector.begin(), myvector.end(), myobject);     //(12 26 32 33 45 53 71 80)


	// using default comparison (operator <):
	std::sort (myvector.begin(), myvector.end());           //(12 26 32 33 45 53 71 80)
	// print out content:
	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	// using function as comp
	std::sort (myvector.begin(), myvector.end(), myfunction);           //(12 26 32 33 45 53 71 80)
	// print out content:
	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';


	// using function as comp
	std::sort (myvector.begin(), myvector.end(), decending);           //(12 26 32 33 45 53 71 80)
	// print out content:
	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	return 0;
}






//// search algorithm example
//#include <iostream>     // std::cout
//#include <algorithm>    // std::search
//#include <vector>       // std::vector
//
//bool mypredicate (int i, int j) {
//	return (i==j);
//}
//
//int main () {
//	std::vector<int> haystack;
//
//	// set some values:        haystack: 10 20 30 40 50 60 70 80 90
//	for (int i=1; i<10; i++) haystack.push_back(i*10);
//
//	// using default comparison:
//	int needle1[] = {40,50,60,70};
//	std::vector<int>::iterator it;
//	it = std::search (haystack.begin(), haystack.end(), needle1, needle1+4);
//
//	if (it!=haystack.end())
//		std::cout << "needle1 found at position " << (it-haystack.begin()) << '\n';
//	else
//		std::cout << "needle1 not found\n";
//
//	// using predicate comparison:
//	int needle2[] = {20,30,50};
//	it = std::search (haystack.begin(), haystack.end(), needle2, needle2+3, mypredicate);
//
//	if (it!=haystack.end())
//		std::cout << "needle2 found at position " << (it-haystack.begin()) << '\n';
//	else
//		std::cout << "needle2 not found\n";
//
//	return 0;
//}






//// find example
//#include <iostream>     // std::cout
//#include <algorithm>    // std::find
//#include <vector>       // std::vector
//
//int main () {
//	// using std::find with array and pointer:
//	int myints[] = { 10, 20, 30, 40 };
//	/*int * p;
//
//	p = std::find (myints, myints+4, 1);
//	if (p != myints+4)
//	std::cout << "Element found in myints: " << *p << '\n';
//	else
//	std::cout << "Element not found in myints\n";*/
//
//	// using std::find with vector and iterator:
//	std::vector<int> myvector (myints,myints+4);
//	std::vector<int>::iterator it;
//
//	it = find (myvector.begin(), myvector.end(), 30);
//	if (it != myvector.end())
//		std::cout << "Element found in myvector: " << *it << '\n';
//	else
//		std::cout << "Element not found in myvector\n";
//
//	return 0;
//}





//// count algorithm example
//#include <iostream>     // std::cout
//#include <algorithm>    // std::count
//#include <vector>       // std::vector
//
//int main () {
//	// counting elements in array:
//	int myints[] = {10,20,30,30,20,10,10,20};   // 8 elements
//	int mycount = std::count (myints, myints+8, 10);
//	std::cout << "10 appears " << mycount << " times.\n";
//
//	// counting elements in container:
//	std::vector<int> myvector (myints, myints+8);
//	mycount = std::count (myvector.begin(), myvector.end(), 20);
//	std::cout << "20 appears " << mycount  << " times.\n";
//
//	return 0;
//}