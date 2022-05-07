
class MyStack {
private:
    queue<int>* q1;
    queue<int>* q2;
    queue<int>* temp;
public:
    MyStack() {
        q1 = new queue<int>;
        q2 = new queue<int>;

    }

    void push(int x) {
        q1->push(x);
    }

    int pop() {
        int x;
        int size = q1->size();
        for (int i = 0; i < size-1; i++)
        {
            x = q1->front();
            q1->pop();
            q2->push(x);
        }
        x = q1->front();
        q1->pop();
        temp = q1;
        q1 = q2;
        q2 = temp;
        return x;
    }

    int top() {
        return q1->back();
    }

    bool empty() {
        return q1->empty();
    }
};