cmake_minimum_required(VERSION 3.8)         # 1.cmake版本
PROJECT(BigTalkDesignPattern)               # 2.工程名

# set the project name
set(PROJECT_NAME BigTalkDesignPattern)      # 3.设置工程名

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)                  # 4.设置c++标准为c++17
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 5.设置本地头文件路径，注意：子目录中的头文件通过target_include_directories添加到${PROJECT_NAME}中
INCLUDE_DIRECTORIES(
    inc                 # 上层头文件路径
    ${SUB_INCLUDE_DIR}  # 下级头文件目录
)

# 6.将源文件路径添加到变量SRC_LIST中
# AUX_SOURCE_DIRECTORY(.          SRC_LIST)
# AUX_SOURCE_DIRECTORY(src        SRC_LIST)

# 7.生成目标(可执行文件)：cmaketest
# ADD_EXECUTABLE(${PROJECT_NAME} ${SRC_LIST})

# 8.设置编译时依赖的subfunc静态库
# target_link_libraries(${PROJECT_NAME}    #目标：tcu
#     subfunc        # sub子目录下的静态库文件
#     subsubfunc     # subsub子目录下的静态库文件
# )

# 9.添加子目录，这样子目录中的CMakeLists.txt才会被调用

add_subdirectory(01_Simple_factory)
add_subdirectory(02_Strategy)
add_subdirectory(03_Decorate)
add_subdirectory(04_Proxy)
add_subdirectory(05_Factory_method)
add_subdirectory(06_Prototype)
add_subdirectory(07_Template_method)
add_subdirectory(08_Facade)
add_subdirectory(09_builder)
add_subdirectory(10_Observer)
add_subdirectory(11_Abstract_factory)
add_subdirectory(12_State)
add_subdirectory(13_Adapter)
add_subdirectory(14_Memento)
add_subdirectory(15_Composite)
add_subdirectory(16_Iterator)
add_subdirectory(17_Singleton)
add_subdirectory(18_Bridge)
add_subdirectory(19_Command)
add_subdirectory(20_Chain_of_responsibility)
add_subdirectory(21_Mediator)
add_subdirectory(22_Flyweight)
add_subdirectory(23_Interpreter)
add_subdirectory(24_Visitor)
