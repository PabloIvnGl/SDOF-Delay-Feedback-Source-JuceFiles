#include "tools.h"


WindowVector::WindowVector(int length)
{
	this->length = length;
	this->values = new float[length];
}

WindowVector::~WindowVector()
{
}

void WindowVector::SetALLValues(float val)
{
	for (int n = 0; n < this->length; n++) {
		this->values[n] = val;
	}
}

void WindowVector::SetRamp(float val_ini, float val_end)
{
	float inc = 0.0;
	if (val_end > val_ini)
	{
		inc = (val_end - val_ini) / (this->length-1);
	}else
	{
		inc = - ((val_ini - val_end) / (this->length-1));
	}
	this->values[0] = val_ini;
	for (int n = 1; n < this->length; n++) {
		this->values[n] = this->values[n-1] + inc;
	}
}

void WindowVector::ToPrint(std::string title)
{
	std::cout << title << std::endl;
	for (int n = 0; n < this->length; n++) {
		std::cout << n << ") " << this->values[n] << std::endl;
	}

}

float WindowVector::getValue(int n) {
	return this->values[n];
}