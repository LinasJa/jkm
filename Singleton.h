#include <string>
#include <fstream>

using namespace std;

class Singleton {
public:
	static Singleton* Instance();
	void writeToLogFile();
	ifstream fin;
	double _pow(double x);
	int ivedimas();

private:
	Singleton() { ifstream fin("fin.txt"); };  // Private so that it can  not be called
	Singleton(Singleton const&) {};             // copy constructor is private
	Singleton& operator=(Singleton const&) {};  // assignment operator is private
	static Singleton* m_pInstance;
};