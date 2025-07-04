/*
fact(5)
= 5 * fact(4)
= 5 * (4 * fact(3))
= 5 * (4 * (3 * fact(2)))
= 5 * (4 * (3 * (2 * fact(1))))
= 5 * (4 * (3 * (2 * 1)))        ← base case returns 1
= 5 * 4 * 3 * 2 * 1
= 120

*/
#include <iostream>

int fact(int n){
	if(n==0 || n==1){
		return 1;
	}
	else{
		return n*fact(n-1);
	}
}
int main(){
	std::cout<<"Enter number of ur choice-";
	int n;
	std::cin>>n;
	std::cout<<	fact(n);;
}