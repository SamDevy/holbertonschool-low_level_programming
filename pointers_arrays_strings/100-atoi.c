/* 100-atoi.c - Method 2 */
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
	unsigned int result = 0;
	int found_digit = 0;
	int INT_MAX = 2147483647;
	int INT_MIN = -2147483648;

	/* Handle sign before first digit */
	while (s[i] && (s[i] < '0' || s[i] > '9'))
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] == '+')
			;
		i++;
	}
	/* Build the number and check for overflow */
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
	{
		found_digit = 1;
		if (result > (INT_MAX - (s[i] - '0')) / 10)
		{
			if (sign == 1)
				return (INT_MAX);
			else
				return (INT_MIN);
		}
		result = result * 10 + (s[i] - '0');
		i++;
	}
	if (!found_digit)
		return (0);
	if (sign == 1)
		return ((int)result);
	else
		return ((int)(-result));
}
