#include <iostream>
#include <math.h>
#include "solver.hpp"



using namespace solver;

bool solver::isZero(double x){
    return (x <= EPS && x >= -EPS);
}

//Real variables

double solver::solve(RealVariable& x){
    return 0;
}

RealVariable& RealVariable::operator==(double x){
    return *this;
}

RealVariable& RealVariable::operator==(RealVariable &x){
    return *this;
}

RealVariable& RealVariable::operator+(double x){
    return *this;
}

RealVariable& RealVariable::operator+(RealVariable &x){
    return *this;
}

RealVariable& RealVariable::operator-(double x){
    return *this;
}

RealVariable& RealVariable::operator-(RealVariable &x){
    return *this;
}

RealVariable& RealVariable::operator*(double x){
    this->coef *= x;
    return *this;
}

RealVariable& RealVariable::operator*(RealVariable &x){
    this->coef *= x.coef;
    this->power *= x.power;
    return *this;
}

RealVariable& RealVariable::operator^(double x){
    this->power *= x;
    return *this;
}

RealVariable& RealVariable::operator/(double x){
    if(isZero(x)) throw runtime_error("cannnot divide by 0");
    this->coef /= x;
    return *this;
}

RealVariable& RealVariable::operator/(RealVariable &x){
    if(isZero(x.coef)) throw runtime_error("cannnot divide by 0");
    this->coef /= x.coef;
    this->power -= x.power;
    return *this;
}

RealVariable& solver::operator==(double x, RealVariable &y){
    return y;
}

RealVariable& solver::operator+(double x, RealVariable &y){
    return y;
}

RealVariable& solver::operator-(double x, RealVariable &y){
    return y;
}

RealVariable& solver::operator*(double x, RealVariable &y){
    return y;
}

RealVariable& solver::operator/(double x, RealVariable &y){
    return y;
}



//complex variables

std::complex<double> solver::solve(ComplexVariable& x){
    return 0;
}

ComplexVariable& ComplexVariable::operator+(std::complex<double> x){
    return *this;
}
ComplexVariable& ComplexVariable::operator==(std::complex<double> x){
    return *this;
}

ComplexVariable& ComplexVariable::operator+(ComplexVariable &x){
    return *this;
}
ComplexVariable& ComplexVariable::operator==(ComplexVariable &x){
    return *this;
}

ComplexVariable& ComplexVariable::operator-(std::complex<double> x){
    return *this;
}

ComplexVariable& ComplexVariable::operator-(ComplexVariable &x){
    return *this;
}

ComplexVariable& ComplexVariable::operator*(std::complex<double> x){
    return *this;
}

ComplexVariable& ComplexVariable::operator*(ComplexVariable &x){
    return *this;
}

ComplexVariable& ComplexVariable::operator^(std::complex<double> x){
    return *this;
}

ComplexVariable& ComplexVariable::operator^(ComplexVariable &x){
    return *this;
}

ComplexVariable& ComplexVariable::operator/(std::complex<double> x){
    return *this;
}

ComplexVariable& ComplexVariable::operator/(ComplexVariable &x){
    return *this;
}

ComplexVariable& solver::operator==(std::complex<double> x, ComplexVariable &y){
    return y;
}

ComplexVariable& solver::operator+(std::complex<double> x, ComplexVariable &y){
    return y;
}

ComplexVariable& solver::operator-(std::complex<double> x, ComplexVariable &y){
    return y;
}

ComplexVariable& solver::operator*(std::complex<double> x, ComplexVariable &y){
    return y;
}

ComplexVariable& solver::operator/(std::complex<double> x, ComplexVariable &y){
    return y;
}