#include<string>
#include<iostream>
#include<ios>
#include<iomanip>
#include<vector>
#include<algorithm>

using std::string;
using std::cin;
using std::endl;
using std::cout;
using std::vector;
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

	vector<double> homework;

	double x;

	while(cin>>x)
		homework.push_back(x);


	typedef vector<double>::size_type vec_sz;
	vec_sz size= homework.size();
	if(size ==0){
		cout<< endl<<" You must enter grades"
		 			 " Please try again"<<endl;
		return 1;
	}

	sort(homework.begin(), homework.end());

	vec_sz mid = size/2;
	cout<<endl;
	cout<<mid<<endl;
	double median = (size%2) == 0 ? (homework[mid] +homework[mid-1])/2 
	                              : homework[mid];

	cout<<median<<endl;
	std::streamsize prec = cout.precision();
	cout<< "Your final grade is "<< std::setprecision(3) <<0.2*midterm +0.4*final + 0.4*median<<std::setprecision(prec)<<endl;

	return 0;
}