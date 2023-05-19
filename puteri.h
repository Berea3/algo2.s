long long int Putere(long long int A ,long long int n)
{
    if(n == 0)
        return 1;
    if(n % 2 == 1)
        return (A * Putere(A , n - 1))%mod;
    long long int P = Putere(A , n / 2);
    return (P * P)%mod;
}