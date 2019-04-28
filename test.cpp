#include <iostream>
#include <algorithm>
#include <random>
#include <string>
 
class Number {
public:
    std::string num;
    int ptr = num.length();
 
    Number()
    {
        num = "";
    }
 
    Number (std::string a)
    {
        num = a;
        ptr = num.length();
    }
 
    Number (size_t a)
    {
        num = std::to_string(a);
        ptr = num.length();
    }
 
    int getd()
    {
        ptr--;
        if(ptr == -1)
            ptr = num.length()-1;
        return num[ptr] - 48; // from char to int
    }
 
    Number operator + (const Number& a)
    {
        Number number;
        int j = a.num.length() - 1;
        int i = this->num.length()-1;
        int tmp2 = 0;
        while(i >= 0 && j >= 0)
            {
               int tmp = this->num[i] - '0' + a.num[j] - '0' + tmp2;
               if(tmp > 9)
               {
                   tmp -= 10;
                   tmp2 = 1;
               } else
                   tmp2 = 0;
               number.num += (tmp + '0');
               j--;
               i--;
            }
        if(i >= 0)
            while(i >= 0)
            {
                int tmp = int(this->num[i] - '0') + tmp2;
                if(tmp > 9)
                {
                    tmp -= 10;
                    tmp2 = 1;
                } else
                    tmp2 = 0;
                number.num += (tmp + '0');
                i--;
            }
        else if (j >= 0)
            while(j >= 0)
            {
                int tmp = int(a.num[j] - '0') + tmp2;
                if(tmp > 9)
                {
                    tmp -= 10;
                    tmp2 = 1;
                } else
                    tmp2 = 0;
                number.num += (tmp + '0');
                j--;
            }
        if(tmp2)
            number.num +=(tmp2 +'0');
        reverse(number.num.begin(), number.num.end());
        return number;
    }
 
    Number operator - (const Number& a)
    {
        Number number;
        int j = a.num.length() - 1;
        int i = this->num.length()-1;
        int tmp2 = 0;
        while(i >= 0 && j >= 0)
        {
            int tmp = this->num[i] - a.num[j] - tmp2;
            if(tmp < 0)
            {
                tmp += 10;
                tmp2 = 1;
            } else
                tmp2 = 0;
            number.num += (tmp + '0');
            j--;
            i--;
        }
        if(i >= 0)
            while(i >= 0)
            {
                int tmp = int(this->num[i] - '0') - tmp2;
                if(tmp < 0)
                {
                    tmp += 10;
                    tmp2 = 1;
                } else
                    tmp2 = 0;
                number.num += (tmp + '0');
                i--;
            }
        else if (j >= 0)
            while(j >= 0)
            {
                int tmp = int(a.num[j] - '0') - tmp2;
                if(tmp < 0)
                {
                    tmp += 10;
                    tmp2 = 1;
                } else
                    tmp2 = 0;
                number.num += (tmp + '0');
                j--;
            }
        for(int n = number.num.length()-1; n > 0 ; n--)
        {
            if(number.num[n] == '0')
                number.num.pop_back();
            else
                break;
        }
        reverse(number.num.begin(), number.num.end());
        return number;
    }
 
    Number operator += (const Number& a)
    {
        *this = *this + a;
        return *this;
    }
 
    Number splitLeft()
    {
        int len = this->num.length();
        if(len == 1)
            return Number("0");
        std::string str = this->num.substr(0, len/2);
        if(str.empty())
            return Number("0");
        else
            return Number(str);
    }
 
    Number splitRight()
    {
        int len = this->num.length();
        if(len == 1)
            return *this;
        std::string str = this->num.substr(len/2, len - 1);
        if(str.empty())
            return Number("0");
        else
            return Number(str);
    }
};
 
class Multiplicator{
public:
    static Number schoolGradeMultiplication(Number &a, Number &b)
    {
        Number res = Number("0");
        std::string mainZeros = "";
        for(int i = 0; i < a.num.length(); i ++)
        {
            int num = a.getd();
            std::string zeros = mainZeros;
            for(int j = 0; j < b.num.length(); j ++)
            {
                Number temp = Number(std::to_string(b.getd() * num) + zeros);
                res += temp;
                zeros += "0";
            }
            mainZeros += "0";
        }
        if(res.num[0] == '0') // multiplication by 0 case
            res.num = "0";
        return res;
    }
 
    static Number divideAndConquer (Number a, Number b)
    {
        if(a.num.length() != b.num.length())
        {
            std::string zeros = "";
            if (a.num.length() > b.num.length())
            {
                int dif = a.num.length() - b.num.length();
                for(int i = 0; i < dif; i++)
                    zeros += '0';
                b.num = zeros + b.num;
            } else
            {
                int dif = b.num.length() - a.num.length();
                for(int i = 0; i < dif; i++)
                    zeros += '0';
                a.num = zeros + a.num;
            }
        }
        if(a.num.length() == 1 && b.num.length() == 1)
        {
            int res = a.getd() * b.getd();
            return Number(std::to_string(res));
        } else
        {
            Number z1 = a.splitLeft();
            Number z2 = b.splitLeft();
            Number q1 = a.splitRight();
            Number q2 = b.splitRight();
            std::string zeros = "";
            for(int i = 0; i < q1.num.length(); i++)
                zeros += '0';
            Number x = divideAndConquer(z1, z2);
            Number z = divideAndConquer(q1, q2);
            Number y = divideAndConquer(z1 + q1, z2 + q2) - x - z;
            x.num += zeros + zeros;
            y.num += zeros;
            Number res = x + y + z;
            for(int i = 0; i < res.num.length() - 1; i++)
            {
                if (res.num[0] == '0')
                    res.num.erase(0,1);
                else
                    break;
            }
            return res;
        }
    }
 
    static Number randomNumber(int k)
    {
        std::string num;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 9);
        std::uniform_int_distribution<> dis1(1, 9);
        num += dis1(gen) + '0';
        for(int i = 0; i < k - 1; i++)
            num += dis(gen) + '0';
        return Number(num);
    }
};
 
int main() {
    Number a = Number("99");
    Number b = Number("99");
    Number s = Multiplicator::divideAndConquer(a,b);
    Number f = Multiplicator::schoolGradeMultiplication(a,b);
    std::cout<<s.num<<std::endl;
    std::cout<<f.num<<std::endl;
//    std::cout<<s.splitLeft().num<<std::endl;
//    std::cout<<s.splitRight().num<<std::endl;
}
