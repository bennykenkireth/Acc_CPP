#include<iostream>
#include<string>
int main(){
	std::cout<<"Please enter your first name: ";
	std::string name;
	std::cin >> name;

	const std::string greeting = "Hello," + name + "!";

	const int pad = 1;

	const int rows = pad*2 +3;

	const std::string::size_type cols =greeting.size() + pad*2 + 2;		

	std::cout<<std::endl;

	for(int r =0;  r!=rows; r++){
		std::string::size_type c =0;
		while(c!=cols){
			if(r == pad +1 && c == pad +1){
				std::cout<<greeting;
				c += greeting.size();
			} else{
				if(r == 0 || r== rows-1 || c==0 || c==cols-1 ){
					std::cout<<"*";
				}
				else{
					std::cout<<" ";
				}
				c++;
			}
		}
		std::cout << std::endl;
	}


	std::cout<<"Ex.1"<<std::endl;
	const int rows1 = pad*2 +1;

	const std::string::size_type cols1 =greeting.size() + pad*2 ;		

	std::cout<<std::endl;
	std::cout<<rows1<<","<<cols1<<std::endl;

	for(int r =0;  r!=rows1; r++){
		std::string::size_type c = 0;
		std::cout<<r<<"\t";
		while(c!=cols1){
			if(r == pad   && c == pad ){
				std::cout<<greeting;
				c += greeting.size();
			}else{
					std::cout<<"*";
					c++;
			}
		}
		std::cout<<std::endl;
	}
	std::cout << std::endl;

	std::cout<<"Ex.2,3"<<std::endl;
	int space = 0;
	std::cout<<"Enter the amount of space: ";
	std::cin>>space;
	int padding=1;
	std::cout<<"Enter the amount of padding: ";
	std::cin>>padding;

	const int rows2 = padding*2 + space*2+ 1;

	const std::string::size_type cols2 =greeting.size() + padding*2  +space*2 + 1;		

	std::cout<<std::endl;
	std::cout<<rows1<<","<<cols1<<std::endl;

	for(int r =0;  r!=rows2; r++){
		std::string::size_type c = 0;
		//std::cout<<r<<"\t";
		while(c!=cols2){
			if(r == padding+space   && c == padding+space ){
				std::cout<<greeting;
				c += greeting.size();
			}else{
				if(r<padding||r>rows2-padding-1||c<padding ||c>cols2-padding-1){
					std::cout<<"*";
				}
				else{
					std::cout<<" ";
				}
				c++;
			}
		}
		std::cout<<std::endl;
	}

	return 0;
}