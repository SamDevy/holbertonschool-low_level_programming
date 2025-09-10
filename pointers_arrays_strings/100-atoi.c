/* 100-atoi.c */
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
	int started = 0;

	/* Process all characters in the string */
	while (s[i])
	{
		/* Update sign for each '-' before digits */
		if (s[i] == '-' && !started)
			sign *= -1;
		else if (s[i] == '+' && !started)
			;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			/* Start building the number as negative to avoid overflow */
			if (!started)
			{
				started = 1;
				result = -(s[i] - '0');
			}
			else
			{
				/* Check for overflow before multiplying and subtracting */
				if (result < (-2147483647 / 10))
					return (sign == 1 ? 2147483647 : -2147483648);
				result = result * 10 - (s[i] - '0');
			}
		}
		else if (started)
			break;
		i++;
	}
	if (!started)
		return (0);
	/* If sign is positive, flip result to positive */
	if (sign == 1)
	{
		/* Handle INT_MIN edge case */
		if (result == -2147483648)
			return (2147483647);
		return (-result);
	}
	return (result);
}
