// CppProgram.cpp : Defines the entry point for the console application.
// Test cases

#include "stdafx.h"
#include <iostream>
#include "mytime0.h"
#include <cstdlib>                                    // rand(), srand()
#include <ctime>                                      // time()
#include "vect.h"
// to save successive positions in a file
#include <fstream>

// sizeof empty class is 1; sizeof class with virtual is 8 (x64) 
class tempClass
{
public:
	tempClass() {};
	virtual ~tempClass() {};
	virtual void func(void) {};
};

//
class CMyString {
public:
	CMyString(char* pData = NULL);
	CMyString(const CMyString& str);
	// CMyString(CMyString other); compiler Err: pass-by-value parameter is not allowed in C++ standard!
	~CMyString(void);
	CMyString& operator=(const CMyString &str);

	char & operator[](int i);
	const char & operator[](int i) const;
private:
	char* m_pData;
};

// Default constructor with no arguments and does nothing; A constructor with arguments still can be a default
// constructor if all its arguments have default values
CMyString::CMyString(char* pData)
{
	if (pData != NULL) {
		m_pData = new char[strlen(pData) + 1];
		strcpy(m_pData, pData);
	}
	else {
		m_pData = pData;
	}
}

/*
explicit Copy constructor, deep copy, is used to copy an object to a newly created object.That is, it¡¯s used
during initialization, including passing function arguments by value and not during ordinary
assignment.
is used: you explicitly init a new object to a existing object
default copy constructor: performs a member-by-member copy of the nonstatic members,shallow copy
*/
CMyString::CMyString(const CMyString& str)
{
	// cf Assignment operator, no mem allocated for target object
	if (str.m_pData != NULL) {
		m_pData = new char[strlen(str.m_pData) + 1];
		strcpy(m_pData, str.m_pData);
	}
	else {
		m_pData = str.m_pData;
	}
}

CMyString::~CMyString(void)
{
	if (m_pData != NULL) {
		std::cout << this->m_pData << " is destructed." << std::endl;
		delete [] m_pData;
	}
}

// Assignment operator
// Assignment does not create a new object
// is used when you assign one object to another existing object
// is not necessarily used when initializing an object
// default Assignment operator: member-to-member copy, static data members are unaffected 
// Exception Safety
CMyString& CMyString::operator=(const CMyString &str)
{
	if (this != &str) {
		// protect against assigning an object to itself
		CMyString strTemp(str);
		char* pTemp = strTemp.m_pData;
		strTemp.m_pData = m_pData;
		m_pData = pTemp;
		// cf copy construct: Because the target object may already refer to previously allocated data, the function
		// should use delete[] to free former obligations. -- here, release 'strTemp'
	}
	return *this;
}

// Bracket Notation: In C++ the two bracket symbols constitute a single operator
// this binary C++ operator places one operand in front of the first bracket and the other operand 
// between the two brackets, ex city[2]: city is 1st operand, 2 is thee 2nd operand.
// read-write char access for non-const String
char & CMyString::operator[](int i)
{
	return m_pData[i];
}
// read-only char access for const String, promise not to alter data
const char & CMyString::operator[](int i) const
{
	return m_pData[i];
}


/*
The srand() function lets you override the default seed value and initiate a different 
sequence of random numbers.This program uses the return value of time(0) to set the seed.
The time(0) function returns the current
calendar time, often implemented as the number of seconds since some specific date.
(More generally, time() takes the address of a type time_t variable and puts the time into
that variable and also returns it. Using 0 for the address argument obviates the need for an
otherwise unneeded time_t variable.) Thus, the following statement sets a different seed
each time you run the program, making the random output appear even more random:
srand(time(0));
The rand() function works by applying an algorithm to an initial seed value to get a random value.
That value/pseudorandom is used as the seed for the next function call, and so on.
*/

int main()
{
	using std::cout;
	using std::endl;
	int len = sizeof(tempClass);

	// test CMyString
	CMyString objString("Hi");
	CMyString objString1("there");
	CMyString objString3;                             // default construct (NULL)
	CMyString ditto(objString);                       // Copy constructor
	CMyString metoo = objString;                      // ..
	CMyString also = CMyString(objString);            // ..
	CMyString *pCMyString = new CMyString(objString); // .., initializes an anonymous object to objString and assiigns addr to
	objString1 = objString;                           // Assignment operator
	
	const CMyString answer("futile");
	//answer[1] = 'i';
	objString[1] = 'o';                               // call CMyString::operator[](int)
	cout << objString[1];                             // uses non-const version of operator[]()
	cout << answer[1];                                // uses const version of operator[]()
	cout << endl;

	// test Time
	Time planning;
	Time coding(2, 40);
	Time fixing(5, 55);
	Time total;
	planning.Reset(3, 20);
	cout << "planning time = ";
	planning.Show();
	cout << endl;

	//total = coding.Sum(fixing);
	total = coding.operator+(fixing);                 // function notation
	total = coding + fixing;                          // operator notation
	cout << "coding + fixing = ";
	total.Show();
	cout << endl;

	total = planning + coding + fixing;               // do planning+coding first, then +fixing
	cout << "planning+ coding + fixing = ";
	total.Show();
	cout << endl;

	total = fixing - coding;
	total = coding - fixing;

	// test Overloading *
	total = planning * 2.75;                          // call member function
	total = 2.75 * planning;                          // call friend func, operator*(2.75, B);

	// test Overloading <<
	cout << coding << "; " << fixing << endl;

	// test vect
	using namespace std;
	using namespace VECTOR;
	Vector shove;
	shove.reset(100, 300);
	cout << shove << endl;

	ofstream fout;
	fout.open("thewalklog.txt");
	srand(time(0));                                   // seed random-number generator,override the default seed value
	double direction, target, dstep;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;

	cout << "Enter target distance (q to quit):";
	while (cin >> target)
	{
		dstep = 2.5;   // step length
		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;                   // placing result in the RECT mode

			fout << result.magval() << "(magnitude), ";
			fout << result << endl;                   // call operator<<(fout, result), log in file

			steps++;
		}
		cout << "After " << steps << "steps, the subject location:\n";
		cout << result << endl;

		fout << "After " << steps << "steps, the drunks walk away from the post, exceeds "
			 << target << " feet.\n";

		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quit):";
	}
	cout << "Bye!\n";
	fout.close();

	cin.clear();
	while (cin.get() != '\n')
		continue;

    return 0;
}

