 
#include <iostream>
#include <cassert> // for assert...
#include<typeinfo> // for typeid...
 

class Fraction {
    private:
        int num, denom;
    
    public:
        Fraction(int num, int denom)   {
            this->num = num; 
            this->denom = denom;
            assert(denom != 0 && "Denominator cannot be zero");
            assert(typeid(num) == typeid(int) && typeid(denom) == typeid(int) && "Numerator and denominator must be of type int");
            reduce();   
        }

    void reduce() {
        int res = gcd(num, denom); 
        num /= res;
        denom /= res;
    }
    
    // override the '+' operator... 
    Fraction operator+(Fraction &other) {
        int ansNum = this->num * other.denom + other.num * this->denom;
        int ansDen = this->denom * other.denom;

        Fraction ans(ansNum, ansDen);
        ans.reduce();
        return ans;
    }

    // using Euclid algorithmmm....
    int gcd(int a, int b) {
        return  (a == 0) ? b : gcd(b%a, a);
    }


    
    // Override the << operator for printing
    friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
        os << fraction.num << "/" << fraction.denom;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Fraction& fraction) {
        is >> fraction.num >> fraction.denom;
        return is;
    }
     

}; 


int main() {
    Fraction fr1(6, 4), fr2(1, 2);
    Fraction ans = fr1 + fr2; 

    std:: cout<< "Fraction is: " << ans << std:: endl;


    return 0;
}