#include "card.h"
#include"globals.h"

Card::Card(Enemy *parent)
    : Enemy{parent}
    ,sprite(new AnimatedSpriteComponent())
{

    sprite->append(new QPixmap(":/card1"),1,"card1");
    sprite->append(new QPixmap(":/card2"),1,"card2");
    sprite->append(new QPixmap(":/card3"),1,"card3");
    sprite->append(new QPixmap(":/card4"),1,"card4");
    sprite->append(new QPixmap(":/card5"),1,"card5");
    sprite->append(new QPixmap(":/card6"),1,"card6");
    sprite->append(new QPixmap(":/card7"),1,"card7");
    sprite->append(new QPixmap(":/card8"),1,"card8");
    sprite->append(new QPixmap(":/card9"),1,"card9");
    sprite->append(new QPixmap(":/card10"),1,"card10");
    sprite->append(new QPixmap(":/card11"),1,"card11");
    sprite->append(new QPixmap(":/card12"),1,"card12");
    sprite->append(new QPixmap(":/card13"),1,"card13");
    sprite->setScale(1);
    sprite->play("card1");


    healthComponent->health = 10;
    healthComponent->couldAttack = false;
    healthComponent->touchArea = new QVector2D(60,100);

    addComponent(sprite);

    connect(this,&GameObject::died,this,[this](){
        Globals::instance()->upgrade(id);
    });
}
