#include "bTree.h"
#include <iostream>
#include <vector>

void printInstructions()
{
	std::cout << "Choose an option or enter -1 to quit. \n"
		<< "1.) Choose active Binary Tree\n"
		<< "2.) Check if the tree is empty\n"
		<< "3.) Check if the tree is full\n"
		<< "4.) Tree swapper. Swap the active tree's data with the data of an inactive tree. \n"
		<< "5.) Insert a number into the tree\n"
		<< "6.) Remove a number from the tree\n"
		<< "7.) Output all data in the tree in-order.\n"
		<< "8.) Draw the tree visually.\n" << std::endl;
}

int main()
{
	bTree<int> tree0, tree1, tree2, tree3;
	std::vector<bTree<int>> trees;
	trees.push_back(tree3);
	trees.push_back(tree2);
	trees.push_back(tree1);
	trees.push_back(tree0);
	
	int userInput, activeTree = 0;
	bool quit = false;
	
	printInstructions();

	while (!quit)
	{
		std::cin >> userInput;

		switch (userInput)
		{
		case 0:
			printInstructions();
			break;
		
		case 1:
			std::cout << "There are 4 trees. which one would you like active?\nEnter 0, 1, 2, or 3:" << std::endl;
			std::cin >> activeTree;
			break;

		case 2:
			if (trees[activeTree].empty()) std::cout << "Tree 1 is empty." << std::endl;
			else std::cout << "Tree 1 is not empty." << std::endl;		
			break;
		
		case 3:
			if (trees[activeTree].full()) std::cout << "Tree 1 is full." << std::endl;
			else std::cout << "Tree 1 is not full." << std::endl;			
			break;

		case 4:
			std::cout << "Your active tree is tree " << activeTree
				<< " .\nWhat tree number would you like to swap all its nodes with?" << std::endl;
			std::cin >> userInput;
			
			trees[activeTree].swap(trees[userInput]);
			std::cout << "The swap is complete. Try outputting in-order with option 7 to see the change." << std::endl;
			break;

		case 5:
			while (userInput != -1)
			{
				std::cout << "Enter a number to insert into the tree. Enter -1 when finished.\n" << std::endl;
				std::cin >> userInput;

				if (userInput != -1)
				{
					trees[activeTree].bInsert(userInput);
				}
			}
			break;

		case 6:
			while (userInput != -1)
			{
				std::cout << "Enter a number to remove from the tree. Enter -1 when finished.\n" << std::endl;
				std::cin >> userInput;

				if (userInput != -1)
				{
					trees[activeTree].bRemove(userInput);
				}
			}
			break;

		case 7:		
			std::cout << "\nTree " << activeTree << " output in-order: " << std::endl;
			trees[activeTree].inorder();
			std::cout << std::endl;
			break;

		case 8:
			std::cout << "not implimented" << std::endl;
			break;

		case -1:
			quit = true;
			break;

		default:
			std::cout << "\nEnter 0 to print the options again.\n" << std::endl;
		}
	}
	return 0;
}