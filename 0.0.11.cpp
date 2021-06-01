#include <iostream>

int main()
{
double m;
double V;
std::cout << "Enter m: ";
std::cin >> m;
if(m < 0)
{
std::cout << "Uncorrect input. Program exit." << std::endl;
return 0;
}
std::cout << "Enter V: ";
std::cin >> V;
if(V < 0)
{
std::cout << "Uncorrect input. Program exit." << std::endl;
return 0;
}
std::cout << "Result: " << (m * V * V) / 2 << std::endl;
return 0;
}
