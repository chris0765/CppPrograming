/* Dynamic memory allocation을 이용한 3D Array  */

#include <iostream>

using namespace std;

 

int*** makeArray3D(int page_size, int row_size, int col_size)

{

    int*** ary;

 

    ary = new int** [page_size];

    for (int i = 0; i < page_size; i++)
    {
        ary[i] = new int* [row_size];
        for(int j = 0; j < row_size; j++)
            ary[i][j] = new int [col_size];
    }

 

    return ary;

}

 

void deleteArray3D(int*** ary, int pages)

{

    for (int i = 0; i < pages; i++)

        delete[] ary[i];

    delete[] ary;

}

 

int main()

{

    int*** ary;

    int pages = 10, rows = 10, cols = 10;



    ary = makeArray3D(pages, rows, cols);

    for (int i = 0; i < pages; i++)

        for (int j = 0; j < rows; j++)

            for (int k = 0; k < cols; k++)
                ary[i][j][k] = i * pages * rows + j * rows + k;

 

    for (int i = 0; i < pages; i++)

    {

        for (int j = 0; j < rows; j++)
        {
            for(int k = 0; k < cols; k++)
                cout << ary[i][j][k] << ' ';
            cout<<endl;
        }

        cout << endl;

    }

 

    deleteArray3D(ary, pages);

    return 0;

}