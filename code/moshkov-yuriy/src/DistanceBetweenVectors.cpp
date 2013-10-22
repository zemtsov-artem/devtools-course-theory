/* Copyright 2013 Moshkov Yuriy */
#include "DistanceBetweenVectors.h"


float DistanceBetweenVectors::CalculateDistance(float *vector1, float *vector2, TypeMetric typeMetric, int sizeVector) {
    float distance;
    if (typeMetric == LInfinity) {
        float max = 0;
        for (int i = 0; i < sizeVector; i++)
            if (max < fabs(vector1[i] - vector2[i]))
                max = fabs(vector1[i] - vector2[i]);
        distance = max;
    } else {
        float sumComp = 0;
        for (int i = 0; i < sizeVector; i++)
            sumComp += powf(fabs(vector1[i] - vector2[i]), 1.0f * typeMetric);
        distance = powf(sumComp, 1.0f / typeMetric);
    }
    return distance;
}
