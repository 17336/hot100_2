//
// Created by 17336 on 2023/4/16.
//

#include "297.h"
#include "437best.h"
#include <iostream>

class Message
{
public:
    Message()
    {
        printf("Message::Message() is called\n");
    }
    Message(const Message &)
    {
        printf("Message::Message(const Message &msg) is called\n");
    }
    Message& operator=(const Message &)
    {
        printf("Message::operator=(const Message &) is called\n");
    }
    Message(int i) {
        a=1;
        printf("Message::Message(int i) is called\n");
    }
    ~Message()
    {
        printf("Message::~Message() is called\n");
    }
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
};

Message func() {
    return 0;
}

int main() {
    vector<int> a{1,5,11,5};
    TreeNode *root=Codec().deserialize("1000000000,1000000000,n,294967296,n,1000000000,n,1000000000,n,1000000000");
    Solution().pathSum(root,8);
}
