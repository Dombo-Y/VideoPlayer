/****************************************************************************
** Meta object code from reading C++ file 'videoplayer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../VideoPlayer-ffmpeg/videoplayer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'videoplayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_videoPlayer_t {
    QByteArrayData data[13];
    char stringdata0[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_videoPlayer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_videoPlayer_t qt_meta_stringdata_videoPlayer = {
    {
QT_MOC_LITERAL(0, 0, 11), // "videoPlayer"
QT_MOC_LITERAL(1, 12, 12), // "stateChanged"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 12), // "videoPlayer*"
QT_MOC_LITERAL(4, 39, 6), // "player"
QT_MOC_LITERAL(5, 46, 11), // "timeChanged"
QT_MOC_LITERAL(6, 58, 12), // "initFinished"
QT_MOC_LITERAL(7, 71, 10), // "playFailed"
QT_MOC_LITERAL(8, 82, 12), // "frameDecoded"
QT_MOC_LITERAL(9, 95, 8), // "uint8_t*"
QT_MOC_LITERAL(10, 104, 4), // "data"
QT_MOC_LITERAL(11, 109, 13), // "VideoSwsSpec&"
QT_MOC_LITERAL(12, 123, 4) // "spec"

    },
    "videoPlayer\0stateChanged\0\0videoPlayer*\0"
    "player\0timeChanged\0initFinished\0"
    "playFailed\0frameDecoded\0uint8_t*\0data\0"
    "VideoSwsSpec&\0spec"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_videoPlayer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       5,    1,   42,    2, 0x06 /* Public */,
       6,    1,   45,    2, 0x06 /* Public */,
       7,    1,   48,    2, 0x06 /* Public */,
       8,    3,   51,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 9, 0x80000000 | 11,    4,   10,   12,

       0        // eod
};

void videoPlayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        videoPlayer *_t = static_cast<videoPlayer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->stateChanged((*reinterpret_cast< videoPlayer*(*)>(_a[1]))); break;
        case 1: _t->timeChanged((*reinterpret_cast< videoPlayer*(*)>(_a[1]))); break;
        case 2: _t->initFinished((*reinterpret_cast< videoPlayer*(*)>(_a[1]))); break;
        case 3: _t->playFailed((*reinterpret_cast< videoPlayer*(*)>(_a[1]))); break;
        case 4: _t->frameDecoded((*reinterpret_cast< videoPlayer*(*)>(_a[1])),(*reinterpret_cast< uint8_t*(*)>(_a[2])),(*reinterpret_cast< VideoSwsSpec(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< videoPlayer* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< videoPlayer* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< videoPlayer* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< videoPlayer* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< videoPlayer* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (videoPlayer::*)(videoPlayer * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&videoPlayer::stateChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (videoPlayer::*)(videoPlayer * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&videoPlayer::timeChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (videoPlayer::*)(videoPlayer * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&videoPlayer::initFinished)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (videoPlayer::*)(videoPlayer * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&videoPlayer::playFailed)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (videoPlayer::*)(videoPlayer * , uint8_t * , VideoSwsSpec & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&videoPlayer::frameDecoded)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject videoPlayer::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_videoPlayer.data,
    qt_meta_data_videoPlayer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *videoPlayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *videoPlayer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_videoPlayer.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int videoPlayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void videoPlayer::stateChanged(videoPlayer * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void videoPlayer::timeChanged(videoPlayer * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void videoPlayer::initFinished(videoPlayer * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void videoPlayer::playFailed(videoPlayer * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void videoPlayer::frameDecoded(videoPlayer * _t1, uint8_t * _t2, VideoSwsSpec & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
