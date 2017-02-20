#include "TString.h"


TString::~TString()
{
	delete[] Data;
}


TString::TString()
{
	Data = new char[1];
	Data[0] = '\0';
}


TString::TString(const TString& rhs)
{
	size_t len = Size() + 1;
	Data = new char[len];
	for (size_t k = 0; k < len; k++)
		Data[k] = rhs.Data[k];
}

TString::TString(const char * data)
{
	size_t len = 0;
	while (data[len] != '\0')
	{
		len++;
	}
	Data = new char[len + 1];
	for (int i = 0; i < len + 1; i++)
	{
		Data[i] = data[i];
	}
}


TString& TString::operator =(const TString& rhs)
{
	if (rhs == *this) return *this;
	if (Data != nullptr) delete[] Data;
	size_t Len = rhs.Size();
	Data = new char[Len + 1];
	for (int i = 0; i < Len + 1; i++)
	{
		Data[i] = rhs.Data[i];
	}
	return *this;
}


TString& TString::operator +=(const TString& rhs)
{
	size_t len1 = Size();
	size_t len2 = rhs.Size();
	size_t len = len1 + len2;
	char * Data1 = new char[len + 1];
	for (int i = 0; i < len1; i++)
	{
		Data1[i] = Data[i];
	}
	for (int i = 0; i < len2 + 1; i++)
	{
		Data1[len1 + i] = rhs.Data[i];
	}
	delete[] Data;
	Data = Data1;
	return *this;
}


bool TString::operator ==(const TString& rhs) const
{
	size_t len = Size();
	if (len != rhs.Size()) return false;
	for (int i = 0; i < len; i++)
	{
		if (Data[i] != rhs.Data[i]) return false;
	}
	return true;
}


bool TString::operator <(const TString& rhs) const
{
	int length;
	if (rhs.Size() > Size())
		length = rhs.Size();
	else
		length = Size();
	for (int i = 0; i<length; i++) {
		if (Data[i] == rhs.Data[i]) continue;
		if (Data[i]<rhs.Data[i]) return true;
		if (Data[i]>rhs.Data[i]) return false;
	}
	return false;
}


size_t TString::Find(const TString& substr) const {
	size_t f = -1;
	size_t len1 = Size() + 1;
	size_t len2 = substr.Size() + 1;
	for (size_t i = 0; i<len1; i++) {
		size_t k = 0;
		if (Data[i] == substr.Data[k] && (i + len2) <= len1 && k == 0) {
			f = i;
			i++;
			for (k = 1; k < len2; k++, i++)
				if (Data[i] != substr.Data[k]) {
					i = f;
					f = -1;
					k = 0;
					break;
				}
		}
	}
	return f;
}

void TString::Replace(char oldSymbol, char newSymbol)
{
	for (int i = 0; i < Size(); i++)
		if (Data[i] == oldSymbol)
		{
			Data[i] = newSymbol;
		}
}


size_t TString::Size() const
{
	size_t i = 0;
	for (i; Data[i]; i++);
	return i;
}


bool TString::Empty() const
{
	if (Data[0] == NULL) return true;
	return false;
}


char TString::operator[](size_t index) const
{
	return Data[index];
}


char& TString::operator[](size_t index)
{
	return Data[index];
}


void TString::RTrim(char symbol)
{
	int len = Size();
	int t = 0;
	while (Data[len - 1 - t] == symbol)
	{
		t++;
	}
	char* Data1 = new char[len - t + 1];
	for (int i = 0; i < len - t; i++)
	{
		Data1[i] = Data[i];
	}
	Data1[len - t] = '\0';
	delete[] Data;
	Data = Data1;
}


void TString::LTrim(char symbol)
{
	int len = Size();
	int t = 0;
	while (Data[t] == symbol)
	{
		t++;
	}
	char * Data1 = new char[len - t + 1];
	for (int i = 0; i < len - t + 1; i++)
	{
		Data1[i] = Data[i + t];
	}
	delete[] Data;
	Data = Data1;
}


TString operator+(const TString & a, const TString & b)
{
	return (TString(a) += TString(b));
}


bool operator!=(const TString & a, const TString & b) {
	int i = 0;
	do {
		if (a[i] == b[i])
			return false;
		i++;
	} while (a[i - 1] != '\0' && b[i - 1] != '\0');
	return true;
}


bool operator>(const TString & a, const TString & b) {
	if (a == b) return false;
	else if (a<b) return false;
	else return true;
}


std::ostream & operator<<(std::ostream &out, const TString &str)
{
	out << str.Data;
	return out;
}