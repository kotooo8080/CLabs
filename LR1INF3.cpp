#include "stdafx.h"
#include <iostream>

using namespace std;
int main()
{
	int a = 65;
	cout << (char)(a + 39) << (char)(a + 36) << (char)(a + 43) << (char)(a + 43) << (char)(a + 46) << (char)(a - 33);
	cout << (char)(a + 54) << (char)(a + 46) << (char)(a + 49) << (char)(a + 43) << (char)(a + 35) << char(a - 32) << endl;
	system ("pause");
	return 0;

}

