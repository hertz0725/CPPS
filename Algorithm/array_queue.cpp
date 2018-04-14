#include <iostream>
using namespace std;

class my_queue{
public:
	my_queue(int size):size(size),tail(0),head(0){
		arr= new int(size);
	}
	
	int top()
	{
		if( head ==  tail)
			return INT_MIN;
		return arr[head];
	}

	void push(int val)
	{
		if( tail == head )
		{
			arr[tail] = val;
			tail = (tail+1)%size;
		}
		else
		{
			cout<<"full"<<endl;
		}
	}

	void pop()
	{
		if( head ==  tail)
			cout<<"empty()!"<<endl;
		else
			head = (head+1)%size;
	}


private:
	int size;
	int tail;
	int head;
	int *arr;
};

int main()
{
	my_queue q(5);
	q.push(1);
	cout<<q.top()<<endl;
	q.push(2);
	q.pop();
	cout<<q.top()<<endl;
	q.pop();
	cout<<q.top()<<endl;
	q.push(3);
	q.push(4);




	return 0;
}