#include <iostream>
#include <algorithm>
#include <random>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>

class Number {
public:
    std::string num; // Your number
    int length = num.length(); // Length of your number
 
    Number() // Best constructor to construct empty string
    {
        num = "";
    }
 
    Number (std::string tonumber) // Construsctor to construct number using string. In our start-up we call it from the string to the number.
    {
        num = tonumber;
        length = num.length();
    }
 
    Number (size_t a) // One more rather useless constructor, but we built it because of flex.
    {
        num = std::to_string(a);
        length = num.length();
    }
 
    int GetDigit() // Converting char to integers
    {
        length--;
        if(length == -1)
        {
            length = num.length()-1;
        }
        return num[length] - 48; 
    }
    
    static Number Addition(const Number& a, const Number& b) // Professional method that allows you to sum 2 numbers of any length
    {
        Number neww;
        int len1 = a.num.length() - 1;
        int len2 = b.num.length() - 1;
        int remainder = 0, res = 0;
        while ((len1 >= 0) && (len2 >= 0))
        {
            res = (a.num[len1] - '0') + (b.num[len2] - '0') + remainder;
            if (res > 9)
            {
                res = res - 10;
                remainder = 1;
            }
            else 
            {
                remainder = 0;
            }
            char t = res + '0';
            neww.num = neww.num + t;
            len1--;
            len2--;
        }
        if (len1 >= 0)
        {
            while (len1 >= 0)
            {
                res = (a.num[len1] - '0') + remainder;
                if (res > 9)
                {
                    res = res - 10;
                    remainder = 1;
                }
                else
                {
                    remainder = 0;
                }
                char tt = res + '0';
                neww.num = neww.num + tt;
                len1--;
            }
        }
        else if (len2 >= 0)
        {
            while (len2 >= 0)
            {
                res = (b.num[len2] - '0') + remainder;
                if (res > 9)
                {
                    res = res - 10;
                    remainder = 1;
                }
                else
                {
                    remainder = 0;
                }
                char ttt = res + '0';
                neww.num = neww.num + ttt;
                len2--;
            }
        }
        if (remainder > 0)
        {
            char tttt = remainder + '0';
            neww.num = neww.num + tttt;
        }
        reverse(neww.num.begin(), neww.num.end());
        return neww;
    }
    
    static Number Minus(const Number& a, const Number& b)
    {
        Number c;
        int len1 = a.num.length() - 1;
        int len2 = b.num.length() - 1;
        int remainder = 0, res = 0;
        char id;
        while ((len1 >= 0) && (len2 >= 0))
        {
            res = a.num[len1] - b.num[len2] - remainder;
            if (res < 0)
            {
                res = res + 10;
                remainder = 1;
            }
            else 
            {
                remainder = 0;
            }
            id = res + '0';
            c.num = c.num + id;
            len1--;
            len2--;
        }
        if (len1 >= 0)
        {
            while(len1 >= 0)
            {
                res = (a.num[len1] - '0') - remainder;
                if (res < 0)
                {
                    res = res + 10;
                    remainder = 1;
                }
                else
                {
                    remainder = 0;
                }
                id = res + '0';
                c.num = c.num + id;
                len1--;
            }
        }
        else if (len2 >= 0)
        {
            while(len2 >= 0)
            {
                res = (b.num[len2] - '0') - remainder;
                if (res < 0)
                {
                    res = res + 10;
                    remainder = 1;
                }
                else
                {
                    remainder = 0;
                }
                id = res + '0';
                c.num = c.num + '0';
                len2--;
            }
        }
        for (int n = c.num.length() - 1; n > 0; n--)
        {
            if (c.num[n] == '0')
            {
                c.num.pop_back();
            }
            else
            {
                break;
            }
        }
        reverse(c.num.begin(), c.num.end());
        return c;
    }

    void Get(Number & a)
    {
        for (int i = 0; i < a.num.length(); i++)
        {
            std::cout << a.num[i];
        }
    }
    
    Number GetLeft()
    {
        int length = num.length();
        if(length == 1)
        {
            return Number("0");
        }
        std::string s = this->num.substr(0, length/2);
        if (s.empty())
        {
            return Number("0");
        }
        else
        {
            return Number(s);
        }
    }
    Number GetRight()
    {
        int length = num.length();
        if(length == 1)
        {
            return *this;
        }
        std::string s = this->num.substr(length/2, length - 1);
        if (s.empty())
        {
            return Number("0");
        }
        else
        {
            return Number(s);
        }        
    }
};

class Multiplicator
{
public:
    std::vector <double> time1;
    std::vector <double> time2;
    static Number School(Number &a, Number &b) // Multiplication of 2 numbers of any length, it has never been easier, thanks to out start-up
    {
        Number result = Number("0");
        Number res = Number("");
        std::string s;
        char q;
        int i, j, digit, temp;
        int remainder = 0;
        for(i = 0; i < b.num.length(); i++)
        {
            remainder = 0;
            s = "";
            digit = b.GetDigit();
            for (j = 0; j < a.num.length(); j++)
            {
                temp = digit * a.GetDigit() + remainder;
                remainder = temp / 10;
                temp = temp % 10;
                q = temp + '0';
                s = s + q;
                // res = Number(std::to_string(b.GetDigit() * digit) + zero);
                // res = Addition(result, res);
            }
            if (remainder > 0)
            {
                q = remainder + '0';
                s = s + q;
            }
            reverse(s.begin(), s.end());
            for (int m = 0; m < i; m++)
            {
                s = s + '0';
            }
            res = Number(s);
            result = Number::Addition(res, result);
        }
        if(result.num[0] == '0')
        {
            result.num = "0";
        }
        return result;    
    }
    static Number pro(Number a, Number b) // Another method to multiply numbers with a little bit of an artistic flair
    {
        if (a.num.length() > b.num.length())
        {
            while (b.num.length() < a.num.length())
            {
                b.num = '0' + b.num;
            }
        }
        else if (a.num.length() < b.num.length())
        {
            while (b.num.length() > a.num.length())
            {
                a.num = '0' + a.num;
            }
        }
        if(a.num.length() == 1 && b.num.length() == 1)
        {
            int res = a.GetDigit() * b.GetDigit();
            return Number(std::to_string(res));
        }
        else
        {
            Number aa = a.GetLeft();
            Number bb = b.GetLeft();
            Number cc = a.GetRight();
            Number dd = b.GetRight();
            std::string zero = "";
            for(int i = 0; i < cc.num.length(); i++)
            {
                zero = zero + '0';
            }
            Number aabb = pro(aa, bb);
            Number ccdd = pro(cc, dd);
            Number aplusc = Number::Addition(aa, cc);
            Number bplusd = Number::Addition(bb, dd);
            Number abcd = pro(aplusc, bplusd);
            abcd = Number::Minus(abcd, aabb);
            abcd = Number::Minus(abcd, ccdd);
            aabb.num = aabb.num + zero + zero;
            abcd.num = abcd.num + zero;
            Number res = Number::Addition(aabb, abcd);
            res = Number::Addition(res, ccdd);
            for(int i = 0; i < res.num.length() - 1; i++)
            {
                if (res.num[0] == '0')
                {
                    res.num.erase(0,1);
                }
                else
                {
                    break;
                }
            }
            return res;
        }
    }
    
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
    std::string GeneratorGeorge(int k) // Now we will generate the whole string of length k with the respect to George and Peppa.
    {
        std::string Peppa;
        int digit = GeneratorB();
        char q;
        q = digit + '0';
        Peppa = Peppa + q;
        for (int i = 1; i < k; i++)
        {
            digit = Generator();
            q = digit + '0';
            Peppa = Peppa + q;
        }
        return Peppa;
    }
    
    void Results(int k) //Grand final of our project, I burst into tears after we had done this
    {
        std::string x,y;
        Number a,b,c;
        double time = 0;
        double flextime = 0;
        for(int i = 1; i <= 3; i++)
        {
            x = GeneratorGeorge(k);
            y = GeneratorGeorge(k);
            a = Number(x);
            b = Number(y);
            clock_t t = clock();
            c = School(a,b);
            t = clock() - t;
            time = time + t;
            clock_t t1 = clock();
            c = pro(a,b);
            t1 = clock() - t1;
            flextime = flextime + t1;
        }
        time = time / 3;
        flextime = flextime / 3;
        time1.push_back(time);
        time2.push_back(flextime);
    }
    
    void GetCSV()
    { // Just gives you CSV file with vectors "time1" and "time2" data, no useless comments, without unnecessary trouble, it has never been more convinient to get you CSV file
        std::ofstream myfile;
        myfile.open ("TimeData.csv");
        for (int i = 0; i < time1.size(); i++)
        {
            myfile << i + 1 << "," << time1[i] << "," << time2[i] << "\n";
        }
        myfile.close();
    }
};

int main()
{
    Number a,b,c;
    int k;
    Multiplicator q;
    for (k = 1; k <= 1000; k++)
    {
        q.Results(k);
    }
    q.GetCSV();
}
