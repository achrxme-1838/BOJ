#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    cout << (a*a + b*b + c*c + d*d + e*e)%10;
}