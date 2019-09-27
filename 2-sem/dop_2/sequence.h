#ifndef sequence
#define sequence

int seque(char s[])
{
    int num, first, a, k;
    int y = -1, z = 0;
    int len = strlen(s);
    while (++y != len)
    {
        first = s[y];
        k = 1;
        while (++z != len)
        {
            a = s[z];
            if (s < first)
                k++;
        }
    }
    assert(k >= 0);
    return k;
}

#endif /* sequence */
