#include "solver.hpp"
#include "doctest.h"
#include <complex>

using std::string;
using namespace std;
using solver::solve, solver::RealVariable, solver::ComplexVariable;



TEST_CASE("Test Realvarible") {
    RealVariable x;
     CHECK(solve(2*x==10)==5);
     CHECK(solve(-2*x==-10)==5);
     CHECK(solve(2*x==0)==0);
     CHECK(solve(8*x==0)==0);
     CHECK(solve(8*x/8==1)==1);
     CHECK(solve(10*x==10)==1);
     CHECK(solve(-3*x==-6)==2);
     CHECK(solve(-2*x==0)==0);
     CHECK((solve((x ^ 2) == 16) == 4 || solve((x ^ 2) == 16) == double(-4)));
    CHECK((solve((x ^ 2) == 9) == double(3) || solve((x ^ 2) == 9) == double(-3)));
    CHECK((solve((x ^ 2) == 25) == double(5) || solve((x ^ 2) == 25) == double(-5)));
    CHECK((solve((x ^ 2) == 100) == double(10) || solve((x ^ 2) == 100) == double(-10)));
     CHECK(solve(14*x==0)==0);
     CHECK(solve(5*x/10==1)==2);
     CHECK(solve(4*x==20)==5);
     CHECK(solve(-4*x==-20)==5);
     CHECK(solve(6*x==0)==0);
     CHECK(solve(90*x==90)==1);
     CHECK(solve(2*x/4==1)==2);
     CHECK(solve(x-20==-20 )==0);
     CHECK(solve(x-20==-5)==15);
     CHECK(solve(x+20==5)==-15);
     CHECK(solve(x+25==5)==-20);
     CHECK(solve(2*x== -4 )==-2);
     CHECK(solve(3*x+5==11)==2);
     CHECK(solve(x-30==-20 )==10);
     CHECK(solve(x-2==-5)==-3);
     CHECK(solve(x+5==8)==3);
     CHECK(solve(x+12==5)==-7);
     CHECK(solve(2*x== 4 )==2);
     CHECK(solve(2*x+2==22)==10);
     CHECK(solve(3*x+2==14)==4);
     CHECK(solve(3*x+4==16)==4);
     CHECK(solve(x+15==-8)==-23);
     CHECK(solve(6*x/2+2==14)==4);
     CHECK(solve(4*x+6==10)==1);
     CHECK(solve(3*x+7==28)==7);
     CHECK(solve(x+8==-18)==-26);
     CHECK(solve(8*x/3-2==14)==6);
     CHECK((solve((x^2)==9)==3||solve((x^2)==9)==-3));
     CHECK((solve(2*(x^2)==18)==3||solve(2*(x^2)==18)==-3));
     CHECK((solve((x^2)+5==30)==5||solve((x^2)+5==30)==-5));
     CHECK(solve(2*x-2==4)==3);
     CHECK((solve((x^2)==16)==4||solve((x^2)==9)==-4));
     CHECK((solve(2*(x^2)==8)==2||solve(2*(x^2)==8)==-2));
     CHECK((solve((x^2)+6==22)==4||solve((x^2)+6==22)==-4));
     CHECK(solve(2*x-9==9)==9);
     CHECK((solve((x^2)==100)==10||solve((x^2)==100)==-10));


}

TEST_CASE("Test Throw Real Varible"){
    RealVariable x;

    CHECK_THROWS(solve((x^2)==-10));
    CHECK_THROWS( solve((x^2)==-7));
    CHECK_THROWS( solve((x^2)==-71));
    CHECK_THROWS( solve(2*(x^2)==-88));
    CHECK_THROWS( solve(2*(x^2)==-90));
    CHECK_THROWS(solve((x^2)==-80));
    CHECK_THROWS( solve((x^2)==-1.0));
    CHECK_THROWS( solve((x^2)==-888));
    CHECK_THROWS( solve(2*(x^2)==-9));
    CHECK_THROWS( solve(4*(x^2)==-100));
    CHECK_THROWS(solve((6*x^2)==-100));
    CHECK_THROWS( solve((10*x^2)==-16));
    CHECK_THROWS( solve((x^2+10)==-1));
    CHECK_THROWS( solve(2*(x^2)+80==-16));
    CHECK_THROWS( solve(2*(x^2)+20==-100));
    CHECK_THROWS_AS(solve((x ^ 2) == -16), std::exception);
    CHECK_THROWS_AS(solve(9 * (x ^ 2) + 8 * x + 7 == 0), std::exception);
    CHECK_THROWS_AS(solve(3 * (x ^ 2) + 4 * x + 5 == 0), std::exception);
    CHECK_THROWS_AS(solve((x ^ 2) + 2 * x + 3 == 0), std::exception);
    CHECK_THROWS_AS(solve(5 * (x ^ 2) + 6 * x + 7 == 0), std::exception);
    CHECK_THROWS_AS(solve(2 * (x ^ 2) + 3 * x + 4 == 0), std::exception);
    CHECK_THROWS_AS(solve((x ^ 2) == -49), std::exception);
    CHECK_THROWS_AS(solve((x ^ 2) == -1), std::exception);
    CHECK_THROWS_AS(solve((x ^ 2) == -16), std::exception);
    CHECK_THROWS_AS(solve((x ^ 2) == -25), std::exception);
    CHECK_THROWS_AS(solve((x ^ 2) == -9), std::exception);
    CHECK_THROWS_AS(solve((x ^ 2) == -36), std::exception);
    CHECK_THROWS_AS(solve((x ^ 2) == -100), std::exception);


}






TEST_CASE("Test ComplexVariable"){
   
    ComplexVariable y;
    CHECK(solve(2*y-4 == 10)==std::complex<double>(7,0));
    CHECK(solve(y-4 == 10)==std::complex<double>(14,0));
    CHECK((solve((y^2) == 16)==std::complex<double>(4,0)||solve((y^2) == 16)==std::complex<double>(-4,0)));
    CHECK((solve((y^2) == -16)==std::complex<double>(0,4)||solve((y^2) == -16)==std::complex<double>(0,-4)));
    CHECK((solve((y^2) + 2*y + 4 == 20 + 6*y/2 - y)==std::complex<double>(4,0)||solve((y^2) + 2*y + 4 == 20 + 6*y/2 - y)==std::complex<double>(-4,0))); 
    CHECK((solve(y+5i == 2*y+3i)==std::complex<double>(0,2)||solve(y+5i == 2*y+3i)==std::complex<double>(0,-2)));
    CHECK(solve(2*y-8 == 10)==std::complex<double>(9,0));
    CHECK(solve(y-14 == 100)==std::complex<double>(114,0));
    CHECK((solve((y^2) == 25)==std::complex<double>(5,0)||solve((y^2) == 25)==std::complex<double>(-5,0)));
    CHECK((solve((y^2) == -36)==std::complex<double>(0,6)||solve((y^2) == -36)==std::complex<double>(0,-6)));
    CHECK((solve((y^2) + 2*y + 4 == 20 + 6*y/2 - y)==std::complex<double>(4,0)||solve((y^2) + 2*y + 4 == 20 + 6*y/2 - y)==std::complex<double>(-4,0))); 
    CHECK((solve(y+5i == 2*y+3i)==std::complex<double>(0,2)||solve(y+5i == 2*y+3i)==std::complex<double>(0,-2)));
    CHECK((solve((y^2) == 16)==std::complex<double>(4,0)||solve((y^2) == 16)==std::complex<double>(-4,0))); 
    CHECK((solve((y^2)==25)==std::complex<double>(5,0)||solve((y^2)==25)==std::complex<double>(-5,0))); 
    CHECK((solve((y^2)+2==18)==std::complex<double>(4,0)||solve((y^2)+2==18)==std::complex<double>(-4,0))); 
    ComplexVariable x;
    CHECK((solve((x ^ 2) == 4) == double(2) || solve((x ^ 2) == 100) == double(-2)));
    CHECK((solve((x ^ 2) == 16) == double(4) || solve((x ^ 2) == 16) == double(-4)));
    CHECK((solve((x ^ 2) == 9) == double(3) || solve((x ^ 2) == 9) == double(-3)));
    CHECK((solve((x ^ 2) == 25) == double(5) || solve((x ^ 2) == 25) == double(-5)));
    CHECK((solve((x ^ 2) == 100) == double(10) || solve((x ^ 2) == 100) == double(-10)));
    CHECK((solve((x ^ 2) == 49) == double(7) || solve((x ^ 2) == 100) == double(-7)));
    CHECK((solve((x ^ 2) == 36) == double(6) || solve((x ^ 2) == 100) == double(-6)));
    CHECK((solve((x ^ 2) == 81) == double(9) || solve((x ^ 2) == 100) == double(-9)));
    
    
}
TEST_CASE("Test Throw ComplexVarible"){

    ComplexVariable x;
    CHECK_THROWS(solve(5 == x*0));
    CHECK_THROWS(solve(15== 2*(x*0)));
    CHECK_THROWS(solve(12 == x*0));


}