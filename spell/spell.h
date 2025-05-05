#ifndef SPELL_H
#define SPELL_H

#include "spell/projectileconfig.h"
#include <QObject>



class Spell : public QObject
{
    Q_OBJECT
public:
    explicit Spell(QObject *parent = nullptr);
    // 是否是子法术
    bool is_child_spell = false;
    // shoot中关闭
    bool could_emit = true;
    // 总冷却时间
    int total_cooldown_time =0;
    // 法力消耗
     int total_mana_consume =0;
    // 等待时间
    int wait_time = 0;
     int mana_consume=0;
    int cooldown_time =0;
     int projectile_amount = 1;
    Spell **trigger_spells = new Spell*[4]{nullptr,nullptr,nullptr,nullptr};
    int spellType;
    ProjectileConfig *projectileConfig;


    virtual void release(QVector2D, QVector2D, int p =0);
    void mix_spells(Spell **);
     void mix_spell(Spell *, int);
    void split_spell(int);
     void update_total_cooldown_time();
    int get_total_cooldown_time();
     void update_total_mana_consume();
    int get_total_mana_consume();
     void change_to_child_spell();
    void change_to_parent_spell();
     int spell_count();
signals:
};

#endif // SPELL_H
