vector<double> runningMedian(vector<int> a) {
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right; 
    vector<double> medians;

    for (int num : a) {
        if (left.empty() || num <= left.top())
            left.push(num);
        else
            right.push(num);
            
        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        } else if (right.size() > left.size() + 1) {
            left.push(right.top());
            right.pop();
        }

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