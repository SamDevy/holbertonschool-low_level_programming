/* 4-free_grid.c */
/**
 * free_grid - Frees a 2D grid previously allocated by alloc_grid
 * @grid: pointer to array of int* rows
 * @height: number of rows
 *
 * Return: Nothing.
 *
 * Description:
 * - Safely frees each row, then frees the grid itself.
 * - Does nothing if grid is NULL or height <= 0.
 */
#include <stdlib.h>

void free_grid(int **grid, int height)
{
	int i;

	if (grid == NULL || height <= 0)
		return;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}

	free(grid);
}
