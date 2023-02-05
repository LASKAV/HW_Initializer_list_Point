#include<iostream>

using namespace std;

/*
Создать шаблонный класс, инкапсулирующий динамический массив.
Создать класс Point и адаптировать этот класс к созданному шаблону.
Продемонстрировать создание и инициализацию объекта шаблонного класса
с помощью списка инициализации, состоящего из значений типа Point.
Для этого использовать конструктор Initializer_list.
*/

class Point
{
	int x;
	int y;
public:

	Point()
	{
		x = NULL;
		y = NULL;
	}

	Point(int x , int y)
	{
		this->x = x;
		this->y = y;
	}

	int Get_X()
	{
		return x;
	}
	int Get_Y()
	{
		return y;
	}
	friend std::ostream& operator << (std::ostream& out, Point& temp_point);
};


template<typename MOD>
class IntArray
{
private:
	int length;
	MOD* data;
public:
	IntArray() : length(0), data(nullptr){}
	IntArray(int length) : length(length)
	{
		data = new MOD[length];
	}
	IntArray(const std::initializer_list<MOD>& list) : IntArray(list.size())
	{
		int i = 0;
		for (auto element : list)
		{
			data[i] = element;
			i++;
		}
	}
	~IntArray()
	{
		delete[] data;
	}
	MOD& operator[](int index)
	{
		return data[index];
	}
	int getLength() const
	{
		return length;
	}
};

std::ostream& operator << (std::ostream& out, Point& temp_point)
{
	out << temp_point.x << ' ' << temp_point.y;
	return out;
}

int main()
{
	IntArray<char> array{ 7, 6, 5, 4, 3, 2, 1, 1, 2, 3 };

	for (int i = 0; i < array.getLength(); i++)
	{
		cout << array[i] << ' ';
	}
	cout << endl;


	IntArray<Point> array_one{ Point(1,2),Point(3,4),Point(5,6)};

	for (int i = 0; i < 3; i++)
	{
		cout << array_one[i] << ' ';
	}
	cout << endl;

	return 0;
}
