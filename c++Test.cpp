#include <random>
#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>

void RandomiseNumbers(std::vector<int>& Numbers, std::vector<int>& SelectedNumbers)
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

bool IsSorted(std::vector<int>& SelectedNumbers)
{
    for (size_t i = 0; i < SelectedNumbers.size() - 1; i++)
    {
        if (SelectedNumbers[i] > SelectedNumbers[i + 1])
        {
            return false;
        }
    }
    return true;
}

void CreateList(std::vector<int>& OriginalNumbers, int listSize)
{
    for (int i = 1; i <= listSize; i++)
    {
        OriginalNumbers.push_back(i);
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    int counter = 1;
    int listSize;
    std::cout << "Enter the size of the list: ";
    std::cin >> listSize;

    std::vector<int> OriginalNumbers;
    CreateList(OriginalNumbers, listSize);

    std::vector<int> SelectedNumbers(listSize);

	auto start = std::chrono::high_resolution_clock::now();

    while (true)
    {
        std::vector<int> Numbers = OriginalNumbers;
        RandomiseNumbers(Numbers, SelectedNumbers);

        if (IsSorted(SelectedNumbers))
        {
			auto end = std::chrono::high_resolution_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
            for (int num : SelectedNumbers)
            {
                std::cout << num << " ";
            }
            std::cout << std::endl;
            std::cout << "Sorted!" << std::endl;
			std::cout << "Total iterations: " << counter << std::endl;
			std::cout << "Time taken: " << duration.count() << " milliseconds" << std::endl;
            std::cout << "Press Enter to exit...";
            std::cin.ignore();
            std::cin.get();
            break;
        }
        else
        {
            for (int num : SelectedNumbers)
            {
                std::cout << num << " ";
            }
            std::cout << std::endl;
            counter++;
        }
    }

    return 0;
}
