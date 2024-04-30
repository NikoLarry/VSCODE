long loop_while(long a, long b)
{
    long i = 1;
        while(a<b)
        {
            i = i * (a+b);
            a++;
        }
        return a;
}