#include <iostream>
#include <cstdio>
#include <vector> //Required for solution #2
#include <algorithm> //Required for sort function of solution #2
using namespace std;

int max_of_four(int a, int b, int c, int d);

int main(){
	int a, b ,c ,d;
	printf("Please enter four numbers separated by spaces:\n");
	scanf("%d %d %d %d", &a, &b, &c, &d);
	int ans = max_of_four(a, b, c, d);
	printf("%d\n", ans);
	return 0;
}

int max_of_four(int a,int b, int c, int d){
	// #1 Possible Solution One using IF statments
	/*
	if( (a > b) && (a > c) && (a > d) )
		return a;
	else if( (b > a) && (b > c) && (b > d) )
		return b;
	else if( (c > a) && (c > b) && (c > d) )
		return c;
	else if( (d > a) && (d > b) && (d > c) )
		return d;
	else
		return false;
	*/
	
	// #2 My solution using vectors
	vector<int> nums = {a,b,c,d};
	//Soft them from smallest to greatest using default operator <
	sort(nums.begin(), nums.end());
	return nums.back(); //Return the last element
}

