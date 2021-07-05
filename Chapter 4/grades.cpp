#include<algorithm>
#include<iostream>
#include<vector>
#include<iomanip>
#include<stdexcept>
#include <iostream>

using std::cout;
using std::string;
using std::cin;
using std::vector;
using std::istream;
using std::domain_error;
using std::endl;
double grade(double midterm, double final, double homework){
	return 0.2* midterm + 0.4*final + 0.4*homework;
}

double median(vector<double> vec){
	typedef vector<double>::size_type vec_sz;
	vec_sz size= vec.size();
	if (size == 0)
		throw domain_error("Median of an empty vector" );
	sort(vec.begin(),vec.end());
	vec_sz mid = size/2;
	return size%2 ==0 ? (vec[mid] +vec[mid-1])/2 : vec[mid];
}


double grade (double midterm, double final, const vector<double>& hw){
	if(hw.size() == 0)
		throw domain_error("Student has done no homework");
	return grade(midterm, final, median(hw));
}

istream& read_hw(istream& in, vector<double>& hw){
	if(in){
		hw.clear();
		double x;
		while(in>>x)
			hw.push_back(x);
		in.clear();
	}
	return in;
}



struct Student_info{
	string name;
	double midterm, final;
	vector<double> homework;
};

istream&  read( istream& is, Student_info& s){
	is>>s.name>>s.midterm>>s.final;
	read_hw(is, s.homework);
	return is;
}

double grade(const Student_info & s){
	return (s.midterm, s.final, s.homework);
}
int main(){

	cout<<"Please enter  your first name: ";
	string name;
	cin>>name;
	cout<<"Hello, "<<name<<"!"<<endl;

	cout<<"Please enter your midterm and final exam grades: ";
	double midterm, final;
	cin>>midterm>>final;

	cout<<"Enter all your homework grades followed by EOF: ";
	vector<double> homework;

	read_hw(cin, homework);
	try{
		double final_grade = grade(midterm, final, homework);
		std::streamsize prec = cout.precision();
		cout<< "Your final grade is "<< std::setprecision(3) << final_grade<<std::setprecision(prec)<<endl;
	} catch (domain_error){
		cout<<endl<<"You must enter your grades"
					"Please try again" <<endl;
		return 1;
	}
	return 0;
}