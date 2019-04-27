#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <fstream>
#include <ctime>

class Multiplicator
{
protected:
    std::vector <int> x; // vector that stores digits of the first number
    std::vector <int> y; // vector that stores digits of the second number
    std::vector <double> time1; //vector that stores execution time of the first algorithm
    std::vector <double> time2; //vector that stores execution time of the second algorithm
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
        else // higly developed protection based on neural networks, this condition will not allow to break this programm
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
        else // higly developed protection based on neural networks, this condition will not allow to break this programm
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

    void GetThis(std::vector<int> & a) // Shows number that is stored in current vector
    {
        for (int i = 0; i < a.size(); i++)
        {
            std::cout << a[i];
        }
        std::cout << "\n";
    }

    void ShowTime1() // This highly technological tool can be used to show data that is stored in vector time1.
    {
        for (int i = 0; i < time1.size(); i++)
        {
            std::cout << time1[i] << "\n";
        }
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

    std::vector <int> School(std::vector <int> & a, std::vector <int> & b) // Multiplication of 2 numbers of any length, it has never been easier, thanks to out start-up
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

    void TripleSchool(int k) // Function that will multiplicate random numbers exactly 3 times to count average time, some MachineLearning mechanisms were used here
    {
        double time = 0;
        std::vector <int> task;
        for (int i = 1; i <= 3; i++)
        {
            setX(k);
            setY(k);
            clock_t t = clock();
            task = School(x, y);
            t = clock() - t;
            time = time + t;
        }
        time = time / 3;
        time1.push_back(time);
    }

    void GetCSV()
    { // Just gives you csv file with vector "time1" data, no useless comments, without unnecessary trouble, it has never been more convinient to get you csv file
        std::ofstream myfile;
        myfile.open ("TimeData.csv");
        for (int i = 0; i < time1.size(); i++)
        {
            myfile << i + 1 << "," << time1[i] << "\n";
        }
        myfile.close();
    }
    
    std::vector <int> Extend(long long int n, std::vector <int> & v) // function for extending vector to size of n elements adding zeros to the beginning of it
    {
        if (v.size() >= n)
        {
            return v;
        }
        else
        {
            std::reverse( v.begin(), v.end() );
            while (v.size() < n)
            {
                v.push_back(0);
            }
            std::reverse( v.begin(), v.end() );
        }
        return v;
    }
    
        
    std::vector<int> pro( std::vector<int>& x,  std::vector<int>& y)
    {
        long long int len = max(x.size(), y.size());
        if (y.size() < x.size())
        {
            y = Extend(x.size(), y);
        }
        else if (x.size() < y.size())
        {
            x = Extend(y.size(), x);
        }
        if (y.size() % 2 != 0)
        {
            y = Extend(x.size() + 1, y);
            x = Extend(x.size() + 1, x);
        }
        
        long long int len = max(x.size(), y.size());
        std::vector<int> res;
        std::vector<int> aPlusb;
        std::vector<int> cPlusd;
        if (len <= 2)
        {
            return School(x, y);
        }
        
        long long int k = len / 2;
        std::vector<int> a {x.begin(), x.begin() + k};
        std::vector<int> b {x.begin() + k, x.end()};
        std::vector<int> c {y.begin(), y.begin() + k};
        std::vector<int> d {y.begin() + k, y.end()};
        
        std::vector<int> ac = pro(a, c);
        std::vector<int> bd = pro(b, d);
        aPlusb = Add(a, b);
        cPlusd = Add(c, d);
        std::vector<int> abcd pro(aPlusb, cPlusd);
        
        abcd = Minus(abcd, ac);
        abcd = Minus(abcd, bd);
        
        for (int f = 0; f < len; f++)
        {
            ac.push_back(0);
        }
        for (int f = 0; f < len/2; f++)
        {
            abcd.push_back(0);
        }
        
        res = Add(ac, abcd);
        res = Add(res, bd);
        return res;
    }
    
    std::vector <int> Minus(std::vector <int> & a, std::vector <int> & b)
    {
        std::reverse( a.begin(), a.end() );
        std::reverse( b.begin(), b.end() );
        std::vector <int> res;
        int remainder = 0, i;
        for (i = 0; i < b.size(); i++)
        {
            remainder = a[i] - b[i];
            if (remainder < 0)
            {
                remainder = remainder + 10;
                a[i+1] = a[i+1] - 1;
            }
            res.push_back(remainder);
            remainder = 0;
        }
        while (i < a.size())
        {
            if(a[i] < 0)
            {
                a[i] = a[i] + 10;
                a[i+1] = a[i+1] - 1;
            }
            res.push_back(a[i]);
            i++;
        }
        while (res[res.size() - 1] == 0)
        {
            res.pop_back();
        }
        std::reverse( res.begin(), res.end() );
        return res;
    }
    
    void Boi()
    {
        x = pro(x, y);
        this->GetX();
    }
};

int main()
{
    Multiplicator A;
    A.setY(3);
    A.setX(5);
    A.GetX();
    A.GetY();
    A.Boi();
}

