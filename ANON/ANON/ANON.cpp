#include <iostream>
#include <string>
#include <istream>

void Fuck(std::string& x) {
    std::getline(std::cin, x);
}

struct obj
{
    obj(
        int sos = 5,
        std::string cal = ""
    ) : x(sos), cal(cal) {}
    int x;
    std::string cal;
};

int main()
{
    obj CAL;
    obj* callll;
    Fuck(CAL.cal);
    callll = &CAL;
    std::cout << "Hello World!\n" << callll&->cal << CAL.x;
    callll.x = 22225;
    std::cout << "\nHello World!\n" << CAL.x << CAL.x;
}
