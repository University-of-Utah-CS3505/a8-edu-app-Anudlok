/****************************************************************************
** Meta object code from reading C++ file 'gamescreen.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Sloshed/gamescreen.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamescreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GameScreen_t {
    const uint offsetsAndSize[18];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_GameScreen_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_GameScreen_t qt_meta_stringdata_GameScreen = {
    {
QT_MOC_LITERAL(0, 10), // "GameScreen"
QT_MOC_LITERAL(11, 18), // "sendHydrationTimer"
QT_MOC_LITERAL(30, 0), // ""
QT_MOC_LITERAL(31, 17), // "sendCollideScreen"
QT_MOC_LITERAL(49, 10), // "resetWater"
QT_MOC_LITERAL(60, 8), // "addWater"
QT_MOC_LITERAL(69, 15), // "updateLevelView"
QT_MOC_LITERAL(85, 13), // "addWaterToBar"
QT_MOC_LITERAL(99, 9) // "nextLevel"

    },
    "GameScreen\0sendHydrationTimer\0\0"
    "sendCollideScreen\0resetWater\0addWater\0"
    "updateLevelView\0addWaterToBar\0nextLevel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameScreen[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x06,    1 /* Public */,
       3,    0,   57,    2, 0x06,    2 /* Public */,
       4,    0,   58,    2, 0x06,    3 /* Public */,
       5,    0,   59,    2, 0x06,    4 /* Public */,
       6,    1,   60,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,   63,    2, 0x0a,    7 /* Public */,
       8,    0,   64,    2, 0x0a,    8 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GameScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GameScreen *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendHydrationTimer(); break;
        case 1: _t->sendCollideScreen(); break;
        case 2: _t->resetWater(); break;
        case 3: _t->addWater(); break;
        case 4: _t->updateLevelView((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->addWaterToBar(); break;
        case 6: _t->nextLevel(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GameScreen::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameScreen::sendHydrationTimer)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GameScreen::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameScreen::sendCollideScreen)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GameScreen::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameScreen::resetWater)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (GameScreen::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameScreen::addWater)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (GameScreen::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameScreen::updateLevelView)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject GameScreen::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_GameScreen.offsetsAndSize,
    qt_meta_data_GameScreen,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_GameScreen_t
, QtPrivate::TypeAndForceComplete<GameScreen, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *GameScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GameScreen.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GameScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void GameScreen::sendHydrationTimer()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void GameScreen::sendCollideScreen()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void GameScreen::resetWater()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void GameScreen::addWater()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void GameScreen::updateLevelView(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
