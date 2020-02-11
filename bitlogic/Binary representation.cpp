#include <iostream>
#include <vector>
using namespace std;
const int num_of_bits = 14;
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> bits;
        while (n)
        {
            bits.emplace_back(n % 2);
            n /= 2;
        }
        while (num_of_bits > bits.size())
        {
            bits.emplace_back(0);
        }
        for (int i = bits.size() - 1; i >= 0; --i)
        {
            cout << bits[i];
        }
        std::cout << endl;
    }
    return 0;
}