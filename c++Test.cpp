#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <array>

int i = 0;

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    std::vector<int> Numbers = { 1,2,3,4,5,6,7,8,9,10 };
    std::array<int, 10> SelectedNumbers;

    while (!Numbers.empty())
    {
        int RandomInt = rand() % Numbers.size();
        int Selected = Numbers[RandomInt];
        std::cout << Selected << "\n";
        SelectedNumbers[i] = Selected;
        i++;

        Numbers.erase(Numbers.begin() + RandomInt);
    }

    std::cout << "Completed";
}