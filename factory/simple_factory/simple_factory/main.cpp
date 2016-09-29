//http://blog.csdn.net/chollima/article/details/3985570

#include <iostream>
#include <string>

#include "rapidxml\rapidxml.hpp"
#include "rapidxml\rapidxml_utils.hpp"

//if  destructor is not virtual, when we destroy the Product, only base class's destructor will be called, which is not safe.
#define VIRTUAL_DESTRUCT
using namespace std;

class Product
{
public: 
	Product()
	{
		cout << "Create Product" << endl;
	}
#ifdef VIRTUAL_DESTRUCT
	virtual ~Product()
	{
		cout << "Destroy Product" << endl;
	}
#else
	~Product()
	{
		cout << "Destroy Product" << endl;
	}
#endif

	virtual void printName(){ cout<< "Product" <<endl; }
	//void printName(){ cout << "Product" << endl; }

};

class Product0 : public Product
{
public:
	Product0()
	{
		cout << "Create Product0" << endl;
	}

#ifdef VIRTUAL_DESTRUCT
	virtual ~Product0()
	{
		cout << "Destroy Product0" << endl;
	}
#else
	~Product()
	{
		cout << "Destroy Product0" << endl;
	}
#endif

	void printName(){ cout << "Product0" << endl; }

};

class Product1 : public Product
{
public:
	Product1()
	{
		cout << "Create Product1" << endl;
	}

#ifdef VIRTUAL_DESTRUCT
	virtual ~Product1()
	{
		cout << "Destroy Product1" << endl;
	}
#else
	~Product()
	{
		cout << "Destroy Product1" << endl;
	}
#endif

	void printName(){ cout << "Product1" << endl; }

};

class simple_factory
{
public:
	static Product* CreateProduct(int numb);
};

Product* simple_factory::CreateProduct(int numb)
{
	if (numb == 0)
	{
		return new Product0();
	}
	else if (numb == 1)
	{
		return new Product1();
	}
	else
	{
		cout << "can not create" << endl;
		return nullptr;
	}
}

bool ReadCreateConfig(string xmlConfigFile, vector<Product*> &vecProduct)
{
	rapidxml::file<> file(xmlConfigFile.c_str());
	rapidxml::xml_document<> doc;

	doc.parse<0>(file.data());
	rapidxml::xml_node<>* xmlRoot = doc.first_node(); //rootnode:overalConfig

	//first level child
	rapidxml::xml_node<>* xmlNode = xmlRoot->first_node("product");
	string productString(xmlNode->value());
	int productInt = stoi(productString);

	vecProduct.push_back(simple_factory::CreateProduct(productInt));

	//first level child END
	
	return true;
}


int main()
{
	/*Product * xx = simple_factory::CreateProduct(0);
	xx = simple_factory::CreateProduct(1);*/
	vector<Product*> vecProduct;
	ReadCreateConfig("xmlConfigFile.xml", vecProduct);
	for (auto it : vecProduct)
	{
		it->printName();
		it->~Product();
	}

	return 0;
}
