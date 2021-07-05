#include<string>
#include<iostream>
#include<ios>
#include<iomanip>

using std::string;
using std::cin;
using std::endl;
using std::cout;
int main(){
	
	cout<<" Please enter your first name: ";
	string name;
	cin>>name;
	cout<<"Hello, " <<name<<"!"<<endl;

	cout<<" Please enter your midterm and final grades: ";
	double midterm, final;
	cin>>midterm>>final;

	cout<<"Please enter all your homework grades, "
	"followed by end-of-file";

	int count =0;
	double sum =0;

	double x;

	while(cin>>x){

		++count;
		sum += x;
	}

	std::streamsize prec = cout.precision();
	cout<< "Your final grade is "<< std::setprecision(3) <<0.2*midterm +0.4*final + 0.4*sum/count <<std::setprecision(prec)<<endl;

	return 0;
}