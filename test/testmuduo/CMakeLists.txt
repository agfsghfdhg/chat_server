# 设置需要编译的源文件
set(SRC_LIST ./muduo_test.cpp)

# 设置可执行文件server的最终存储路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 表示生成可执行文件server，由SRC_LIST变量所定义的源文件编译而来
add_executable(server ${SRC_LIST})

# 设置头文件搜索位置
# include_directories()

# 设置库文件搜索位置
# link_libraries()

# 设置链接的库文件
target_link_libraries(server muduo_net muduo_base pthread)