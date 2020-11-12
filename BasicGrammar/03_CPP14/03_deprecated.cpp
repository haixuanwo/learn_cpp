#include <iostream>
using namespace std;

/**
 * @brief [[弃用的]][[deprecated]]属性
 */

class [[deprecated]] flaky{

};

[[deprecated("consider using something other than cranky")]]
int cranky()
{
    return 0;
}

int main(int argc, char * argv [ ])
{
    flaky f;

    return cranky();
}

