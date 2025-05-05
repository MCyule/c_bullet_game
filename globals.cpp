#include "globals.h"
#include "ui_hud.h"
#include<QRandomGenerator>

Globals::Globals(QObject *parent)
    : QObject{parent}
    ,music(new QSoundEffect())
{
    std::random_shuffle<int*>(cards,cards+12);
    //for(int i=0;i<13;i++)
    //qDebug()<<cards[i];
    music->setSource(QUrl::fromLocalFile(":/upgrade"));
    music->setVolume(0.4);
}

Globals* Globals::object=0;
QPoint Globals::mousePos;
QVector2D Globals::player_direction;
const QPoint Globals::centerPos = QPoint(800,400);

Globals* Globals::instance(){
    if(object == nullptr){
        object = new Globals();
    }
    return object;
}

QVector2D Globals::randomPoitOutside(){
    // 左上右下
    int pos = QRandomGenerator::global()->bounded(1,5);
    int x =0;
    int y =0;
    if(pos == 1) {
        x = -100;
        y = QRandomGenerator::global()->bounded(-100,1100);
    }
    else if (pos == 2) {
        y = -100;
        int dir = QRandomGenerator::global()->bounded(0,2);
        if(dir==0){
            x = QRandomGenerator::global()->bounded(-100,500);
        }else{
            x = QRandomGenerator::global()->bounded(1000,1900);
        }
    }
    else if (pos == 3) {
        x = 1900;
        y = QRandomGenerator::global()->bounded(-100,1100);
    }
    else if (pos == 4) {
        y = 1100;
        int dir = QRandomGenerator::global()->bounded(0,2);
        if(dir==0){
            x = QRandomGenerator::global()->bounded(-100,500);
        }else{
            x = QRandomGenerator::global()->bounded(1000,1900);
        }
    }
    return QVector2D(x,y);
}


QPoint Globals::toPoint(const QVector2D vec){
    return QPoint(vec.x(),vec.y());
}
QVector2D Globals::toVector2(const QPoint point){
    return QVector2D(point.x(),point.y());

}

void Globals::setplayer(Player *_player){
    player = _player;
    emit playerLoaded(player);
}
QVector2D Globals::rotated(QVector2D vec,qreal angle){
    QVector2D nn;
    nn.setX(vec.x()*std::cos(angle) - vec.y()*std::sin(angle));
    nn.setY(vec.x()*std::sin(angle) + vec.y()*std::cos(angle));
    return nn;
}


QVector2D Globals::generateRandomUnitVector() {
    // 生成 0 到 2π 的随机弧度
    int angle1 = QRandomGenerator::global()->bounded(0, 628318);
    double angle = (angle1+0.0) / 100000;
    // 计算单位向量（cosθ, sinθ）
    double x = qCos(angle);
    double y = qSin(angle);

    return QVector2D(x, y).normalized(); // 确保模长为 1（处理浮点误差）
}

void Globals::upgrade(int id){
    music->play();
    id = cards[id];
    //qDebug()<<"升级！！！！！！          "<<id;
    if(id==0){
     player->spell->projectile_amount++;
        player->spell->mana_consume += 5;
     hud->ui->label->setVisible(true);
    }else if(id == 1){//折射路径
             hud->ui->label_2->setVisible(true);
        QVector<QVector2D> path;
        path.append(QVector2D(0,0));
       path.append(QVector2D(1,1));
        path.append(QVector2D(2,0));
        path.append(QVector2D(3,-1));
        path.append(QVector2D(4,0));
        Globals::player->spell->motions->path.clear();
        Globals::player->spell->motions->path = path;
        Globals::instance()->player->spell->motions->path_length += 20000;
        Globals::instance()->player->spell->projectileConfig->maxLifetime += 500;
    }else if(id == 2){//击中散射
                    hud->ui->label_3->setVisible(true);
        ProjectileConfig *config1 = new ProjectileConfig();
        config1->attackPower = 4;
        NormalSpell *child =new NormalSpell();
        child->projectileConfig = config1;
        child->projectile_amount = 8;
        child->projectileConfig->aniName = "little_bullet";
        child->projectileConfig->aniScale = 1;
        Globals::instance()->player->spell->trigger_spells[0] = child;
    }else if(id == 3){//中途折射
                    hud->ui->label_4->setVisible(true);
        ProjectileConfig *config1 = new ProjectileConfig();
        config1->attackPower = 5;
        NormalSpell *child =new NormalSpell();
        child->projectileConfig = config1;
        child->projectile_amount = 1;
        child->motions->path.append(QVector2D(0,0));
        child->motions->path.append(QVector2D(1,0));
        child->motions->path.append(QVector2D(0,0));
         child->motions->path.append(QVector2D(-1,0));
        child->motions->path.append(QVector2D(0,0));
        child->projectileConfig->maxLifetime += 400;
        child->motions->path_length += 100000;
        child->projectileConfig->aniName = "arrow_bullet";
        child->projectileConfig->aniScale = 1;
        Globals::instance()->player->spell->trigger_spells[1] = child;
    }else if(id == 4){//末尾环绕
                    hud->ui->label_5->setVisible(true);
        ProjectileConfig *config1 = new ProjectileConfig();
        config1->attackPower = 5;
        NormalSpell *child =new NormalSpell();
        child->projectileConfig = config1;
        child->projectile_amount = 1;
        child->motions->path.append(QVector2D(0,0));
        child->motions->path.append(QVector2D(1,1));
        child->motions->path.append(QVector2D(1,2));
        child->motions->path.append(QVector2D(0,2));
        child->motions->path.append(QVector2D(-1,1));
        child->motions->path.append(QVector2D(0,0));
        child->projectileConfig->maxLifetime += 1500;
        child->motions->path_length += 60000;
        child->projectileConfig->aniName = "circle_bullet";
        child->projectileConfig->aniScale = 1;
        Globals::instance()->player->spell->trigger_spells[3] = child;
    }else if(id == 5){//强化
                    hud->ui->label_6->setVisible(true);
        Globals::instance()->player->spell->projectileConfig->maxLifetime += 1000;
        Globals::instance()->player->spell->projectileConfig->attackPower += 10;
        Globals::instance()->player->spell->projectileConfig->shootSpeed += 100;
        Globals::instance()->player->healthComponent->health += 50;
    }else if(id == 6){//自动回血
                    hud->ui->label_7->setVisible(true);
        Globals::instance()->player->recoverHealth = true;
    }else if(id == 7){//无敌帧
                    hud->ui->label_8->setVisible(true);
        Globals::instance()->player->hasInvinTime = true;
    }else if(id == 8){//受伤施法
                    hud->ui->label_9->setVisible(true);
        Globals::instance()->player->hasHurtSpell = true;
        Globals::instance()->player->addComponent(Globals::instance()->player->spell1);
      //  Glo
    }else if(id == 9){//碰撞伤害
                    hud->ui->label_10->setVisible(true);
        Globals::instance()->player->healthComponent->couldAttack = true;
    }else if(id==10){//自动1
                    hud->ui->label_11->setVisible(true);
        Globals::instance()->player->autoTimer1->start();
            Globals::instance()->player->addComponent(Globals::instance()->player->chara);

    }else if(id == 11){//自动2
                    hud->ui->label_12->setVisible(true);
        Globals::instance()->player->autoTimer2->start();
        //Globals::instance()->player->spell2->play("ene3");
        Globals::instance()->player->addComponent(Globals::instance()->player->spell2);
    }
}
