#pragma once
#include "clientCall.h"
class clientFeedBack :
    public clientCall
{
    float averScore;     
    int speedScore;     
    int qualityScore;   
    int comScore;       
public:
    clientFeedBack();
    float countAverage();
    float getAverScore();
    void setAverScore(float averScore);
    int getSpeedScore();
    void setSpeedScore(int speedScore);
    int getQualityScore();
    void setQualityScore(int qualityScore);
    int getComScore();
    void setComScore(int comScore);
};

