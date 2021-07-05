// Program to count the number of occurences of eachg distinct word.
#include<iostream>
#include<algorithm>
#include<vector>


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main(){
	//Read the inputs into a vector input_string

	string data;
	vector<string> input_string;
	cout<<"Please enter the strings";
	while(cin>>data)
		input_string.push_back(data);
	sort(input_string.begin(), input_string.end());

	cout<<endl;

	int count =0;
	int i =0;
	string current=input_string[0];
	string shortest= input_string[0];
	string longest =input_string[0];

	do{
		if(current == input_string[i]){
			count++;
		}
		else{

			cout<<count<<"\t"<<current<<endl;
			count=1;
			current= input_string[i];
		}
		if(input_string[i].length() < shortest.length() ){
			shortest = input_string[i];
		}
		if(input_string[i].length()  > longest.length() ){
			longest = input_string[i];
		}
		i++;

	}while(i < input_string.size());

		cout<<"Longest string is "<< longest<<endl;
		cout<<"Shortest string is "<< shortest<<endl;


}
