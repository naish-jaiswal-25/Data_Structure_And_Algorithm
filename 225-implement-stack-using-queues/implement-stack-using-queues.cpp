class MyStack {
public:
    queue<int> q;

    MyStack() {
    }

    void push(int x) {
        q.push(x);

        int sz = q.size();
        while (sz > 1) {
            q.push(q.front());
            q.pop();
            sz--;
        }
    }

    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

