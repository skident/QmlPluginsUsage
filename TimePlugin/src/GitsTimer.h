#pragma once

#include <QQuickItem>
#include <QTimer>

class GitsTimer : public QQuickItem
{
    Q_OBJECT

    Q_PROPERTY(QString timeElapsed READ timeElapsed NOTIFY timeElapsedChanged)
    Q_PROPERTY(bool isActive READ isActive NOTIFY isActiveChanged)

public:
    GitsTimer();

    Q_INVOKABLE void start();

    Q_INVOKABLE void stop();

    Q_INVOKABLE void pause();

    Q_INVOKABLE void resume();

    QString timeElapsed();

    bool isActive() const;

    virtual QString elapsed();

private slots:
    void timeout();

protected:
    int secondsElapsed();

signals:
    void timeElapsedChanged();
    void isActiveChanged();
    void authorChanged();

private:
    const int mTimerIntervalInSecs = 1;
    int mSecondsElapsed = 0;
    QTimer mTimer;
};


