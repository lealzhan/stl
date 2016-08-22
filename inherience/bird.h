typedef float real;

class Vector3
{
public:
	real x;
	real y;
	real z;

	Vector3(){
		x = 0; y = 0; z = 0;
	};
	~Vector3(){};
};

//Vector3::Vector3()
//{}
//Vector3::~Vector3()
//{}

class Bird
{
public:
	Bird(){};
	virtual ~Bird(){};

	Vector3 pos;
};

class FlyingBird : public Bird
{
public:
	FlyingBird(){};
	virtual ~FlyingBird(){};
	virtual void Fly() = 0;
};

class Penguin : public Bird
{
public:
	Penguin();
	virtual ~Penguin();
	
	virtual void Swim();
};


class Lark : public FlyingBird
{
public:
	Lark();
	virtual ~Lark();

	virtual void Fly();
};