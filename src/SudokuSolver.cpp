#include <iostream>
#include "SudokuSolver.h"

SudokuSolver::SudokuSolver() : grid(gridSize, std::vector<int>(gridSize))
{
}

SudokuSolver::SudokuSolver(std::string inputFileName) : grid(gridSize, std::vector<int>(gridSize))
{
	initialization(inputFileName);
}

void SudokuSolver::initialization(std::string inputFileName)
{
	inputFile.open(inputFileName);
	if(!inputFile.is_open())
		std::cout << "failed to open" << inputFileName << std::endl;
	else
	{
		for(size_t i = 0; i < gridSize; ++i)
		{
			for(size_t j = 0; j < gridSize; ++j)
			{
				inputFile >> grid[i][j];
			}
		}
	}
	inputFile.close();
}

void SudokuSolver::solve()
{
	solving(grid);
}

bool SudokuSolver::solving(std::vector<std::vector<int> >& grid)
{
	for(size_t i = 0; i < gridSize; ++i)
	{
		for(size_t j = 0; j < gridSize; ++j)
		{
			if(grid[i][j] == 0)
			{
				for(size_t k = 1; k <= 9; ++k)
				{
					if(isValidState(grid, i, j, k))
					{
						grid[i][j] = k;
						if(solving(grid))
							return true;

						grid[i][j] = 0;
					}
				}
				return false;
			}
		}
	}
	return true;
}

bool SudokuSolver::isValidState(std::vector<std::vector<int> >& grid, const int row, const int column, const int value)
{
	for(size_t i = 0; i < gridSize; ++i)
	{
		if(grid[i][column] == value)
			return false;

		if(grid[row][i] == value)
			return false;

		if(grid[3 * (row / 3) + i / 3][3 * (column / 3) + i % 3] == value)
			return false;
	}

	return true;
}

void SudokuSolver::output(std::string outputFileName)
{
	outputFile.open(outputFileName);
	for(size_t i = 0; i < gridSize; ++i)
	{
		for(size_t j = 0; j < gridSize; ++j)
		{
			outputFile << grid[i][j] << " ";
		}
		outputFile << std::endl;
	}
	outputFile.close();
}