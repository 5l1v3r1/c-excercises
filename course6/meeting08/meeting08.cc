#include <iostream>
#include <string>
#include <memory>

struct Record
{
	Record() { std::cout << "Record(), this=" << this << std::endl; }
	Record(int x) { id = x; std::cout << "Record(int), this=" << this << std::endl; }
	~Record() { std::cout << "~Record(), this=" << this << std::endl; }
	
	std::string name;
	int id;
	float factor;
};

int main(int argc, char** argv)
{
	std::unique_ptr<Record> datumPtr = std::make_unique<Record>(77);
	datumPtr->name = "Hello 1234567890 1234567890";

	auto p = std::make_unique<int>(7);

	std::cout << datumPtr->name << std::endl;
	std::cout << *p << std::endl;
}

