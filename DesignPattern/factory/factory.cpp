#include "factory.h"
#include "product.h"

#include <iostream>
using namespace std;

Factory::Factory() {
}

Factory::~Factory() {
}

ConcreteFactory::ConcreteFactory() {
    cout << "ConcreteFactory..." << endl;
}

ConcreteFactory::~ConcreteFactory() {
    cout << "destory ConcreteFactory" << endl;
}

Product* ConcreteFactory::CreateProduct() {
    return new ConcreteProduct();
}
