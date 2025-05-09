#include <random>
#include <iostream>
#include <vector>
#include <array>
#include <ctime>

int i = 0;
void RandomiseNumbers(std::vector<int>& Numbers, std::array<int, 10>& SelectedNumbers)
{
    i = 0;

    while (!Numbers.empty())
    {
        int RandomInt = rand() % Numbers.size();
        int Selected = Numbers[RandomInt];
        std::cout << Selected;
        SelectedNumbers[i] = Selected;
        i++;

        Numbers.erase(Numbers.begin() + RandomInt);
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    std::vector<int> Numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::array<int, 10> SelectedNumbers;
    RandomiseNumbers(Numbers, SelectedNumbers);

    return 0;
}