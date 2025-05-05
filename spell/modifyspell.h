#ifndef MODIFYSPELL_H
#define MODIFYSPELL_H

#include "spell/spell.h"
#include <QObject>

class ModifySpell : public Spell
{
    Q_OBJECT
public:
    explicit ModifySpell(Spell *parent = nullptr);
    void apply(Spell*);
    void remove(Spell*);
signals:
};

#endif // MODIFYSPELL_H
