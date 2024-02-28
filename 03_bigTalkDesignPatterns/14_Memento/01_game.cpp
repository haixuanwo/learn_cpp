/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-26 14:16:51
 * @Description: file content
 */

#include <list>
#include <string>
#include <iostream>
using namespace std;

class GameRole
{
public:
    void set_vit(int vit)
    {
        this->vit = vit;
    }

    int get_vit()
    {
        return vit;
    }

    void set_atk(int atk)
    {
        this->atk = atk;
    }

    int get_atk()
    {
        return atk;
    }

    void set_def(int def)
    {
        this->def = def;
    }

    int get_def()
    {
        return def;
    }

    void state_display()
    {
        cout << "角色当前状态：" << endl;
        cout << "体力：" << vit << endl;
        cout << "攻击力：" << atk << endl;
        cout << "防御力：" << def << endl;
    }

    void get_init_state()
    {
        vit = 100;
        atk = 100;
        def = 100;
    }

    void fight()
    {
        vit = 0;
        atk = 0;
        def = 0;
    }

private:
    int vit;
    int atk;
    int def;
};

int main()
{
    // 大战boss前
    GameRole *lixiaoyao = new GameRole();
    lixiaoyao->get_init_state();
    lixiaoyao->state_display();

    // 保存进度
    GameRole *backup = new GameRole();
    backup->set_vit(lixiaoyao->get_vit());
    backup->set_atk(lixiaoyao->get_atk());
    backup->set_def(lixiaoyao->get_def());

    // 大战boss时，损耗严重
    lixiaoyao->fight();
    lixiaoyao->state_display();

    // 恢复之前的状态
    lixiaoyao->set_vit(backup->get_vit());
    lixiaoyao->set_atk(backup->get_atk());
    lixiaoyao->set_def(backup->get_def());
    lixiaoyao->state_display();

    return 0;
}
