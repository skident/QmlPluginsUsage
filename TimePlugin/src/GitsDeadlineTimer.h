#include "GitsTimer.h"
#include <QObject>

class GitsDeadlineTimer
        : public GitsTimer
{
    Q_OBJECT

    Q_PROPERTY(bool aboutToReachEvent READ aboutToReachEvent NOTIFY aboutToReachEventChanged)
    Q_PROPERTY(int secondsToEvent READ secondsToEvent WRITE setSecondsToEvent NOTIFY secondsToEventChanged)
    Q_PROPERTY(bool countdown READ countdown WRITE setCountdown NOTIFY countdownChanged)

public:
    int secondsToEvent();
    void setSecondsToEvent(int sec);

    bool countdown();

    void setCountdown(bool countdown);

    virtual QString elapsed();

    bool aboutToReachEvent();

signals:
    void secondsToEventChanged();
    void countdownChanged();
    void aboutToReachEventChanged();
    void finished();

private:
    int mSecondsToEvent;
    bool mCountdown = true;
    int mSecondsToAboutReachEvent = 5;
    bool mAboutToReachEvent = false;
};
