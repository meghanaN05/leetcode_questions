class Solution {
public:
    int minimumSum(int num) {
    int n1=num%10;
    num=num/10;
    int n2=num%10;
    num=num/10;
     int n3=num%10;
    num=num/10;
    int n4=num%10;
    num=num/10;
    vector<int>a={n1,n2,n3,n4};
    sort(a.begin(),a.end());
    int number1=a[0]*10+a[2];
    int number2=a[1]*10+a[3];
    return number1+number2;


    }
};