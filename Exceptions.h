#pragma once
#include <iostream>
using namespace std;

class IException {
public:
	virtual void show() = 0;
};

class IntErr : public IException {
	int err;
public:
	IntErr(int e = 0) : err(e) {}
	void show() { cout << "code error: " << err << "\n"; }
};

class StrErr : public IException {
	string err;
public:
	StrErr(string e = "") : err(e) {}
	void show() { cout << "error: " << err << "\n"; }
};