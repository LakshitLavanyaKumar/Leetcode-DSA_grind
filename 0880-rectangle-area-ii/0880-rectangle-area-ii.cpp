class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        const int MOD = 1e9 + 7;

        // Step 1: Collect all unique y-values (bottom and top of rectangles)
        set<int> uniqueYs;
        for (const auto& rect : rectangles) {
            uniqueYs.insert(rect[1]); // y1
            uniqueYs.insert(rect[3]); // y2
        }

        // Step 2: Sort rectangles by their starting x-coordinate (left side)
        sort(rectangles.begin(), rectangles.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        // Step 3: Initialize result and previous y value
        long long totalArea = 0;
        int prevY = *uniqueYs.begin(); // Start with the smallest y value

        // Step 4: Sweep through all adjacent y-intervals (like scanning horizontal strips)
        for (int currY : uniqueYs) {
            // Compute height of current horizontal strip
            int height = currY - prevY;
            if (height == 0) {
                prevY = currY;
                continue;
            }

            // Now compute the width of union of all rectangles covering this horizontal strip
            long long xStart = -1;
            long long xEnd = -1;

            for (const auto& rect : rectangles) {
                int x1 = rect[0], y1 = rect[1];
                int x2 = rect[2], y2 = rect[3];

                // Check if this rectangle fully spans the current y-strip [prevY, currY)
                if (y1 <= prevY && y2 >= currY) {
                    // If the rectangle starts after current x-end → gap → add previous segment
                    if (x1 > xEnd) {
                        totalArea = (totalArea + (xEnd - xStart) * height % MOD) % MOD;
                        xStart = x1;
                        xEnd = x2;
                    } else {
                        // Extend the current segment if needed
                        xEnd = max(xEnd, (long long)x2);
                    }
                }
            }

            // Add the final x segment for this y-strip
            totalArea = (totalArea + (xEnd - xStart) * height % MOD) % MOD;

            // Move to next strip
            prevY = currY;
        }

        return totalArea % MOD;
    }
};
