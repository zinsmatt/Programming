class MyQueue:

    def __init__(self):
        self.s_in = []
        self.s_out = []

    def transverse(self):
        while len(self.s_in) > 0:
            self.s_out.append(self.s_in[-1])
            self.s_in.pop(-1)

    def push(self, x: int) -> None:
        self.s_in.append(x)
        

    def pop(self) -> int:
        if len(self.s_out) == 0:
            self.transverse()
        ret = self.s_out[-1]
        self.s_out.pop()
        return ret

    def peek(self) -> int:
        if len(self.s_out) == 0:
            self.transverse()
        return self.s_out[-1]

    def empty(self) -> bool:
        return len(self.s_in) == 0 and len(self.s_out) == 0
        


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
