int cookies(int k, vector<int> A) {
    priority_queue<int, vector<int>, greater<int>> pq(A.begin(), A.end());
    int operations = 0;

    while (pq.size() > 1 && pq.top() < k) {
        int least = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();

        int new_cookie = least + 2 * second;
        pq.push(new_cookie);
        operations++;
    }

    return (pq.top() >= k) ? operations : -1;
}
