// ConsoleApplication6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
void findFirstZero(vector<vector <int> >shape, int firstZeroCord[2]);
bool solve(vector<vector<int> >*solM, vector<vector<int> >shape);
vector<vector<int> > rotateVector(vector<vector<int> >input, int n, int m);
bool findMatch(vector<vector<int> >solM, vector<vector<int> > shape, int tempi, int tempj, int i, int j);

/*int* solve(int solM[4][4] , int shape[n][m] )
{
int i, j, q, s;
for (i = 0; i < 4; i++)
{
for (j = 0; j < 4; j++)
{
if (solM[i][j] == 0 && shape[0][0] == 1)
{
if (findMatch(solM, shape, i, j))
{
for (int k = i; k < n; k++)
{
for (int p = j; p < m; p++)
{
solM[k][p] = shape[k - 1][p - 1];
}
}
solve (solM, shape2)
}
}
}
}
rotateMatrix(shape);
solve(solM, shape);
}


bool findMatch(int(*solM)[4] , int* shape, int i, int j)
{
bool garen = true;
if ((4 - i) < shape.size() || (4 - j) < shape[0].size())
{
garen = false;
return garen;
}
for (int k = i; k < shape.size(); k++)
{
for (int p = j; j < shape[0].size(); j++)
{
if (shape[k - i][p - j] == 1 && solM[k][p] == 1)
{
garen = false;
break;
}
}
}
return garen;
}



void rotateMatrix(int mat[][], int N)
{
// Consider all squares one by one
for (int x = 0; x < N / 2; x++)
{
// Consider elements in group of 4 in
// current square
for (int y = x; y < N - x - 1; y++)
{
// store current cell in temp variable
int temp = mat[x][y];

// move values from right to top
mat[x][y] = mat[y][N - 1 - x];

// move values from bottom to right
mat[y][N - 1 - x] = mat[N - 1 - x][N - 1 - y];

// move values from left to bottom
mat[N - 1 - x][N - 1 - y] = mat[N - 1 - y][x];

// assign temp to left
mat[N - 1 - y][x] = temp;
}
}
}
*/






int main()
{
	int dimentions[5][2];
	vector<vector<int> > solM(4, vector<int>(4, 0));	//creating the solution matrix and initilize it to all 0

	int m, n;
	int numOfShapes;
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
	dimentions[0][0] = m;
	dimentions[0][1] = n;
	int value;
	vector<vector<int> > shape1;	//declaring the first shape as a vector of vectors of int
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
	dimentions[1][0] = m;
	dimentions[1][1] = n;
	vector<vector<int> > shape2;
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
	dimentions[2][0] = m;
	dimentions[2][1] = n;
	vector<vector<int> > shape3;
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
	dimentions[3][0] = m;
	dimentions[3][1] = n;
	vector<vector<int> > shape4;
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
		dimentions[4][0] = m;
		dimentions[4][1] = n;
		vector<vector<int> > shape5;
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
	else
	{
		dimentions[4][0] = 0;
		dimentions[4][1] = 0;
	}
	//setting a flag to false then calling solve which returns a boolean value to determine if it has found a solution possible with the first shape and the solution matrix
	bool flag = false;
	vector<vector<int> > *garen = &solM;
	flag = solve(&solM, shape1);
	/////////////////////////////////////////////////////////////
	if (!flag)
	{
	//	shape1 = rotateVector(shape1);
	}
	flag = false;
	flag = solve(&solM, shape2);

	if (!flag)
	{

	}
	flag = false;
	flag = solve(&solM, shape3);
	if (!flag)
	{

	}
	flag = false;
	flag = solve(&solM, shape4);
	if (!flag)
	{

	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			cout << solM[i][j];
		cout << "\n";
	}
	return 0;
}

void findFirstZero(vector<vector <int> >shape, int firstZeroCord[2])
{
	for (int i = 0; i < shape.size(); i++)
	{
		for (int j = 0; j < shape[0].size(); j++)
		{
			if (shape[i][j] == 1)
			{
				firstZeroCord[0] = i;
				firstZeroCord[1] = j;
				return;
			}
		}
	}
	cout << "wrong shape";
}

bool solve(vector<vector<int> >*solM, vector<vector<int> >shape)
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
			else if(shape.size() == 4)
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
				else if((i + shape.size()) <= 4)
				{
					tempi = i + shape.size();
					tempj = shape[0].size();
				}
				else
				{
					break;
				}
			}
			//after partitioning find if the shape can fit in the first partition
			int q, s;
			if (findMatch(*solM, shape, tempi, tempj, i, j))
			{
				//if fit start fitting it and set the flag to true
				q = i;
				
				for (int k = 0; k < shape.size() && q < tempi; k++)
				{
					s = j;
					for (int p = 0 ; p < shape[0].size() && s < tempj; p++)
					{
						if (shape[k][p] >= 1 && (*solM)[q][s] == 0)
						{
							(*solM)[q][s] = shape[k][p];
							flag = true;
						}
						s++;
					}
					q++;
				}
				if (flag)
				{
					return flag;
				}
			}
		}
	}
	return flag;
}

vector<vector<int> > rotateVector(vector<vector<int> >input, int n, int m)
{
	vector<vector<int> > output(n, vector<int>(m, 0));
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
