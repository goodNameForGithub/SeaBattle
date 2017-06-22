#include <iostream>

#include "Field.h"


Field::Field()
{
}


void Field::show() const
{
	using std::cout;
	using std::endl;
	size_t width = getSize(), height = getSize();
	cout << "\t   ";
	for (size_t i = 0; i < width; ++i)
	{
		cout << static_cast<char>(i + 'a');
	}
	cout << "\n\t   ";

	for (size_t i = 0; i < width; ++i)
	{
		cout << "_";
	}
	cout << "\n\t";

	for (size_t i = 0; i < width; ++i)
	{
		for (size_t j = 0; j < height; ++j)
		{
			if (j == 0)
			{
				if (!((i + 1) > 9))
					cout << i + 1 << " ";
				else
					cout << i + 1;
			}

			if (j == 0)
			{
				cout << "/";
			}
			else if (j == (height - 1))
			{
				cout << " /";
			}
			switch (getCell(j, i))
			{
			case eCell::EMPTY:
				cout << " ";
				break;

			case eCell::MISS:
				cout << ".";
				break;

			case eCell::DAMAGED:
				cout << "D";
				break;

			case eCell::UNDAMAGED:
				cout << "H";
				break;

			default:
				break;

			}
		}
		cout << "\n\t";
	}
	//cout << "\n\t   ";
	cout << "   ";
	for (size_t i = 0; i < width; ++i)
	{
		cout << "_";
	}
	cout << "\n";
}

Field::~Field()
{
}
