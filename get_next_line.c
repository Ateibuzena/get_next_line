/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:47:26 by azubieta          #+#    #+#             */
/*   Updated: 2025/07/06 15:20:00 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

static char	*ft_read_fd(int fd, char *buffer)
{
	char	*temp;
	char	*chunk;
	int		bytes;

	chunk = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!chunk)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(buffer, '\n') && bytes > 0)
	{
		bytes = read(fd, chunk, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (ft_free(chunk));
		}
		chunk[bytes] = '\0';
		temp = buffer;
		buffer = ft_strjoin(buffer, chunk);
		free(temp);
		if (!buffer)
			return (ft_free(chunk));
	}
	free(chunk);
	return (buffer);
}

static char	*ft_extract_line(char *buffer)
{
	int		i;
	char	*line;
	int		len;

	if (!buffer || buffer[0] == '\0')
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	len = i;
	if (buffer[i] == '\n')
		len++;
	line = malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*ft_update_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new = malloc((ft_strlen(buffer) - i + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i++;
	while (buffer[i])
		new[j++] = buffer[i++];
	new[j] = '\0';
	free(buffer);
	buffer = NULL;
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (buffer)
		{
			free(buffer);
			buffer = NULL;
		}
		return (NULL);
	}
	buffer = ft_read_fd(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_extract_line(buffer);
	buffer = ft_update_buffer(buffer);
	return (line);
}

/*#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;
    int line_count = 0;

    // Test 1: Reading from a file
    printf("=== Test 1: Reading from file ===\n");
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error: Could not open test.txt\n");
        printf("Creating a test file...\n");
        
        // Create a test file
        int create_fd = open("test.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
        if (create_fd != -1)
        {
            write(create_fd, "Line 1\nLine 2\nLine 3\n\nLine 5", 26);
            close(create_fd);
            fd = open("test.txt", O_RDONLY);
        }
    }
    
    if (fd != -1)
    {
        while ((line = get_next_line(fd)) != NULL)
        {
            printf("Line %d: %s", ++line_count, line);
            if (line[ft_strlen(line) - 1] != '\n')
                printf("\n");
            free(line);
        }
        close(fd);
        printf("Total lines read: %d\n\n", line_count);
    }

    // Test 2: Edge cases
    printf("=== Test 2: Edge cases ===\n");
    
    // Invalid file descriptor
    line = get_next_line(-1);
    printf("Invalid fd (-1): %s\n", line ? line : "NULL (correct)");
    
    // Non-existent file
    fd = open("nonexistent.txt", O_RDONLY);
    line = get_next_line(fd);
    printf("Non-existent file: %s\n", line ? line : "NULL (correct)");
    
    // Test 3: Reading from stdin (uncomment to test)
    printf("\n=== Test 3: Reading from stdin ===\n");
    printf("Enter some lines (Ctrl+D to end):\n");
    line_count = 0;
    while ((line = get_next_line(0)) != NULL)
    {
        printf("You entered: %s", line);
        free(line);
        line_count++;
    }
    printf("Read %d lines from stdin\n", line_count);
    

    return (0);
}*/