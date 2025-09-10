/* 100-atoi.c */
/**
 * convert_digits - Converts digit characters to integer
 * @s: The string to convert
 * @i: The starting index
 * @sign: The sign of the number
 *
 * Return: The converted integer
 */
int convert_digits(char *s, int i, int sign)
{
	int result = 0;
	int started = 0;

	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			if (!started)
			{
				started = 1;
				result = -(s[i] - '0');
			}
			else
			{
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
	if (sign == 1)
	{
		if (result == -2147483648)
			return (2147483647);
		return (-result);
	}
	return (result);
}

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

	while (s[i])
	{
		if (s[i] == '-' && (s[i + 1] < '0' || s[i + 1] > '9'))
			sign *= -1;
		else if (s[i] == '+' && (s[i + 1] < '0' || s[i + 1] > '9'))
			;
		else if (s[i] >= '0' && s[i] <= '9')
			break;
		i++;
	}
	return (convert_digits(s, i, sign));
}
