#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

double mySqrt(double x) {
    
    if(x==0)
        return 0;
    
    double err = 1e-15;
    
    double x0 = x;
    
    while( fabs(x0-x/x0) > x0*err )  
    {        
        x0 = (x0+x/x0)/2;
    }
    
    return x0;
}

int main()
{
    cout<<mySqrt(2.5)<<endl;

}