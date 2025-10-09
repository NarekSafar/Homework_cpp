#include <iostream>
#include <forward_list>
#include <cmath>

class Polynomial {
private:
    std::forward_list<std::pair<int, double>> polynom;
public:
    void addTerm(int degree, double coefficient) {
        if(coefficient != 0.0) {
            bool inserted = false;
            
            auto curr = polynom.begin();
            auto prev = polynom.before_begin();
            
            while(curr != polynom.end()) {
                if(degree > (*curr).first) {
                    polynom.insert_after(prev, std::pair<int, double>(degree, coefficient));
                    inserted = true;
                    break;
                } else if(degree == (*curr).first) {
                    (*curr).second += coefficient;
                    inserted = true;
                    break;
                }
                prev = curr;
                ++curr;
            }
            
            if(!inserted) {
                polynom.insert_after(prev, std::pair<int, double>(degree, coefficient));
            }
        }
    }
    
    double evaluate(double x) const {
        double value = 0.0;
        for(auto it = polynom.begin(); it != polynom.end(); ++it) {
            value += (*it).second * pow(x, (*it).first);
        }
        return value;
    }
    
    Polynomial derivative() const {
        Polynomial dp;
        for(auto it = polynom.begin(); it != polynom.end(); ++it) {
            if((*it).first != 0) {
                dp.addTerm((*it).first - 1, (*it).second * (*it).first);
            }
        }
        return dp;
    }
    
    void print() const {
        bool first = true;
        for(auto it = polynom.begin(); it != polynom.end(); ++it) {
            double coeff = (*it).second;
            int deg = (*it).first;
    
            if(first) {
                if(coeff < 0) std::cout << "-";
                first = false;
            } else {
                std::cout << (coeff > 0 ? " + " : " - ");
            }
            
            double absCoeff = abs(coeff);
            if(deg == 0) {
                std::cout << absCoeff;
            } else if(deg == 1) {
                if(absCoeff != 1) std::cout << absCoeff;
                std::cout << "x";
            } else {
                if(absCoeff != 1) std::cout << absCoeff;
                std::cout << "x^" << deg;
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    Polynomial p;
    p.addTerm(2, 3.0);  
    p.addTerm(0, 5.0);  
    p.addTerm(1, -2.0); 
    p.print(); 
    double result = p.evaluate(2.0); 
    std::cout << result << std::endl;
    Polynomial dp = p.derivative();
    dp.print();
    return 0;
}

