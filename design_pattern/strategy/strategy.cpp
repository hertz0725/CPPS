//strategy.cpp

#include "strategy.h"
#include <iostream>
using namespace std;

Strategy::Strategy() {
}

Strategy::~Strategy() { 
    cout << "~Strategty..." << endl;
}

void Strategy::AlgorithmInterface() {
    
}

ConcreteStrategyA::ConcreteStrategyA() {
}

ConcreteStrategyA::~ConcreteStrategyA() {
    cout << "~ConcreteStrategyA..." << endl;
}

void ConcreteStrategyA::AlgorithmInterface() {
    cout << "test ConcreteStrategyA..." << endl;
}

ConcreteStrategyB::ConcreteStrategyB() {
    
}

ConcreteStrategyB::~ConcreteStrategyB() {
    cout << "~ConcreteStrategyB..." << endl;
}

void ConcreteStrategyB::AlgorithmInterface() {
    cout << "test ConcreteStrategyB..." << endl;
}

