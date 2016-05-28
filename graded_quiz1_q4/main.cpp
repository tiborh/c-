#include <iostream>

using namespace std;

int abs(int x){
    if(x<0) return -x;
    else return x;
}
struct sample {
    int pp, qq;
};

int compact(int a, int b){
   if(a%b==0) return b;
   int n=a%b;
   if(b%n==0) return n;
   else return compact(b,n);
}

void reduce(sample& rt1) {
    int st1 = compact(abs(rt1.pp), rt1.qq);
    rt1.pp = rt1.pp/st1;
    rt1.qq = rt1.qq/st1;
    if(rt1.qq < 0) {
         rt1.pp= -rt1.pp;
         rt1.qq= -rt1.qq;
    }
}

sample activity(sample a1, sample b1) {
    sample c1;
    c1.pp = a1.pp*b1.qq + b1.pp*a1.qq;
    c1.qq = a1.qq*b1.qq;
    reduce(c1);
    return c1;
}

sample activity2(sample a1, sample b1) {
    sample c1;
    c1.pp = a1.pp*b1.pp;
    c1.qq = a1.qq*b1.qq;
    reduce(c1);
    return c1;
}

int main(){
    sample num1, num2;
    num1.pp=4;
    num1.qq=14;
    num2.pp=4;
    num2.qq=18;
    reduce(num1);
    reduce(num2);
    int output1=activity2(num1,num2).pp;
    cout << "output1: " << output1 << endl;
    int output2=activity2(num1,num2).qq;
    cout << "output2: " << output2 << endl;
    int output3=activity(num1,num2).pp;
    cout << "output3: " << output3 << endl;
    int output4=activity(num1,num2).qq;
    cout << "output4: " << output4 << endl;
    return 0;
}
