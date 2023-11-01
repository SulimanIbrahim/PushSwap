/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suibrahi <suibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 02:46:10 by suibrahi          #+#    #+#             */
/*   Updated: 2023/11/01 22:45:14 by suibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	if (d == s || (d == NULL && s == NULL ))
	{
		return (d);
	}
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		lentotal;
	char	*strjoin;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s2 || !s1)
		return (NULL);
	lentotal = ft_strlen(s1) + ft_strlen(s2);
	strjoin = malloc(lentotal + 2);
	if (!strjoin)
		return (NULL);
	while (s1[i] != '\0')
	{
		strjoin[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		strjoin[i + j] = s2[j];
		j++;
	}
	strjoin[i + j] = ' ';
	strjoin[i + j + 1] = '\0';
	return (strjoin);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;

	s2 = (char *)malloc(ft_strlen(s1) + 1);
	if (!s2)
		return (0);
	ft_memcpy(s2, s1, ft_strlen(s1) + 1);
	return (s2);
}

int none_integers_check(char **arg) {
    int i;
	int j;

	i = 1;
    while (arg[i]) 
	{
        j = 0;
        while (arg[i][j] != '\0') {
            if ((arg[i][j] >= '0' && arg[i][j] <= '9') || arg[i][j] == '-' || arg[i][j] == ' ') 
                j++;
        	 else 
                return 1;
        }
        i++;
    }

    return 0;
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);

	if (len >= ft_strlen(s))
		len = ft_strlen(s);
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	str = ft_memcpy(str, s + start, len);
	str[len] = 0;
	return (str);
}

static int	strings_count(char const *s, char c)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			word_count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (word_count);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		start;
	char	**substr;
	int		word_count;

	if (s == NULL)
		return (0);
	word_count = strings_count(s, c);
	substr = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (substr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (j < word_count)
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		substr[j++] = ft_substr(s, start, i - start);
	}
	substr[j] = NULL;
	return (substr);
}

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	res;
	unsigned long long	max;

	res = 0;
	sign = 1;
	max = 9223372036854775807;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9' )
	{
		res = res * 10 + *str - '0';
		if (res > max && sign == 1)
			return (-1);
		if (res > max + 1 && sign == -1)
			return (0);
		str++;
	}
	return (res * sign); 
}

int main(int ac, char **av)
{
	int i = 1;
	int check = 0;
	char *joined = strdup("");
	while(av[i])
	{
		joined = ft_strjoin(joined, av[i]);
		i++;
	}
	
 	char **splitted = ft_split(joined, ' ');
	check = none_integers_check(splitted);
	if (check == 1)
	{
		printf("ERROR");
		return 0;
	}
	while(*splitted)
		printf("%s\n", *splitted++);
}