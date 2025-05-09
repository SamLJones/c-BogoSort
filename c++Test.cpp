#include <random>
#include <iostream>
#include <vector>
#include <array>
#include <ctime>

void RandomiseNumbers(std::vector<int>& Numbers, std::array<int, 4>& SelectedNumbers)
{
    int i = 0;

    while (!Numbers.empty())
    {
        int RandomInt = rand() % Numbers.size();
        int Selected = Numbers[RandomInt];
        SelectedNumbers[i] = Selected;
        i++;

        Numbers.erase(Numbers.begin() + RandomInt);
    }
}

bool IsSorted(std::array<int, 4>& SelectedNumbers)
{
    for (int i = 0; i < 3; i++)
    {
        if (SelectedNumbers[i] > SelectedNumbers[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    std::vector<int> OriginalNumbers = { 1, 2, 3, 4 };
    std::array<int, 4> SelectedNumbers;

    while (true)
    {
        std::vector<int> Numbers = OriginalNumbers;
        RandomiseNumbers(Numbers, SelectedNumbers);

        if (IsSorted(SelectedNumbers))
        {
            for (int num : SelectedNumbers)
            {
                std::cout << num << " ";
            }
            std::cout << std::endl;
            std::cout << "Sorted!" << std::endl;
            exit(0);
        }
        else
        {
            for (int num : SelectedNumbers)
            {
                std::cout << num << " ";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}
