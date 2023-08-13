#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - to Read text file print to STDOUT.
 * @filename: ///the text file being read
 * @letters: number of letters to be read
 * Return: w- actual number of bytes read and printed
 *        0 when function fails otherwise filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t p;
	ssize_t l;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	l = read(fd, buf, letters);
	p = write(STDOUT_FILENO, buf, l);

	free(buf);
	close(fd);
	return (p);
}
