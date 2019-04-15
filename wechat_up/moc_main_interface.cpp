/****************************************************************************
** Meta object code from reading C++ file 'main_interface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "main_interface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_interface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TimeThread_t {
    QByteArrayData data[5];
    char stringdata0[32];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TimeThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TimeThread_t qt_meta_stringdata_TimeThread = {
    {
QT_MOC_LITERAL(0, 0, 10), // "TimeThread"
QT_MOC_LITERAL(1, 11, 9), // "send_time"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 4), // "date"
QT_MOC_LITERAL(4, 27, 4) // "time"

    },
    "TimeThread\0send_time\0\0date\0time"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TimeThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QDate, QMetaType::QTime,    3,    4,

       0        // eod
};

void TimeThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TimeThread *_t = static_cast<TimeThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send_time((*reinterpret_cast< QDate(*)>(_a[1])),(*reinterpret_cast< QTime(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TimeThread::*_t)(QDate , QTime );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimeThread::send_time)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject TimeThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_TimeThread.data,
      qt_meta_data_TimeThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TimeThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TimeThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TimeThread.stringdata0))
        return static_cast<void*>(const_cast< TimeThread*>(this));
    return QThread::qt_metacast(_clname);
}

int TimeThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void TimeThread::send_time(QDate _t1, QTime _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_Main_interface_t {
    QByteArrayData data[16];
    char stringdata0[198];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Main_interface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Main_interface_t qt_meta_stringdata_Main_interface = {
    {
QT_MOC_LITERAL(0, 0, 14), // "Main_interface"
QT_MOC_LITERAL(1, 15, 16), // "update_date_time"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 4), // "date"
QT_MOC_LITERAL(4, 38, 4), // "time"
QT_MOC_LITERAL(5, 43, 12), // "receivelogin"
QT_MOC_LITERAL(6, 56, 14), // "GetWebJsonData"
QT_MOC_LITERAL(7, 71, 14), // "QNetworkReply*"
QT_MOC_LITERAL(8, 86, 11), // "analyseJson"
QT_MOC_LITERAL(9, 98, 10), // "new_client"
QT_MOC_LITERAL(10, 109, 14), // "new_client_msg"
QT_MOC_LITERAL(11, 124, 9), // "read_data"
QT_MOC_LITERAL(12, 134, 13), // "read_data_msg"
QT_MOC_LITERAL(13, 148, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(14, 170, 21), // "on_listWidget_clicked"
QT_MOC_LITERAL(15, 192, 5) // "index"

    },
    "Main_interface\0update_date_time\0\0date\0"
    "time\0receivelogin\0GetWebJsonData\0"
    "QNetworkReply*\0analyseJson\0new_client\0"
    "new_client_msg\0read_data\0read_data_msg\0"
    "on_pushButton_clicked\0on_listWidget_clicked\0"
    "index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Main_interface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   64,    2, 0x08 /* Private */,
       5,    0,   69,    2, 0x08 /* Private */,
       6,    1,   70,    2, 0x08 /* Private */,
       8,    0,   73,    2, 0x08 /* Private */,
       9,    0,   74,    2, 0x08 /* Private */,
      10,    0,   75,    2, 0x08 /* Private */,
      11,    0,   76,    2, 0x08 /* Private */,
      12,    0,   77,    2, 0x08 /* Private */,
      13,    0,   78,    2, 0x08 /* Private */,
      14,    1,   79,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QDate, QMetaType::QTime,    3,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   15,

       0        // eod
};

void Main_interface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Main_interface *_t = static_cast<Main_interface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->update_date_time((*reinterpret_cast< QDate(*)>(_a[1])),(*reinterpret_cast< QTime(*)>(_a[2]))); break;
        case 1: _t->receivelogin(); break;
        case 2: _t->GetWebJsonData((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 3: _t->analyseJson(); break;
        case 4: _t->new_client(); break;
        case 5: _t->new_client_msg(); break;
        case 6: _t->read_data(); break;
        case 7: _t->read_data_msg(); break;
        case 8: _t->on_pushButton_clicked(); break;
        case 9: _t->on_listWidget_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

const QMetaObject Main_interface::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Main_interface.data,
      qt_meta_data_Main_interface,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Main_interface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Main_interface::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Main_interface.stringdata0))
        return static_cast<void*>(const_cast< Main_interface*>(this));
    return QWidget::qt_metacast(_clname);
}

int Main_interface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
