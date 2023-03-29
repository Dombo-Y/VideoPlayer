#ifndef APLAYER_H
#define APLAYER_H

#include <QObject>

class APlayer : public QObject
{
    Q_OBJECT
public:
    explicit APlayer(QObject *parent = nullptr);

public:
    void play(const std::string& ){

    }

signals:

public slots:
};

#endif // APLAYER_H
