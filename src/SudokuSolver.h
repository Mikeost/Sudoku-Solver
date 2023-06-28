#ifndef SUDOKUSOLVER_H
#define SUDOKUSOLVER_H

#include <fstream>
#include <vector>
#include <string>

class SudokuSolver
{
private:
	std::ifstream inputFile;
	std::ofstream outputFile;

	static const int gridSize = 9;

	std::vector<std::vector<int> > grid;

	bool isValidState(std::vector<std::vector<int> >&, const int, const int, const int);
	bool solving(std::vector<std::vector<int> >&);

public:
	SudokuSolver();
	SudokuSolver(std::string);

	void initialization(std::string);
	void solve();
	void output(std::string);

};

#endif // SUDOKUSOLVER_H