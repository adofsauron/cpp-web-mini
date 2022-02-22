#include <iostream>

#include "../src/proto/hello.pb.h"


bool writeBuf(string file_path)
{
    helloworld msg1;   // 包名::Message名 
    helloworld::PhoneNumber *phone;  // 注意嵌套Message使用指针
    msg1.set_id(100);
    msg1.set_str("200");

    phone = msg1.add_phones();
    phone->set_number("12345");
    phone->set_type(helloworld_PhoneType_HOME);  // 注意Enum的调用方式(所有的默认值相当于C++中的Const对象, 所以直接使用类调用)

    // Write the new address book back to disk. 
    fstream output(file_path, ios::out | ios::trunc | ios::binary); 

    if (!msg1.SerializeToOstream(&output)) { 
        std::cerr << "Failed to write msg." << std::endl; 
        return false; 
    }     
    return true;
}

// 输出数据
void ListMsg(const helloworld & msg) { 
    cout << msg.id() << std::endl; 
    cout << msg.str() << std::endl; 
    for (int i =0; i<msg.phones_size(); i++)
    {
        // 注意此时调用嵌套类中的值不是用的指针方式.
        cout << msg.phones(i).number() << std::endl;
    }
} 

// 读取文件,写入到protobuf生成的类中
bool readBuf(string file_path)
{
    helloworld msg1;
    { 
        fstream input(file_path, ios::in | ios::binary); 
        if (!msg1.ParseFromIstream(&input)) { 
            std::cerr << "Failed to parse address book." << std::endl; 
            return -1; 
        } 
    } 
    ListMsg(msg1); 
}

int main()  
{  
    string path = "./test.log";
    writeBuf(path);
    readBuf(path);
    return 0;  
}  


