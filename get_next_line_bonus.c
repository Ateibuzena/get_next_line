/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:47:26 by azubieta          #+#    #+#             */
/*   Updated: 2025/07/06 15:58:32 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line_bonus.h"

char	*ft_free(char *ptr)
{
	free(ptr);
	ptr = NULL;
	return (ptr);
}

static char	*ft_buffer_update(char *buffer)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
		return (ft_free(buffer));
	ptr = malloc(((ft_strlen(buffer) - i)
				+ 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		ptr[j++] = buffer[i++];
	ptr[j] = '\0';
	free(buffer);
	buffer = NULL;
	return (ptr);
}

static char	*ft_line_extract(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer || !buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_read_fd(int fd, char *buffer)
{
	char	*ptr;
	char	*temp;
	int		bytes;

	bytes = 1;
	ptr = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (!ft_strchr(buffer, '\n') && bytes != 0)
	{
		bytes = read(fd, ptr, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (ft_free(ptr));
		}
		ptr[bytes] = '\0';
		temp = buffer;
		buffer = ft_strjoin(buffer, ptr);
		free(temp);
		if (!buffer)
			return (ft_free(ptr));
	}
	free(ptr);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static t_fdnode	*list;
	t_fdnode		*current;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) < 0)
		return (ft_freenode(&list, fd), NULL);
	current = list;
	while (current && current->fd != fd)
		current = current->next;
	if (!current)
    {
        current = ft_newnode(fd);
        if (!current)
            return (NULL);
        current->next = list;
        list = current;
    }
	current->buffer = ft_read_fd(fd, current->buffer);
	if (!current->buffer)
		return (ft_freenode(&list, fd));
	line = ft_line_extract(current->buffer);
	current->buffer = ft_buffer_update(current->buffer);
	if (!current->buffer)
		ft_freenode(&list, fd);
	return (line);
}

/*#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd1, fd2, fd3;
    char *line;
    int line_count = 0;

    // Create test files
    printf("=== Creating test files ===\n");
    
    // Create file1.txt
    fd1 = open("file1.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd1 != -1)
    {
        write(fd1, "File1 Line1\nFile1 Line2\nFile1 Line3\n", 36);
        close(fd1);
    }
    
    // Create file2.txt
    fd2 = open("file2.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd2 != -1)
    {
        write(fd2, "File2 LineA\nFile2 LineB\nFile2 LineC\nFile2 LineD\n", 48);
        close(fd2);
    }
    
    // Create file3.txt
    fd3 = open("file3.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd3 != -1)
    {
        write(fd3, "File3 Start\nFile3 Middle\nFile3 End\n", 35);
        close(fd3);
    }
    
    printf("Test files created successfully!\n\n");

    // Test 1: Reading from multiple files simultaneously
    printf("=== Test 1: Multiple file descriptors ===\n");
    
    fd1 = open("file1.txt", O_RDONLY);
    fd2 = open("file2.txt", O_RDONLY);
    fd3 = open("file3.txt", O_RDONLY);
    
    if (fd1 != -1 && fd2 != -1 && fd3 != -1)
    {
        printf("Reading alternately from 3 files:\n");
        
        // Read alternately from the three files
        for (int i = 0; i < 4; i++)
        {
            // Read from file1
            line = get_next_line(fd1);
            if (line)
            {
                printf("FD%d: %s", fd1, line);
                free(line);
            }
            
            // Read from file2
            line = get_next_line(fd2);
            if (line)
            {
                printf("FD%d: %s", fd2, line);
                free(line);
            }
            
            // Read from file3
            line = get_next_line(fd3);
            if (line)
            {
                printf("FD%d: %s", fd3, line);
                free(line);
            }
            
            printf("--- Round %d completed ---\n", i + 1);
        }
        
        close(fd1);
        close(fd2);
        close(fd3);
    }

    // Test 2: Edge cases with multiple FDs
    printf("\n=== Test 2: Edge cases ===\n");
    
    // Invalid file descriptor
    line = get_next_line(-1);
    printf("Invalid fd (-1): %s\n", line ? line : "NULL (correct)");
    
    // Mix valid and invalid FDs
    fd1 = open("file1.txt", O_RDONLY);
    line = get_next_line(fd1);
    printf("Valid FD first line: %s", line ? line : "NULL");
    if (line) free(line);
    
    line = get_next_line(-5);
    printf("Invalid FD: %s\n", line ? line : "NULL (correct)");
    
    line = get_next_line(fd1);
    printf("Valid FD second line: %s", line ? line : "NULL");
    if (line) free(line);

	line = get_next_line(fd1);
    printf("Valid FD 3 line: %s", line ? line : "NULL");
    if (line) free(line);

	line = get_next_line(fd1);
    printf("Valid FD 4 line: %s", line ? line : "NULL");
    if (line) free(line);
    
    close(fd1);

    // Test 3: Many file descriptors
    printf("\n=== Test 3: Many file descriptors ===\n");
    
    int fds[5];
    char filename[20];
    
    // Create and open multiple files
    for (int i = 0; i <= 5; i++)
    {
        sprintf(filename, "test%d.txt", i);
        int create_fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
        if (create_fd != -1)
        {
            char content[50];
            sprintf(content, "Test%d Line1\nTest%d Line2\n", i, i);
            write(create_fd, content, ft_strlen(content));
            close(create_fd);
        }
        fds[i] = open(filename, O_RDONLY);
    }
    
    // Read first line from each
    printf("Reading first line from 5 files:\n");
	for (int i = 0; i <= 5; i++)
    {
        if (fds[i] != -1)
        {
            line = get_next_line(fds[i]);
            if (line)
            {
                printf("File%d: %s", i, line);
                free(line);
            }
		}
		else
		{
			printf("File%d could not be opened.\n", i);
        }
    }
    
    // Read second line from each
    printf("Reading second line from 5 files:\n");
    for (int j = 0; j <= 5; j++)
    {
        if (fds[j] != -1)
        {
            line = get_next_line(fds[j]);
            if (line)
            {
                printf("File%d: %s", j, line);
                free(line);
            }
            close(fds[j]);
        }
    }

	// Read 3 line from each
    printf("Reading 3 line from 5 files:\n");
    for (int j = 0; j <= 5; j++)
    {
        if (fds[j] != -1)
        {
            line = get_next_line(fds[j]);
            if (line)
            {
                printf("File%d: %s", j, line);
                free(line);
            }
            close(fds[j]);
        }
    }

    // Test 4: Reading from stdin (commented out)
    printf("\n=== Test 4: Reading from stdin ===\n");
    printf("Enter some lines (Ctrl+D to end):\n");
    while ((line = get_next_line(0)) != NULL)
    {
        printf("You entered: %s", line);
        free(line);
    }

    printf("\n=== All tests completed ===\n");
    
    return (0);
}*/