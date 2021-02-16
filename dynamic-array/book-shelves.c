/*
    https://www.hackerrank.com/challenges/dynamic-array-in-c/problem
*/

#include <stdio.h>
#include <stdlib.h>

/*
 * This stores the total number of books in each shelf.
 */
int *total_number_of_books;

/*
 * This stores the total number of pages in each book of each shelf.
 * The rows represent the shelves and the columns represent the books.
 */
int **total_number_of_pages;

int main()
{
    int total_number_of_shelves = 5;

    // init memory
    total_number_of_books = (int *)malloc(sizeof(int) * total_number_of_shelves);
    total_number_of_pages = (int **)malloc(sizeof(int *) * total_number_of_shelves);
    for (int i = 0; i < total_number_of_shelves; i++)
    {
        total_number_of_books[i] = 0;
        total_number_of_pages[i] = (int *)malloc(sizeof(int));
    }

    // append a book with y pages at the end of the x shelf.
    int x=1, y=200;
    
    // books on shelves[x] + 1
    total_number_of_books[x]++;
    // relloc the pags array for selves[x]
    total_number_of_pages[x] = realloc(total_number_of_pages[x], total_number_of_books[x] * sizeof(int));
    // set pages to the last book on seleves[x]
    total_number_of_pages[x][total_number_of_books[x] - 1] = y;

    for (int i = 0; i < total_number_of_shelves; i++)
    {
        if (*(total_number_of_pages + i))
        {
            free(*(total_number_of_pages + i));
        }
    }

    if (total_number_of_pages)
    {
        free(total_number_of_pages);
    }

    return 0;
}