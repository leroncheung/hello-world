#include <iostream>

using namespace std;

bool IsBigEndian1() {
    int a = 0x12345678;
    // char b = static_cast<char>(a);
    // 通过将int强制转换为char单字节，通过判断起始存储位置
    // b为a的低地址部分，0x12为a的高位字节
    char b = *(char *)&a;
    // cout << hex << b << endl;
    if (b == 0x12) {
        return true;
    }
    return false;
}


bool IsBigEndian2() {
    union NUM {
        int a;
        char b;
    };
    NUM num;
    num.a = 0x12345678;
    // 联合体union的存放顺序是所有成员都从低地址开始存放
    // NUM联合体中a和b共用4字节，a占用后，再查看num.b。正常情况下b占用的是低地址位的那个字节
    // 所以判断num.b与a的高位字节0x12是否相等，如果相等则为大端模式
    // cout << hex << num.b << endl;
    if (num.b == 0x12) {
        return true;
    }
    return false;
}

int main() {
    cout << IsBigEndian2() << endl;

    return 0;
}