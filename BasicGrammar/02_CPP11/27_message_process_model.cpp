
#include <iostream>
#include <utility>
#include <deque>
#include <chrono>
#include <unordered_map>
#include <functional>
#include <mutex>
#include <thread>
#include <condition_variable>

using namespace std;

using callback = function<void(int)>;

void show1(int value)
{
    cout<<"1 --- value :"<<value<<endl;
}

void show2(int value)
{
    cout<<"2 --- value :"<<value<<endl;
}


unordered_map<int, callback> messageMapTable = {
                  {1, show1},
                  {2, show2}
};

deque<pair<int, int>> msgData;

mutex mtx;
condition_variable repo_message;

void produce_item(int id, int value)
{
	unique_lock<mutex> lck(mtx);
    msgData.push_back(make_pair(id, value));
	repo_message.notify_one();
}

int consume_item()
{
    pair<int, int> msgDataItem;
    {
        unique_lock<mutex> lck(mtx);
        while (0 == msgData.size())
        {
            cout<<"wait for message ..."<<endl;
            repo_message.wait(lck);
        }

        swap(msgDataItem, msgData.front());
        msgData.pop_front();
    }

    cout<<"do task ..."<<endl;
    messageMapTable[msgDataItem.first](msgDataItem.second);
    return 0;
}

void Producer_thread()
{
	for (;;)
	{
		this_thread::sleep_for(chrono::milliseconds(5000));
		produce_item(1, 100);
		produce_item(2, 200);
	}
}

void Consumer_thread()
{
	while (1)
	{
		consume_item();
	}
}

int main()
{
	thread producer(Producer_thread); // 创建生产者线程.
	thread consumer(Consumer_thread); // 创建消费之线程.
	producer.join();
	consumer.join();
}
