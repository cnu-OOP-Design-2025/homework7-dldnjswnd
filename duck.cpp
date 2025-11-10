#include "duck.h"

// Duck 공통 동작
void Duck::performFly()
{
    if (flyBehavior)
        flyBehavior->fly();
}
void Duck::performQuack()
{
    if (quackBehavior)
        quackBehavior->quack();
}
void Duck::setFlyBehavior(FlyBehavior *fb)
{
    if (flyBehavior != fb)
    {
        delete flyBehavior;
        flyBehavior = fb;
    }
}
void Duck::setQuackBehavior(QuackBehavior *qb)
{
    if (quackBehavior != qb)
    {
        delete quackBehavior;
        quackBehavior = qb;
    }
}

// 각 오리의 기본 전략 설정
MallardDuck::MallardDuck() : Duck(new FlyWithWings(), new Quack()) {}
RedheadDuck::RedheadDuck() : Duck(new FlyWithWings(), new Quack()) {}
RubberDuck::RubberDuck() : Duck(new FlyNoWay(), new Squeak()) {}
DecoyDuck::DecoyDuck() : Duck(new FlyNoWay(), new MuteQuack()) {}
ModelDuck::ModelDuck() : Duck(new FlyNoWay(), new MuteQuack()) {}
