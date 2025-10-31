vector<double> runningMedian(vector<int> a) {
    priority_queue<int> left; // max-heap for the smaller half
    priority_queue<int, vector<int>, greater<int>> right; // min-heap for the larger half
    vector<double> medians;

    for (int num : a) {
        // Step 1: Add to one of the heaps
        if (left.empty() || num <= left.top())
            left.push(num);
        else
            right.push(num);

        // Step 2: Rebalance if size difference > 1
        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        } else if (right.size() > left.size() + 1) {
            left.push(right.top());
            right.pop();
        }

        // Step 3: Calculate median
        double median;
        if (left.size() == right.size())
            median = (left.top() + right.top()) / 2.0;
        else if (left.size() > right.size())
            median = left.top();
        else
            median = right.top();

        medians.push_back(median);
    }

    return medians;
}
