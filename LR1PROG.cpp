
#include "stdafx.h"
#include "math.h"
#include <iostream>

using namespace std;

int main(){

	setlocale(LC_ALL, "Russian");

	float R,   // R - радиус окружности
		A,     // A - точка на оси OY, по которой строится прямая y = A
		x, y;  // x,y - координаты точки
	
	int f;
	do {
		do
		{
			cout << "enter radius R>0" << endl;
			cin >> R;
			if (R <= 0)
				cout << "please, try to enter radius again \n";
		} while (R <= 0);

		do {

			do
			{
				cout << "enter A, 0<A<R" << endl;
				cin >> A;
				if ((A >= R) || (A <= 0))
					cout << "please, enter A again \n";
			} while ((A >= R) || (A <= 0));

			
			do {

				cout << "enter (x,y)" << endl;
				cin >> x >> y;
				if (y > 0)
					if ((pow(x, 2) + pow(y, 2)) < pow(R, 2))
						cout << "the point lies in the interval" << endl;
					else
						if ((pow(x, 2) + pow(y, 2)) == pow(R, 2))
							cout << "the point lies on the boundary of the interval" << endl;
						else
							if (y > A)
								cout << "the point does not belong to the interval" << endl;
							else
								if (y == A)
									if (abs(x) >= sqrt(pow(R, 2) - pow(A, 2)))
										cout << "the point lies on the boundary of the interval" << endl;
									else
										cout << "the point lies in the interval" << endl;
								else
									cout << "the point lies in the interval" << endl;
				else
					if (y == 0)
						cout << "the point lies on the boundary of the interval" << endl;
					else
						cout << "the point does not belong to the interval" << endl;

				cout << "enter coordinates again? yes - 1, no - 0" << endl;
				cin >> f;
			} while (f == 1);

			cout << "enter A again? yes - 1, no - 0" << endl;
			cin >> f;

		} while (f == 1);

		cout << "enter radius R again? yes - 1, no - 0" << endl;
		cin >> f;

	} while (f == 1);
		
    system("pause");

	return 0;
	}