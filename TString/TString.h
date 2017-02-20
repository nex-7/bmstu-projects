#include <iostream>
class TString
{
	char * Data;
public:
	/// <summary> ���������� </summary> 
	~TString();


	/// <summary> ����������� �� ��������� </summary>  
	TString();


	/// <summary> ����������� ����������� </summary>  
	/// <param name="rhs">������, ������� �������� </param>  
	TString(const TString& rhs);


	/// <summary> ���������������� ����������� </summary>  
	/// <param name="data">������, ������� ��������� ��������� � ����������� ������ </param>  
	TString(const char * data);


	/// <summary> �������� ������������ </summary>  
	/// <param name="data">������, ������� �������� </param>  
	/// <returns>���������� ������ �� ����</returns>  
	TString& operator =(const TString& rhs);


	/// <summary> �������� += </summary>  
	/// <param name="rhs">������, ������� ����� ����� ����� '+=' </param>  
	/// <returns>���������� ������ �� ����</returns>  
	TString& operator +=(const TString& rhs);


	/// <summary> �������� == </summary>  
	/// <param name="rhs">������, ������� ����� ����� ����� '==' </param>  
	/// <returns>���������� �������� ��������� ���� �����</returns>  
	bool operator ==(const TString& rhs) const;


	/// <summary> �������� &lt; </summary>  
	/// <param name="rhs">������, ������� ����� ����� ����� "&lt;" </param>  
	/// <returns>���������� �������� ��������� ���� �����</returns>  
	bool operator <(const TString& rhs) const;


	/// <summary> ������� ������ ���������</summary>  
	/// <param name="substr">���������, ������� ���������� ����� </param>  
	/// <returns>���������� ������� substr. ���� ��������� �� �������, �� ���������� -1</returns> 
	size_t Find(const TString& substr) const;


	/// <summary> ������� ������ ���� </summary>  
	/// <param name="oldSymbol">������, ������� ��������� �������� </param>  
	/// <param name="newSymbol">������, �� ������� ��������� �������� </param>
	void Replace(char oldSymbol, char newSymbol);


	/// <summary> ������� ���������� ����� ������ </summary>  
	/// <returns>���������� ����� ������</returns> 
	size_t Size() const;


	/// <summary> ������� ��� ����������� ����� �� ������ </summary>  
	bool Empty() const;


	/// <summary> �������� [] </summary> 
	/// <example> 
	/// <code>
	/// TString str = "some string";
	/// char symbol = str[2]; // symbol == 'm'
	/// </code>
	/// </example>
	/// <param name="index"> ������ ������� </param>  
	/// <returns> �������� ������� � ������ � �������� index</returns> 
	char operator[](size_t index) const;


	/// <summary> �������� [] </summary> 
	/// <example> 
	/// <code>
	/// TString str = "some string";
	/// str[0] = 'S'; // ������ ���������� str ����� "Some string"
	/// </code>
	/// </example>
	/// <param name="index"> ������ ������� </param>  
	/// <returns> ������ �� ������ � ������ � �������� index</returns> 
	char& operator[](size_t index);


	/// <summary> ������ ������ </summary> 
	/// <example> 
	/// <code>
	/// TString str = "___some string___";
	/// str.RTrim('_'); // ������ ���������� str ����� "___some string"
	/// </code>
	/// </example>
	/// <param name="symbol"> �������� ��������, ������ �������� </param> 
	void RTrim(char symbol);


	/// <summary> ������ ������ </summary> 
	/// <example> 
	/// <code>
	/// TString str = "___some string___";
	/// str.LTrim('_'); // ������ ���������� str ����� "some string___"
	/// </code>
	/// </example>
	/// <param name="symbol"> �������� ��������, ������ �������� </param> 
	void LTrim(char symbol);

	friend std::ostream & operator<<(std::ostream &, const TString &);
};

/// <summary> �������� +</summary>  
/// <example> 
/// <code>
/// TString a = "Hello";
/// TString b = "World";
/// TString c = a + b; // c ����� "HelloWorld"
/// </code>
/// </example>
/// <returns>���������� ������ ������ a + b</returns>  
TString operator+(const TString & a, const TString & b);


/// <summary> �������� !=</summary>
bool operator!=(const TString & a, const TString & b);


/// <summary> �������� &gt;</summary>
bool operator>(const TString & a, const TString & b);


/// <summary> �������� ������ </summary>  
/// <param name="out">����� ���� ������� ������ </param>  
/// <param name="str">������, ������� ������� </param>
/// <returns>���������� ������ �� �����</returns> 
std::ostream & operator<<(std::ostream &out, const TString &str);