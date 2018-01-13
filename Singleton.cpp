#include "Singleton.h"
#include "iostream"

using namespace std;

// Global static pointer used to ensure a single instance of the class.
Singleton* Singleton::m_pInstance = NULL;

/** This function is called to create an instance of the class.
Calling the constructor publicly is not allowed. The constructor
is private and is only called by this Instance function.
*/

Singleton* Singleton::Instance()
{
	if (!Singleton::m_pInstance)   // Only allow one instance of class to be generated.
		Singleton::m_pInstance = new Singleton;

	return Singleton::m_pInstance;
}

int Singleton::ivedimas()
{
	double x;
	do
	{
		//Patikrina skaiciu
		while (!(Singleton::Instance()->fin >> x) || x != int(x))
		{
			Singleton::Instance()->fin.clear();
			Singleton::Instance()->fin.ignore();
		}

		if (x != int(x))
		{
			Singleton::Instance()->fin.clear();
			Singleton::Instance()->fin.ignore();
			x = 0.5;
		}

	} while (x != int(x));

	return x;
}

double Singleton::_pow(double x)
{
	return x*x;
}

void Singleton::writeToLogFile()
{
	cout << "Hello Singleton world" << endl;
}