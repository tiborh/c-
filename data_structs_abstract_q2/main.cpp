#include <iostream>

using namespace std;

int abs(int x){
    if(x<0) return -x;
    else return x;
}
struct complex {
    int pp, qq;
};


complex operation1(complex d1, complex e1) {
    complex f1;
    f1.pp = d1.pp + e1.pp;
    f1.qq = d1.qq + e1.qq;
    return f1;
}

complex operation3(complex d1, complex e1) {
    complex f1;
    f1.pp = d1.pp - e1.pp;
    f1.qq = d1.qq - e1.qq;
    return f1;
}

complex operation2(complex d1, complex e1) {
    complex f1;
    f1.pp = d1.pp*e1.pp - d1.qq*e1.qq;
    f1.qq = d1.pp*e1.qq + d1.qq*e1.pp;
    return f1;
}

complex process4(complex d1, complex e1) {
    complex f1;
    f1.pp = (d1.pp*e1.pp + d1.qq*e1.qq)/(e1.pp*e1.pp+e1.qq*e1.qq);
    f1.qq = (-d1.pp*e1.qq + d1.qq*e1.pp)/(e1.pp*e1.pp+e1.qq*e1.qq);
    return f1;
}

int main(){
    complex num1, num2;
    /*num1 and num2 are two points in the complex plane */
    num1.pp=-6; // x-coordinate of num1
    num1.qq=8; // y-coordinate of num1
    num2.pp=-3; // x-coordinate of num2
    num2.qq=9; // y-coordinate of num2
    //cout << operation3(operation2(operation1(num1, num2), operation1(num1, num2)), operation2(operation1(num1, num2), operation1(num1, num2))) << endl;
    //cout << operation2(operation1(operation3(num1, num2), operation3(num1, num2)), operation1(operation3(num1, num2), operation3(num1, num2))) << endl;
    //cout << operation1(operation2(operation3(num1, num2), operation3(num1, num2)), operation2(operation3(num1, num2), operation3(num1, num2))) << endl;
    return 0;
}
