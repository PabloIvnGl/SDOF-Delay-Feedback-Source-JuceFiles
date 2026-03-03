#pragma once


#include <iostream>
#include <string>



class WindowVector
{
public:
	WindowVector(int length);
	~WindowVector();

	void SetALLValues(float val);
	void SetRamp(float val_ini, float val_end);
	void ToPrint(std::string title);
	float getValue(int n);

private:
	int length;
	float* values = NULL;

};
