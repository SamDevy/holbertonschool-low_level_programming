/* 3-cp.c (snippet: fix mixed declarations inside while) */
while (1)
{
	ssize_t nread;
	ssize_t nwritten;
	ssize_t off;

	nread = read(fd_from, buf, sizeof(buf));
	if (nread == 0)
		break;
	if (nread < 0)
	{
		xclose(fd_from);
		xclose(fd_to);
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	off = 0;
	while (off < nread)
	{
		nwritten = write(fd_to, buf + off, (size_t)(nread - off));
		if (nwritten <= 0)
		{
			xclose(fd_from);
			xclose(fd_to);
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
		off += nwritten;
	}
}
