#ifndef DEGREES_H
#define DEGREES_H

#include <QString>
#include <QDebug>

struct Coord {
    QString lon = "";
    QString lat = "";
};

class Degrees
{
public:
    Degrees();
    ~Degrees();

    Coord convertUDToDMS(QString longitude, QString latitude);
    Coord convertDMStoUD(QString longitude, QString latitude);

private:
    int m_lonDegree;
    int m_latDegree;
    int m_lonMinutes;
    int m_latMinutes;
    double m_lonDegreeDouble;
    double m_latDegreeDouble;
    double m_lonMinutesDouble;
    double m_latMinutesDouble;
    double m_lonSecondsDouble;
    double m_latSecondsDouble;
    Coord m_coord;
};

#endif // DEGREES_H
