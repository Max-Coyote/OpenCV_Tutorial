#include <iostream>
#include <Eigen/Dense>
#include <vector>
#include <Eigen/LU>
#include <string>
using namespace std;
using Eigen::MatrixXd;

class full_2x2_Kalman
{
public:

    MatrixXd P;
    MatrixXd F;
    MatrixXd H;
    MatrixXd Z;
    MatrixXd R;
    MatrixXd I;
    MatrixXd x;
    MatrixXd y;
    MatrixXd S;
    MatrixXd K;
    full_2x2_Kalman() : P(2,2), F(2,2), H(1,2), Z(1,1), R(1,1), I(2,2), x(2,1){}

double dt = 1;
void _init()
{


    x(0,0) = 0;
    x(1,0) = 0;

    double dt = 1;
    //Uncertainty Matrix

    //MatrixXd P(2x2);
    P(0,0) = 1000;
    P(0,1) = 0;
    P(1,0) = 0;
    P(1,1) = 1000;

    //State Transition Matrix
    //MatrixXd F(2x2);
    F(0,0) = 1;
    F(0,1) = 1;
    F(1,0) = 0;
    F(1,1) = 1;


    //Mesurement Matrix
   // MatrixXd H(1,2);
    H(0,0) = 1;
    H(0,1) = 0;



    //MatrixXd Z(1,2);
    //Measurement Uncertainty
   // MatrixXd R(2,2);
    R(0,0) = 0.1; //0.01

    //Identity matrix
    //MatrixXd I(2x2);
    I(0,0) = 1;
    I(0,1) = 0;
    I(1,0) = 0;
    I(1,1) = 1;



}
void predict()
{
   cout << "full 2X2 kalman" << endl;
   F(0,1) = dt;

   x = F * x;

   P = F * P * Eigen::Transpose<MatrixXd>(F);


   cout << "prediction" << endl;
   cout << x << endl;

}
void update_measurements(double xt, double yt)
{

    Z(0,0) = xt;
   // Z(0,1) = yt;

    cout << Eigen::Transpose<MatrixXd>(Z) - (H * x) << endl;
    y = Eigen::Transpose<MatrixXd>(Z) - (H * x);

    S = H * P * Eigen::Transpose<MatrixXd>(H) + R;
    K = P * Eigen::Transpose<MatrixXd>(H) * Eigen::Inverse<MatrixXd>(S);
    x = x + K * y;
    P = (I - K *H ) * P;
}
};

class full_4x4_Kalman
{
public:
    MatrixXd P;
    MatrixXd F;
    MatrixXd H;
    MatrixXd Z;
    MatrixXd R;
    MatrixXd I;
    MatrixXd x;
    MatrixXd y;
    MatrixXd S;
    MatrixXd K;
    full_4x4_Kalman() : P(4,4), F(4,4), H(2,4), Z(1,2), R(2,2), I(4,4), x(4,1){}
double pp = 0;
double dt = 1;
void _init()
{

    x(0,0) = 0;
    x(1,0) = 0;
    x(2,0) = 0;
    x(3,0) = 0;

    double dt = 1;
    //Uncertainty Matrix

    //MatrixXd P(4x4);
    P(0,0) = 1000;
    P(0,1) = 0;
    P(0,2) = 0;
    P(0,3) = 0;
    P(1,0) = 0;
    P(1,1) = 1000;
    P(1,2) = 0;
    P(1,3) = 0;
    P(2,0) = 0;
    P(2,1) = 0;
    P(2,2) = 1000;
    P(2,3) = 0;
    P(3,0) = 0;
    P(3,1) = 0;
    P(3,2) = 0;
    P(3,3) = 1000;


    //State Transition Matrix
    //MatrixXd F(4x4);
    F(0,0) = 1;
    F(0,1) = 0;
    F(0,2) = dt;
    F(0,3) = 0;
    F(1,0) = 0;
    F(1,1) = 1;
    F(1,2) = 0;
    F(1,3) = dt;
    F(2,0) = 0;
    F(2,1) = 0;
    F(2,2) = dt;
    F(2,3) = 0;
    F(3,0) = 0;
    F(3,1) = 0;
    F(3,2) = 0;
    F(3,3) = 1;



    //Mesurement Matrix
   // MatrixXd H(2,4);
    H(0,0) = 1;
    H(0,1) = 0;
    H(0,2) = 0;
    H(0,3) = 0;
    H(1,0) = 0;
    H(1,1) = 1;
    H(1,2) = 0;
    H(1,3) = 0;


    //MatrixXd Z(1,2);
    //Measurement Uncertainty
   // MatrixXd R(2,2);
    R(0,0) = 0.01; //0.01
    R(0,1) = 0;
    R(1,0) = 0;
    R(1,1) = 0.01;

    //Identity matrix
    //MatrixXd I(2x2);
    I(0,0) = 1;
    I(0,1) = 0;
    I(0,2) = 0;
    I(0,3) = 0;
    I(1,0) = 0;
    I(1,1) = 1;
    I(1,2) = 0;
    I(1,3) = 0;
    I(2,0) = 0;
    I(2,1) = 0;
    I(2,2) = 1;
    I(2,3) = 0;
    I(3,0) = 0;
    I(3,1) = 0;
    I(3,2) = 0;
    I(3,3) = 1;
}
void _init(double p, double r, double n)
{

    pp = n;

    x(0,0) = 0;
    x(1,0) = 0;
    x(2,0) = 0;
    x(3,0) = 0;

    double dt = 1;
    //Uncertainty Matrix

    //MatrixXd P(4x4);
    P(0,0) = p;
    P(0,1) = 0;
    P(0,2) = 0;
    P(0,3) = 0;
    P(1,0) = 0;
    P(1,1) = p;
    P(1,2) = 0;
    P(1,3) = 0;
    P(2,0) = 0;
    P(2,1) = 0;
    P(2,2) = p;
    P(2,3) = 0;
    P(3,0) = 0;
    P(3,1) = 0;
    P(3,2) = 0;
    P(3,3) = p;


    //State Transition Matrix
    //MatrixXd F(4x4);
    F(0,0) = 1;
    F(0,1) = 0;
    F(0,2) = dt;
    F(0,3) = 0;
    F(1,0) = 0;
    F(1,1) = 1;
    F(1,2) = 0;
    F(1,3) = dt;
    F(2,0) = 0;
    F(2,1) = 0;
    F(2,2) = dt;
    F(2,3) = 0;
    F(3,0) = 0;
    F(3,1) = 0;
    F(3,2) = 0;
    F(3,3) = 1;



    //Mesurement Matrix
   // MatrixXd H(2,4);
    H(0,0) = 1;
    H(0,1) = 0;
    H(0,2) = 0;
    H(0,3) = 0;
    H(1,0) = 0;
    H(1,1) = 1;
    H(1,2) = 0;
    H(1,3) = 0;


    //MatrixXd Z(1,2);
    //Measurement Uncertainty
   // MatrixXd R(2,2);
    R(0,0) = r; //0.01
    R(0,1) = 0;
    R(1,0) = 0;
    R(1,1) = r;

    //Identity matrix
    //MatrixXd I(2x2);
    I(0,0) = 1;
    I(0,1) = 0;
    I(0,2) = 0;
    I(0,3) = 0;
    I(1,0) = 0;
    I(1,1) = 1;
    I(1,2) = 0;
    I(1,3) = 0;
    I(2,0) = 0;
    I(2,1) = 0;
    I(2,2) = 1;
    I(2,3) = 0;
    I(3,0) = 0;
    I(3,1) = 0;
    I(3,2) = 0;
    I(3,3) = 1;  //  cout << "My track" << endl;
    //  cout << xt << "    " << yt << endl;
    //  cout << "Prediction" << endl;
     // cout << xp << "    " << yp << endl;

    Z(0,0) = 1;
    Z(0,1) = 0;
}

double xi = 0;
double xi_1 = 0;
double xi_2 = 0;

double count_ax(double x0)
{
    xi_2 = xi_1;
    xi_1 = xi;
    xi = x0;
    return (xi - 2*xi_1 + xi_2)/dt;
}

double yi = 0;
double yi_1 = 0;
double yi_2 = 0;


double count_ay(double y0)
{
    yi_2 = yi_1;
    yi_1 = yi;
    yi = y0;
    return (xi - 2*xi_1 + xi_2)/dt;
}


double jxi = 0;
double jxi_1 = 0;
double jxi_2 = 0;
double jxi_3 = 0;

double count_jx(double x0)
{
    jxi_3 = jxi_2;
    jxi_2 = jxi_1;
    jxi_1 = jxi;
    jxi = x0;

    return (jxi - 3*jxi_1 + 3 * jxi_2 - jxi_3)/dt;
}

double jyi = 0;
double jyi_1 = 0;
double jyi_2 = 0;
double jyi_3 = 0;

double count_jy(double y0)
{
    jyi_3 = jyi_2;
    jyi_2 = jyi_1;
    jyi_1 = jyi;
    jyi = y0;
    return (jyi - 3*jyi_1 + 3 * jyi_2 - jyi_3)/dt;
}

void predict()
{
   F(0,1) = dt;

   x = F * x;

   P = F * P * Eigen::Transpose<MatrixXd>(F);


}
double v0 = 0;
double a = 0;
double a1 = 0;
double ar = 0;
int k = 0;
double x_error = 0;
double y_error = 0;
double x_step = 0;
double y_step = 0;
double step = 0;
double a_xy =0;
double a_x =0;
double a_y =0;
double i_x =0;
double i_y =0;
double i_xy = 0;
void update_measurements(double xt, double yt)
{
  // xy_error = sqrt((xt - x(0,0))*(xt - x(0,0)) + (yt - x(1,0))*(yt - x(1,0)));
   step = sqrt((xt - Z(0,0))*(xt - Z(0,0)) + (yt - Z(0,1))*(yt - Z(0,1)));
//cout << "-----------" << endl;
   x_step = xt - Z(0,0);
   y_step = yt - Z(0,1);
   x_error = xt - x(0,0);
   y_error = yt - x(1,0);
   a_x = count_ax(xt);
   a_y = count_ay(yt);
   i_x = count_jx(xt);
   i_y = count_jy(yt);
   Z(0,0) = xt;
   Z(0,1) = yt;
   //cout << step << endl;
  // cout << step << endl;
   //cout << x_step << "," << y_step << "," << x_error << "," <<y_error<<","<<count_ax(xt) << ","<< count_ay(yt) << ","<< count_jx(xt) << "," << count_jy(yt) << endl;
  // cout << sqrt(x_step *x_step + y_step*y_step) << "," << sqrt(x_error*x_error + y_error*y_error) << "," << sqrt(a_x*a_x + a_y*a_y) << ","<<sqrt(i_x*i_x + i_y*i_y) << endl;


   // cout << "+++++++++" << endl;
    y = Eigen::Transpose<MatrixXd>(Z) - (H * x);
    S = H * P * Eigen::Transpose<MatrixXd>(H) + R;
    K = P * Eigen::Transpose<MatrixXd>(H) * Eigen::Inverse<MatrixXd>(S);
    x = x + K * y;
    P = (I - K * H ) * P;
    P(0,0) += pp;
    P(1,1) += pp;
    P(2,2) += pp;
    P(3,3) += pp;

}
};
