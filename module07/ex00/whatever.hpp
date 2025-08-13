template <typename T>
void swap(T &x, T &y)
{
    T tempx = x;

    x = y;
    y = tempx;
}

template <typename T>
T min(T x, T y)
{
    return (x < y) ? x : y;
}

template <typename T>
T max(T x, T y) 
{
    return (x > y) ? x : y;
}