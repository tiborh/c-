class StackOfInt {
public:
  StackOfInt(int);		// constructor
  void push(int);
  int pop();
  int top() const;
  int size() const;
  ~StackOfInt();		// destructor

private:
  int *data;
  int length;
  int ptr;
};
