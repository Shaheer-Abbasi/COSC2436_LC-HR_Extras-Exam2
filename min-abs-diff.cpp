int minimumAbsoluteDifference(vector<int> arr) {
    sort(arr.begin(), arr.end());
    int minDiff = INT_MAX;

    for (int i = 1; i < arr.size(); i++) {
        int diff = abs(arr[i] - arr[i - 1]);
        minDiff = min(minDiff, diff);
    }

    return minDiff;
}