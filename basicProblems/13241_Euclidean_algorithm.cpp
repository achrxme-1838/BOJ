#include <iostream>

using namespace std;

long long int Greatest_Common_Divisor(long long int A, long long int B)
{
    while(B > 0)
    {
        long long int tmp = A;
        A = B;
        B = tmp % B;
    }

    return A;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long long int A, B;
    cin >> A >> B;
    long long int gcd = Greatest_Common_Divisor(A, B);

    cout << A * B / gcd;

    return 0;
}