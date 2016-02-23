#include "degrees.h"

Degrees::Degrees()
{

}

Degrees::~Degrees()
{

}

Coord Degrees::convertUDToDMS(QString longitude, QString latitude)
{
    double lon = longitude.toDouble();
    double lat = latitude.toDouble();
    m_lonDegree = lon;
    m_latDegree = lat;
    m_lonMinutesDouble = (lon - m_lonDegree)*60;
    m_latMinutesDouble = (lat - m_latDegree)*60;
    m_lonMinutes = m_lonMinutesDouble;
    m_latMinutes = m_latMinutesDouble;
    m_lonSecondsDouble = (m_lonMinutesDouble - m_lonMinutes)*60;
    m_latSecondsDouble = (m_latMinutesDouble - m_latMinutes)*60;

    qDebug()<<"LON: "<<m_lonDegree<<" "<<m_lonMinutes<<" "<<m_lonSecondsDouble;
    qDebug()<<"LAT: "<<m_latDegree<<" "<<m_latMinutes<<" "<<m_latSecondsDouble;

    m_coord.lon = QString::number(m_lonDegree) + ", " + QString::number(m_lonMinutes) + "', " + QString::number(m_lonSecondsDouble) + "''";
    m_coord.lat = QString::number(m_latDegree) + ", " + QString::number(m_latMinutes) + "', " + QString::number(m_latSecondsDouble) + "''";
    return m_coord;
}

Coord Degrees::convertDMStoUD(QString longitude, QString latitude)
{
    QStringList listLon = longitude.split(",");
    QStringList listLat = latitude.split(",");

    double lon = listLon[0].toDouble() + listLon[1].toDouble()/60 + listLon[2].toDouble()/3600;
    double lat = listLat[0].toDouble() + listLat[1].toDouble()/60 + listLat[2].toDouble()/3600;

    m_coord.lon = QString::number(lon);
    m_coord.lat = QString::number(lat);

    qDebug()<<"LON: "<< m_coord.lon;
    qDebug()<<"LAT: "<< m_coord.lat;

    return m_coord;
}

