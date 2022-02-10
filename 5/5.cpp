#include <iostream>
#include <string.h>
#include <cmath> 

using namespace std;

void show_matrix(char ** a, int size)
{
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout.width(3);
            cout << a[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

char** sort_first_column(char ** matrix, int size) 
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (matrix[i][0] > matrix[j][0])
            {
                for (int m = 0; m < size; m++)
                {
                    char c = matrix[i][m];
                    matrix[i][m] = matrix[j][m];
                    matrix[j][m] = c;
                }
            }
        }
    }
    return matrix;
}


bool are_equal_matrixes(char ** old_matrix, char ** new_matrix, int matrix_size)
{
    for (int i = 0; i < matrix_size; i++)
    {
        for (int j = 0; j < matrix_size; j++)
        {
            for (int m = 0; m < matrix_size; m++)
            {
                if (old_matrix[i][0] != new_matrix[j][0]) 
                {
                    return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    string s;
    int n, k = 0;  
    cin >> n;

    int matrix_size = sqrt(n);
    char** old_matrix = new char* [matrix_size];

    cin >> s;
    for (int i = 0; i < matrix_size; i++)
        old_matrix[i] = new char[matrix_size];

    for (int i = 0; i < matrix_size; i++)
    {
        for (int j = 0; j < matrix_size; j++)
        {
            old_matrix[i][j] = s.at(k);
            k++;
        }
    }

    cout << endl << "Old Matrix" << endl;
    show_matrix(old_matrix, matrix_size);

    char** new_matrix = sort_first_column(old_matrix, matrix_size);

    cout << "New Matrix" << endl;
    show_matrix(new_matrix, matrix_size);

    if (!are_equal_matrixes(old_matrix, new_matrix, matrix_size))
    {
        cout << "Can" << endl;
    }
    else 
    {
        cout << "Can't" << endl;
    }

    delete new_matrix, old_matrix;
    return 0;
}