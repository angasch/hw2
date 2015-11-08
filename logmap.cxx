#include <iostream>
#include <fstream>

using namespace std;

int main(){
	double x0 = 0.5;
	double x;
	double a[Nend-Nskip];
	int Nskip = 100; //Number of iterations to skip
	int Nend  = 200; //Number of total iterations
	
	ofstream out("output.dat");
	
	for(double r=0; r <= 4; r += 0.001){
		x=x0;
	   for(int i=1; i <= Nskip; i++)
		   x= r*x*(1-x);
	   for(int i=Nskip+1; i <= Nend; i++){
	   		   x = r*x*(1-x);
	   		   a[i-Nskip-1]=x;
   	   }
   	   for(int i=0; i<Nend-Nskip; i++){
   		 out  << r << \t << a[i] << endl; 
   	   }

	}
	out.close()

	return 0;
}
