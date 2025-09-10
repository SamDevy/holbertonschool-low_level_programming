/* 9. String copy implementation */
/**
 * _strcpy - Copies the string pointed to by src to dest
 * @dest: The destination buffer
 * @src: The source string
 *
 * Return: Pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	/* Copy each character including the null terminator */
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
