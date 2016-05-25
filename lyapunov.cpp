#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

#include "integrator.h"
#include "rkInt.h"

#include "dist.h"
#include "randomVec.h"

using namespace::std;

void deriv(const double& x, const vector<double>& y,
	vector<double>& dydx)
{
	double rho = 28.;
	double sig = 10.; 
	double beta = 8./3.;

	dydx[0] = sig*(y[1] - y[0]);
	dydx[1] = y[0]*(rho - y[2]);
	dydx[2] = y[0]*y[1] - beta*y[2];
}

int main()
{

	double h = 0.01;
	double tinit = 100;
	double dx = 0.01;

	double Navg= 100000;
	vector<double> dts(100);
	double dts0 = 0.1;
	double dts1 = 5000;
	for( int i=0;i<dts.size();++i)
		dts[i] = dts0 + i*(dts1-dts0)/(dts.size()-1);

	vector<double> ly(dts.size(),0.0);

	vector<double> xyz0(3,0.0);
	vector<double> xyz(3,0.0);
	vector<double> xyz2(3,0.0);


	default_random_engine generator;
	normal_distribution<double> Ndist(1.,0.0);


	// set init vals
	xyz0[0] = 0.;
	xyz0[1] = 1.;
	xyz0[2] = 1.5;
	// integrate  until +- at attractor
	double t = 0.0;
	integrator(t,xyz0,h,tinit,rkInt,deriv);
	vector<double> dxyz = randVec(3,dx,generator,Ndist);

	for(int dti=0;dti<dts.size();++dti) {
		xyz = xyz0;
		xyz2 = addVec(xyz,dxyz);
		for(int Ni=0;Ni<Navg;++Ni) {
			//xyz2 = addVec(xyz,randVec(3,dx,generator,Ndist));
			integrator(t,xyz,h,dts[dti],rkInt,deriv);
			integrator(t,xyz2,h,dts[dti],rkInt,deriv);
			ly[dti] += log(dist(xyz,xyz2)/dx)/Navg;
			dxyz = subtrVec(xyz2,xyz);
			for(int i=0;i<xyz.size();++i) 
				xyz2[i] = xyz[i] + dx*dxyz[i]/dist(xyz,xyz2);

		}
	}

	ofstream lyout("ly.csv");
	ofstream dtout("dt.csv");
	for(int i=0;i<ly.size();++i) {
		lyout << ly[i] << ';';
		dtout << dts[i] << ';';
	}

	return 0;
}

