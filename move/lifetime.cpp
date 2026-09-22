#include <iostream>
#include <string>
#include <vector>

struct User {
    std::string name;

    const std::string& GetName() const {
        return name;
    }
};

// const std::string& name1 = User{"Alice"}.name;
// const std::string& name2 = User{"Bob"}.GetName();

struct Numbers {
    int values[3];
};

// const int& num1 = Numbers{{10, 20, 30}}.values[1];
// const int& num2 = std::vector<int>{10, 20, 30}[1];

const std::string& Identity(const std::string& value) {
    return value;
}

// const std::string& direct = std::string{"direct"};
// const std::string& indirect = Identity(std::string{"indirect"});

struct Storage {
    std::vector<int> data{1, 2, 3};

    const std::vector<int>& Values() const {
        return data;
    }

    static Storage Make() {
        return {};
    }
};

// const auto& values = Storage::Make().Values();

// // c++23 https://en.cppreference.com/cpp/language/range-for
// for (auto & value : Storage::Make().Values()) {
//     std::cout << value << '\n';
// }

// безопасный getter
class User {
public:
    explicit User(std::string name)
        : name_(std::move(name)) {}

    const std::string& Name() const & {
        return name_;
    }

    std::string Name() && {
        return std::move(name_);
    }

private:
    std::string name_;
};

User MakeUser() {
    return User{"Alice"};
}

// User user{"Bob"};
// const std::string& first = user.Name();
// std::string second = MakeUser().Name();
// std::string && second = MakeUser().Name();
