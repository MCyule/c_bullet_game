#include "spell.h"
#include "qvectornd.h"
#include "spell/modifyspell.h"



Spell::Spell(QObject *parent)
    : QObject{parent}
{}

void Spell::release(QVector2D,QVector2D,int){
    could_emit = false;
}
void Spell::mix_spells(Spell** spells){
    trigger_spells = spells;
    for (int i =0;i<4;i++/**/){
        Spell *spell = spells[i];
        if( spell==nullptr||!  qobject_cast<ModifySpell*>(spell)){
            continue;
        }
        qobject_cast<ModifySpell*>(spell)->apply(this);
    }
    update_total_cooldown_time();
    update_total_mana_consume();
}
void Spell::mix_spell(Spell* spell,int index){
    trigger_spells[index] = spell;
    if (spell !=nullptr && qobject_cast<ModifySpell*>(spell)){
        qobject_cast<ModifySpell*>(spell)->apply(this);
    }
    update_total_cooldown_time();
    update_total_mana_consume();
}
void Spell::split_spell(int index){
    if(trigger_spells[index] != nullptr){
        return;
    }
    if(qobject_cast<ModifySpell*>(trigger_spells[index])){
       qobject_cast<ModifySpell*>(trigger_spells[index])->remove(this);
        trigger_spells[index] = nullptr;
    }
    update_total_cooldown_time();
    update_total_mana_consume();
}
void Spell::update_total_cooldown_time(){
    int result = cooldown_time;
    for(int i=0;i<4;i++){
        Spell *spell = trigger_spells[i];
        if(spell == nullptr){
            continue;
        }
        if(qobject_cast<ModifySpell*>(spell)){
            result += spell->total_cooldown_time;
            continue;
        }
        result += spell->get_total_cooldown_time();
    }
    total_cooldown_time = result;
}
int Spell::get_total_cooldown_time(){
    if(total_cooldown_time <= 0){
        total_cooldown_time = cooldown_time;
    }
    return total_cooldown_time;
}
void Spell::update_total_mana_consume(){
    int result  = mana_consume;
    for(int i=0;i<4;i++){
        Spell* spell = trigger_spells[i];
        if(not spell){
            continue;
        }
        if(qobject_cast<ModifySpell*>(spell)){
            result += spell->total_mana_consume;
            continue;
        }
        result += spell->get_total_mana_consume();
    }
    total_mana_consume = result;
}
int Spell::get_total_mana_consume(){
    if(total_mana_consume <= 0){
        total_mana_consume = mana_consume;
    }
    return total_mana_consume;
}
void Spell::change_to_child_spell(){
    is_child_spell = true;
}
void Spell::change_to_parent_spell(){
    is_child_spell = false;
}
int Spell::spell_count(){
    int result = 1;
    Spell*spell;
    for(int i=0;i<4;i++){
        spell= trigger_spells[i];
        if(spell == nullptr){
            continue;
        }
        result += spell->spell_count();
    }
    return result;
}


