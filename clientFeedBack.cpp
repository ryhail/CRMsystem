#include "clientFeedBack.h"

clientFeedBack::clientFeedBack()
{
    averScore = -1;
    speedScore = -1;
    qualityScore = -1;
    comScore = -1;
}

float clientFeedBack::getAverScore()  {
    return averScore;
}

void clientFeedBack::setAverScore(float averScore) {
    clientFeedBack::averScore = averScore;
}

int clientFeedBack::getSpeedScore() {
    return speedScore;
}

void clientFeedBack::setSpeedScore(int speedScore) {
    clientFeedBack::speedScore = speedScore;
}

int clientFeedBack::getQualityScore() {
    return qualityScore;
}

void clientFeedBack::setQualityScore(int qualityScore) {
    clientFeedBack::qualityScore = qualityScore;
}

int clientFeedBack::getComScore() {
    return comScore;
}

void clientFeedBack::setComScore(int comScore) {
    clientFeedBack::comScore = comScore;
}

