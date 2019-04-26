#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>

class Multiplicator
{
protected:
    std::vector <int> x;
    std::vector <int> y;
public:
    Multiplicator() // default constructor will make your numbers equal to 0
    {
        x.push_back(0);
        y.push_back(0);
    }
    Multiplicator(std::vector <int> a, std::vector <int> b): x(a), y(b) {} // another constructor if you want to create not zero nubmers, works with vectors
    
    int GeneratorB() // Professional generator that will give you any digit from 1 to 9, in particular, I used it to define first digit in number
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 9);
        return dis(gen);
    }
    
    int Generator() // Professional generator that gives randomly any digit from 0 to 9, was constructed in 1337 year by villagers in Minecraft
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> ndis(0, 9);
        return ndis(gen);
    }
    
    void setX(int k) // This bad boi allows you to generate k-digit number
    {
        std::vector <int> temp;
        temp.push_back(GeneratorB());
        for (int i = 1; i < k; i++)
        {
            temp.push_back(Generator());
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

    void GetX() // Shows current value of number X
    {
        for (int i = 0; i < x.size(); i++)
        {
            std::cout << x[i];
        }
        std::cout << "\n";
    }

    void setY(int k) // This bad boi allows you to generate k-digit number
    {
        std::vector <int> temp;
        temp.push_back(GeneratorB());
        for (int i = 1; i < k; i++)
        {
            temp.push_back(Generator());
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

    void GetY() // Shows current value of number Y
    {
        for (int i = 0; i < y.size(); i++)
        {
            std::cout << y[i];
        }
        std::cout << "\n";
    }

    std::vector <int> Add(std::vector <int> & base, std::vector <int> & add) // Professional method that allows you to sum 2 numbers of any length
    {
        std::vector <int> temp;
        int remainder = 0, res = 0, i = 0;
        if (base.size() < add.size())
        {
            std::reverse( base.begin(), base.end() );
            while (base.size() < add.size())
            {
                base.push_back(0);
            }
            std::reverse( base.begin(), base.end() );
        }
        else if (base.size() > add.size())
        {
            std::reverse( add.begin(), add.end() );
            while (base.size() > add.size())
            {
                add.push_back(0);
            }
            std::reverse( add.begin(), add.end() );
        }
        std::reverse( base.begin(), base.end() );
        std::reverse( add.begin(), add.end() );
        for (i = 0; i < add.size(); i++)
        {
            res = base[i] + add[i] + remainder;
            if (res > 9)
            {
                remainder = 1;
                res = res - 10;

            }
            else
            {
                remainder = 0;
            }
            temp.push_back(res);
        }
        if (remainder > 0)
        {
            temp.push_back(remainder);
        }
        std::reverse( base.begin(), base.end() );
        std::reverse( add.begin(), add.end() );
        std::reverse( temp.begin(), temp.end() );
        return temp;
    }

    std::vector <int> School(std::vector <int> & a, std::vector <int> & b) // Multiplication of 2 numbers of any length
    {
        std::vector <int> sumres;
        sumres.push_back(0);
        int i = 0, remainder = 0, res = 0;
        
        if (a.size() < b.size()) // In this particular part i would make vectors of the same size attributing zeros to the left side of these numbers
        {
            std::reverse( a.begin(), a.end() );
            while (a.size() < b.size())
            {
                a.push_back(0);
            }
            std::reverse( a.begin(), a.end() );
        }
        else if (a.size() > b.size())
        {
            std::reverse( b.begin(), b.end() );
            while (a.size() > b.size())
            {
                b.push_back(0);
            }
            std::reverse( b.begin(), b.end() );
        }
        
        std::reverse( a.begin(), a.end() );
        std::reverse( b.begin(), b.end() );
        for (i = 0; i < a.size(); i++)
        {
            std::vector <int> temp;
            remainder = 0;
            for (int j = 0; j < a.size(); j++)
            {
                res = b[i] * a[j] + remainder;
                remainder = res / 10;
                res = res % 10;
                temp.push_back(res);
            }
            if (remainder > 0)
            {
                temp.push_back(remainder);
            }
            std::reverse( temp.begin(), temp.end() );
            for (int m = 0; m < i; m++)
            {
                temp.push_back(0);
            }
            sumres = Add(sumres, temp);
        }
        std::reverse( sumres.begin(), sumres.end() );
        while (sumres[sumres.size() - 1] == 0)
        {
            sumres.pop_back();
        }
        std::reverse( sumres.begin(), sumres.end() );
        std::reverse( a.begin(), a.end() );
        std::reverse( b.begin(), b.end() );
        return sumres;
    }
    
    void Boi()
    {
        x = School(x, y);
        GetX();
    }
};

int main()
{
    Multiplicator A;
    int k = 5;
    A.setX(6);
    A.setY(2);
    A.GetX();
    A.GetY();
    A.Boi();
}
