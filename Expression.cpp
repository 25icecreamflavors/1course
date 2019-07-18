#include <iostream>
#include <memory>
#include <string>

class Expression {
public:
    virtual int Evaluate() const = 0;
    virtual std::string ToString() const = 0;
    virtual ~Expression() {}
};

using ExpressionPtr = std::shared_ptr<Expression>;

class Digit: public Expression
{
public:
    int n;
    Digit(int x)
    {
        n = x;
    }
    virtual int Evaluate() const override
    {
        return n;
    }
    std::string ToString() const override
    {
        return std::to_string(n);
    }
    ~Digit() override
    {
    }
};

class Plus: public Expression
{
public:
    ExpressionPtr one;
    ExpressionPtr two;
    Plus (ExpressionPtr x, ExpressionPtr y)
    {
        one = x;
        two = y;
    }
    virtual int Evaluate() const override
    {
        return one->Evaluate() + two->Evaluate();
    }
    std::string ToString() const override
    {
        return one->ToString() + " + " + two->ToString();
    }
    ~Plus() override
    {
    }
};

class Multiplicator: public Expression
{
public:
    ExpressionPtr a;
    ExpressionPtr b;
    Multiplicator (ExpressionPtr x, ExpressionPtr y)
    {
        a = x;
        b = y;
    }
    virtual int Evaluate() const override
    {
        return a->Evaluate() * b->Evaluate();
    }
    std::string ToString() const override
    {
        std::string s = "";
        if ((dynamic_cast<Plus*>(a.get())) && (dynamic_cast<Plus*>(b.get())))
        {
            s = "(" + a->ToString() + ")" + " * " + "(" + b->ToString() + ")";
        }
        else if (dynamic_cast<Plus*>(a.get()))
        {
            s = "(" + a->ToString() + ")" + " * " + b->ToString();
        }
        else if (dynamic_cast<Plus*>(b.get()))
        {
            s = a->ToString() + " * " + "(" + b->ToString() + ")";
        }
        else
        {
            s = a->ToString() + " * " + b->ToString();
        }
        return s;
    }
    ~Multiplicator() override
    {
    }
};

ExpressionPtr Const(int n)
{
    return ExpressionPtr(new Digit(n));
}
ExpressionPtr Sum(ExpressionPtr x, ExpressionPtr y)
{
    return ExpressionPtr(new Plus(x, y));
}
ExpressionPtr Product(ExpressionPtr x, ExpressionPtr y)
{
    return ExpressionPtr(new Multiplicator(x, y));
}

int main() {
    ExpressionPtr ex1 = Sum(Product(Const(3), Const(4)), Const(5));
    std::cout << ex1->ToString() << "\n";  // 3 * 4 + 5
    std::cout << ex1->Evaluate() << "\n";  // 17

    ExpressionPtr ex2 = Product(Const(6), ex1);
    std::cout << ex2->ToString() << "\n";  // 6 * (3 * 4 + 5)
    std::cout << ex2->Evaluate() << "\n";  // 102
}
