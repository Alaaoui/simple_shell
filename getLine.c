#include "shell.h"

/**
 * input_buf - buffers chained value
 * @info: parameter struct value
 * @buf: buffer address
 * @len: len var
 *
 * Return: bytes
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t v = 0;
	size_t len_q = 0;

	if (!*len)
	{
		/*bfree((void **)info->cmd_buf);*/
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		v = getline(buf, &len_q, stdin);
#else
		v = _getline(info, buf, &len_q);
#endif
		if (v > 0)
		{
			if ((*buf)[v - 1] == '\n')
			{
				(*buf)[v - 1] = '\0';
				v--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);

			{
				*len = v;
				info->cmd_buf = buf;
			}
		}
	}
	return (v);
}

/**
 * get_input - gets a line
 * @info: parameter value
 *
 * Return: bytes
 */
ssize_t get_input(info_t *info)
{
	static char *buf;
	static size_t a, b, len;
	ssize_t r = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	r = input_buf(info, &buf, &len);
	if (r == -1)
		return (-1);
	if (len)
	{
		b = a;
		p = buf + a;

		check_chain(info, buf, &b, a, len);
		while (b < len)
		{
			if (is_chain(info, buf, &b))
				break;
			b++;
		}

		a = b + 1;
		if (a >= len)
		{
			a = len = 0;
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p;
		return (_strlen(p)); /* return length of current command */
	}

	*buf_p = buf;
	return (r);
}

/**
 * read_buf - reads a buffer
 * @info: parameter struct value
 * @buf: buffer
 * @i: size
 * Return: r
 */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
	ssize_t z = 0;

	if (*i)
		return (0);
	z = read(info->readfd, buf, READ_BUF_SIZE);
	if (z >= 0)
		*i = z;
	return (z);
}

/**
 * _getline - next line of input from STDIN
 * filestream
 * @info: parameter struct value
 * @ptr: pointer to buffer,
 * @length: size of  ptr
 *
 * Return: s
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t m, len;
	size_t l;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		s = *length;
	if (m == len)
		m = len = 0;

	r = read_buf(info, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _strchr(buf + m, '\n');
	l = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, s, s ? s + l : l + 1);
	if (!new_p)
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(new_p, buf + m, l - m);
	else
		_strncpy(new_p, buf + m, l - m + 1);

	s += l - m;
	m = l;
	p = new_p;

	if (length)
		*length = s;
	*ptr = p;
	return (s);
}

/**
 * sigintHandler - this blocks ctrl-C
 * @sig_num:signal number value
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
