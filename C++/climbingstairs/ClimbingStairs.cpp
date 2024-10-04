class Solution
{
public:
    int climbStairs(int n)
    {
        if (n < 2)
        {
            return 1;
        }
        int firstStep = 1;
        int secondStep = 1;
        int thirdStep = 0;
        for (int i = 2; i <= n; i++)
        {
            thirdStep = firstStep + secondStep;
            firstStep = secondStep;
            secondStep = thirdStep;
        }
        return thirdStep;
    }
};