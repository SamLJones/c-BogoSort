#include <random>
#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>

void RandomiseNumbers(std::vector<int>& Numbers, std::vector<int>& SelectedNumbers)
{
    SelectedNumbers.clear();

    while (!Numbers.empty())
    {
        int RandomInt = rand() % Numbers.size();
        int Selected = Numbers[RandomInt];
        SelectedNumbers.push_back(Selected);
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
    bool validInput = false;

    srand(static_cast<unsigned int>(time(0)));

    bool visual;
    std::string visualQuery;
    std::cout << " Would you like visual representation (Yes or No) ";
    std::cin >> visualQuery;
    if (visualQuery == "yes" || visualQuery == "Yes")
    {
        visual = true;
    }
    else
    {
        visual = false;
    }

    int listSize;
    std::cout << "Enter the size of the list: ";
    std::cin >> listSize;

    while (!validInput)
    {
        std::cout << "Choose your sorting algorithm" << std::endl;
        std::cout << "Bogo, Stalin, Miracle" << std::endl;
        std::string choice;
        std::cin >> choice;

        int counter = 1;

        std::vector<int> OriginalNumbers;
        CreateList(OriginalNumbers, listSize);

        std::vector<int> SelectedNumbers(listSize);

        auto start = std::chrono::high_resolution_clock::now();

        if (choice == "Bogo" || choice == "bogo")
        {
            validInput = true;
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
                    if (visual)
                    {
                        for (int num : SelectedNumbers)
                        {
                            std::cout << num << " ";
                        }
                        std::cout << std::endl;
                    }
                    counter++;
                }
            }
        }
        else if (choice == "Stalin" || choice == "stalin")
               {
                   validInput = true;
                   auto start = std::chrono::high_resolution_clock::now();
                   int i = 1;
                   RandomiseNumbers(OriginalNumbers, SelectedNumbers);

                   while (i < static_cast<int>(SelectedNumbers.size()))
                   {
                       if (SelectedNumbers[i - 1] > SelectedNumbers[i])
                       {
                           SelectedNumbers.erase(SelectedNumbers.begin() + i);
                       }
                       else
                       {
                           i++;
                       }

                       if (visual)
                       {
                           for (int num : SelectedNumbers)
                           {
                               std::cout << num << " ";
                           }
                           std::cout << std::endl;
                       }
                   }

                   for (int num : SelectedNumbers)
                   {
                       std::cout << num << " ";
                   }
                   std::cout << std::endl;

                   auto end = std::chrono::high_resolution_clock::now();
                   auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
                   std::cout << "Sorted!" << std::endl;
                   std::cout << "Time taken: " << duration.count() << " milliseconds" << std::endl;
                   std::cout << "Press Enter to exit...";
                   std::cin.ignore();
                   std::cin.get();
                   break;
               }

		else if (choice == "Miracle" || choice == "miracle")
		{
			validInput = true;
			RandomiseNumbers(OriginalNumbers, SelectedNumbers);

            if (IsSorted(SelectedNumbers))
            {
				std::cout << "ITS A MIRACLE!" << std::endl;
            }
            else
			{
				std::cout << "Not a miracle" << std::endl;
			}
            for (int num : SelectedNumbers)
            {
                std::cout << num << " ";
            }
            std::cout << std::endl;
            std::cout << "Press Enter to exit...";
            std::cin.ignore();
            std::cin.get();
            break;
		}

        else if (choice == "Elon" || choice == "elon")
        {
            validInput = true;
            
			int elonSize = listSize / 2;

			RandomiseNumbers(OriginalNumbers, SelectedNumbers);

            while (elonSize > 0)
            {
				SelectedNumbers.erase(SelectedNumbers.begin() + 1);
                if (visual)
                {
                    for (int num : SelectedNumbers)
                    {
                        std::cout << num << " ";
                    }
                }
				elonSize--;
            }

			for (int num : SelectedNumbers)
			{
				std::cout << num << " ";
			}

			std::cout << std::endl;
			std::cout << "List is now sorted to DOGE standards!" << std::endl;
			std::cout << "Press Enter to exit...";
			std::cin.ignore();
			std::cin.get();
			break;
		}
		else
		{
			std::cout << "Invalid choice, please try again." << std::endl;
        }

    }
    return 0;
}
