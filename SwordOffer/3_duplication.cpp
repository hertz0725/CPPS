#include <iostream>
using namespace std;

bool duplicate(int numbers[], int length, int* duplication) {
    if(length <= 0) return false;
    
    int *pd = duplication;
    
    int i=0;
    while(i != length)
    {
        if(numbers[i] == i)
            i++;
        else if(numbers[i]==numbers[numbers[i]])
            {*(pd++)=numbers[i]; i++; }
        else
            swap(numbers[i],numbers[numbers[i]]);     
    }
    *pd = -1;
    if(pd==duplication)
        return false;
    else
        return true;   
}

int main()
{
    int num[] = {2,3,1,0,2,5,3,0};

    int *pd = new int[10];

    cout<<"source:"<<endl;
    for(auto i:num)
        cout<<i<<" ";

    duplicate(num,8,pd);

    cout<<endl<<"dup:"<<endl;

    while(*pd != -1)
    {
        cout<<*pd++<<" ";
       
    }    

    cout<<endl;

    cout<<"sorted:"<<endl;
    for(auto i:num)
        cout<<i<<" ";

    cout<<endl;

    return 0;
}