#include <iostream>
#include <fstream>

using namespace std;

int main(){
	double x0 = 0.5;
	double x;
	int Nskip = 100; //Number of iterations to skip
	int Nend  = 200; //Number of total iterations
	double xfile[Nend - Nskip];
	
	ofstream out("output.dat");
	  
	for(double r = 0; r <= 4; r += 0.001){
	   x = x0;
	   for(int i=1; i <= Nskip; i++){
		   x = r*x*(1-x);
	   }
	   xfile[0] = x;
	   for(int i = 1; i <= Nend - Nskip; i++){
	           xfile[i] = r*xfile[i-1]*(1-xfile[i-1]);
      	   }
	   for(int i = 1; i <= Nend - Nskip; i++){
	           out << r << "\t" << xfile[i] << endl;
	   }
	}

	out.close();
	return 0;
}
