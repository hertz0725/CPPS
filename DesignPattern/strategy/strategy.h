//strategy.h

#ifndef _STRATEGY_H_
#define _STRATEGY_H_

class Strategy{
public:
    Strategy();
    virtual ~Strategy();
    virtual void AlgorithmInterface() = 0;

protected:

private:
};

class ConcreteStrategyA : public Strategy{
public:
    

};

#endif //_STRATEGY_H_
