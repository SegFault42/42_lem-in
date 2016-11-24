#include "./includes/libft.h"

int	ft_strccmp(const char *s1, const char *s2, char c)
{
	int				i;
	int				j;
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	i = 0;
	j = 0;
	while (s2[j] != c)
		++j;
	++j;
	/*if (ft_strlen(s1) + j > ft_strlen(s2))*/
		/*return (1);*/
	/*else if (ft_strlen(s1) + j < ft_strlen(s2))*/
		/*return (-1);*/
	while (ss1[i] != '\0')
	{
		if (ss2[j] != ss1[i])
		{
			return (ss1[i] - ss2[j]);
		}
		i++;
		j++;
	}
	return (0);
}
