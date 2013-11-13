#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double pie = 3.1415926;
	double w;
	double h;
	while(cin.good())
	{
		cin >> w;
		cin >> h;
		if(w != 0 && h != 0)
		{
			double p;
			double r;
			if((h/2.0) > w)
			{
				p = h/2.0;
			}
			else
			{
				p = w/2.0;
			}
			r = p/2.0;
			double a = pow(r,2.0)*pie;
			double c = p*pie;
			double v;
			if(h/2.0 > w)
			{
				v = c*w;
			}
			else
			{
				v = c*(h/2.0);
			}
			cout << v << endl;
		}
	}
	return 0;
}