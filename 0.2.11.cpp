#include <iostream>

#define PI 3.14

int main()
{
double r;
double R;
std::cout << "Enter r: ";
std::cin >> r;
if(r < 0)
{
std::cout << "Uncorrect input. Program exit." << std::endl;
return 0;
}
std::cout << "Enter R: ";
std::cin >> R;
if(R < 0)
{
std::cout << "Uncorrect input. Program exit." << std::endl;
return 0;
}
std::cout << "Result: " << 2 * PI * PI * R * r * r << std::endl;
return 0;
}
