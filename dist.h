#ifndef GUARD_dist_h
#define GUARD_dist_h

#include <vector>
#include <math.h>
#include <assert.h>

double dist(const std::vector<double>& x,
		const std::vector<double>& y)
{
	assert(x.size() == y.size());

	double d = 0.0;
	for(int i=0;i<x.size();++i)
		d += (x[i] - y[i])*(x[i]-y[i]);
	return sqrt(d);
}


#endif
