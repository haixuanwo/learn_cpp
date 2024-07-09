/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-07-09 20:45:16
 * @LastEditors: Clark
 * @LastEditTime: 2024-07-09 21:55:16
 * @Description: file content
 */

#include <iostream>
#include <functional>

/*
在C++11中，std::function和std::bind是两个非常有用的模板类，用于处理函数对象和函数绑定。它们在许多场景下提供了灵活性和便利性
*/

/*
1. 使用std::function作为泛型参数
std::function允许你将函数作为参数传递，这在需要处理不同类型的函数时非常有用。例如，你可以创建一个函数，接受一个std::function作为参数：
*/
void process_function(std::function<void()> func)
{
    func(); // 调用传递的函数
}

/*
2. 使用std::bind简化函数绑定
std::bind允许你创建一个函数对象，该对象将预绑定一些参数。这在需要固定某些参数值并传递剩余参数时非常有用
*/
void print_message(const std::string& message) {
    std::cout << message << std::endl;
}

void greet(const std::string& name) {
    print_message("Hello, " + name + "!");
}

/*
3. 使用std::function和std::bind处理回调函数
在需要使用回调函数的场景中，std::function和std::bind可以用来简化回调的注册和执行：
*/
void register_callback(std::function<void()> callback) {
    // 在这里注册回调
    // ...
}

void event_handler() {
    // 触发事件，执行回调
    // register_callback(std::bind(&print_message, "Event triggered!"));
}

/*
4. 使用std::function和std::bind处理事件驱动编程
在事件驱动编程中，std::function和std::bind可以用来处理不同类型的事件：
*/
void on_key_press(int key) {
    std::cout << "Key " << key << " pressed." << std::endl;
}

void on_mouse_click(int button) {
    std::cout << "Mouse button " << button << " clicked." << std::endl;
}

/*
5. 使用std::function和std::bind处理模板函数
std::function和std::bind也可以用于处理模板函数，这使得在不显式声明所有模板参数的情况下调用模板函数成为可能：
*/
template<typename T>
void process_value(T value) {
    std::cout << "Processing value: " << value << std::endl;
}

template<typename T>
void process_values(std::function<void(T)> func, T value) {
    func(value); // 使用 std::function 调用模板函数
}

void say_hello(const std::string& name, int a) {
    std::cout << "Hello, " << name << "!\n" << "a = " << a << std::endl;
}

int main()
{
    // 传递一个lambda表达式作为参数
    process_function([](){ std::cout << "Hello, world!" << std::endl; });

    auto greet_with_name = std::bind(greet, "Alice"); // 预绑定名字为"Alice"
    greet_with_name(); // 输出 "Hello, Alice!"


    std::function<void(int)> key_press_handler = std::bind(&on_key_press, 1); // 预绑定按键为1
    std::function<void(int)> mouse_click_handler = std::bind(&on_mouse_click, 1); // 预绑定鼠标按钮为1

    // 假设这里有一个事件处理器，可以注册这些回调
    // event_handler(key_press_handler);
    // event_handler(mouse_click_handler);

    // process_values(std::bind(&process_value<int>, std::placeholders::_1), 42);
    // process_values(std::bind(&process_value<std::string>, std::placeholders::_1), "Hello");

     auto bound_func = std::bind(say_hello, std::placeholders::_1, std::placeholders::_2);

    // 在调用 bound_func 时提供参数 "LiMing"。
    bound_func("LiMing", 119);  // 输出 "Hello, LiMing!"

    return 0;
}
