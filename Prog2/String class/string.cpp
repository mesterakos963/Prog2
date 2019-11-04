#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
class mystring
{
	char* data;
	public:
	char* Data() const {return data;}
	mystring(const char* p)
	{
		cout<<"konstruktor"<<endl;
		size_t size = strlen(p) + 1;
		data = new char[size];
		memcpy(data, p, size);
	}
	~mystring()
	{
	delete[] data;
	}
	mystring(const mystring& regi)
	{
		cout<<"másoló konstruktor"<<endl;
		size_t size = strlen(regi.data) + 1;
		data = new char[size];
		memcpy(data, regi.data, size);
	}
	mystring& operator=(const mystring& regi)
	{
		cout<<"másoló értékadás"<<endl;
		delete[] data;
		size_t size = strlen(regi.data) + 1;
		data = new char[size];
		memcpy(data, regi.data, size);
		return *this;
	}
	mystring (mystring&& regi )
	{
		cout<<"mozgató konstruktor"<<endl;
		data = regi.data;
		regi.data = nullptr;
	}
	mystring& operator=(mystring&& regi)
	{
		cout<<"mozgató értékadás"<<endl;
		swap(data, regi.data);
		return *this;
	}

	char operator[](int i) 
	{
		size_t size = strlen(data) -1;
		if( i > size ) 
		{ 
			cout << "Out of range" <<endl; 
		}
		return data [i];
	}
};

ostream& operator<<(ostream& os,const mystring& x)
{
	return os<<x.Data();
}
int main()
{
	mystring a("szoveg helye");
	cout<<a[5]<<endl;
}