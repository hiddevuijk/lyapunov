#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>


using namespace::std;


void deriv(const double& x,const  double& y,const double& z,
		double& dxdt, double& dydt, double& dzdt,
		const double& sig, const double& rho, const double& beta)
{

	dxdt = sig*(y-x);
	dydt = x*(rho-z);
	dzdt = x*y-beta*z;
}



int main()
{

	double sig = 10;
	double rho = 28;
	double beta = 2.667;

	double tMax = 100;
	double dt = 0.01;

	int tiMax = int(tMax/dt);


	vector<double> xt(tiMax,0.0);
	vector<double> yt(tiMax,0.0);
	vector<double> zt(tiMax,0.0);
	vector<double> t(tiMax,0.0);
	// set init vals
	xt[0] = 0.;
	yt[0] = 1.;
	zt[0] = 1.05;

	double dxdt, dydt, dzdt;
	for(int ti=1;ti<tiMax;++ti) {
		deriv(xt[ti-1],yt[ti-1],zt[ti-1],
			dxdt,dydt,dzdt,sig,rho,beta);
		xt[ti] = xt[ti-1] + dt*dxdt;
		yt[ti] = yt[ti-1] + dt*dydt;
		zt[ti] = zt[ti-1] + dt*dzdt;
	}

	ofstream xout("xt.csv");
	ofstream yout("yt.csv");
	ofstream zout("zt.csv");
	for( int i=0;i<xt.size();++i) {
		xout << xt[i] << ';';
		yout << yt[i] << ';';
		zout << zt[i] << ';';
	}

	return 0;
}



