#include <iostream>
using namespace std;
#include <vector>

class StrVec{

public:
	StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr){}

	StrVec(const StrVec&);
	StrVec(StrVec &&s) noexcept;
	StrVec &operator=(const StrVec&);
	StrVec &operator=(StrVec &&rhs) noexcept;
	~StrVec();

private:
	static allocator<string> alloc;

	string *elements;
	string *first_free;
	string *cap;

};


StrVec::StrVec(StrVec &&s) noexcept
:elements(s.elements), first_free(s.first_free), cap(s.cap)
{
	s.elements = s.first_free = s.cap = nullptr;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept
{
	if(this != &rhs)
	{
		//free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;

		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}

	return *this;

}


int main()
{ 
	vector<int> v1;
	v1.push_back(2);
	vector<int> &&v2 = move(v1);

	v2.push_back(4);

	cout<<v1[1]<<endl;
	return 0;
}
