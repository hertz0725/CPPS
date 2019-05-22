//context.cpp

#include "context.h"
#include "strategy.h"
#include <iostream>
using namespace std;

Context::Context(Strategy* stg) {
    _stg = stg;
}

Context::~Context() {
    if (_stg) {
        delete _stg;
    }
    _stg = nullptr;
}

void Context::DoAction() {
    _stg->AlgorithmInterface();
}
