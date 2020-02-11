#include <vector>
int PalinArray(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        int num = a[i];
        std::vector<int> digits;
        while (num)
        {
            digits.emplace_back(num % 10);
            num = num / 10;
        }
        int j = 0;
        int k = digits.size() - 1;
        while (j < k)
        {
            if (digits[j] != digits[k])
            {
                return 0;
            }
            ++j;
            --k;
        }
    }
    return 1;
}