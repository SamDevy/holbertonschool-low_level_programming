/* 100-atoi.c - Method 1 */
/**
 * _atoi - Converts a string to an integer
 * @s: The string to convert
 *
 * Return: The converted integer, or 0 if no numbers found
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int result = 0;
	int found_digit = 0;

	/* Process all characters in the string */
	while (s[i])
	{
		/* Update sign for each '-' before digits */
		if (s[i] == '-')
			sign *= -1;
		/* Ignore '+' signs */
		else if (s[i] == '+')
			;
		/* If digit found, build the number */
		else if (s[i] >= '0' && s[i] <= '9')
		{
			found_digit = 1;
			result = result * 10 + (s[i] - '0');
		}
		/* If digits have started and current char is not a digit, break */
		else if (found_digit)
			break;
		i++;
	}
	/* If no digits found, return 0 */
	if (!found_digit)
		return (0);
	return (result * sign);
}
