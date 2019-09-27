int seque(char s[]);

int main(void)
{
    int num, a, max_a, rem1, rem2, seq;
    char s[80] = "1 2 8 7 6 5";
    printf("Input string of numbers: ");
    gets_s(s);
    int y = -1, z = 0;
    int len = strlen(s);
    assert(len > 0);
    seq = seque(s);
    printf("Length of a decreasing sequence: %d", seq);
    while (++y != len)
    {
        a = s[y];
        max_a = a;
        while (++z != len)
        {
            a += s[z];
            if (a > max_a)
            {
                max_a = a;
                rem1 = s[y];
                rem2 = s[z];
            }
        }
    }
    while (++y != len)
        if ((s[y] == rem1) || (s[y] == rem2))
        {
            int j = y--;
            --len;
            while (++j != len+1)
                s[j-1] = s[j];
        }
    assert(len > 0);
    s[len] = '\0';
    if (s == "1 2 6 5")
        printf("Test #1 OK");
    if (seq == 4)
        printf("Test #2 OK");
    return 0;
}
