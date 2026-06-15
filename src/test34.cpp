#include <iostream>
#include <memory>
#include <string>

class Resource {
    std::string name;
public:
    Resource(const std::string& name) : name(name) {
        std::cout << "创建资源：" << name << std::endl;
    }
    ~Resource() {
        std::cout << "释放资源：" << name << std::endl;
    }
    void use() {
        std::cout << "使用资源：" << name << std::endl;
    }
};

int main() {
    std::cout << "=== unique_ptr ===" << std::endl;
    {
        auto ptr1 = std::make_unique<Resource>("资源A");
        ptr1->use();

        auto ptr2 = std::move(ptr1);
        std::cout << "ptr1是否为空：" << (ptr1 == nullptr ? "是" : "否") << std::endl;
        ptr2->use();
    }
    std::cout << std::endl;

    std::cout << "=== shared_ptr ===" << std::endl;
    {
        auto sp1 = std::make_shared<Resource>("资源B");
        std::cout << "引用计数：" << sp1.use_count() << std::endl;
        {
            auto sp2 = sp1;
            std::cout << "创建sp2后引用计数：" << sp1.use_count() << std::endl;
            sp2->use();

            auto sp3 = sp1;
            std::cout << "创建sp3后引用计数：" << sp1.use_count() << std::endl;
        }

        std::cout << "sp2，sp3销毁后引用计数：" << sp1.use_count() << std::endl;
    }

    std::cout << "\n程序结束" << std::endl;

    return 0;
}