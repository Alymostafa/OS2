// ConsoleApplication6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;


vector<vector<int> > shape1;	//declaring the first shape as a vector of vectors of int
vector<vector<int> > shape2;	//declaring the first shape as a vector of vectors of int
vector<vector<int> > shape3;	//declaring the first shape as a vector of vectors of int
vector<vector<int> > shape4;	//declaring the first shape as a vector of vectors of int
vector<vector<int> > shape5;	//declaring the first shape as a vector of vectors of int

vector<vector<vector<int>>> solutionMatrcies;

int numOfShapes;
vector<vector<int> > rotateVector(vector<vector<int> >input, int n, int m);
bool findMatch(vector<vector<int> >solM, vector<vector<int> > shape, int tempi, int tempj, int i, int j);
void solve1(vector<vector<int> >solM, vector<vector<int> > shape);
void solve2(vector<vector<int> >solM, vector<vector<int> > shape);
void solve3(vector<vector<int> >solM, vector<vector<int> > shape);
void solve4(vector<vector<int> >solM, vector<vector<int> > shape);
void solve5(vector<vector<int> >solM, vector<vector<int> > shape);
void fit1(vector<vector<int> >solM, vector<vector<int> > shape, int tempi, int tempj, int i, int j);
void fit2(vector<vector<int> >solM, vector<vector<int> > shape, int tempi, int tempj, int i, int j);
void fit3(vector<vector<int> >solM, vector<vector<int> > shape, int tempi, int tempj, int i, int j);
void fit4(vector<vector<int> >solM, vector<vector<int> > shape, int tempi, int tempj, int i, int j);
void fit5(vector<vector<int> >solM, vector<vector<int> > shape, int tempi, int tempj, int i, int j);
vector<vector <int> > flipV(vector<vector<int> >input);
vector<vector <int> > flipH(vector<vector<int> >input);
int determinant(vector<vector<int> > matrix, int n);
void removeOverlapping(vector<vector <int> > solM);

int main()
{
	vector<vector<int> > solM(4, vector<int>(4, 0));	//creating the solution matrix and initilize it to all 0
	int m, n;

	//scanning the number of shapes 
	cout << "enter number of shapes\n";
	cin >> numOfShapes;
	if (numOfShapes < 4 || numOfShapes > 5)	//validation on the number of shapes to be 4 or 5
	{
		cout << "wrong input";
		return 0;
	}
	cout << "enter dimentiions\n";
	cin >> m;	//scanning the first shape's dimentions
	cin >> n;
	int value;
	cout << "enter values\n";
	for (int i = 0; i < m; i++)
	{
		vector<int> row;
		for (int j = 0; j < n; j++)// scanning the values
		{
			cin >> value;
			row.push_back(value); // pushing in the vector rows
		}
		shape1.push_back(row);	// pushing the complete row
	}
	/////////////////// same applies for the rest of dimentions
	cout << "enter dimentiions\n";
	cin >> m;
	cin >> n;
	cout << "enter values\n";
	for (int i = 0; i < m; i++)
	{
		vector<int> row;
		for (int j = 0; j < n; j++)
		{
			cin >> value;
			if (value == 1)
			{
				value = 2;
			}
			row.push_back(value);
		}
		shape2.push_back(row);
	}
	cout << "enter dimentiions\n";
	cin >> m;
	cin >> n;
	cout << "enter values\n";
	for (int i = 0; i < m; i++)
	{
		vector<int> row;
		for (int j = 0; j < n; j++)
		{
			cin >> value;
			if (value == 1)
			{
				value = 3;
			}
			row.push_back(value);
		}
		shape3.push_back(row);
	}
	cout << "enter dimentiions\n";
	cin >> m;
	cin >> n;
	cout << "enter values\n";
	for (int i = 0; i < m; i++)
	{
		vector<int> row;
		for (int j = 0; j < n; j++)
		{
			cin >> value;
			if (value == 1)
			{
				value = 4;
			}
			row.push_back(value);
		}
		shape4.push_back(row);
	}
	if (numOfShapes == 5)
	{
		cout << "enter dimentiions\n";
		cin >> m;
		cin >> n;
		cout << "enter values\n";
		for (int i = 0; i < m; i++)
		{
			vector<int> row;
			for (int j = 0; j < n; j++)
			{
				cin >> value;
				if (value == 1)
				{
					value = 5;
				}
				row.push_back(value);
			}
			shape5.push_back(row);
		}
	}

	//shape without rotation or flipping
	solve1(solM, shape1);

	//shape without rotation with flipping H
	vector<vector<int> > fliph = flipH(shape1);
	solve1(solM, fliph);

	//shape without rotation with flipping V
	vector<vector<int> > flipv = flipV(shape1);
	//solve1(solM, flipv);

	//shape without rotation with flipping V and flipping H
	vector<vector<int> > flipvh = flipH(flipv);
	//solve1(solM, flipvh);
	
	/////////////////////////////////////////

	//shape rotated 90d without flipping
	vector<vector<int> > rotated = rotateVector(shape1, shape1.size(), shape1[0].size());
	solve1(solM, rotated);

	//shape rotated 90d with flipping H
	vector<vector<int> > rfliph = flipH(rotated);
	solve1(solM, rfliph);

	//shape rotated 90d with flipping V
	vector<vector<int> > rflipv = flipV(rotated);
	//solve1(solM, rflipv);

	//shape rotated 90d with flipping V and flipping H
	vector<vector<int> > rflipvh = flipH(rflipv);
	//solve1(solM, rflipvh);

	//////////////////////////////////////////

	/*//shape rotated 180d without flipping
	vector<vector<int> > rotated1 = rotateVector(rotated, rotated.size(), rotated[0].size());
	solve1(solM, rotated1);

	//shape rotated 180d with flipping H
	vector<vector<int> > r180fliph = flipH(rotated1);
	//solve1(solM, r180fliph);

	//shape rotated 180d with flipping V
	vector<vector<int> >r180flipv = flipV(rotated1);
	//solve1(solM, r180flipv);

	//shape rotated 180d with flipping V and flipping H
	vector<vector<int> >r180flipvh = flipH(r180flipv);
	//solve1(solM, r180flipvh);
	
	///////////////////////////////////////////////

	//shape rotated 270d without flipping
	vector<vector<int> >rotated2 = rotateVector(rotated, rotated.size(), rotated[0].size());
	solve1(solM, rotated2);

	//shape rotated 270d with flipping H
	vector<vector<int> > r270fliph = flipH(rotated2);
	//solve1(solM, r270fliph);

	//shape rotated 270 with flipping V
	vector<vector<int> >r270flipv = flipV(rotated2);
	//solve1(solM, r270flipv);

	//shape rotated 270d with flipping V and flipping H
	vector<vector<int> > r270flipvh = flipH(r270flipv);
	//solve1(solM, r270flipvh);
	*/
	int i, j, k;
	for (i = 0; i < solutionMatrcies.size(); i++)
	{
		for (j = 0; j < 4; j++)
		{
			for (k = 0; k < 4; k++)
			{
				cout << solutionMatrcies[i][j][k];
				cout << " ";
			}
			cout << "\n";
		}
	}

	return 0;
}

vector<vector <int> > flipV(vector<vector<int> >input)
{
	return input;
}

vector<vector <int> > flipH(vector<vector<int> >input)
{
	int q, j;
	if (input.size() % 2 == 0)
	{
		vector<vector <int> > garen;
		for (int i = 0; i < (input.size() / 2); i++)
		{
			garen.push_back(input[i]);
		}
		for (q = (input.size()) / 2, j = (input.size() / 2) - 1; q < input.size() && j >= 0; q++)
		{
			input[j] = input[q];
			input[q] = garen[j];
			j--;
		}
		return input;
	}
	else
	{
		int middle = (input.size()) / 2;
		vector<vector <int> > garen;
		for (int i = 0; i < middle; i++)
		{
			garen.push_back(input[i]);
		}
		for (q = middle + 1, j = middle - 1; q < input.size() && j >= 0; q++)
		{
			input[j] = input[q];
			j--;
		}
		for (q = 0, j = (input.size()) - 1; q < garen.size() && j > middle; q++)
		{
			input[j] = garen[q];
			j--;
		}
		return input;
	}
}

vector<vector<int> > rotateVector(vector<vector<int> >input, int n, int m)
{
	vector<vector<int> > output(m, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			output[j][n - 1 - i] = input[i][j];
	return output;
}

bool findMatch(vector<vector<int> >subMatrix, vector<vector<int> > shape, int tempi, int tempj, int i, int j)
{
	bool garen = true;
	int q, s;
	q = i;
 	for (int k = 0; k < shape.size() && q < tempi; k++)
	{
		s = j;
		for (int p = 0; p < shape[0].size() && s < tempj; p++)
		{
			//start checking if thhere is a value in the solution submatrix equal to 1 and a value in the shape equal to 1 then it won't fit in this
			//partition and return false
			if (shape[k][p] >= 1 && subMatrix[q][s] == 1)
			{
				garen = false;
				break;
			}
			s++;
		}
		q++;
	}
	return garen;
}

void solve1(vector<vector<int> >solM, vector<vector<int> > shape) 
{
	int i, j, tempi, tempj;
	bool flag = false;	//declaring a boolean value to return
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			//partitioning with the 4 possible possiblities
			if (shape.size() == 4 && shape[0].size() == 4)
			{
				tempi = shape.size() - 1;
				tempj = shape[0].size() - 1;
			}
			else if (shape.size() == 4)
			{
				if ((j + shape[0].size()) <= 4)
				{
					tempi = shape.size();
					tempj = j + shape[i].size();
				}
				else
				{
					break;
				}
			}
			else if (shape[0].size() == 4)
			{
				if ((i + shape.size()) <= 4)
				{
					tempi = i + shape.size();
					tempj = shape[0].size();
				}
				else
				{
					break;
				}
			}
			else
			{
				if ((i + shape.size()) <= 4 && (j + shape[0].size()) <= 4)
				{
					tempi = i + shape.size();
					tempj = j + shape[0].size();
				}
				else if ((j + shape[0].size()) <= 4)
				{
					tempi = shape.size();
					tempj = j + shape[0].size();
				}
				else if ((i + shape.size()) <= 4)
				{
					tempi = i + shape.size();
					tempj = shape[0].size();
				}
				else
				{
					break;
				}
			}
			if (findMatch(solM, shape, tempi, tempj, i, j))
			{
				fit1(solM, shape, tempi, tempj, i, j);
			}
		}
	}
}

void solve2(vector<vector<int> >solM, vector<vector<int> > shape)
{
	int i, j, tempi, tempj;
	bool flag = false;	//declaring a boolean value to return
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			//partitioning with the 4 possible possiblities
			if (shape.size() == 4 && shape[0].size() == 4)
			{
				tempi = shape.size() - 1;
				tempj = shape[0].size() - 1;
			}
			else if (shape.size() == 4)
			{
				if ((j + shape[0].size()) <= 4)
				{
					tempi = shape.size();
					tempj = j + shape[i].size();
				}
				else
				{
					break;
				}
			}
			else if (shape[0].size() == 4)
			{
				if ((i + shape.size()) <= 4)
				{
					tempi = i + shape.size();
					tempj = shape[0].size();
				}
				else
				{
					break;
				}
			}
			else
			{
				if ((i + shape.size()) <= 4 && (j + shape[0].size()) <= 4)
				{
					tempi = i + shape.size();
					tempj = j + shape[0].size();
				}
				else if ((j + shape[0].size()) <= 4)
				{
					tempi = shape.size();
					tempj = j + shape[0].size();
				}
				else if ((i + shape.size()) <= 4)
				{
					tempi = i + shape.size();
					tempj = shape[0].size();
				}
				else
				{
					break;
				}
			}
			if (findMatch(solM, shape, tempi, tempj, i, j))
			{
				fit2(solM, shape, tempi, tempj, i, j);
			}
		}
	}
}
void solve3(vector<vector<int> >solM, vector<vector<int> > shape)
{
 
	int i, j, tempi, tempj;
	bool flag = false;	//declaring a boolean value to return
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			//partitioning with the 4 possible possiblities
			if (shape.size() == 4 && shape[0].size() == 4)
			{
				tempi = shape.size() - 1;
				tempj = shape[0].size() - 1;
			}
			else if (shape.size() == 4)
			{
				if ((j + shape[0].size()) <= 4)
				{
					tempi = shape.size();
					tempj = j + shape[i].size();
				}
				else
				{
					break;
				}
			}
			else if (shape[0].size() == 4)
			{
				if ((i + shape.size()) <= 4)
				{
					tempi = i + shape.size();
					tempj = shape[0].size();
				}
				else
				{
					break;
				}
			}
			else
			{
				if ((i + shape.size()) <= 4 && (j + shape[0].size()) <= 4)
				{
					tempi = i + shape.size();
					tempj = j + shape[0].size();
				}
				else if ((j + shape[0].size()) <= 4)
				{
					tempi = shape.size();
					tempj = j + shape[0].size();
				}
				else if ((i + shape.size()) <= 4)
				{
					tempi = i + shape.size();
					tempj = shape[0].size();
				}
				else
				{
					break;
				}
			}
			if (findMatch(solM, shape, tempi, tempj, i, j))
			{
				fit3(solM, shape, tempi, tempj, i, j);
			}
		}
	}
}
void solve4(vector<vector<int> >solM, vector<vector<int> > shape)
{
	int i, j, tempi, tempj;
	bool flag = false;	//declaring a boolean value to return
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			//partitioning with the 4 possible possiblities
			if (shape.size() == 4 && shape[0].size() == 4)
			{
				tempi = shape.size() - 1;
				tempj = shape[0].size() - 1;
			}
			else if (shape.size() == 4)
			{
				if ((j + shape[0].size()) <= 4)
				{
					tempi = shape.size();
					tempj = j + shape[i].size();
				}
				else
				{
					break;
				}
			}
			else if (shape[0].size() == 4)
			{
				if ((i + shape.size()) <= 4)
				{
					tempi = i + shape.size();
					tempj = shape[0].size();
				}
				else
				{
					break;
				}
			}
			else
			{
				if ((i + shape.size()) <= 4 && (j + shape[0].size()) <= 4)
				{
					tempi = i + shape.size();
					tempj = j + shape[0].size();
				}
				else if ((j + shape[0].size()) <= 4)
				{
					tempi = shape.size();
					tempj = j + shape[0].size();
				}
				else if ((i + shape.size()) <= 4)
				{
					tempi = i + shape.size();
					tempj = shape[0].size();
				}
				else
				{
					break;
				}
			}
			if (findMatch(solM, shape, tempi, tempj, i, j))
			{
				fit4(solM, shape, tempi, tempj, i, j);
			}
		}
	}
}
void solve5(vector<vector<int> >solM, vector<vector<int> > shape)
{
 
	int i, j, tempi, tempj;
	bool flag = false;	//declaring a boolean value to return
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			//partitioning with the 4 possible possiblities
			if (shape.size() == 4 && shape[0].size() == 4)
			{
				tempi = shape.size() - 1;
				tempj = shape[0].size() - 1;
			}
			else if (shape.size() == 4)
			{
				if ((j + shape[0].size()) <= 4)
				{
					tempi = shape.size();
					tempj = j + shape[i].size();
				}
				else
				{
					break;
				}
			}
			else if (shape[0].size() == 4)
			{
				if ((i + shape.size()) <= 4)
				{
					tempi = i + shape.size();
					tempj = shape[0].size();
				}
				else
				{
					break;
				}
			}
			else
			{
				if ((i + shape.size()) <= 4 && (j + shape[0].size()) <= 4)
				{
					tempi = i + shape.size();
					tempj = j + shape[0].size();
				}
				else if ((j + shape[0].size()) <= 4)
				{
					tempi = shape.size();
					tempj = j + shape[0].size();
				}
				else if ((i + shape.size()) <= 4)
				{
					tempi = i + shape.size();
					tempj = shape[0].size();
				}
				else
				{
					break;
				}
			}
			if (findMatch(solM, shape, tempi, tempj, i, j))
			{
				fit5(solM, shape, tempi, tempj, i, j);
			}
		}
	}
}

void fit1(vector<vector<int> >solM, vector<vector<int> > shape, int tempi, int tempj, int i, int j)
{
 
	int q, s;
	q = i;
	for (int k = 0; k < shape.size() && q < tempi; k++)
	{
		s = j;
		for (int p = 0; p < shape[0].size() && s < tempj; p++)
		{
			if (shape[k][p] >= 1 && solM[q][s] == 0)
			{
				solM[q][s] = shape[k][p];
			}
			s++;
		}
		q++;
	}
	//shape without rotation or flipping
	solve2(solM, shape2);

	//shape without rotation with flipping H
	vector<vector<int> > fliph = flipH(shape2);
	solve2(solM, fliph);

	//shape without rotation with flipping V
	vector<vector<int> > flipv = flipV(shape2);
	//solve2(solM, flipv);

	//shape without rotation with flipping V and flipping H
	vector<vector<int> > flipvh = flipH(flipv);
	//solve2(solM, flipvh);

	/////////////////////////////////////////

	//shape rotated 90d without flipping
	vector<vector<int> > rotated = rotateVector(shape2, shape2.size(), shape2[0].size());
	solve2(solM, rotated);

	//shape rotated 90d with flipping H
	vector<vector<int> > rfliph = flipH(rotated);
	solve2(solM, rfliph);

	//shape rotated 90d with flipping V
	vector<vector<int> > rflipv = flipV(rotated);
	//solve2(solM, rflipv);

	//shape rotated 90d with flipping V and flipping H
	vector<vector<int> > rflipvh = flipH(rflipv);
	//solve2(solM, rflipvh);

	//////////////////////////////////////////

	/*//shape rotated 180d without flipping
	vector<vector<int> > rotated1 = rotateVector(rotated, rotated.size(), rotated[0].size());
	solve2(solM, rotated1);

	//shape rotated 180d with flipping H
	vector<vector<int> > r180fliph = flipH(rotated1);
	//solve2(solM, r180fliph);

	//shape rotated 180d with flipping V
	vector<vector<int> >r180flipv = flipV(rotated1);
	//solve2(solM, r180flipv);

	//shape rotated 180d with flipping V and flipping H
	vector<vector<int> >r180flipvh = flipH(r180flipv);
	//solve2(solM, r180flipvh);

	///////////////////////////////////////////////

	//shape rotated 270d without flipping
	vector<vector<int> >rotated2 = rotateVector(rotated, rotated.size(), rotated[0].size());
	solve2(solM, rotated2);

	//shape rotated 270d with flipping H
	vector<vector<int> > r270fliph = flipH(rotated2);
	//solve2(solM, r270fliph);

	//shape rotated 270 with flipping V
	vector<vector<int> >r270flipv = flipV(rotated2);
	//solve2(solM, r270flipv);

	//shape rotated 270d with flipping V and flipping H
	vector<vector<int> > r270flipvh = flipH(r270flipv);
	//solve2(solM, r270flipvh);
	*/
}

void fit2(vector<vector<int> >solM, vector<vector<int> > shape, int tempi, int tempj, int i, int j)
{

	int q, s;
	q = i;
	for (int k = 0; k < shape.size() && q < tempi; k++)
	{
		s = j;
		for (int p = 0; p < shape[0].size() && s < tempj; p++)
		{
			if (shape[k][p] >= 1 && solM[q][s] == 0)
			{
				solM[q][s] = shape[k][p];
			}
			s++;
		}
		q++;
	}
	//shape without rotation or flipping
	solve3(solM, shape3);

	//shape without rotation with flipping H
	vector<vector<int> > fliph = flipH(shape3);
	solve3(solM, fliph);

	//shape without rotation with flipping V
	vector<vector<int> > flipv = flipV(shape3);
	//solve3(solM, flipv);

	//shape without rotation with flipping V and flipping H
	vector<vector<int> > flipvh = flipH(flipv);
	//solve3(solM, flipvh);

	/////////////////////////////////////////

	//shape rotated 90d without flipping
	vector<vector<int> > rotated = rotateVector(shape3, shape3.size(), shape3[0].size());
	solve3(solM, rotated);

	//shape rotated 90d with flipping H
	vector<vector<int> > rfliph = flipH(rotated);
	solve3(solM, rfliph);

	//shape rotated 90d with flipping V
	vector<vector<int> > rflipv = flipV(rotated);
	//solve3(solM, rflipv);

	//shape rotated 90d with flipping V and flipping H
	vector<vector<int> > rflipvh = flipH(rflipv);
	//solve3(solM, rflipvh);

	//////////////////////////////////////////

	/*/shape rotated 180d without flipping
	vector<vector<int> > rotated1 = rotateVector(rotated, rotated.size(), rotated[0].size());
	solve3(solM, rotated1);

	//shape rotated 180d with flipping H
	vector<vector<int> > r180fliph = flipH(rotated1);
	//solve3(solM, r180fliph);

	//shape rotated 180d with flipping V
	vector<vector<int> >r180flipv = flipV(rotated1);
	//solve3(solM, r180flipv);

	//shape rotated 180d with flipping V and flipping H
	vector<vector<int> >r180flipvh = flipH(r180flipv);
	//solve3(solM, r180flipvh);

	///////////////////////////////////////////////

	//shape rotated 270d without flipping
	vector<vector<int> >rotated2 = rotateVector(rotated, rotated.size(), rotated[0].size());
	solve3(solM, rotated2);

	//shape rotated 270d with flipping H
	vector<vector<int> > r270fliph = flipH(rotated2);
	//solve3(solM, r270fliph);

	//shape rotated 270 with flipping V
	vector<vector<int> >r270flipv = flipV(rotated2);
	//solve3(solM, r270flipv);

	//shape rotated 270d with flipping V and flipping H
	vector<vector<int> > r270flipvh = flipH(r270flipv);
	//solve3(solM, r270flipvh);*/
}

void fit3(vector<vector<int> >solM, vector<vector<int> > shape, int tempi, int tempj, int i, int j)
{
 

	int q, s;
	q = i;
	for (int k = 0; k < shape.size() && q < tempi; k++)
	{
		s = j;
		for (int p = 0; p < shape[0].size() && s < tempj; p++)
		{
			if (shape[k][p] >= 1 && solM[q][s] == 0)
			{
				solM[q][s] = shape[k][p];
			}
			s++;
		}
		q++;
	}
	//shape without rotation or flipping
	solve4(solM, shape4);

	//shape without rotation with flipping H
	vector<vector<int> > fliph = flipH(shape4);
	solve4(solM, fliph);

	//shape without rotation with flipping V
	vector<vector<int> > flipv = flipV(shape4);
	//solve4(solM, flipv);

	//shape without rotation with flipping V and flipping H
	vector<vector<int> > flipvh = flipH(flipv);
	//solve4(solM, flipvh);

	/////////////////////////////////////////

	//shape rotated 90d without flipping
	vector<vector<int> > rotated = rotateVector(shape4, shape4.size(), shape4[0].size());
	solve4(solM, rotated);

	//shape rotated 90d with flipping H
	vector<vector<int> > rfliph = flipH(rotated);
	solve4(solM, rfliph);

	//shape rotated 90d with flipping V
	vector<vector<int> > rflipv = flipV(rotated);
	//solve4(solM, rflipv);

	//shape rotated 90d with flipping V and flipping H
	vector<vector<int> > rflipvh = flipH(rflipv);
	//solve4(solM, rflipvh);

	/*/////////////////////////////////////////

	//shape rotated 180d without flipping
	vector<vector<int> > rotated1 = rotateVector(rotated, rotated.size(), rotated[0].size());
	solve4(solM, rotated1);

	//shape rotated 180d with flipping H
	vector<vector<int> > r180fliph = flipH(rotated1);
	//solve4(solM, r180fliph);

	//shape rotated 180d with flipping V
	vector<vector<int> >r180flipv = flipV(rotated1);
	//solve4(solM, r180flipv);

	//shape rotated 180d with flipping V and flipping H
	vector<vector<int> >r180flipvh = flipH(r180flipv);
	//solve4(solM, r180flipvh);

	///////////////////////////////////////////////

	//shape rotated 270d without flipping
	vector<vector<int> >rotated2 = rotateVector(rotated, rotated.size(), rotated[0].size());
	solve4(solM, rotated2);

	//shape rotated 270d with flipping H
	vector<vector<int> > r270fliph = flipH(rotated2);
	//solve4(solM, r270fliph);

	//shape rotated 270 with flipping V
	vector<vector<int> >r270flipv = flipV(rotated2);
	//solve4(solM, r270flipv);

	//shape rotated 270d with flipping V and flipping H
	vector<vector<int> > r270flipvh = flipH(r270flipv);
	//solve4(solM, r270flipvh);*/
}

void fit4(vector<vector<int> >solM, vector<vector<int> > shape, int tempi, int tempj, int i, int j)
{
 

	int q, s;
	q = i;
	for (int k = 0; k < shape.size() && q < tempi; k++)
	{
		s = j;
		for (int p = 0; p < shape[0].size() && s < tempj; p++)
		{
			if (shape[k][p] >= 1 && solM[q][s] == 0)
			{
				solM[q][s] = shape[k][p];
			}
			s++;
		}
		q++;
	}

	if (numOfShapes == 4)
	{
		bool flag = true;
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (solM[i][j] == 0)
				{
					flag = false;
					break;
				}
			}
		}
		if (flag)
		{
			removeOverlapping(solM);
		}
	}
	else if(numOfShapes == 5)
	{
		//shape without rotation or flipping
		solve5(solM, shape5);

		//shape without rotation with flipping H
		vector<vector<int> > fliph = flipH(shape5);
		solve5(solM, fliph);

		//shape without rotation with flipping V
		vector<vector<int> > flipv = flipV(shape5);
		//solve5(solM, flipv);

		//shape without rotation with flipping V and flipping H
		vector<vector<int> > flipvh = flipH(flipv);
		//solve5(solM, flipvh);

		/////////////////////////////////////////

		//shape rotated 90d without flipping
		vector<vector<int> > rotated = rotateVector(shape5, shape5.size(), shape5[0].size());
		solve5(solM, rotated);

		//shape rotated 90d with flipping H
		vector<vector<int> > rfliph = flipH(rotated);
		solve5(solM, rfliph);

		//shape rotated 90d with flipping V
		vector<vector<int> > rflipv = flipV(rotated);
		//solve5(solM, rflipv);

		//shape rotated 90d with flipping V and flipping H
		vector<vector<int> > rflipvh = flipH(rflipv);
		//solve5(solM, rflipvh);

		/*/////////////////////////////////////////

		//shape rotated 180d without flipping
		vector<vector<int> > rotated1 = rotateVector(rotated, rotated.size(), rotated[0].size());
		solve5(solM, rotated1);

		//shape rotated 180d with flipping H
		vector<vector<int> > r180fliph = flipH(rotated1);
		solve5(solM, r180fliph);

		//shape rotated 180d with flipping V
		vector<vector<int> >r180flipv = flipV(rotated1);
		solve5(solM, r180flipv);

		//shape rotated 180d with flipping V and flipping H
		vector<vector<int> >r180flipvh = flipH(r180flipv);
		solve5(solM, r180flipvh);

		///////////////////////////////////////////////

		//shape rotated 270d without flipping
		vector<vector<int> >rotated2 = rotateVector(rotated, rotated.size(), rotated[0].size());
		solve5(solM, rotated2);

		//shape rotated 270d with flipping H
		vector<vector<int> > r270fliph = flipH(rotated2);
		solve5(solM, r270fliph);

		//shape rotated 270 with flipping V
		vector<vector<int> >r270flipv = flipV(rotated2);
		solve5(solM, r270flipv);

		//shape rotated 270d with flipping V and flipping H
		vector<vector<int> > r270flipvh = flipH(r270flipv);
		solve5(solM, r270flipvh);*/
	}
}

void fit5(vector<vector<int> >solM, vector<vector<int> > shape, int tempi, int tempj, int i, int j)
{
 

	int q, s;
	q = i;
	for (int k = 0; k < shape.size() && q < tempi; k++)
	{
		s = j;
		for (int p = 0; p < shape[0].size() && s < tempj; p++)
		{
			if (shape[k][p] >= 1 && solM[q][s] == 0)
			{
				solM[q][s] = shape[k][p];
			}
			s++;
		}
		q++;
	}

	bool flag = true;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (solM[i][j] == 0)
			{
				flag = false;
				break;
			}
		}
	}
	if (flag)
	{
		removeOverlapping(solM);
	}
}

int determinant(vector<vector<int> > matrix, int n) 
{
 

	int det = 0;
	vector<vector <int>> submatrix(4, vector<int>(4, 0));
	if (n == 2)
		return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
	else {
		for (int x = 0; x < n; x++) {
			int subi = 0;
			for (int i = 1; i < n; i++) {
				int subj = 0;
				for (int j = 0; j < n; j++) {
					if (j == x)
						continue;
					submatrix[subi][subj] = matrix[i][j];
					subj++;
				}
				subi++;
			}
			det = det + (pow(-1, x) * matrix[0][x] * determinant(submatrix, n - 1));
		}
	}
	return det;
}

void removeOverlapping(vector<vector <int> > solM)
{
 
	static int flag = 0;
	if (flag == 0)
	{
		flag++;
		solutionMatrcies.push_back(solM);
		return;
	}
	else
	{
		if (std::find(solutionMatrcies.begin(), solutionMatrcies.end(), solM) != solutionMatrcies.end())
		{
			return;
		}
		else
		{
			solutionMatrcies.push_back(solM);
		}
	}
}