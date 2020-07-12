#include "GitsDeadlineTimer.h"

#include <QTime>

int GitsDeadlineTimer::secondsToEvent()
{
    return mSecondsToEvent;
}

void GitsDeadlineTimer::setSecondsToEvent(int sec)
{
    mSecondsToEvent = sec;
    emit secondsToEventChanged();
}

bool GitsDeadlineTimer::countdown()
{
    return mCountdown;
}

void GitsDeadlineTimer::setCountdown(bool countdown)
{
    mCountdown = countdown;
    emit countdownChanged();
}

QString GitsDeadlineTimer::elapsed()
{
    int secs = secondsElapsed();
    if (countdown())
        secs = secondsToEvent() - secs;

    if (secondsElapsed() + mSecondsToAboutReachEvent >= secondsToEvent())
    {
        mAboutToReachEvent = true;
        emit aboutToReachEventChanged();
    }

    if (secondsToEvent() == secondsElapsed())
    {
        stop();
        mAboutToReachEvent = false;
    }

    QTime time(0, 0, 0);
    time = time.addSecs(secs);
    QString res = time.toString("hh : mm : ss");

#ifdef __GITS_TRACE__
    qDebug() << "Elapsed secs: " << secondsElapsed() << ", HumanReadable: " << res;
#endif

    return res;
}

bool GitsDeadlineTimer::aboutToReachEvent()
{
    return mAboutToReachEvent;
}
