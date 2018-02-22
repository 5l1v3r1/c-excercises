#include <iostream>
#include <string>
#include <memory>

struct Fred
{
	Fred() { std::cout << "Fred created, this=" << this << std::endl; }
	~Fred() { std::cout << "Fred destroyed, this=" << this << std::endl; }
};

struct FredsHouse
{
	FredsHouse(const std::string& f)
		: fridge(f) { std::cout << "FredsHouse created, this=" << this << std::endl; }
	~FredsHouse() { std::cout << "FredsHouse destroyed, this=" << this << std::endl; }

	void state()
	{
		if (visitor)
			std::cout << "Fred this= " << visitor.get() << " is in the house" << std::endl;
		else
			std::cout << "No visitors" << std::endl;
	}

	std::string fridge;
	Fred f1;
	Fred f2;
	std::unique_ptr<Fred> visitor;

};

std::unique_ptr<FredsHouse> houseFactory(const std::string& f)
{
	std::unique_ptr<FredsHouse> p = std::make_unique<FredsHouse>(f);
	return p;
}

int main(int argc, char** argv)
{
	FredsHouse* p = nullptr;
	for (int i = 0; i < 4; i++)
	{
	 	p = new FredsHouse("wine" + std::to_string(i));
		//
		delete p;
	}

		// x
	std::cout << "hello, world!, in the fridge=" << p->fridge << std::endl;
	delete p;
}
