// Date:-25-1-25
// Author:-suyash singh
class Solution
{
public:
    bool checkOverlap(int r, int h, int k, int x1, int y1, int x2, int y2)
    {

        for (int x = x1; x <= x2; x++)
        {
            for (int y = y1; y <= y2; y++)
            {
                if ((int)((x - h) * (x - h) + (y - k) * (y - k)) <= r * r)
                    return 1;
            }
        }
        return 0;
    }
};

// optimal
class Solution
{
public:
    bool checkOverlap(int r, int h, int k, int x1, int y1, int x2, int y2)
    {
        int dx = 0, dy = 0;
        if (x1 > h)
        {
            dx = x1;
        }
        else if (x2 < h)
        {
            dx = x2;
        }
        else
            dx = h;

        if (y1 > k)
        {
            dy = y1;
        }
        else if (y2 < k)
        {
            dy = y2;
        }
        else
            dy = k;

        return (dx - h) * (dx - h) + (dy - k) * (dy - k) <= r * r;
    }
};
