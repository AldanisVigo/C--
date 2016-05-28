#include <iostream>
#include <stdio.h>
#include <cmath> //For abs function

using namespace std;

void update(int* a, int* b){
	//Complete this function
	int curA = *a, curB = *b;
	*a = curA + curB;
	*b = abs(curA - curB); 
}
int main(){
	int a, b;
	int *pa = &a, *pb = &b;
	scanf("%d %d", &a, &b);
	update(pa, pb);
	printf("%d\n%d\n", a, b);
	return 0;
}
