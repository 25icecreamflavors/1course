#include <iostream>
#include <string>
#include <vector>
#include <random>
class Multiplicator
{
protected:
    std::vector <int> x;
    std::vector <int> y;
public:
    Multiplicator()
    {
        x.push_back(0);
        y.push_back(0);
    }
    Multiplicator(std::vector <int> a, std::vector <int> b): x(a), y(b) {}
    void setX(int k)
    {
        std::vector <int> temp;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 9);
        temp.push_back(dis(gen));
        std::uniform_int_distribution<> ndis(0, 9);
        for (int i = 1; i < k; i++)
        {
            temp.push_back(ndis(gen));
        }
        if (k > 0)
        {
            x = temp;
        }
        else
        {
            std::cout << "You are not able to create number with length 0 and less, please, enter another number which must be positive integer." << "\n";
        }
    }
    void GetX()
    {
        for (int i = 0; i < x.size(); i++)
        {
            std::cout << x[i];
        }
        std::cout << "\n";
    }
    void setY(int k)
    {
        std::vector <int> temp;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 9);
        temp.push_back(dis(gen));
        std::uniform_int_distribution<> ndis(0, 9);
        for (int i = 1; i < k; i++)
        {
            temp.push_back(ndis(gen));
        }
        if (k > 0)
        {
            y = temp;
        }
        else
        {
            std::cout << "You are not able to create number with length 0 or less, please, enter another number which must be positive integer." << "\n";
        }
    }
    void GetY()
    {
        for (int i = 0; i < y.size(); i++)
        {
            std::cout << y[i];
        }
        std::cout << "\n";
    }
};

int main()
{
    Multiplicator A;
    int k = 5;
    A.setX(5);
    A.GetX();
    A.setY(0);
    A.GetY();
}
