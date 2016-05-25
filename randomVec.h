#ifndef GUARD_randomVec_h
#define GUARD_randomVec_h

#include <vector>
#include <random>
#include <math.h>

std::vector<double> randVec(int N,double dx,
			std::default_random_engine& generator,
			std::normal_distribution<double>& Ndist)
{
	std::vector<double> v(N,0.0);
	double len = 0.0;
	for(int i=0;i<N;++i){
		v[i] = Ndist(generator);
		len += v[i]*v[i];
	}
	for(int i=0;i<N;++i)
		v[i] *= dx/sqrt(len);
	return v;
}

std::vector<double> addVec(const std::vector<double>& v1,
		const std::vector<double>& v2)
{
	int N = v1.size() < v2.size() ? v1.size() : v2.size();
	std::vector<double> vout(N,0.0);
	for(int i=0;i<N;++i)
		vout[i] = v1[i] + v2[i];

	return vout;
}

std::vector<double> subtrVec(const std::vector<double>& v1,
		const std::vector<double>& v2)
{
	std::vector<double> vout(v1.size(),0.0);
	for(int i=0;i<vout.size();++i)
		vout[i] = v1[i] - v2[i];
	return vout;
}

#endif
