#include "GitsTimer.h"

#include <QTime>
#include <QDebug>

GitsTimer::GitsTimer()
{
    connect(&mTimer, &QTimer::timeout, this, &GitsTimer::timeout);
}

void GitsTimer::start()
{
    mTimer.setInterval(mTimerIntervalInSecs * 1000);
    mTimer.start();
    emit isActiveChanged();

#ifdef __GITS_TRACE__
    qDebug() << "Timer started";
#endif
}

void GitsTimer::stop()
{
    mTimer.stop();
    mSecondsElapsed = 0;
    emit isActiveChanged();
    //        emit timeElapsedChanged();

#ifdef __GITS_TRACE__
    qDebug() << "Timer stopped";
#endif
}

void GitsTimer::pause()
{
    mTimer.stop();
    emit isActiveChanged();

#ifdef __GITS_TRACE__
    qDebug() << "Timer paused";
#endif
}

void GitsTimer::resume()
{
    start();

#ifdef __TRACE__
    qDebug() << "Timer resumed";
#endif
}

QString GitsTimer::timeElapsed()
{
    return elapsed();
}

bool GitsTimer::isActive() const
{
    return mTimer.isActive();
}

QString GitsTimer::elapsed()
{
    QTime time(0, 0, 0);
    time = time.addSecs(mSecondsElapsed);
    QString res = time.toString("hh : mm : ss");

#ifdef __GITS_TRACE__
    qDebug() << "Elapsed secs: " << mSecondsElapsed << ", HumanReadable: " << res;
#endif

    return res;
}

void GitsTimer::timeout()
{
    mSecondsElapsed += mTimerIntervalInSecs;
    emit timeElapsedChanged();
}

int GitsTimer::secondsElapsed()
{
    return mSecondsElapsed;
}
