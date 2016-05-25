#include <vector>
#include <iostream>
#include "randomVec.h"
#include "dist.h"

using namespace::std;

int main()
{

	vector<double> a = {1,2,3};
	vector<double> b = {2,3,4};
	vector<double> b1 = {2,3,4};
	double d0 = dist(a,b);
	vector<double> dab = subtrVec(b,a);
	for( int i=0;i<a.size();++i)
		b[i] = a[i] + 2.*dab[i]/d0;

	double d1 = dist(a,b);

	cout << d0 << endl << d1 <<endl;

	cout << dist(b,b1) << endl;

	return 0;
}

