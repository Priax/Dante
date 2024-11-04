/*
** EPITECH PROJECT, 2023
** my_strcmp
** File description:
** libC
*/

int my_strcmp(char const *s1, char const *s2)
{
    int	i = 0;

    while ((s1[i] == s2[i]) && s1[i] && s2[i]) {
        i++;
    }
    return (s1[i] - s2[i]);
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && n > i) {
        if (s1[i] != s2[i]) {
            return (s1[i] - s2[i]);
        }
        i++;
    }
    if (i < n) {
        return (s1[i] - s2[i]);
    } else {
        return (0);
    }
}

int min(int a, int b)
{
    return (a < b) ? a : b;
}
