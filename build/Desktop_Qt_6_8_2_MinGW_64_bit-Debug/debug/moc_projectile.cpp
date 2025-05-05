/****************************************************************************
** Meta object code from reading C++ file 'projectile.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../spell/projectile.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'projectile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN10ProjectileE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN10ProjectileE = QtMocHelpers::stringData(
    "Projectile",
    "setuped",
    "",
    "shooted",
    "enemyPassed",
    "HealthComponent*",
    "area",
    "onTriggerTimeTimeout",
    "onLifetimeTimeout",
    "onDeath",
    "isHit",
    "dealDeath",
    "onHitEnemy"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN10ProjectileE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x06,    1 /* Public */,
       3,    0,   69,    2, 0x06,    2 /* Public */,
       4,    1,   70,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,   73,    2, 0x0a,    5 /* Public */,
       8,    0,   74,    2, 0x0a,    6 /* Public */,
       9,    1,   75,    2, 0x0a,    7 /* Public */,
       9,    0,   78,    2, 0x2a,    9 /* Public | MethodCloned */,
      11,    0,   79,    2, 0x0a,   10 /* Public */,
      12,    0,   80,    2, 0x0a,   11 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Projectile::staticMetaObject = { {
    QMetaObject::SuperData::link<GameObject::staticMetaObject>(),
    qt_meta_stringdata_ZN10ProjectileE.offsetsAndSizes,
    qt_meta_data_ZN10ProjectileE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN10ProjectileE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Projectile, std::true_type>,
        // method 'setuped'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'shooted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'enemyPassed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<HealthComponent *, std::false_type>,
        // method 'onTriggerTimeTimeout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onLifetimeTimeout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDeath'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'onDeath'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'dealDeath'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onHitEnemy'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Projectile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Projectile *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->setuped(); break;
        case 1: _t->shooted(); break;
        case 2: _t->enemyPassed((*reinterpret_cast< std::add_pointer_t<HealthComponent*>>(_a[1]))); break;
        case 3: _t->onTriggerTimeTimeout(); break;
        case 4: _t->onLifetimeTimeout(); break;
        case 5: _t->onDeath((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 6: _t->onDeath(); break;
        case 7: _t->dealDeath(); break;
        case 8: _t->onHitEnemy(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< HealthComponent* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (Projectile::*)();
            if (_q_method_type _q_method = &Projectile::setuped; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (Projectile::*)();
            if (_q_method_type _q_method = &Projectile::shooted; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _q_method_type = void (Projectile::*)(HealthComponent * );
            if (_q_method_type _q_method = &Projectile::enemyPassed; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *Projectile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Projectile::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN10ProjectileE.stringdata0))
        return static_cast<void*>(this);
    return GameObject::qt_metacast(_clname);
}

int Projectile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GameObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Projectile::setuped()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Projectile::shooted()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Projectile::enemyPassed(HealthComponent * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
