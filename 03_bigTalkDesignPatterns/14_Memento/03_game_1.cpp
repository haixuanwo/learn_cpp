/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-26 15:20:28
 * @Description: file content
 */

#include <list>
#include <string>
#include <iostream>
using namespace std;

class RoleStateMemento
{
public:
    RoleStateMemento(int vit, int atk, int def)
    {
        this->vit = vit;
        this->atk = atk;
        this->def = def;
    }

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

private:
    int vit;
    int atk;
    int def;
};

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

    RoleStateMemento *save_state()
    {
        return new RoleStateMemento(vit, atk, def);
    }

    void recovery_state(RoleStateMemento *memento)
    {
        this->vit = memento->get_vit();
        this->atk = memento->get_atk();
        this->def = memento->get_def();
    }

private:
    int vit;
    int atk;
    int def;
};

class RoleStateCaretaker
{
public:
    void set_RoleStateMemento(RoleStateMemento *memento)
    {
        this->memento = memento;
    }

    RoleStateMemento *get_RoleStateMemento()
    {
        return memento;
    }
private:
    RoleStateMemento *memento;
};

int main()
{
    // 大战boss前
    GameRole *lixiaoyao = new GameRole();
    lixiaoyao->get_init_state();
    lixiaoyao->state_display();

    // 保存进度
    RoleStateCaretaker *backup = new RoleStateCaretaker();
    backup->set_RoleStateMemento(lixiaoyao->save_state());

    // 大战boss时，损耗严重
    lixiaoyao->fight();
    lixiaoyao->state_display();

    // 恢复之前的状态
    lixiaoyao->recovery_state(backup->get_RoleStateMemento());
    lixiaoyao->state_display();

    return 0;
}
