long power(int base, int exponent)
{
    long result = 1;
    for(int i = 0; i < exponent; i++)
    {
        result *= base;
    }
    return result;
}