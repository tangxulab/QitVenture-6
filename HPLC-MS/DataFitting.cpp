#include "DataFitting.h"
#include "SQLList.h"

DataFitting::DataFitting()
{

}
void DataFitting::LineFitLeastSquares(double* data_x, double* data_y, int data_n, double& a, double& b)
{
    float A = 0.0;
    float B = 0.0;
    float C = 0.0;
    float D = 0.0;


    for (int i = 0; i < data_n; i++)
    {
        A += data_x[i] * data_x[i];
        B += data_x[i];
        C += data_x[i] * data_y[i];
        D += data_y[i];
    }

    // 计算斜率a和截距b
    //float a, b, temp = 0;
    float temp = 0;
    if (temp = (data_n * A - B * B))// 判断分母不为0
    {
        a = (data_n * C - B * D) / temp;
        b = (A * D - B * C) / temp;
    }
    else
    {
        a = 1;
        b = 0;
    }

    SQLList *sqlList = new SQLList();
    sqlList->updateDataFit(QString::number(a),QString::number(b)," "," ","线性拟合");

}





//累加
double DataFitting::sum(QVector<double> Vnum, int n)
{
    double dsum = 0;
    for (int i = 0; i < n; i++)
    {
        dsum += Vnum[i];
    }
    return dsum;
}
//乘积和
double DataFitting::MutilSum(QVector<double> Vx, QVector<double> Vy, int n)
{
    double dMultiSum = 0;
    for (int i = 0; i < n; i++)
    {
        dMultiSum += Vx[i] * Vy[i];
    }
    return dMultiSum;
}
//ex次方和
double DataFitting::RelatePow(QVector<double> Vx, int n, int ex)
{
    double ReSum = 0;
    for (int i = 0; i < n; i++)
    {
        ReSum += pow(Vx[i], ex);
    }
    return ReSum;
}
//x的ex次方与y的乘积的累加
double DataFitting::RelateMutiXY(QVector<double> Vx, QVector<double> Vy, int n, int ex)
{
    double dReMultiSum = 0;
    for (int i = 0; i < n; i++)
    {
        dReMultiSum += pow(Vx[i], ex) * Vy[i];
    }
    return dReMultiSum;
}
//计算方程组的增广矩阵
void DataFitting::EMatrix(QVector<double> Vx, QVector<double> Vy, int n, int ex, double coefficient[])
{
    for (int i = 1; i <= ex; i++)
    {
        for (int j = 1; j <= ex; j++)
        {
            Em[i][j] = RelatePow(Vx, n, i + j - 2);
        }
        Em[i][ex + 1] = RelateMutiXY(Vx, Vy, n, i - 1);
    }
    Em[1][1] = n;
    CalEquation(ex, coefficient);
}
//求解方程
void DataFitting::CalEquation(int exp, double coefficient[])
{
    for (int k = 1; k < exp; k++) //消元过程
    {
        for (int i = k + 1; i < exp + 1; i++)
        {
            double p1 = 0;

            if (Em[k][k] != 0)
                p1 = Em[i][k] / Em[k][k];

            for (int j = k; j < exp + 2; j++)
                Em[i][j] = Em[i][j] - Em[k][j] * p1;
        }
    }
    coefficient[exp] = Em[exp][exp + 1] / Em[exp][exp];
    for (int l = exp - 1; l >= 1; l--)   //回代求解
        coefficient[l] = (Em[l][exp + 1] - F(coefficient, l + 1, exp)) / Em[l][l];


}
//供CalEquation函数调用
double DataFitting::F(double c[], int l, int m)
{
    double sum = 0;
    for (int i = l; i <= m; i++)
        sum += Em[l - 1][i] * c[i];
    return sum;
}
