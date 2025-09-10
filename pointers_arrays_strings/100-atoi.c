/* 100-atoi.c - Way 1 */
/**
 * _atoi - Converts a string to an integer
 * @s: The string to convert
 *
 * Return: The converted integer, or 0 if no numbers found
 */
int _atoi(char *s)
{
	int i = 0, sign = 1, result = 0, started = 0;

	/* Skip non-digit and non-sign characters */
	while (s[i] && (s[i] < '0' || s[i] > '9'))
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] == '+')
			;
		i++;
	}
	/* Build the number */
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
	{
		if (!started)
		{
			started = 1;
			result = s[i] - '0';
		}
		else
		{
			if (result > (2147483647 - (s[i] - '0')) / 10)
				return (sign == 1 ? 2147483647 : -2147483648);
			result = result * 10 + (s[i] - '0');
		}
		i++;
	}
	if (!started)
		return (0);
	return (result * sign);
}
