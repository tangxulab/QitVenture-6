#ifndef DATAFITTING_H
#define DATAFITTING_H
#include <QVector>
#include <QtMath>
#include "SQLList.h"

class DataFitting
{
public:
    DataFitting();

    //最小二乘拟合相关函数定义
    double sum(QVector<double> Vnum, int n);
    double MutilSum(QVector<double> Vx, QVector<double> Vy, int n);
    double RelatePow(QVector<double> Vx, int n, int ex);
    double RelateMutiXY(QVector<double> Vx, QVector<double> Vy, int n, int ex);
    void EMatrix(QVector<double> Vx, QVector<double> Vy, int n, int ex, double coefficient[]);
    void CalEquation(int exp, double coefficient[]);
    double F(double c[], int l, int m);
    double Em[6][4];

    void LineFitLeastSquares(double* data_x, double* data_y, int data_n, double& a, double& b);
};

#endif // DATAFITTING_H
