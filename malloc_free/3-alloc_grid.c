/* 3-alloc_grid.c */
/**
 * alloc_grid - Allocates a 2D grid of integers initialized to 0
 * @width: number of columns per row
 * @height: number of rows
 *
 * Return: Pointer to int** grid, or NULL on failure or invalid size
 *
 * Description:
 * - Allocates an array of int* of size `height`.
 * - For each row, allocates `width` ints.
 * - Initializes all elements to 0.
 * - On any failure, frees everything and returns NULL.
 */
#include <stdlib.h>

int **alloc_grid(int width, int height)
{
	int **grid;
	int i, j;

	if (width <= 0 || height <= 0)
		return (NULL);

	grid = (int **)malloc(sizeof(int *) * height);
	if (grid == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		grid[i] = (int *)malloc(sizeof(int) * width);
		if (grid[i] == NULL)
		{
			/* free any previously allocated rows, then the grid pointer */
			while (i > 0)
			{
				i--;
				free(grid[i]);
			}
			free(grid);
			return (NULL);
		}
		/* initialize row to zeros */
		for (j = 0; j < width; j++)
			grid[i][j] = 0;
	}

	return (grid);
}
