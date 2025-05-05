#ifndef PROJECTILECONFIG_H
#define PROJECTILECONFIG_H

#include <QObject>

class ProjectileConfig
{
public:
    ProjectileConfig();
    // 轨迹相关
    float damp = 0;
    int shootSpeed = 500;
    // 投掷物属性相关
    float maxLifetime = 1000;
    int passCount = 1;
    int attackPower = 0;
    int aniScale = -1;
    QString aniName = "";
};

#endif // PROJECTILECONFIG_H
