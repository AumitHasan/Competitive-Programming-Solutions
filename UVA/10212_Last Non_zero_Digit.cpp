#include <iostream>

#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;

int main()

{

    mp::cpp_int s1("12368123681263817263863821638126328136218362182163812638213681312836816231283123612386128362813628137218313612830923405840459");

    mp::cpp_int s2("345897934309876048509348509806322098730945708923569854979837290738978903789223986534687534895473257890354709230923504923709887329092450970423707534025");

    mp::cpp_int S=s1*s2;

    std::cout << S << '\n';

}
