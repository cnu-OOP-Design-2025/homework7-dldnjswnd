#pragma once
#include <iostream>
using namespace std;

//---------------------------------------------------
// 인터페이스 클래스: 날기 행동
class FlyBehavior
{
public:
    virtual void fly() = 0;
    virtual ~FlyBehavior() {}
};

// 전략 구현 클래스들
class FlyWithWings : public FlyBehavior
{
public:
    void fly() override { cout << "I can Fly!" << endl; }
};

class FlyNoWay : public FlyBehavior
{
public:
    void fly() override { cout << "I can't fly..." << endl; }
};

//---------------------------------------------------
// 인터페이스 클래스: 꽥꽥 행동
class QuackBehavior
{
public:
    virtual void quack() = 0;
    virtual ~QuackBehavior() {}
};

class Quack : public QuackBehavior
{
public:
    void quack() override { cout << "Quack!" << endl; }
};

class Squeak : public QuackBehavior
{
public:
    void quack() override { cout << "Squeak!" << endl; }
};

class MuteQuack : public QuackBehavior
{
public:
    void quack() override { cout << "<<Silent>>" << endl; }
};

//---------------------------------------------------
// 추상 클래스: Duck
class Duck
{
protected:
    FlyBehavior *flyBehavior;
    QuackBehavior *quackBehavior;

public:
    Duck(FlyBehavior *f = nullptr, QuackBehavior *q = nullptr)
        : flyBehavior(f), quackBehavior(q) {}

    virtual ~Duck()
    {
        delete flyBehavior;
        delete quackBehavior;
    }

    void swim() { cout << "All ducks float, even decoys!" << endl; }
    virtual void display() = 0;

    void performFly();
    void performQuack();

    void setFlyBehavior(FlyBehavior *fb);
    void setQuackBehavior(QuackBehavior *qb);
};

// 구체 클래스들
class MallardDuck : public Duck
{
public:
    MallardDuck();
    void display() override { cout << "I'm a Mallar Duck." << endl; } // 과제 출력에 맞춤(오타 포함)
};

class RedheadDuck : public Duck
{
public:
    RedheadDuck();
    void display() override { cout << "I'm a Redhead Duck." << endl; }
};

class RubberDuck : public Duck
{
public:
    RubberDuck();
    void display() override { cout << "I'm a Rubber Duck." << endl; }
};

class DecoyDuck : public Duck
{
public:
    DecoyDuck();
    void display() override { cout << "I'm a Decoy Duck." << endl; }
};

class ModelDuck : public Duck
{
public:
    ModelDuck();
    // 과제 README 요구대로 ModelDuck도 Decoy 문구를 출력
    void display() override { cout << "I'm a Decoy Duck." << endl; }
};
