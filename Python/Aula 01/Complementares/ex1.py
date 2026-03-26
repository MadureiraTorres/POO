class Widget:
    def __init__(self):
        self._msg = "Hello, I'm a widget!"

    def replace(self):
        index = self._msg.index('w')
        msg_list = list(self._msg)
        msg_list[index] = 'g'
        self._msg = ''.join(msg_list)

    def __str__(self):
        return 'My string is: ' + self._msg