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
	int digit;
	int INT_MAX = 2147483647;
	int INT_MIN = -2147483648;

	/* Process all characters in the string */
	while (s[i])
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] == '+')
			;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			found_digit = 1;
			digit = s[i] - '0';

			/* Check for overflow before multiplying and adding */
			if (sign == 1 && (result > (INT_MAX - digit) / 10))
				return (INT_MAX);
			if (sign == -1 && (result > (-(INT_MIN + digit)) / 10))
				return (INT_MIN);

			result = result * 10 + digit;
		}
		else if (found_digit)
			break;
		i++;
	}
	if (!found_digit)
		return (0);
	return (result * sign);
}
