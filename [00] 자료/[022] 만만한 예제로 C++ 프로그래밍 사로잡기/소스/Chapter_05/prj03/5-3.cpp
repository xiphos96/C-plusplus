// 5-3.cpp

#include <iostream.h>
#include <stdarg.h>

double sum(int n...)		// ���� ���� �Լ�
{
	va_list market;
	va_start(market, n);
	double sum = 0.;
	for (int i=0; i<n; i++)
	{
		double item = va_arg(market, double);
		sum += item;
	}
	va_end(market);
	return sum;
}

void main()
{
 	cout << sum(3, 1., 2., 3.) << endl;	// ��(.)�� �ſ� �߿��ϴ�.
	cout << sum(3, 1, 2, 3) << endl;
	cout << sum(3, 'A', 'B', 'C') << endl;
	cout << sum(3, "C++", "C", "JAVA") << endl;
}