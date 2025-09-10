/* 100-atoi.c - Way 1 */
/**
 * _atoi - Converts a string to an integer
 * @s: The string to convert
 *
 * Return: The converted integer, or 0 if no numbers found
 */
int _atoi(char *s)
{
	int i = 0, sign = 1, result = 0, found = 0, minus_count = 0;

	/* Count minus signs before the first digit */
	while (s[i] && (s[i] < '0' || s[i] > '9'))
	{
		if (s[i] == '-')
			minus_count++;
		i++;
	}
	if (minus_count % 2)
		sign = -1;
	/* Build the number */
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
	{
		found = 1;
		if (result > (2147483647 - (s[i] - '0')) / 10)
			return (sign == 1 ? 2147483647 : -2147483648);
		result = result * 10 + (s[i] - '0');
		i++;
	}
	if (!found)
		return (0);
	return (result * sign);
}
